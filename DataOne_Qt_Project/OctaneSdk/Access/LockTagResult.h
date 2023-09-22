#ifndef _TETON_LOCKTAGRESULT_H_
#define _TETON_LOCKTAGRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the results of a SpeedwayReader.LockTag operation
    /// </summary>
    class LockTagResult : public CommonAccessResult
    {
      public: 
        /// <summary>
        /// The result of the lock operation
        /// </summary>
        PrimitiveLockResult LockResult;

        /// <summary>
        /// Initializes a new instance of the LockTagResult class
        /// </summary>
        LockTagResult();

        /// <summary>
        /// Initializes a new instance of the LockTagResult class
        /// from a commonAccessResult
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        LockTagResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the LockTagResult class
        /// (copy constructor)
        /// </summary>
        LockTagResult(const LockTagResult & lockTagResult);
    };
}
#endif /* _TETON_LOCKTAGRESULT_H_ */
