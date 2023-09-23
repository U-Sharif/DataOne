using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;
using System.Net;

namespace HandreaderEmu.cs
{
    class Program
    {
        private static Socket mSocket;
        private static NetworkStream ns;
        private static StreamWriter sw;

        static void Main(string[] args)
        {
            mSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            mSocket.Bind(new IPEndPoint(IPAddress.Any, 1234));
            mSocket.Listen(5);
            Socket s = mSocket.Accept();

            ns = new NetworkStream(s);
            sw = new StreamWriter(ns);

            while (true)
            {
                sw.WriteLine("CONNECT");
                for (int i = 0; i < new Random().Next(100); i++)
                {
                    sw.WriteLine("3000" + new Random().Next(10).ToString("x24"));
                    sw.Flush();
                    ns.Flush();
                    Thread.Sleep(100);
                }
                sw.WriteLine("DISCONNECT");
                sw.Flush();
                ns.Flush();
                Thread.Sleep(5000);
            }
        }
    }
}
