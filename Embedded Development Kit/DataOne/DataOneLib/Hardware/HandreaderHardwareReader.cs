using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace DataOneLib
{
    public class HandreaderHardwareReader : BaseHardwareReader
    {
        public override event BaseHardwareReader.TagEvent OnTag;
        public bool Receiving = false;
        private Socket mSocket;
        private StreamReader mReader;
        private bool mRunning = false;
        private List<OneTag> mBuffer = null;

        public override bool Connected
        {
            get
            {
                return (mReader != null);
            }
        }

        public override bool CanWrite
        {
            get
            {
                return false;
            }
        }

        public override void Connect(string addr, int port)
        {
            mSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                mSocket.Connect(addr, port);
            }
            catch
            {
                mReader = null;
                throw;
            }

            mReader = new StreamReader(new NetworkStream(mSocket));
            new Thread(delegate()
            {
                while (mSocket.Connected)
                {
                    string s = mReader.ReadLine();
                    if (s.StartsWith( "CONNECT"))
                        Receiving = true;
                    if (s.StartsWith("DISCONNECT"))
                        Receiving = false;
                    if (s.Length > 0 && Char.IsDigit(s[0]) && mRunning)
                    {
                        Receiving = true;
                        string epc = s.Substring(4);
                        OneTag tag = new OneTag();
                        tag.EPC = epc;
                        tag.LastSeen = DateTime.Now;
                        tag.TID = "";
                        if (OnTag != null)
                            OnTag(tag);
                        if (mBuffer != null)
                            lock (mBuffer)
                                mBuffer.Add(tag);
                    }
                }
            }).Start();
        }

        public override List<OneTag> Query(double secs)
        {
            mBuffer = new List<OneTag>();
            Thread.Sleep((int)(secs * 10000));
            List<OneTag> t = mBuffer;
            mBuffer = null;
            return t;
        }

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
