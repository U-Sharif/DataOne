using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Threading;
using System.IO;

namespace DataOneLib
{
    public class Server
    {
        public static int AppInstanceNumber = 0;
        private Socket mSocket;
        private Thread mListener;
        private bool mStopping = false;
        private Logger mLogger;
        public event ServerEvent OnRequest;
        public int Port;

        public Server(Logger l, int port)
        {
            mSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            Port = port;
            AppInstanceNumber = 1;
            while (true)
            {
                try
                {
                    mSocket.Bind(new IPEndPoint(IPAddress.Any, Port));
                    break;
                }
                catch
                {
                    Port++;
                    AppInstanceNumber++;
                }
            }
            mSocket.Listen(5);
            mLogger = l;
            mListener = new Thread(new ThreadStart(Listen));
            mListener.Start();
        }

        public void Abort()
        {
            mStopping = true;
            mListener.Abort();
        }

        private void Listen()
        {
            try
            {
                while (!mStopping)
                {
                    Socket ns = mSocket.Accept();
                    ServerWorker w = new ServerWorker();
                    w.mLogger = mLogger;
                    w.OnRequest += new ServerEvent(w_OnRequest);
                    new Thread(new ParameterizedThreadStart(w.Work)).Start(ns);
                }
            }
            catch { }
        }

        void w_OnRequest(EndPoint remote, int start)
        {
            OnRequest(remote, start);
        }

        public delegate void ServerEvent(EndPoint remote, int start);
    }
}
