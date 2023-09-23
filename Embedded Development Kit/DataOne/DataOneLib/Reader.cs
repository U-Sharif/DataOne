using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using Impinj.OctaneSdk;
using System.Threading;

namespace DataOneLib
{
    public static class Reader
    {
        public static event OnTagDelegate TagReported;
        public static event SimpleDelegate HwDisconnect;
        public static event SimpleDelegate HwReconnect;

        public static bool Running = false;
        public static DateTime Started = DateTime.MinValue;
        public static DateTime Stopped = DateTime.MinValue;
        public static int TotalReceived = 0, LastRunReceived = 0;
        public static string Password = null;
        public static bool LockCounting = false;
        public static BaseHardwareReader Hardware;
        private static string mHost;
        private static int mPort;

        public static bool Connected
        {
            get
            {
                return (Hardware.Connected);
            }
        }

        public static void Reconnect(string host, int port)
        {
            mHost = host;
            mPort = port;
            Hardware.Connect(host, port);
            Hardware.OnTag += new BaseHardwareReader.TagEvent(mReader_OnTag);
            Hardware.OnDisconnect += new BaseHardwareReader.DisconnectEvent(Hardware_OnDisconnect);
        }

        static void Hardware_OnDisconnect()
        {
            if (HwDisconnect != null)
                HwDisconnect();
            new Thread(new ThreadStart(Reconnector)).Start();
        }

        static void Reconnector()
        {
            while (true)
            {
                Thread.Sleep(5000);
                try
                {
                    Reconnect(mHost, mPort);
                    if (HwReconnect != null)
                        HwReconnect();
                    return;
                }
                catch { }
            }
        }

        public static List<OneTag> Query(double secs)
        {
            return Hardware.Query(secs);
        }

        static void mReader_OnTag(OneTag tag)
        {
            TagReported(tag);
            TotalReceived++;
            if (!LockCounting)
                LastRunReceived++;
        }

        public static void Set()
        {
            Hardware.ResetSettings();
            object settings = Hardware.GetSettings();
            if (settings != null && settings is Settings)
            {

                try
                {
                    Config.Apply(settings as Settings);
                }
                catch { }

                try
                {
                    Hardware.SetSettings(settings);
                }
                catch
                {
                    MessageBox.Show("Invalid settings", "DataOne", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }

            if (Running)
                Start();
        }

        public static void Start()
        {
            try
            {
                if (Hardware != null)
                    Hardware.Start();
            }
            catch { }
            Started = DateTime.Now;
            LastRunReceived = 0;
            Running = true;
        }

        public static void Stop()
        {
            try
            {
                if (Hardware != null)
                    Hardware.Stop();
            }
            catch { }
            Stopped = DateTime.Now;
            Running = false;
        }

        public static bool WriteTag(string tag, string newEpc)
        {
            return Hardware.WriteTag(tag, newEpc);
        }


        public delegate void OnTagDelegate(OneTag tag);
        public delegate void SimpleDelegate();
    }
}
