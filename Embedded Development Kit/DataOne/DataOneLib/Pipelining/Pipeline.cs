using System;
using System.Collections.Generic;
using System.Text;
using Impinj.OctaneSdk;
using System.Media;
using System.Threading;

namespace DataOneLib
{
    public class Pipeline : IPipelineCallback
    {
        public bool Running = false;

        public event LogEvent OnLog;
        public event WrittenEvent OnWrittenTag;
        public event FinishedEvent OnFinished;
        public event ProgressEvent OnProgress;

        internal IBibProvider mBibber;
        internal IEpcProcessor mProc;
        private bool mWasReading;
        private Worker mWorker;

        public delegate void LogEvent(string log);
        public delegate void WrittenEvent(OneTag tag, int bib, string newepc);
        public delegate void ProgressEvent(int c, int t);
        public delegate void FinishedEvent();


        public void Prepare(IBibProvider bib, IEpcProcessor proc)
        {
            mBibber = bib;
            mProc = proc;
            mBibber.Init(this);
            mProc.Init(this);
        }

        public void Start()
        {
            Running = true;
            mWasReading = Reader.Running;
            if (mWasReading)
                Reader.Stop();
            mWorker = new Worker(this);
            mWorker.Start();
        }

        public void Stop()
        {
            Running = false;
            new Thread(delegate()
            {
                if (OnFinished != null)
                    OnFinished();
                if (mWasReading)
                    Reader.Start();
                mProc.PipelineAborted();
                mBibber.PipelineAborted();
                mWorker.Abort();
            }).Start();
        }

        public void Log(string str)
        {
            if (OnLog != null)
                OnLog(str);
        }

        public void StartWriting()
        {
            mProc.Begin();
        }

        public int GetOneBib()
        {
            return mBibber.GetBib();
        }

        public void WriteSingleTag(OneTag t, string epc)
        {
            if (!Reader.WriteTag(t.EPC, epc))
            {
                if (OnLog != null)
                    OnLog("Can't write tag " + t.EPC);
            }
            else
            {
                SystemSounds.Asterisk.Play();
                int bib = GetOneBib();
                mBibber.SingleTagWritten();
                if (OnWrittenTag != null)
                    OnWrittenTag(t, bib, epc);
            }
        }

        public List<OneTag> QueryTags()
        {
            List<OneTag> epcs = new List<OneTag>();
            foreach (OneTag t in Reader.Query(1))
            {
                bool f = false;
                foreach (OneTag s in epcs)
                    if (s.EPC == t.EPC && s.TID == t.TID)
                        f = true;
                if (!f)
                    epcs.Add(t);
            }
            return epcs;
        }

        public void SetProgress(int t, int c)
        {
            if (OnProgress != null)
                OnProgress(c, t);
        }

        class Worker : AsyncTask
        {
            private Pipeline mPipe;

            public Worker(Pipeline pip)
            {
                mPipe = pip;
            }

            protected override void Run(object arg)
            {
                mPipe.mBibber.PipelineReady();
                mPipe.mProc.PipelineReady();
            }
        }
    }
}
