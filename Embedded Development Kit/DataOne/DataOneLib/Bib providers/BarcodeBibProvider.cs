using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace DataOneLib
{
    public class BarcodeBibProvider : AsyncTask, IBibProvider
    {
        private IPipelineCallback mCallback;
        private int mBib;

        protected override void Run(object arg)
        {
            mCallback.Log("Connecting to barcode reader");
            BarcodeScanner.Host = Config.BarcodeReaderAddr;
            BarcodeScanner.Port = Config.BarcodeReaderPort;
            BarcodeScanner.Connect();
            if (!BarcodeScanner.Connected)
                BarcodeScanner.Connect();

            DateTime lastCode = DateTime.Now;
            int code = 0;

            while (true)
            {
                mCallback.SetProgress(1, -1);
                int? ncode = BarcodeScanner.Scan();
                if (ncode.HasValue && ncode.Value != code)
                {
                    code = ncode.Value;

                    mBib = code;

                    mCallback.Log("New barcode: " + code);

                    mCallback.StartWriting();

                    mCallback.Log("Finished writing");

                    lastCode = DateTime.Now;
                }
                else
                    if (ncode.HasValue)
                        Thread.Sleep(500);
                    else
                        Thread.Sleep(600);

                if ((DateTime.Now - lastCode).TotalSeconds > 180)
                    break;
            }

            mCallback.Stop();
        }


        public void Init(IPipelineCallback cb)
        {
            mCallback = cb;
        }

        public int GetBib()
        {
            return mBib;
        }

        public void PipelineReady()
        {
            Start();
        }

        public void PipelineAborted()
        {
            Abort();
        }

        public void SingleTagWritten() { }
    }
}
