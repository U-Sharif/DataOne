using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace DataOneLib
{
    public static class TidDB
    {
        private static FileSystemWatcher mFSW;
        private static string mTidFile;
        private static List<string> mTidList = new List<string>();

        static TidDB()
        {
            mTidFile = Application.StartupPath + @"\tid.txt";
            mFSW = new FileSystemWatcher();
            mFSW.Changed += new FileSystemEventHandler(mFSW_Changed);
            mFSW.Path = new FileInfo(mTidFile).Directory.FullName;
            mFSW.Filter = new FileInfo(mTidFile).Name;
            mFSW.EnableRaisingEvents = true;
            mFSW.NotifyFilter = NotifyFilters.LastWrite |
                NotifyFilters.CreationTime |
                NotifyFilters.FileName |
                NotifyFilters.DirectoryName |
                NotifyFilters.Size;
            ReloadTids();
        }

        static void mFSW_Changed(object sender, FileSystemEventArgs e)
        {
            ReloadTids();
        }

        public static bool HasTid(string tid)
        {
            lock (mTidList)
                foreach (string t in mTidList)
                    if (t == tid)
                        return true;
            return false;
        }

        public static void ReloadTids()
        {
            lock (mTidList)
            {
                mTidList.Clear();
                try
                {
                    string[] lines = File.ReadAllLines(mTidFile);
                    foreach (string l in lines)
                        if (l != "")
                            mTidList.Add(l.Trim());
                }
                catch { }
            }
        }

        public static void AddTid(string tid)
        {
            lock (mTidList)
            {
                File.AppendAllText(mTidFile, tid + "\r\n");
            }
        }
    }
}
