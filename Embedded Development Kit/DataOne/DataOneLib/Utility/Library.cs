using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Globalization;

namespace DataOneLib
{
    public static class Library
    {
        private static Dictionary<string, string> mData = null;

        public static void Load()
        {
            mData = new Dictionary<string, string>();
            try
            {
                string[] lines = File.ReadAllLines(Application.StartupPath + @"\bib.txt");
                foreach (string line in lines)
                    if (line.Contains(","))
                    {
                        string[] d = line.Split(',');
                        string key = d[0];
                        for (int i = 1; i < d.Length; i++)
                            mData.Add(d[i].Trim(), key);
                    }
            }
            catch { }
        }

        public static string ParseEPC(String epc)
        {
            if (epc.Length == 8)
            {
                uint inVal = UInt32.Parse(epc, NumberStyles.AllowHexSpecifier);
                uint id = inVal % 131072;
                uint evt = (inVal / 131072) % 128;
                uint tmr = inVal / 16777216;
                return tmr + "/" + evt + "/" + id;
            }
            if (epc.Length == 24 && epc.StartsWith("FF"))
                return DSEPC.Decode(epc);
            return epc;
        }

        public static string Resolve(OneTag tag)
        {
            if (tag.BibOverride != null)
                return tag.BibOverride;

            string epc = tag.EPC;
            if (epc.Length == 8)
                try
                {
                    uint inVal = UInt32.Parse(epc, NumberStyles.AllowHexSpecifier);
                    uint id = inVal % 131072;
                    uint evt = (inVal / 131072) % 128;
                    return id.ToString();
                }
                catch { }

            if (epc.Length == 24 && epc.StartsWith("FF"))
                return DSEPC.Decode(epc).Split('/')[1];

            epc = epc.Substring(epc.Length - 8).TrimStart('0');
            try
            {
                return mData[epc];
            }
            catch
            {
                return "";
            }
        }
    }
}
