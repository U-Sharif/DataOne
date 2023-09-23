using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using DataOneLib;
using System.Threading;
using System.Reflection;
using System.IO;

namespace DataOne
{
    public partial class ConnectForm : Form
    {
        public bool DemoMode = false;
        public ConnectForm()
        {
            InitializeComponent();
            Text += " " + Assembly.GetExecutingAssembly().GetName().Version.ToString(2);
        }

        private void ConnectForm_Load(object sender, EventArgs e)
        {
            PopulateAddresses();
            radioButton_CheckedChanged(null, null);
            ReloadList();

            DemoMode = true;
            try
            {
                if (File.ReadAllText(@"C:\windows\win.ini").Contains("r"))
                    DemoMode = false;
            }
            catch { }
            if (DemoMode)
            {
                new Thread(new ThreadStart(delegate
                {
                    Thread.Sleep(1000 * 60 * 5);
                    if (!Config.Data.ContainsKey("notimelimit"))
                        Environment.Exit(0);
                })).Start();
                radioButton2.Enabled = false;
                radioButton3.Enabled = false;
                MessageBox.Show("Demo mode", "DataOne", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        void ReloadList()
        {
            ConfigList.Items.Clear();
            foreach (FileInfo f in new DirectoryInfo(Application.StartupPath).GetFiles("*.ini"))
            {
                Config.Reset();
                Config.Load(f.FullName);
                ListViewItem i = new ListViewItem(new string[] {
                    f.Name,
                    Config.Data["device"]=="1"?"DS DataOne":(Config.Data["device"]=="2"?"Orangebox":"Handreader"),
                    Config.Data["description"],
                    Config.Data["address"]+(Config.Data["device"]=="3"?(":"+Config.Data["reader_port"]):"")
                });
                ConfigList.Items.Add(i);
            }

            if (ConfigList.Items.Count == 0)
                StartCreatingButton_Click(null, null);
        }

        private void CreateButton_Click(object sender, EventArgs e)
        {
            string s = NewNameBox.Text;

            if (s == "")
                return;

            Config.Reset();
            //Config.Data["description"] = s;

            if (!s.EndsWith(".ini"))
                s += ".ini";
            Config.Name = s;
            s = Application.StartupPath + @"\" + s;

            if (File.Exists(s))
                MessageBox.Show("Config already exists", "DataOne", MessageBoxButtons.OK, MessageBoxIcon.Error);
            else
                File.Create(s).Close();

            NewNameBox.Text = "";

            ReloadList();
            StartCreatingButton.Visible = true;
            SelectButton.Visible = true;
            NewNameBox.Visible = false;
            CreateButton.Visible = false;
        }

        void LoadConfig(string name)
        {
            if (!name.Contains("\\"))
                name = Application.StartupPath + "\\" + name;
            if (!name.Contains(".ini"))
                name += ".ini";

            Config.Reset();
            Config.Load(name);

        }

        string addr;
        string port;

        void Connect()
        {
            bool err = false;

            try
            {
                if (radioButton1.Checked)
                {
                    if (!Config.Data.ContainsKey("antenna_1")) // First run
                        Config.Data["bib_filter"] = "3";
                    SpeedwayHardwareReader swr = new SpeedwayHardwareReader();
                    swr.Init(addr);
                    if (Config.Data["master"] == "reader")
                        swr.GoD1();
                    Reader.Hardware = swr;
                    Reader.Reconnect(addr, 0);

                    port = "";
                    try
                    {
                        Config.LoadPresets(((SpeedwayHardwareReader)Reader.Hardware).Expose());
                    }
                    catch { }
                }

                if (radioButton2.Checked)
                {
                    Reader.Hardware = new OrangeboxHardwareReader();
                    if (OBModeI.Checked)
                        ((OrangeboxHardwareReader)Reader.Hardware).PIFilter = "I";
                    else
                        ((OrangeboxHardwareReader)Reader.Hardware).PIFilter = "P";

                    Reader.Reconnect(null, 0);
                    addr = "";
                    port = "";
                }

                if (radioButton3.Checked)
                {
                    Reader.Hardware = new HandreaderHardwareReader();
                    Reader.Reconnect(addr, int.Parse(port));
                }

                Config.Data["address"] = addr;
                Config.Data["reader_port"] = port;
                Config.Data["device"] = radioButton1.Checked ? "1" : (radioButton2.Checked ? "2" : "3");
                if (radioButton2.Checked)
                    Config.Data["obmode"] = OBModeI.Checked ? "I" : "P";
                Config.Save();
                Invoke((MethodInvoker)delegate()
                {
                    Hide();
                    MainForm frm = new MainForm();
                    frm.SelectedAddress = AddressBox.Text;
                    frm.SelectedPort = PortBox.Text;
                    frm.DemoMode = DemoMode;
                    frm.Show();
                });
            }
            catch
            {
                err = true;
            }

            Invoke((MethodInvoker)delegate()
            {
                Enabled = true;
                Progress.Style = ProgressBarStyle.Blocks;
                if (err)
                    MessageBox.Show("Cannot connect", "DataOne", MessageBoxButtons.OK, MessageBoxIcon.Error);
            });
        }

        private void PopulateAddresses()
        {
            AddressBox.Items.Clear();
            if (radioButton1.Checked)
            {
                for (int i = 1; i <= 20; i++)
                    AddressBox.Items.Add(i.ToString());
                AddressBox.Items.Add("99");
            }
            if (radioButton3.Checked)
            {
                for (int i = 1; i < 7; i++)
                    AddressBox.Items.Add(i.ToString());
            }
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            Enabled = false;
            Progress.Style = ProgressBarStyle.Marquee;

            if (radioButton1.Checked && !AddressBox.Text.Contains("."))
                AddressBox.Text = "10.90.9." + AddressBox.Text;

            if (radioButton3.Checked && !AddressBox.Text.Contains("."))
                AddressBox.Text = "10.90.3." + (AddressBox.SelectedIndex / 2 * 2 + 1);

            addr = AddressBox.Text;
            port = PortBox.Text;
            new Thread(new ThreadStart(Connect)).Start();
        }

        private void radioButton_CheckedChanged(object sender, EventArgs e)
        {
            PopulateAddresses();
            PortBox.Enabled = radioButton3.Checked;
            AddressBox.Enabled = !radioButton2.Checked;
            Progress.Enabled = !radioButton2.Checked;
            OBModeI.Enabled = radioButton2.Checked;
            OBModeP.Enabled = radioButton2.Checked;
        }

        private void AddressBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (radioButton3.Checked)
            {
                if (AddressBox.SelectedIndex % 2 == 1)
                    PortBox.Text = "10002";
                else
                    PortBox.Text = "10001";
            }
        }

        private void ConnectForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            Environment.Exit(0);
        }

        private void SelectButton_Click(object sender, EventArgs e)
        {
            if (ConfigList.SelectedItems.Count > 0)
            {
                string name = ConfigList.SelectedItems[0].SubItems[0].Text;
                Config.Reset();
                Config.Load(Application.StartupPath + @"\" + name);
                Config.Name = name;
                //Config.Data["description"] = name;

                AddressBox.Text = Config.Data["address"];
                PortBox.Text = Config.Data["reader_port"];

                radioButton1.Checked = Config.Data["device"] == "1";
                radioButton2.Checked = Config.Data["device"] == "2";
                radioButton3.Checked = Config.Data["device"] == "3";

                if (radioButton2.Checked)
                    try
                    {
                        OBModeI.Checked = Config.Data["obmode"] == "I";
                        OBModeP.Checked = Config.Data["obmode"] == "P";
                    }
                    catch { }

                PopulateAddresses();
                radioButton_CheckedChanged(null, null);

                FilesGB.Enabled = false;
                ConnectionGB.Enabled = true;
            }
        }

        private void ConfigList_DoubleClick(object sender, EventArgs e)
        {
            SelectButton_Click(sender, e);
        }

        private void StartCreatingButton_Click(object sender, EventArgs e)
        {
            StartCreatingButton.Visible = false;
            SelectButton.Visible = false;
            NewNameBox.Visible = true;
            CreateButton.Visible = true;
        }
    }
}