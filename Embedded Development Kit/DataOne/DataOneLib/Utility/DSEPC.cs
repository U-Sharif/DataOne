using System;
using System.Collections.Generic;
using System.Text;
using System.Globalization;

namespace DataOneLib
{
    public static class DSEPC
    {
        private static byte[] Key = Encoding.ASCII.GetBytes("ThePassword");

        public static string Encode(string Event, int bib)
        {
            string s = Event.PadRight(5, ' ') + bib.ToString().PadLeft(6, ' ');
            byte[] data = Encoding.ASCII.GetBytes(s);
            Xor(data);
            s = "";
            foreach (byte b in data)
                s += b.ToString("x2");
            return "FF" + s.ToUpper();
        }

        public static string Decode(string EPC)
        {
            EPC = EPC.Substring(2);
            byte[] d = new byte[11];
            for (int i = 0; i < 11; i++)
                d[i] = Byte.Parse(EPC.Substring(i * 2, 2), NumberStyles.AllowHexSpecifier);
            Xor(d);
            string r = Encoding.ASCII.GetString(d);
            r = r.Insert(5, "/");
            while (r.Contains(" "))
                r = r.Replace(" ", "");
            return r;
        }

        private static void Xor(byte[] data)
        {
            for (int i = 0; i < data.Length; i++)
                data[i] = (byte)(data[i] ^ Key[i % Key.Length]);
        }
    }
}
