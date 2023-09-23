using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public class BasicEpcProcessor : IEpcProcessor
    {
        public string EpcPrefix;
        public bool CheckTIDs;
        private IPipelineCallback mCallback;

        public void Init(IPipelineCallback cb)
        {
            mCallback = cb;
        }

        public void PipelineReady() { }

        public void PipelineAborted() { }

        public void Begin()
        {
            List<OneTag> list = mCallback.QueryTags();
            int idx = 0;
            foreach (OneTag t in list)
            {
                idx++;
                mCallback.SetProgress(list.Count, idx);
                if (t.RSSIMax < Config.MinRSSI)
                {
                    mCallback.Log("Tag " + t.EPC + " signal is too weak");
                    continue;
                }

                if (CheckTIDs && TidDB.HasTid(t.TID))
                    continue;

                for (int i = 0; i < Config.WriteRepeat; i++)
                {
                    string newEpc = "" + EpcPrefix;
                    while (newEpc.Length < 16)
                        newEpc += "0";
                    newEpc += mCallback.GetOneBib().ToString("x8");
                    mCallback.WriteSingleTag(t, newEpc);
                }

                TidDB.AddTid(t.TID);
            }
        }
    }
}
