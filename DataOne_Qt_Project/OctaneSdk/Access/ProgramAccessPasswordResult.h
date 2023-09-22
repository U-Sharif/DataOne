#ifndef _TETON_PROGRAMACCESSPASSWORDRESULT_H_
#define _TETON_PROGRAMACCESSPASSWORDRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ProgramAccessPassword
    /// operation
    /// </summary>
    class ProgramAccessPasswordResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result status of the access password programming
        /// </summary>
        PrimitiveWriteResult WriteResult;

        /// <summary>
        /// The result status of optional verify
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// The result status of optional accessPassword lock operation
        /// </summary>
        PrimitiveLockResult LockResult;

        /// <summary>
        /// Initializes a new instance of the ProgramAccessPasswordResult class
        /// </summary>
        ProgramAccessPasswordResult();

        /// <summary>
        /// Initializes a new instance of the ProgramAccessPasswordResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ProgramAccessPasswordResult(const CommonAccessResult & commonAccessResult);
        
        /// <summary>
        /// Initializes a new instance of the ProgramAccessPasswordResult class
        /// (copy constructor)
        /// </summary>
        ProgramAccessPasswordResult(const ProgramAccessPasswordResult & programAccessPasswordResult);
    };
}
#endif /* define _TETON_PROGRAMACCESSPASSWORDRESULT_H_ */
