using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public class PairwiseEpcProcessor : IEpcProcessor
    {
        public string EpcPrefix;
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

            if (!CheckSeries || ((epc1.EPC.StartsWith("E200") && epc2.EPC.StartsWith("3008")) ||
                (epc2.EPC.StartsWith("E200") && epc1.EPC.StartsWith("3008"))))
            {
                if (epc1.EPC.StartsWith("3008"))
                {
                    OneTag t = epc2;
                    epc2 = epc1;
                    epc1 = t;
                }

                mCallback.WriteSingleTag(epc1, "AAAA" + Series + "00000000" + mCallback.GetOneBib().ToString("x8"));
                mCallback.WriteSingleTag(epc2, "BBBB" + Series + "00000000" + mCallback.GetOneBib().ToString("x8"));
                mCallback.Log("Wrote tags");
            }
            else
                mCallback.Log("Invalid tag prerequisite");
        }

    }
}
