using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Threading;
using System.Reflection;

namespace DataOneLib
{
    public class TimingClient
    {
        Logger mLogger;
        string mHost;
        int mPort;
        Thread runner;
        Thread thisRun;

        public TimingClient(string host, int port, Logger log)
        {
            mLogger = log;
            mHost = host;
            mPort = port;
        }

        public void Start()
        {
            runner = new Thread(new ThreadStart(Run));
            runner.Start();
        }

        public void Run()
        {
            while (true)
            {
                thisRun = new Thread(new ThreadStart(SingleRun));
                thisRun.Start();
                thisRun.Join();
                Thread.Sleep(2000);
            }
        }

        void SingleRun()
        {
            Thread pinger = null;
            try
            {
                Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                s.Connect(mHost, mPort);

                s.Send(Encoding.ASCII.GetBytes("DSDOV" + Assembly.GetEntryAssembly().GetName().Version.ToString(2) + "," + mLogger.Last + "\r\n"));

                pinger = new Thread(new ParameterizedThreadStart(Pinger));
                pinger.Start(s);
                new ServerWorker(mLogger).Work(s);
                s.Close();
            }
            catch { }
            try
            {
                pinger.Abort();
            }
            catch { }
        }

        public void Pinger(Object o)
        {
            Socket s = (Socket)o;
            try
            {
                while (true)
                {
                    lock (s)
                        s.Send(Encoding.ASCII.GetBytes("PING\r\n"));
                    Thread.Sleep(10000);
                }
            }
            catch {
                thisRun.Abort();
            }
        }
    }
}
