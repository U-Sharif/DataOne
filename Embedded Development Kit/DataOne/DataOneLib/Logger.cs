using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Impinj.OctaneSdk;

namespace DataOneLib
{
    public class Logger
    {
        public string LogPath;
        public List<String> LiveStream = new List<string>();
        public int ClipCount = -1;
        public event LogEvent OnLog;
        public int BibFilter = 0;

        private Dictionary<string, DateTime> FilterDB = new Dictionary<string, DateTime>();

        private StreamWriter mStream;
        public int Last = 0;
        private int mCounter = 0;
        private string mFile;
        private int mFileWriteCount = 0;


        public Logger(string path)
        {
            if (path.EndsWith(".ini"))
                path = path.Substring(0, path.Length - 4);

            LogPath = path;

            if (!Directory.Exists(LogPath))
                Directory.CreateDirectory(LogPath);
        }

        public int FindLast()
        {
            int r = 0;
            List<string> ls = new List<string>();
            ls.AddRange(Directory.GetFiles(LogPath, "*.log"));
            ls.Sort();
            try
            {
                string s = ls[ls.Count - 1];
                string[] ll = File.ReadAllLines(Path.Combine(LogPath, s));
                for (int i = ll.Length - 1; i > 0; i--)
                {
                    try
                    {
                        string l = ll[i].Split(',')[0];
                        r = Math.Max(r, int.Parse(l));
                        break;
                    }
                    catch { }
                }
            }
            catch { }
            return r;
        }

        public void NextFile()
        {
            if (mStream != null)
                Finish();
            Last = FindLast();
            string file = LogPath + "\\" + String.Format("{0:000000}", Last + 1) + " " + Config.GenerateFilename() + ".log";
            FileInfo fi = new FileInfo(file);
            if (fi.Exists)
                mStream = fi.AppendText();
            else
            {
                FileStream s = fi.Open(FileMode.OpenOrCreate, FileAccess.Write, FileShare.ReadWrite);
                mStream = new StreamWriter(s);
            }
            mFile = file;
            mFileWriteCount = 0;
            LiveStream = new List<string>();
            DumpSettings();
        }

        public void Log(OneTag t, int count)
        {
            string bib = Library.Resolve(t);

            if (BibFilter > 0) // filter time!
            {
                if (bib == "")
                    return;
                if (FilterDB.ContainsKey(bib) && (DateTime.Now - FilterDB[bib]).TotalSeconds < BibFilter)
                    return;
                FilterDB[bib] = DateTime.Now;
            }

            Last++;

            string line = Last + "," + t.EPC + "," + bib + "," + t.LastSeen.ToString("dd.MM.yyyy HH:mm:ss.fff") + "," + t.LastAntenna + "," + t.RSSILast;

            try
            {
                mStream.WriteLine(line);

                if (mCounter % 10 == 0)
                    Flush();
            }
            catch { }

            lock (LiveStream)
                LiveStream.Add(line);
            if (OnLog != null)
                OnLog(line);

            mCounter++;
            mFileWriteCount++;
            if (ClipCount > 0 && mCounter >= ClipCount)
            {
                mCounter = 0;
                NextFile();
            }
        }

        public void Finish()
        {
            mStream.Flush();
            mStream.Close();
            if (mFileWriteCount == 0)
                File.Delete(mFile);
        }

        public void Flush()
        {
            try
            {
                mStream.Flush();
            }
            catch { }
        }

        public void DumpSettings()
        {
            string r = "";
            foreach (string l in Config.Dump().Split('\n'))
            {
                string x = l.Trim('\r', '\n');
                if (x != "")
                    r += "# " + x + "\r\n";
            }
            mStream.Write(r);
        }

        public delegate void LogEvent(string l);
    }
}
