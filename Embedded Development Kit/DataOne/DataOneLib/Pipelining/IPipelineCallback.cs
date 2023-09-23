using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public interface IPipelineCallback
    {
        void Log(string str);
        void StartWriting();
        void Stop();
        int GetOneBib();
        void WriteSingleTag(OneTag old, string epc);
        List<OneTag> QueryTags();
        void SetProgress(int t, int c);
    }
}
