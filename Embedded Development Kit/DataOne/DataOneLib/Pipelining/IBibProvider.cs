using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public interface IBibProvider
    {
        void Init(IPipelineCallback pipeline);
        void PipelineReady();
        void PipelineAborted();
        void SingleTagWritten();
        int GetBib();
    }
}
