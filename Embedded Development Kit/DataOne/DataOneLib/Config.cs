using System;
using System.Collections.Generic;
using System.Text;
using Impinj.OctaneSdk;
using System.IO;
using System.Windows.Forms;
using DataOneLib;

namespace DataOneLib
{
    public static class Config
    {
        public static Dictionary<string, ReaderMode> ReaderModes = new Dictionary<string, ReaderMode>();
        public static Dictionary<string, SearchMode> SearchModes = new Dictionary<string, SearchMode>();
        public static Dictionary<string, double> Frequencies = new Dictionary<string, double>();
        public static List<string> Volumes = new List<string>();

        public static Dictionary<string, string> Data = new Dictionary<string, string>();

        public static int MinRSSI = -99;
        public static double MaxTxPower = 0;
        public static string BarcodeReaderAddr = "";
        public static int BarcodeReaderPort;
        public static int BibFilter;
        public static int WriteRepeat;

        public static string Name, FileName;
        public static bool Shutdown = false;


        static Config()
        {
            Reset();
        }

        public static void Reset()
        {
            Data.Clear();
            Data["device"] = "1";
            Data["clip"] = "5000";
            Data["description"] = "R1";
            Data["address"] = "";
            Data["reader_port"] = "";
            Data["min_rssi"] = "-99";
            Data["port"] = "3322";
            Data["reader_mode"] = "AutoSet Dense Reader";
            Data["search_mode"] = "Dual Target";
            Data["session"] = "0";
            Data["frequency"] = "Auto";
            Data["tag_volume"] = "4-8";
            Data["barcode_addr"] = "10.90.3.10";
            Data["barcode_port"] = "10002";
            Data["bib_filter"] = "0";
            Data["repeat_write"] = "1";
            Data["skip_special"] = "on";
            Data["master"] = "reader";
        }

        private static void PopulateFields()
        {
            MinRSSI = int.Parse(Data["min_rssi"]);
            BarcodeReaderAddr = Data["barcode_addr"];
            BarcodeReaderPort = int.Parse(Data["barcode_port"]);
            BibFilter = int.Parse(Data["bib_filter"]);
            WriteRepeat = int.Parse(Data["repeat_write"]);
        }

        public static void LoadPresets(SpeedwayReader r)
        {
            FeatureSet f = r.QueryFeatureSet();
            foreach (ReaderModeEntry m in f.ReaderModes.Entries)
                ReaderModes.Add(m.Description, m.Mode);

            foreach (SearchModeEntry m in f.SearchModes.Entries)
                SearchModes.Add(m.Description, m.Mode);

            Frequencies.Add("Auto", 0);
            int ct = 0;
            foreach (TxFrequencyEntry m in f.TxFrequencies.Entries)
                if (f.TxFrequencies.Entries.Count > 26)
                    Frequencies.Add(String.Format("{0:000.0} MHz", m.Mhz), m.Mhz);
                else
                    Frequencies.Add(String.Format("{0} - {1:000.0} MHz", Char.ConvertFromUtf32(Char.ConvertToUtf32("A", 0) + ct++), m.Mhz), m.Mhz);

            MaxTxPower = 0;
            foreach (TxPowerEntry m in f.TxPowers.Entries)
                MaxTxPower = Math.Max(MaxTxPower, m.Dbm);

            Volumes.Add("1-4");
            Volumes.Add("4-8");
            Volumes.Add("8-16");
            Volumes.Add("16-32");
            Volumes.Add("32-64");
            Volumes.Add("64-128");
            Volumes.Add("128-256");
            Volumes.Add("256-512");
            Volumes.Add("512-1024");
        }

        public static void Load(string file)
        {
            try
            {
                FileName = file;
                string[] lines = File.ReadAllLines(file);
                foreach (string line in lines)
                    if (line.Contains("="))
                        Data[line.Split('=')[0].Trim()] = line.Split('=')[1].Trim();
                PopulateFields();
            }
            catch { }
        }

        public static string Dump()
        {
            String data = "";
            try
            {
                foreach (string key in Data.Keys)
                    data += key + " = " + Data[key] + "\r\n";
            }
            catch { }
            return data;
        }

        public static void Save()
        {
            File.WriteAllText(FileName, Config.Dump());
            PopulateFields();
        }

        public static void Apply(Settings s)
        {
            s.ReaderMode = ReaderModes[Data["reader_mode"]];
            s.SearchMode = SearchModes[Data["search_mode"]];
            s.Session = int.Parse(Data["session"]);
            s.TagPopulationEstimate = int.Parse(Data["tag_volume"].Split('-')[0].Trim());
            s.TxFrequenciesInMhz.Clear();
            if (Data["frequency"] != "Auto")
                s.TxFrequenciesInMhz.Add(Frequencies[Data["frequency"]]);
            s.Antennas[1].IsEnabled = Data["antenna_1"] == "on";
            s.Antennas[2].IsEnabled = Data["antenna_2"] == "on";
            s.Antennas[3].IsEnabled = Data["antenna_3"] == "on";
            s.Antennas[4].IsEnabled = Data["antenna_4"] == "on";
            s.Antennas[1].TxPowerInDbm = double.Parse(Data["antenna_1_power"]);
            s.Antennas[2].TxPowerInDbm = double.Parse(Data["antenna_2_power"]);
            s.Antennas[3].TxPowerInDbm = double.Parse(Data["antenna_3_power"]);
            s.Antennas[4].TxPowerInDbm = double.Parse(Data["antenna_4_power"]);
        }

        public static string GenerateFilename()
        {
            string r = DateTime.Now.ToString("yyyyMMdd HHmmssfff");
            return r;
        }
    }
}
