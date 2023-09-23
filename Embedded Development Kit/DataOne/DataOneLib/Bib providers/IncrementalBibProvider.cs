using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public class IncrementalBibProvider : IBibProvider
    {
        public bool Increment = true;
        private IPipelineCallback mCallback;
        private int mBib;

        public IncrementalBibProvider(int bib)
        {
            mBib = bib;
        }

        public void Init(IPipelineCallback cb)
        {
            mCallback = cb;
        }

        public void PipelineReady()
        {
            mCallback.StartWriting();
            mCallback.Stop();
        }

        public void PipelineAborted() { }

        public void SingleTagWritten()
        {
            if (Increment)
                mBib++;
        }

        public int GetBib()
        {
            return mBib;
        }

    }
}
