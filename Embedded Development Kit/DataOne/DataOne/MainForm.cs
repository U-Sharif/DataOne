using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using DataOneLib;
using System.Collections;
using System.Reflection;
using System.Media;
using System.IO;
using System.Threading;
using Impinj.OctaneSdk;

namespace DataOne
{
    public partial class MainForm : Form
    {
        private Watcher mWatcher;
        private Logger mLogger;
        private Logger mFilter;
        private Server mServer;
        private Pipeline mPipeline;
        private SoundPlayer BeepSound;

        private static Color ColorNew = Color.FromArgb(0x66ff00);
        private static Color ColorUpdated = Color.FromArgb(0xeeffee);
        private static Color ColorLosing = Color.FromArgb(0xffdddd);

        private List<ListViewItem> UpdateBatch = new List<ListViewItem>();

        private string mWriteLog;
        public bool DemoMode = false;

        public String SelectedAddress;
        public String SelectedPort;
        public Label[] GPOLabels = new Label[4];
        public Button[] GPOButtons = new Button[4];

        public MainForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Assembly asm = Assembly.GetExecutingAssembly();
            BeepSound = new SoundPlayer(asm.GetManifestResourceStream(asm.GetName().Name + ".beep.wav"));
            BeepSound.Load();

            Library.Load();

            Reader.HwDisconnect += new Reader.SimpleDelegate(Reader_HwDisconnect);
            Reader.HwReconnect += new Reader.SimpleDelegate(Reader_HwReconnect);

            mWatcher = new Watcher();
            mWatcher.NewTag += new Watcher.TagEvent(mWatcher_NewTag);
            mWatcher.LostTag += new Watcher.TagEvent(mWatcher_LostTag);

            mLogger = new Logger(Application.StartupPath + "\\data - " + Config.Name);
            mFilter = new Logger(Application.StartupPath + "\\filtered - " + Config.Name);
            mFilter.BibFilter = Config.BibFilter;

            Reader.Set();

            Reader.TotalReceived = mLogger.FindLast();
            mLogger.ClipCount = int.Parse(Config.Data["clip"]);
            mLogger.NextFile();
            mLogger.OnLog += new Logger.LogEvent(mLogger_OnLog);
            mFilter.FindLast();
            mFilter.ClipCount = int.Parse(Config.Data["clip"]);
            mFilter.NextFile();
            mFilter.OnLog += new Logger.LogEvent(mFilter_OnLog);

            Reader.TagReported += new Reader.OnTagDelegate(Reader_TagReported);

            try
            {
                UpdateSettingsPanel();
            }
            catch { }

            TestList.ListViewItemSorter = new ListViewItemComparer(1);
            TestList.Sorting = SortOrder.Ascending;

            mServer = new Server(mFilter, int.Parse(Config.Data["port"]));
            mServer.OnRequest += new Server.ServerEvent(mServer_OnRequest);
            SPort.Value = mServer.Port;

            mPipeline = new Pipeline();
            mPipeline.OnLog += new Pipeline.LogEvent(Pipeline_OnLog);
            mPipeline.OnWrittenTag += new Pipeline.WrittenEvent(Pipeline_OnWrittenTag);
            mPipeline.OnFinished += new Pipeline.FinishedEvent(Pipeline_OnFinished);
            mPipeline.OnProgress += new Pipeline.ProgressEvent(Pipeline_OnProgress);

            if (Reader.Hardware is SpeedwayHardwareReader)
            {
                if (Config.Data["master"] != "app")
                {
                    ((SpeedwayHardwareReader)Reader.Hardware).GoD1();
                    ((SpeedwayHardwareReader)Reader.Hardware).D1C.RequestFreq();
                }
                if (SelectedAddress.StartsWith("10.90.9."))
                    try
                    {
                        int i = int.Parse(SelectedAddress.Split('.')[3]);
                        new TimingClient("timing.datasport.com", 13200 + i, mFilter).Start();
                        new TimingClient("timing2.datasport.com", 13200 + i, mFilter).Start();
                    }
                    catch { }
            }

            if (Reader.Hardware is HandreaderHardwareReader)
            {
                if (SelectedAddress.StartsWith("10.90.3."))
                    try
                    {
                        int i = int.Parse(SelectedAddress.Split('.')[3]) + int.Parse(SelectedPort) % 10 - 1;
                        new TimingClient("timing.datasport.com", 13800 + i, mFilter).Start();
                        new TimingClient("timing2.datasport.com", 13800 + i, mFilter).Start();
                    }
                    catch { }
            }

            UpdateWriterSettings();
            UpdateSettingsPanel();
            UpdateTitle();

            for (int i = 0; i < 4; i++)
            {
                Label l = new Label();
                l.Text = (i + 1).ToString();
                GpoPanel.Controls.Add(l);
                l.Left = 0;
                l.AutoSize = true;
                l.Top = 15 + 30 * i;

                l = new Label();
                l.Text = "Off";
                GpoPanel.Controls.Add(l);
                l.Left = 40;
                l.AutoSize = true;
                l.Top = 15 + 30 * i;
                GPOLabels[i] = l;

                Button b1 = new Button();
                b1.Text = "On";
                b1.Left = 80;
                b1.Width = 30;
                b1.Top = 10 + 30 * i;
                b1.Click += new EventHandler(GpoOn_Click);
                b1.Tag = i;
                GPOButtons[i] = b1;
                GpoPanel.Controls.Add(b1);
            }


            if (DemoMode)
                WMode4.Enabled = false;
        }

        void Reader_HwReconnect()
        {
            Invoke(new MethodInvoker(delegate()
            {
                Enabled = true;
                Form1_Load(null, null);
            }));
        }

        void Reader_HwDisconnect()
        {
            Invoke(new MethodInvoker(delegate()
            {
                Enabled = false;
                Text = "Reconnecting...";
                Form1_FormClosing(null, null);
            }));
        }

        void UpdateSettingsPanel()
        {
            EnableSettingsPanel();

            try
            {
                Config.LoadPresets(((SpeedwayHardwareReader)Reader.Hardware).Expose());
            }
            catch { }

            try
            {
                SModeBox.Items.Clear();
                foreach (string key in Config.ReaderModes.Keys)
                    SModeBox.Items.Insert(0, key); // Reverse order
                SSearchModeBox.Items.Clear();
                foreach (string key in Config.SearchModes.Keys)
                    SSearchModeBox.Items.Add(key);
                SFreqBox.Items.Clear();
                foreach (string key in Config.Frequencies.Keys)
                    SFreqBox.Items.Add(key);
                STagVolumeBox.Items.Clear();
                foreach (string key in Config.Volumes)
                    STagVolumeBox.Items.Add(key);
                SSessionBox.Items.Clear();
                for (int i = 0; i < 4; i++)
                    SSessionBox.Items.Add(i.ToString());

                SMaxPower.Text = "Maximum power: " + Config.MaxTxPower + " dBm";
                SAntenna1Box.Text = Config.MaxTxPower.ToString();
                SAntenna2Box.Text = Config.MaxTxPower.ToString();
                SAntenna3Box.Text = Config.MaxTxPower.ToString();
                SAntenna4Box.Text = Config.MaxTxPower.ToString();


                SMasterBox.SelectedIndex = Config.Data["master"] == "reader" ? 0 : 1;

                SBeepType.SelectedIndex = 0;

                SDescriptionBox.Text = Config.Data["description"];
                SModeBox.SelectedItem = Config.Data["reader_mode"];
                SBibFilter.Value = int.Parse(Config.Data["bib_filter"]);
                SSearchModeBox.SelectedItem = Config.Data["search_mode"];
                SSessionBox.SelectedItem = Config.Data["session"];
                SFreqBox.SelectedItem = Config.Data["frequency"];
                STagVolumeBox.SelectedItem = Config.Data["tag_volume"];
                SAntenna1Check.Checked = Config.Data["antenna_1"] == "on";
                SAntenna2Check.Checked = Config.Data["antenna_2"] == "on";
                SAntenna3Check.Checked = Config.Data["antenna_3"] == "on";
                SAntenna4Check.Checked = Config.Data["antenna_4"] == "on";
                SAntenna1Box.Text = Config.Data["antenna_1_power"];
                SAntenna2Box.Text = Config.Data["antenna_2_power"];
                SAntenna3Box.Text = Config.Data["antenna_3_power"];
                SAntenna4Box.Text = Config.Data["antenna_4_power"];
                SClipCount.Value = int.Parse(Config.Data["clip"]);
                SPort.Value = int.Parse(Config.Data["port"]);
                SMinRSSI.Value = int.Parse(Config.Data["min_rssi"]);
                SBarcodeIP.Text = Config.Data["barcode_addr"];
                SBarcodePort.Value = int.Parse(Config.Data["barcode_port"]);
                WSeriesBox3.Text = Config.Data["series"];
                SWriteRepeat.Value = int.Parse(Config.Data["repeat_write"]);

                SBeepPC.Checked = Config.Data["beep_pc"] == "on";
                SBeepReader.Checked = Config.Data["beep_reader"] == "on";
                SBeepType.SelectedIndex = int.Parse(Config.Data["beep_type"]);

                SSkipSpecial.Checked = Config.Data["skip_special"] == "on";
            }
            catch (KeyNotFoundException) { }
        }

        void EnableSettingsPanel()
        {
            try
            {
                SMasterBox.Enabled = Reader.Hardware is SpeedwayHardwareReader;
                bool writable = Reader.Hardware is SpeedwayHardwareReader && SMasterBox.SelectedIndex == 1;
                SSearchModeBox.Enabled = writable;
                SModeBox.Enabled = writable;
                SSessionBox.Enabled = writable;
                SFreqBox.Enabled = writable;
                STagVolumeBox.Enabled = writable;
                SAntenna1Box.Enabled = writable;
                SAntenna1Check.Enabled = writable;
                SAntenna2Box.Enabled = writable;
                SAntenna2Check.Enabled = writable;
                SAntenna3Box.Enabled = writable;
                SAntenna3Check.Enabled = writable;
                SAntenna4Box.Enabled = writable;
                SAntenna4Check.Enabled = writable;

                SMinRSSI.Enabled = !(Reader.Hardware is HandreaderHardwareReader);

                LoadFileButton.Visible = Reader.Hardware is OrangeboxHardwareReader;
                SBeepType.Enabled = Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "app";
                SBeepReader.Enabled = Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "app";
                FullDownloadButton.Visible = Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "reader";
                SReaderFreq.Visible = Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "reader";

                CommandsGroup.Visible = Reader.Hardware is SpeedwayHardwareReader;
                CommandsGroup.Enabled = Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "reader" && !Reader.Running;
            }
            catch (KeyNotFoundException) { }
        }

        void Beep()
        {
            BeepSound.Play();
        }

        void mFilter_OnLog(string l)
        {
            try
            {
                if (Config.Data["beep_pc"] == "on")
                    Beep();
                if (Reader.Hardware is SpeedwayHardwareReader && Config.Data["beep_reader"] == "on")
                    ((SpeedwayHardwareReader)Reader.Hardware).Beep();
            }
            catch { }
        }

        void mLogger_OnLog(string l)
        {
            try
            {
                if (Reader.Hardware is SpeedwayHardwareReader && Config.Data["beep_reader"] == "on" && Config.Data["beep_type"] == "1")
                    ((SpeedwayHardwareReader)Reader.Hardware).Beep();
            }
            catch { }
        }

        void GpoOn_Click(object sender, EventArgs e)
        {
            SpeedwayHardwareReader hw = (SpeedwayHardwareReader)Reader.Hardware;
            int idx = (int)((Control)sender).Tag + 1;
            hw.SetGpo(idx, !hw.GPOs[idx - 1]);
        }

        void UpdateTitle()
        {
            Text = "DataOne " + Config.Data["description"] + " : " + mServer.Port;
        }

        void Pipeline_OnProgress(int c, int t)
        {
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    if (c == -1)
                    {
                        WriterProgress.Style = ProgressBarStyle.Marquee;
                    }
                    else
                    {
                        WriterProgress.Style = ProgressBarStyle.Blocks;
                        if (WriterProgress.Maximum != t)
                            WriterProgress.Maximum = t;
                        WriterProgress.Value = c;
                    }
                });
            }
            catch { }
        }

        void Pipeline_OnFinished()
        {
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {

                    WriterStartButton.Text = "Write";
                    WriterSettingsGroupbox.Enabled = true;
                    StartButton.Enabled = true;
                    WriterProgress.Value = 0;
                    WriterProgress.Maximum = 1;
                    WriterProgress.Style = ProgressBarStyle.Blocks;
                    WFirstBib.Enabled = true;
                });
            }
            catch { }
        }

        void Pipeline_OnWrittenTag(OneTag tag, int bib, string newepc)
        {
            ListViewItem lvi = new ListViewItem(new String[] { 
                (tag.TID==null)?"":tag.TID.Replace(" ", "").ToUpper(),
                tag.EPC.ToUpper(),
                bib.ToString(),
                newepc.ToUpper()
            });

            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    WFirstBib.Value = mPipeline.GetOneBib();
                    WriterList.Items.Insert(0, lvi);
                });
            }
            catch { }

            File.AppendAllText(mWriteLog, ((tag.TID == null) ? "" : tag.TID.Replace(" ", "").ToUpper()) + "," +
                tag.EPC.ToUpper() + "," + bib + "," + newepc.ToUpper() + "\r\n");
        }

        void Pipeline_OnLog(string log)
        {
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    WriterLog.Text = log + "\r\n" + WriterLog.Text;
                    if (log.StartsWith("New barcode")) // Hack!
                        try
                        {
                            int bc = int.Parse(log.Split(' ')[2]);
                            WFirstBib.Value = bc;
                        }
                        catch { }
                });
            }
            catch { }

            File.AppendAllText(mWriteLog, log + "\r\n");
        }

        void mBarcoder_OnFinished()
        {
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    WriterStartButton.Text = "Write";
                    WriterSettingsGroupbox.Enabled = true;
                    WriterProgress.Value = 0;
                    WriterProgress.Maximum = 1;
                });
            }
            catch { }
        }

        void mServer_OnRequest(System.Net.EndPoint remote, int start)
        {
            ListViewItem lvi = new ListViewItem(new String[] { 
                remote.ToString(),
                (start>0)?start.ToString():"Disconnected",
                DateTime.Now.ToString("dd.MM.yyyy HH:mm:ss.fff"),
            });

            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    ServerList.Items.Insert(0, lvi);
                });
            }
            catch { }
        }


        public void SaveSettings()
        {
            String desc = SDescriptionBox.Text;
            for (int i = 0; i < desc.Length; i++)
                if (!Char.IsLetterOrDigit(desc, i))
                    desc = desc.Remove(i--, 1);

            if (desc.Length > 12) desc = desc.Substring(0, 12);


            Config.Data["description"] = desc;
            if (((string)SModeBox.SelectedItem) != "")
            {
                if (SModeBox.SelectedItem != null)
                    Config.Data["reader_mode"] = (string)SModeBox.SelectedItem;
                if (SSearchModeBox.SelectedItem != null)
                    Config.Data["search_mode"] = (string)SSearchModeBox.SelectedItem;
                if (SSessionBox.SelectedItem != null)
                    Config.Data["session"] = (string)SSessionBox.SelectedItem;
                if (SFreqBox.SelectedItem != null)
                    Config.Data["frequency"] = (string)SFreqBox.SelectedItem;
                if (STagVolumeBox.SelectedItem != null)
                    Config.Data["tag_volume"] = (string)STagVolumeBox.SelectedItem;
                Config.Data["antenna_1"] = SAntenna1Check.Checked ? "on" : "off";
                Config.Data["antenna_2"] = SAntenna2Check.Checked ? "on" : "off";
                Config.Data["antenna_3"] = SAntenna3Check.Checked ? "on" : "off";
                Config.Data["antenna_4"] = SAntenna4Check.Checked ? "on" : "off";
                Config.Data["antenna_1_power"] = SAntenna1Box.Text;
                Config.Data["antenna_2_power"] = SAntenna2Box.Text;
                Config.Data["antenna_3_power"] = SAntenna3Box.Text;
                Config.Data["antenna_4_power"] = SAntenna4Box.Text;
                Config.Data["master"] = (SMasterBox.SelectedIndex == 0) ? "reader" : "app";
            }
            Config.Data["clip"] = SClipCount.Value.ToString();
            Config.Data["port"] = SPort.Value.ToString();
            Config.Data["min_rssi"] = SMinRSSI.Value.ToString();
            Config.Data["barcode_addr"] = SBarcodeIP.Text;
            Config.Data["barcode_port"] = SBarcodePort.Value.ToString();
            Config.Data["series"] = WSeriesBox3.Text;
            Config.Data["repeat_write"] = SWriteRepeat.Value.ToString();
            Config.Data["bib_filter"] = SBibFilter.Value.ToString();
            Config.MinRSSI = (int)SMinRSSI.Value;

            Config.Data["beep_pc"] = SBeepPC.Checked ? "on" : "off";
            Config.Data["beep_reader"] = SBeepReader.Checked ? "on" : "off";
            Config.Data["beep_type"] = SBeepType.SelectedIndex.ToString();

            Config.Data["skip_special"] = SSkipSpecial.Checked ? "on" : "off";
            Config.Save();


            Reader.Set();

            mLogger.ClipCount = (int)SClipCount.Value;
            mLogger.DumpSettings();
            mFilter.BibFilter = (int)SBibFilter.Value;
            mFilter.ClipCount = (int)SClipCount.Value;
            mFilter.DumpSettings();
            try
            {
                File.AppendAllText(mWriteLog, Config.Dump());
            }
            catch { }
            UpdateTitle();

            UpdateSettingsPanel();
        }

        void Reader_TagReported(OneTag tag)
        {
            // if (!Reader.Running)
            //   return;

            ListViewItem lvi = new ListViewItem(new String[] { 
                (Reader.TotalReceived+1).ToString(),
                tag.LastSeen.ToString("dd.MM.yyyy HH:mm:ss.fff"),
                tag.LastAntenna.ToString(),
                tag.RSSILast.ToString(),
                Library.ParseEPC(tag.EPC),
                Library.Resolve(tag)
            });

            lock (UpdateBatch)
            {
                UpdateBatch.Add(lvi);
            }

            if (Config.Data["skip_special"] == "on" && tag.EPC.Length == 8)
                return;

            if (tag.Index.HasValue)
            {
                mLogger.Last = tag.Index.Value;
            }

            mLogger.Log(tag, Reader.TotalReceived + 1);

            if (tag.EPC.StartsWith("99999999"))
                try
                {
                    if (Config.Data["beep_pc"] == "on")
                        Beep();
                    if (Reader.Hardware is SpeedwayHardwareReader && Config.Data["beep_reader"] == "on")
                        ((SpeedwayHardwareReader)Reader.Hardware).Beep();
                }
                catch { }

            if (tag.RSSILast < Config.MinRSSI)
                return;

            tag.Index = null;
            mFilter.Log(tag, Reader.TotalReceived + 1);
        }

        #region Test mode
        void mWatcher_NewTag(OneTag t)
        {
            ListViewItem item = new ListViewItem(new string[] { "", "", "", "", "", "", "", "", "", "" });
            item.Text = t.EPC;
            UpdateRow(item, t);
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    TestList.Items.Insert(0, item);
                });
            }
            catch { }
            t.Updated += new Watcher.TagEvent(t_Updated);
            t.Losing += new Watcher.TagEvent(t_Updated);
            t.Restored += new Watcher.TagEvent(t_Updated);
            t.Idle += new Watcher.TagEvent(t_Updated);
        }

        void t_Updated(OneTag t)
        {
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    foreach (ListViewItem i in TestList.Items)
                        if (CompareTags(i, t))
                        {
                            UpdateRow(i, t);
                            return;
                        }
                });
            }
            catch { }
        }

        void mWatcher_LostTag(OneTag t)
        {
            try
            {
                this.Invoke((MethodInvoker)delegate()
                {
                    ListViewItem item = null;
                    foreach (ListViewItem i in TestList.Items)
                        if (CompareTags(i, t))
                            item = i;
                    if (item != null)
                        TestList.Items.Remove(item);
                });
            }
            catch { }
        }

        public void UpdateRow(ListViewItem i, OneTag t)
        {
            SetListItem(i, 0, Library.ParseEPC(t.EPC));
            SetListItem(i, 1, Library.Resolve(t));
            SetListItem(i, 2, t.cTotal.ToString());
            SetListItem(i, 3, t.cSingle[0].ToString());
            SetListItem(i, 4, t.cSingle[1].ToString());
            SetListItem(i, 5, t.cSingle[2].ToString());
            SetListItem(i, 6, t.cSingle[3].ToString());
            SetListItem(i, 7, t.RSSILast.ToString());
            SetListItem(i, 8, t.RSSIMax.ToString());
            SetListItem(i, 9, t.RSSIMin.ToString());

            TagStatus s = t.GetStatus();
            if (s == TagStatus.Idle)
                i.BackColor = Color.Transparent;
            if (s == TagStatus.Losing)
                i.BackColor = ColorLosing;
            if (s == TagStatus.New)
                i.BackColor = ColorNew;
            if (s == TagStatus.Updated)
                i.BackColor = ColorUpdated;
        }

        private void SetListItem(ListViewItem i, int p, string text)
        {
            if (i.SubItems[p].Text != text)
                i.SubItems[p].Text = text;
        }

        #endregion

        private bool CompareTags(ListViewItem i, OneTag t)
        {
            return (i.Text == Library.ParseEPC(t.EPC));
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                Config.Shutdown = true;
                mWatcher.Abort();
                if (Reader.Running)
                    Reader.Stop();
                mLogger.Finish();
                mFilter.Finish();
                mServer.Abort();
            }
            catch { }
            if (sender != null)
                Environment.Exit(0);
        }

        int speedwayUpdateCycler = 0;

        private void UpdateTimer_Tick(object sender, EventArgs e)
        {
            if (Reader.Started != DateTime.MinValue)
                StartedLabel.Text = Reader.Started.ToString();
            if (Reader.Stopped != DateTime.MinValue)
                StoppedLabel.Text = Reader.Stopped.ToString();
            ReceivedLabel.Text = Reader.TotalReceived.ToString();
            FilteredLabel.Text = mFilter.Last.ToString();


            try
            {
                if (Reader.Started != DateTime.MinValue && Reader.Running)
                    ThroughputLabel.Text = ((int)(Reader.LastRunReceived / (DateTime.Now - Reader.Started).TotalSeconds)).ToString();
            }
            catch
            {
            }


            lock (UpdateBatch)
            {
                foreach (ListViewItem lvi in UpdateBatch)
                {
                    MainList.Items.Insert(0, lvi);
                    while (MainList.Items.Count > 100)
                        MainList.Items.RemoveAt(MainList.Items.Count - 1);
                }
                UpdateBatch.Clear();
            }

            GPIOPanel.Enabled = (Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "reader");

            if (Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "reader")
            {
                SpeedwayHardwareReader r = (SpeedwayHardwareReader)Reader.Hardware;
                TemperatureLabel.Text = "Reader temperature: " + r.D1C.Temperature + " C";
                if (r.D1C.HasFreq)
                {
                    SReaderFreq.Text = r.D1C.Freq;
                    r.D1C.HasFreq = false;
                }
            }
            if (Reader.Hardware is SpeedwayHardwareReader && Config.Data["master"] == "app")
            {
                StatusLabel.Text = "";
                SpeedwayHardwareReader r = (SpeedwayHardwareReader)Reader.Hardware;

                // Temperature
                Status s = null;
                try
                {
                    s = r.Expose().QueryStatus((speedwayUpdateCycler == 0) ? StatusRefresh.Everything : StatusRefresh.None);
                }
                catch { return; }

                speedwayUpdateCycler = (speedwayUpdateCycler + 1) % 10;

                TemperatureLabel.Text = "Reader temperature: " + s.TemperatureInCelsius + " C";

                // GPIs
                GPIList.Items.Clear();

                if (GPIBox.Checked)
                {
                    for (int i = 0; i < 4; i++)
                        GPIList.Items.Add(new ListViewItem(
                            new string[]{
                                (i+1).ToString(),
                                ((SpeedwayHardwareReader)Reader.Hardware).GPIs[i].ToString()
                            }
                        ));
                }

                // GPOs
                for (int i = 0; i < 4; i++)
                {
                    GPOLabels[i].Text = r.GPOs[i] ? "On" : "Off";
                    GPOButtons[i].Text = (!r.GPOs[i]) ? "On" : "Off";
                }
            }/*
            else
            {
                if (tabControl1.TabPages.Count == 5)
                    tabControl1.TabPages.Remove(tabPage6.Controls.);
            }*/

            if (Reader.Hardware is OrangeboxHardwareReader)
                StatusLabel.Text = ((OrangeboxHardwareReader)Reader.Hardware).ClientCount + " client(s) connected";
            if (Reader.Hardware is HandreaderHardwareReader)
                StatusLabel.Text = ((HandreaderHardwareReader)Reader.Hardware).Receiving ? "Connected" : "Disconnected";

            groupBox1.Invalidate();
        }

        private void StartButton_Click(object sender, EventArgs e)
        {
            if (Reader.Running)
            {
                Reader.Stop();
                mLogger.Flush();
                //mWatcher.Stop();
                StartButton.Text = "Start";
            }
            else
            {
                Reader.Start();
                //mWatcher.Start();
                StartButton.Text = "Stop";
            }
            EnableSettingsPanel();
        }

        private void TestModeCheckbox_CheckedChanged(object sender, EventArgs e)
        {
            if (TestModeCheckbox.Checked) mWatcher.Start(); else mWatcher.Stop();
        }

        private void ReloadSettingsButton_Click(object sender, EventArgs e)
        {
            try
            {
                UpdateSettingsPanel();
            }
            catch { }
        }

        private void ApplySettingsButton_Click(object sender, EventArgs e)
        {
            SaveSettings();
        }

        class ListViewItemComparer : IComparer
        {
            private int col;
            public ListViewItemComparer()
            {
                col = 0;
            }
            public ListViewItemComparer(int column)
            {
                col = column;
            }
            public int Compare(object x, object y)
            {
                int returnVal = -1;
                returnVal = String.Compare(((ListViewItem)x).SubItems[col].Text,
                ((ListViewItem)y).SubItems[col].Text);
                return returnVal;
            }
        }

        private void MainForm_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.W && e.Modifiers == (Keys.Alt | Keys.Control) && !WriterPanel.Enabled)
            {
                WriterPanel.Enabled = true;

                mWriteLog = Application.StartupPath + @"\write-log-" + Config.Name.Split('.')[0] + ".txt";
                if (!File.Exists(mWriteLog))
                    File.CreateText(mWriteLog).Close();
                File.AppendAllText(mWriteLog, Config.Dump());
                File.AppendAllText(mWriteLog, "-----------\r\nStarted at " + DateTime.Now + "\r\n");
            }
            if (e.KeyCode == Keys.M && e.Control && e.Alt)
                WMode0.Enabled = WMode2.Enabled = WMode3.Enabled = WMode4.Enabled = true;
        }



        private void WriterStartButton_Click_1(object sender, EventArgs e)
        {
            if (mPipeline.Running)
            {
                mPipeline.Stop();
            }
            else
            {
                IEpcProcessor epcP = null;

                if (WMode0.Checked)
                {
                    BasicEpcProcessor epcProc = new BasicEpcProcessor();
                    epcProc.CheckTIDs = WTIDCheck.Checked;
                    epcProc.EpcPrefix = WEpcStart.Text;
                    epcP = epcProc;
                }

                if (WMode2.Checked)
                {
                    PairwiseEpcProcessor2 epcProc = new PairwiseEpcProcessor2();
                    epcProc.CheckTIDs = WTIDCheck.Checked;
                    epcProc.Series = WSeriesBox2.Text;
                    epcProc.CheckSeries = WSeriesCheck2.Checked;
                    epcP = epcProc;
                }

                if (WMode3.Checked)
                {
                    PairwiseEpcProcessor epcProc = new PairwiseEpcProcessor();
                    epcProc.CheckTIDs = WTIDCheck.Checked;
                    epcProc.EpcPrefix = WEpcStart.Text;
                    epcProc.Series = WSeriesBox3.Text;
                    epcProc.CheckSeries = WSeriesCheck3.Checked;
                    epcP = epcProc;
                }

                if (WMode4.Checked)
                {
                    EncodedEpcProcessor epcProc = new EncodedEpcProcessor();
                    epcProc.CheckTIDs = WTIDCheck.Checked;
                    epcProc.Event = (int)WEventCode4.Value;
                    epcP = epcProc;
                }

                if (WMode1.Checked)
                {
                    DSEpcProcessor epcProc = new DSEpcProcessor();
                    epcProc.CheckTIDs = WTIDCheck.Checked;
                    epcProc.Event = WEventCode1.Text;
                    epcProc.CheckSeries = WSeriesCheck1.Checked;
                    epcP = epcProc;
                }


                IBibProvider bibProv;
                if (radioButton5.Checked)
                {
                    bibProv = new BarcodeBibProvider();
                    WFirstBib.Enabled = false;
                }
                else
                {
                    IncrementalBibProvider ibp = new IncrementalBibProvider((int)WFirstBib.Value);
                    ibp.Increment = radioButton4.Checked;
                    bibProv = ibp;
                }


                Reader.Password = WPasswordCheck.Checked ? WPasswordBox.Text : null;

                mPipeline.Prepare(bibProv, epcP);
                mPipeline.Start();

            }

            WriterSettingsGroupbox.Enabled = !mPipeline.Running;
            StartButton.Enabled = !mPipeline.Running;
            WriterStartButton.Text = mPipeline.Running ? "Stop" : "Write";
        }

        private void UpdateWriterSettings()
        {
            WEpcStart.Enabled = WMode0.Checked;
            WSeriesCheck3.Enabled = WMode3.Checked;
            WSeriesBox3.Enabled = WMode3.Checked;
            WSeriesCheck2.Enabled = WMode2.Checked;
            WSeriesBox2.Enabled = WMode2.Checked;
            WEventCode4.Enabled = WMode4.Checked;
            WEventCode1.Enabled = WMode1.Checked;
            WSeriesCheck1.Enabled = WMode1.Checked;
        }

        private void WriterModeChanged(object sender, EventArgs e)
        {
            UpdateWriterSettings();
        }

        private void LoadFileButton_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string f = openFileDialog.FileName;
                new Thread(delegate()
                {
                    Reader.LockCounting = true;
                    foreach (string l in File.ReadAllLines(f))
                        ((OrangeboxHardwareReader)(Reader.Hardware)).ProcessTag(l.Split('~'));
                    Reader.LockCounting = false;
                }).Start();
            }
        }

        private void DemoTimer_Tick(object sender, EventArgs e)
        {
            Close();
        }

        private void ClearBufferButton_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure?", "DataOne", MessageBoxButtons.YesNo, MessageBoxIcon.Warning) == DialogResult.Yes)
                ((SpeedwayHardwareReader)Reader.Hardware).ClearBuffer();
        }

        private void FullDownloadButton_Click(object sender, EventArgs e)
        {
            ((SpeedwayHardwareReader)Reader.Hardware).FullDownload();
        }

        private void SMasterBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (SMasterBox.SelectedIndex == -1) return;
            EnableSettingsPanel();
            Config.Data["master"] = SMasterBox.SelectedIndex == 0 ? "reader" : "app";
            // Speedway modeswitch
            if (Reader.Hardware is SpeedwayHardwareReader)
            {
                SpeedwayHardwareReader hw = (SpeedwayHardwareReader)Reader.Hardware;
                if (Config.Data["master"] == "app" && hw.D1Mode)
                {
                    try
                    {
                        hw.GoLLRP();
                        Reader.Set();
                        if (Reader.Running)
                            StartButton_Click(null, null);
                    }
                    catch
                    {
                        hw.GoD1();
                        MessageBox.Show("Cannot connect to reader", "D1", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        Config.Data["master"] = "reader";
                        UpdateSettingsPanel();
                    }
                }
                if (Config.Data["master"] == "reader" && !hw.D1Mode)
                {
                    hw.GoD1();
                    hw.D1C.RequestFreq();
                    if (Reader.Running)
                        StartButton_Click(null, null);
                }
            }
            UpdateSettingsPanel();
        }

        private void WEventCode4_TextChanged(object sender, EventArgs e)
        {
            if (WEventCode1.Text.Length > 5)
            {
                WEventCode1.Text = WEventCode1.Text.Substring(0, 5);
                WEventCode1.SelectionStart = 5;
            }
        }

        private void SetTimeButton_Click(object sender, EventArgs e)
        {
            DateTimeForm f = new DateTimeForm();
            f.Client = ((SpeedwayHardwareReader)Reader.Hardware).D1C;
            f.ShowDialog();
        }

        private void SReaderFreq_SelectedIndexChanged(object sender, EventArgs e)
        {
            ((SpeedwayHardwareReader)Reader.Hardware).D1C.SetFreq(SReaderFreq.Text);
        }

    }
}