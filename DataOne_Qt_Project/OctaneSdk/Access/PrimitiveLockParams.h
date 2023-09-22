#ifndef _TETON_PRIMITIVELOCKPARAMS_H_
#define _TETON_PRIMITIVELOCKPARAMS_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for locking a tag
    /// </summary>
    class PrimitiveLockParams : public PrimitiveParams
    {
      public:
        /// <summary>
        /// The new lock state for the tag access password
        /// </summary>
        LockType LockAccessPassword;

        /// <summary>
        /// The new lock state for the tag kill password
        /// </summary>
        LockType LockKillPassword;

        /// <summary>
        /// The new lock state for the tag EPC memory
        /// </summary>
        LockType LockEpcMemory;

        /// <summary>
        /// The new lock state for the tag TID memory
        /// </summary>
        LockType LockTidMemory;

        /// <summary>
        /// The new lock state for the tag user memory
        /// </summary>
        LockType LockUserMemory;

        /// <summary>
        /// Construct a PrimitiveLockParams instance
        /// </summary>
        PrimitiveLockParams();

        /// <summary>
        /// Construct a PrimitiveLockParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveLockParams(const PrimitiveLockParams & primitiveLockParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveParams</returns>
        PrimitiveParams * Clone();
    };

}
#endif /* _TETON_PRIMITIVELOCKPARAMS_H_ */
