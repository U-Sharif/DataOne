
#ifndef _TETON_KILLTAGRESULT_H_
#define _TETON_KILLTAGRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class used to carry the result of a SpeedwayReader.KillTag operation
    /// </summary>
    class KillTagResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result of the tag kill operation
        /// </summary>
        PrimitiveKillResult KillResult;

        /// <summary> Default constructor</summary>
        KillTagResult();

        /// <summary> Construct a KillTagResult from a base class
        /// instance</summary>
        KillTagResult(const CommonAccessResult & commonAccessResult);

        /// <summary> Copy constructor</summary>
        KillTagResult(const KillTagResult & killTagResult);
    };
}
#endif /* _TETON_KILLTAGRESULT_H_ */
