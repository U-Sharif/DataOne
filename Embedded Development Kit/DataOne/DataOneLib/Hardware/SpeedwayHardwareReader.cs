using System;
using System.Collections.Generic;
using System.Text;
using Impinj.OctaneSdk;
using System.Threading;

namespace DataOneLib
{
    public class SpeedwayHardwareReader : BaseHardwareReader
    {
        private SpeedwayReader mReader;
        public override event BaseHardwareReader.TagEvent OnTag;
        public override event BaseHardwareReader.DisconnectEvent OnDisconnect;

        public GpioState[] GPIs = new GpioState[8];
        public bool[] GPOs = new bool[4];
        public string Host;
        private Settings savedSettings;
        public bool D1Mode = false;
        public D1Client D1C;

        public void GoLLRP() { D1Mode = false; Connect(Host, 0); }
        public void GoD1() { D1Mode = true; Disconnect(); }

        private List<OneTag> D1Buf = new List<OneTag>();
        private bool D1Reading = false;

        public override bool Connected
        {
            get
            {
                return (mReader != null || D1C.Connected);
            }
        }

        public override bool CanWrite
        {
            get
            {
                return true;
            }
        }

        public void Init(string addr)
        {
            Host = addr;
            D1C = new D1Client(addr);
            D1C.OnTag += new TagEvent(D1C_OnTag);
            D1C.OnDisconnect += new DisconnectEvent(D1C_OnDisconnect);

            try
            {
                D1C.Connect();
            }
            catch { }
        }

        void D1C_OnDisconnect()
        {
            if (OnDisconnect != null)
                OnDisconnect();
        }

        public override void Connect(string addr, int port)
        {
            if (!D1C.Connected)
                try
                {
                    D1C.Connect();
                }
                catch { }

            if (D1Mode) return;

            if (mReader != null)
                try
                {
                    mReader.Disconnect();
                }
                catch { }

            mReader = new SpeedwayReader();
            try
            {
                mReader.Connect(addr);
            }
            catch
            {
                mReader = null;
                throw;
            }

            mReader.LogLevel = LogLevel.Error;
            mReader.TagsReported += new EventHandler<TagsReportedEventArgs>(Reader_TagsReported);
            mReader.Gpi1Changed += new EventHandler<GpiChangedEventArgs>(onGPI);
            mReader.Gpi2Changed += new EventHandler<GpiChangedEventArgs>(onGPI);
            mReader.Gpi3Changed += new EventHandler<GpiChangedEventArgs>(onGPI);
            mReader.Gpi4Changed += new EventHandler<GpiChangedEventArgs>(onGPI);

            foreach (GpiStatus g in mReader.QueryStatus().Gpis.Elements)
                GPIs[g.PortNumber - 1] = g.State;
        }

        void D1C_OnTag(OneTag t)
        {
            if (D1Reading)
                D1Buf.Add(t);
            if (OnTag != null)
                OnTag(t);
        }

        void onGPI(Object sender, GpiChangedEventArgs e)
        {
            GPIs[e.PortNumber - 1] = e.State;
        }

        public override List<OneTag> Query(double secs)
        {
            try
            {
                if (D1Mode)
                {
                    D1Buf.Clear();
                    D1Reading = true;
                    Thread.Sleep((int)(secs * 1000));
                    D1Reading = false;
                    List<OneTag> r = new List<OneTag>();
                    r.AddRange(D1Buf);
                    return r;
                }

                Settings s = mReader.QuerySettings();
                s.Report.IncludeSerializedTid = true;
                mReader.ApplySettings(s);

                List<OneTag> l = new List<OneTag>();
                foreach (Tag tag in mReader.QueryTags(secs).Tags)
                {
                    l.Add(new OneTag(tag));
                }

                s.Report.IncludeSerializedTid = false;
                mReader.ApplySettings(s);
                return l;
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
                return null;
            }
        }

        public override void Start()
        {
            try
            {
                if (D1Mode)
                {
                    D1C.Start();
                    return;
                }

                mReader.Start();
                savedSettings = mReader.QuerySettings();
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
            }
        }

        public override void Stop()
        {
            try
            {
                if (D1Mode)
                {
                    D1C.Stop();
                    return;
                }

                mReader.Stop();
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
            }
        }

        void Reader_TagsReported(object sender, TagsReportedEventArgs e)
        {
            foreach (Tag tag in e.TagReport.Tags)
            {
                if (OnTag != null)
                    OnTag(new OneTag(tag));
            }
        }

        public override object GetSettings()
        {
            if (D1Mode)
                return null;

            try
            {
                return mReader.QuerySettings();
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
                return null;
            }
        }

        public override void ResetSettings()
        {
            if (D1Mode)
                return;

            try
            {
                mReader.ApplyFactorySettings();
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
            }
        }

        public override void SetSettings(object set)
        {
            if (D1Mode)
                return;

            try
            {
                Settings settings = (Settings)set;
                settings.Report.Mode = ReportMode.Individual;
                settings.Report.IncludeAntennaPortNumber = true;
                settings.Report.IncludePeakRssi = true;
                settings.Report.IncludeSerializedTid = false;
                for (int i = 0; i < 4; i++)
                {
                    GpiSettings s = new GpiSettings();
                    s.PortNumber = i + 1;
                    s.IsEnabled = true;
                    settings.Gpis.Add(s);
                }
                mReader.ApplySettings((Settings)settings);
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
            }
        }

        public override bool WriteTag(string oldEpc, string newEpc)
        {
            if (D1Mode)
                return false;

            try
            {
                Settings set = mReader.QuerySettings();
                mReader.ApplyFactorySettings();

                ProgramEpcParams p = new ProgramEpcParams();
                p.TargetTag = oldEpc;
                p.AccessPassword = null;
                p.TimeoutInMs = 15000;
                p.NewEpc = newEpc;
                p.AntennaPortNumber = 1;
                p.IsWriteVerified = true;
                p.LockType = LockType.Locked;

                bool res = false;
                try
                {
                    res = mReader.ProgramEpc(p).WriteResult.Result == AccessResult.Success;
                }
                catch
                {
                    res = false;
                }
                finally
                {
                    mReader.ApplySettings(set);
                }

                return res;
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
                return false;
            }
        }

        public SpeedwayReader Expose()
        {
            return mReader;
        }

        public void SetGpo(int idx, bool state)
        {
            try
            {
                GPOs[idx - 1] = state;
                mReader.SetGpo(idx, state);
            }
            catch (OctaneSdkException)
            {
                OnDisconnect();
            }
        }

        public void Beep()
        {
            new Thread(delegate()
            {
                SetGpo(1, true);
                Thread.Sleep(200);
                SetGpo(1, false);
            }).Start();
        }


        void Reconnect()
        {
            if (mReader != null)
                try
                {
                    mReader.Disconnect();
                }
                catch { }
            Connect(Host, 0);
            Reader.Set();
        }

        void Disconnect()
        {
            try
            {
                mReader.Disconnect();
            }
            catch { }
        }

        public void ClearBuffer()
        {
            if (D1Mode)
                D1C.ClearBuffer();
        }

        public void FullDownload()
        {
            if (D1Mode)
                D1C.StartFirst();
        }
    }
}
