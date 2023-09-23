using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;

namespace DataOneLib
{
    public class Client
    {
        private string mHost;
        private int mPort;

        public Client(string host, int port)
        {
            mHost = host;
            mPort = port;
        }

        public NetworkStream Fetch(int start)
        {
            Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            s.Connect(mHost, mPort);
            s.Send(Encoding.ASCII.GetBytes(start.ToString()));
            return new NetworkStream(s);
        }
    }
}
