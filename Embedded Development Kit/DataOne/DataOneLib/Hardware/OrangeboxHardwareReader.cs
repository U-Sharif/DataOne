using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;
using System.Net;
using System.Globalization;

namespace DataOneLib
{
    public class OrangeboxHardwareReader : BaseHardwareReader
    {
        public override event BaseHardwareReader.TagEvent OnTag;
        public string PIFilter = "P";
        public int ClientCount = 0;
        private object writeLock = new object();
        private Socket mSocket;
        private Thread mListener;
        private bool mRunning = false, mStopping = false;

        public OrangeboxHardwareReader()
        {
            mSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            mSocket.Bind(new IPEndPoint(IPAddress.Any, 61610));
            mSocket.Listen(5);
            mListener = new Thread(new ThreadStart(Listen));
            mListener.Start();
        }

        private void Listen()
        {
            try
            {
                while (!mStopping)
                {
                    Socket ns = mSocket.Accept();
                    Worker w = new Worker();
                    w.parent = this;
                    ClientCount++;
                    w.OnTag += new TagEvent(w_OnTag);
                    new Thread(new ParameterizedThreadStart(w.Work)).Start(ns);
                }
            }
            catch { }
        }

        void w_OnTag(OneTag t)
        {
            if (OnTag != null)
                OnTag(t);
        }

        public void ProcessTag(string[] args)
        {
            if (args.Length > 10 && args[0] == "TO")
            {
                if (args[10] != PIFilter)
                    return;

                OneTag t = new OneTag();
                t.BibOverride = args[2].TrimStart('0');
                DateTime d = new DateTime(1970, 1, 1);
                try
                {
                    d = d.AddSeconds(double.Parse(args[5].Replace(',', '.'), CultureInfo.InvariantCulture));
                    t.RSSILast = double.Parse(args[8].Replace(',', '.'), CultureInfo.InvariantCulture);
                }
                catch { }
                int timer = int.Parse(args[3]);
                int evt = int.Parse(args[4]);
                string epc = timer + "/" + evt + "/" + t.BibOverride;
                t.LastSeen = d;
                t.EPC = epc;
                t.RSSIMax = t.RSSILast;
                t.RSSIMin = t.RSSILast;
                if (OnTag != null)
                    OnTag(t);
            }
        }

        class Worker
        {
            private Socket s;
            public event BaseHardwareReader.TagEvent OnTag;
            public OrangeboxHardwareReader parent;
            private string Buffer = "";
            private bool Dead = false;

            public void Work(object o)
            {
                s = (Socket)o;
                s.SendBufferSize = 1;

                bool first = true;

                try
                {
                    while (true)
                    {
                        string line = Receive();
                        string[] args = line.Split('~');

                        if (first)
                        {
                            string ip = "93.125.15.156";//((IPEndPoint)s.LocalEndPoint).Address 
                            Send("ACK~CCSLite~" + ip + "~0.1.14");
                            Send("IS");
                            Send("MR~~1");
                            Send("RR~1");
                        }
                        else
                        {
                            if (args[0] == "PING")
                                Send("ACK~PING");

                            lock (parent.writeLock)
                            {
                                try
                                {
                                    parent.ProcessTag(args);
                                }
                                catch { }
                            }
                        }

                        first = false;
                    }
                }
                catch { }
            }


            public void Send(string str)
            {
                try
                {
                    s.Send(Encoding.ASCII.GetBytes(str + "\r\n"));
                }
                catch (SocketException)
                {
                    if (!Dead)
                    {
                        Dead = true;
                        parent.ClientCount--;
                    }
                }
            }

            public string Receive()
            {
                byte[] buf = new byte[1024];
                while (!Buffer.Contains("\n"))
                    try
                    {
                        int l = s.Receive(buf, 1024, SocketFlags.None);
                        Buffer += Encoding.ASCII.GetString(buf, 0, l);
                        if (l == 0)
                            throw new Exception();
                    }
                    catch (SocketException)
                    {
                        if (!Dead)
                        {
                            Dead = true;
                            parent.ClientCount--;
                        }
                    }
                string[] t = Buffer.Split(new char[] { '\n' }, 2);
                Buffer = t[1].Trim('\n', '\r');
                return t[0].Trim('\n', '\r');
            }
        }

        public override bool Connected
        {
            get
            {
                return true;
            }
        }

        public override bool CanWrite
        {
            get
            {
                return false;
            }
        }

        public override void Connect(string addr, int port) { }

        public override List<OneTag> Query(double secs) { return null; }

        public override void Start()
        {
            mRunning = true;
        }

        public override void Stop()
        {
            mRunning = false;
        }

        public override bool WriteTag(string oldEpc, string newEpc)
        {
            throw new NotSupportedException();
        }
    }
}
