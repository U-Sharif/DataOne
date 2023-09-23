using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using Impinj.OctaneSdk;

namespace DataOneLib
{
    public class Watcher
    {
        private Thread mWorker;
        private bool mStopped = false;
        private bool mWorking = false;

        public List<OneTag> Tags = new List<OneTag>();
        public List<OneTag> TagsLost = new List<OneTag>();

        public event TagEvent NewTag, LostTag;

        public Watcher()
        {
            Reader.TagReported += new Reader.OnTagDelegate(rd_TagReported);
            mWorker = new Thread(new ThreadStart(Run));
            mStopped = false;
            mWorker.Start();
        }

        public void Start()
        {
            mWorking = true;
        }

        public void Stop()
        {
            mWorking = false;
        }

        public void Abort()
        {
            mWorker.Interrupt();
            mStopped = true;
            mWorker = null;
        }

        private void rd_TagReported(OneTag tag)
        {
            if (!mWorking) return;
            
            lock (Tags)
            {
                foreach (OneTag t in Tags)
                    if (t.EPC == tag.EPC)
                    {
                        t.NotifyUpdated(tag);
                        return;
                    }
                Tags.Add(tag);
                if (NewTag != null)
                    NewTag(tag);
            }
        }

        private void Run()
        {
            while (!mStopped)
            {
                try
                {
                    Thread.Sleep(300);

                    lock (Tags)
                    {
                        foreach (OneTag t in Tags)
                            if (t.GetStatus() == TagStatus.Lost)
                            {
                                TagsLost.Add(t);
                                if (LostTag != null)
                                    LostTag(t);
                            }
                            else if (t.GetStatus() == TagStatus.Idle)
                                t.SendIdle();
                            else if (t.GetStatus() == TagStatus.Losing)
                                t.SendLosing();
                        foreach (OneTag t in TagsLost)
                            Tags.Remove(t);
                        TagsLost.Clear();
                    }
                }
                catch { return; }
            }
        }

        public delegate void TagEvent(OneTag t);
    }
}
