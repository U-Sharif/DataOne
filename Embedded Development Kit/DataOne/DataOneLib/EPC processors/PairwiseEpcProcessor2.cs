using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public class PairwiseEpcProcessor2 : IEpcProcessor
    {
        public bool CheckTIDs;
        public bool CheckSeries;
        public string Series;
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

            if (list.Count != 2)
            {
                mCallback.Log("Invalid tag prerequisite");
                return;
            }

            OneTag epc1 = list[0];
            OneTag epc2 = list[1];

            if (!CheckSeries || (epc1.EPC.StartsWith("3008") && epc2.EPC.StartsWith("3008")))
            {
                mCallback.WriteSingleTag(epc1, "B2BB" + Series + "00000000" + mCallback.GetOneBib().ToString("x8"));
                mCallback.WriteSingleTag(epc2, "B2BB" + Series + "00000000" + mCallback.GetOneBib().ToString("x8"));
                mCallback.Log("Wrote tags");
            }
            else
                mCallback.Log("Invalid tag prerequisite");
        }

    }
}
