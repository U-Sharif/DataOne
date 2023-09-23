using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace DataOneLib
{
    public class AsyncTask
    {
        private Thread mThread;
        public bool Running;

        public AsyncTask()
        {
            mThread = new Thread(new ParameterizedThreadStart(InnerRun));
        }

        protected virtual void Prepare() { }
        protected virtual void Run(object arg) { }
        protected virtual void Finish() { }

        private void InnerRun(object arg)
        {
            Running = true;
            Prepare();
            try
            {
                Run(arg);
            }
            catch { }
            finally
            {
                Finish();
                Running = false;
            }
        }

        public void Start()
        {
            Start(null);
        }

        public void Start(object arg)
        {
            mThread.Start(arg);
        }

        public void Abort()
        {
            try { mThread.Abort(); }
            catch { }
            Finish();
            Running = false;
        }
    }
}
