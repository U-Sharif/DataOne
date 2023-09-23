using System;
using System.Collections.Generic;
using System.Text;

namespace DataOneLib
{
    public interface IEpcProcessor
    {
        void Init(IPipelineCallback cb);
        void PipelineReady();
        void PipelineAborted();
        void Begin();
    }
}
