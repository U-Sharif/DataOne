using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace DataOneLib
{
    public static class BarcodeScanner
    {
        static Socket socket;
        static NetworkStream ns;
        public static string Host;
        public static int Port;
        public static bool Connected = false;

        public static void Connect()
        {
            if (socket != null && socket.Connected)
                socket.Disconnect(true);
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            socket.Connect(Host, Port);
            Connected = true;
            ns = new NetworkStream(socket);
        }

        public static int? Scan()
        {
            byte[] d = Encoding.ASCII.GetBytes("\u001BZ\r");
            ns.Write(d, 0, d.Length);
            ns.Flush();
            result = null;
            Thread t = new Thread(new ParameterizedThreadStart(scan));
            t.Start(ns);
            t.Join(1000000);

            if (result == null)
                return null;

            try
            {
                result = result.Trim('\r', '\n', '\t', ' ', '\b');
                int res = int.Parse(result);
                result = null;
                if (res == 0)
                    return null;
                return res;
            }
            catch { }
            return null;
        }

        private static string result = null;
        private static void scan(object o)
        {
            try
            {
                result = "";
                while (!result.Contains("\r"))
                {
                    byte[] buf = new byte[100];
                    int s = ((NetworkStream)o).Read(buf, 0, 100);
                    result += Encoding.ASCII.GetString(buf, 0, s);
                }
            }
            catch { }
        }

        public static void Dispose()
        {
            socket.Close();
        }
    }
}
