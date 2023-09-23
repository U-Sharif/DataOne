using System;
using System.Collections.Generic;
using System.Text;
using Impinj.OctaneSdk;

namespace DataOneLib
{
    public class OneTag
    {
        public string EPC, TID, BibOverride;
        public int cTotal = 0;
        public int LastAntenna = 1;
        public int[] cSingle = new int[8];
        public double RSSIMin = 0, RSSIMax = -9000, RSSILast = 0;
        public DateTime LastSeen;
        public DateTime FirstSeen;
        public DateTime LocalTimestamp;

        public int? Index = null;

        public static int TagUpdatingTimeout = 500;
        public static int TagNewTimeout = 1000;
        public static int TagLosingTimeout = 1000;
        public static int TagLostTimeout = 4000;

        public event Watcher.TagEvent Losing, Updated, Restored, Idle;

        public OneTag()
        {
            LocalTimestamp = DateTime.Now;
        }

        public OneTag(Tag t)
        {
            EPC = t.Epc;
            TID = t.SerializedTid;
            FirstSeen = DateTime.Now;
            LocalTimestamp = DateTime.Now;
            NotifyUpdated(t);
        }

        public void NotifyUpdated(Tag t)
        {
            cTotal++;
            cSingle[t.AntennaPortNumber - 1]++;
            RSSIMin = Math.Min(RSSIMin, t.PeakRssiInDbm);
            RSSIMax = Math.Max(RSSIMax, t.PeakRssiInDbm);
            RSSILast = t.PeakRssiInDbm;

            TagStatus old = GetStatus();
            LastSeen = DateTime.Now;
            LocalTimestamp = DateTime.Now;
            LastAntenna = t.AntennaPortNumber;

            if (Updated != null)
                Updated(this);
            if (GetStatus() == TagStatus.Updated && old == TagStatus.Losing)
                if (Restored != null)
                    Restored(this);
        }

        public void NotifyUpdated(OneTag t)
        {
            cTotal++;
            cSingle[t.LastAntenna - 1]++;
            RSSIMin = Math.Min(RSSIMin, t.RSSILast);
            RSSIMax = Math.Max(RSSIMax, t.RSSILast);
            RSSILast = t.RSSILast;

            TagStatus old = GetStatus();
            LastSeen = DateTime.Now;
            LocalTimestamp = DateTime.Now;
            LastAntenna = t.LastAntenna;

            if (Updated != null)
                Updated(this);
            if (GetStatus() == TagStatus.Updated && old == TagStatus.Losing)
                if (Restored != null)
                    Restored(this);
        }

        public TagStatus GetStatus()
        {
            if ((DateTime.Now - LocalTimestamp).TotalMilliseconds > TagLostTimeout)
                return TagStatus.Lost;
            if ((DateTime.Now - LocalTimestamp).TotalMilliseconds > TagLosingTimeout)
                return TagStatus.Losing;
            if ((DateTime.Now - FirstSeen).TotalMilliseconds < TagNewTimeout)
                return TagStatus.New;
            if ((DateTime.Now - LocalTimestamp).TotalMilliseconds < TagUpdatingTimeout)
                return TagStatus.Updated;
            return TagStatus.Idle;
        }

        public void SendIdle()
        {
            if (Idle != null)
                Idle(this);
        }

        public void SendLosing()
        {
            if (Losing != null)
                Losing(this);
        }
    }

    public enum TagStatus
    {
        New, Updated, Idle, Losing, Lost
    };
}
