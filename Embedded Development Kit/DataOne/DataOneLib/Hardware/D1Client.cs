using System;
using System.Collections.Generic;
using System.Text;
using System.Net.Sockets;
using System.Threading;
using System.IO;
using System.Globalization;
using Impinj.OctaneSdk;

namespace DataOneLib
{
    public class D1Client
    {
        public string Host;
        public bool Connected = false;
        public bool Running = false;
        public event BaseHardwareReader.TagEvent OnTag;
        public event BaseHardwareReader.DisconnectEvent OnDisconnect;
        public DateTime Time = DateTime.Now;
        public bool HasTime = false;
        public string Freq = null;
        public bool HasFreq = false;
        public int Temperature = 0;

        private TcpClient mClient;
        private object mWritelock = new Object();
        private Thread mWorker;
        private Thread mPinger;
        private string LastItem = null;


        public D1Client(string host)
        {
            Host = host;
        }

        public void Connect()
        {
            mClient = new TcpClient(Host, 2233);
            StreamReader mReader = new StreamReader(mClient.GetStream());
            if (LastItem != null)
                Send("S" + LastItem + "\r\n");

            mWorker = new Thread(delegate()
            {
                while (mClient.Connected)
                    try
                    {
                        string s = mReader.ReadLine();
                        Console.WriteLine("<< " + s);
                        if (s.StartsWith("PING") || s.Length == 0)
                            continue;
                        if (s.StartsWith("status"))
                        {
                            Temperature = int.Parse(s.Split()[2]);
                            continue;
                        }
                        try
                        {
                            Time = DateTime.Parse(s, CultureInfo.GetCultureInfo("en-GB"));
                            HasTime = true;
                            continue;
                        }
                        catch { }

                        if (s.Length < 5)
                        {
                            Freq = s;
                            HasFreq = true;
                        }

                        try
                        {
                            string[] ss = s.Split(',');
                            OneTag tag = new OneTag();
                            LastItem = ss[0];
                            tag.EPC = ss[1];
                            tag.LastSeen = DateTime.ParseExact(ss[2], "dd.MM.yyyy HH:mm:ss.fff", null);
                            tag.LastAntenna = int.Parse(ss[3]);
                            tag.RSSILast = double.Parse(ss[4], CultureInfo.InvariantCulture);
                            tag.TID = "";
                            tag.RSSIMax = tag.RSSILast;
                            tag.RSSIMin = tag.RSSILast;
                            tag.Index = int.Parse(ss[0]);
                            Reader.TotalReceived = tag.Index.Value;
                            if (OnTag != null)
                                OnTag(tag);
                        }
                        catch { }
                    }
                    catch (ArgumentOutOfRangeException)
                    {
                    }
                    catch (IOException)
                    {
                        Fail();
                    }
            });
            mWorker.Start();

            mPinger = new Thread(delegate()
            {
                while (true)
                {
                    Send("PING\r\n");
                    Thread.Sleep(19000);
                }
            });

            Connected = true;
        }

        public void Disconnect()
        {
            Stop();
            try
            {
                mWorker.Abort();
            }
            catch { }
            try
            {
                mPinger.Abort();
            }
            catch { }
            try
            {
                mClient.Close();
            }
            catch { }
            Connected = false;
        }

        private void Send(string text)
        {
            Console.WriteLine(">> " + text);
            try
            {
                byte[] d = Encoding.ASCII.GetBytes(text);
                lock (mWritelock)
                    mClient.GetStream().Write(d, 0, d.Length);
            }
            catch
            {
                Fail();
            }
        }

        public void Start()
        {
            if (!Connected) Connect();
            Running = true;
            Send("start_reading\r\n");
        }

        public void Stop()
        {
            if (Config.Shutdown) return;
            if (!Connected) Connect();
            Running = false;
            Send("stop_reading\r\n");
        }

        public void ClearBuffer()
        {
            if (!Connected) Connect();
            Send("clear_buffer\r\n");
        }

        public void StartFirst()
        {
            if (!Connected) Connect();
            Send("S1\r\n");
        }

        void Fail()
        {
            if (OnDisconnect != null)
                OnDisconnect();
            else
                throw new OctaneSdkException(""); //imitate Speedway
        }

        public void RequestTime()
        {
            HasTime = false;
            Send("get_date_time\r\n");
        }

        public void SetTime(DateTime t)
        {
            Send("set_date_time=" + t.ToString("dd.MM.yyyy HH:mm:ss") + "\r\n");
        }

        public void RequestFreq()
        {
            HasFreq = false;
            Send("get_frequency\r\n");
        }

        public void SetFreq(string p)
        {
            Send("set_frequency=" + p + "\r\n");
        }
    }
}
