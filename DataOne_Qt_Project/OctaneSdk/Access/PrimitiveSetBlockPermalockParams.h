#ifndef _TETON_PRIMITIVESETBLOCKPERMALOCKPARAMS_H_
#define _TETON_PRIMITIVESETBLOCKPERMALOCKPARAMS_H_ 
#include "Enums/MemoryBank.h"
namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for setting block permalock
    /// status on a tag
    /// </summary>
    class PrimitiveSetBlockPermalockParams : public PrimitiveParams
    {
      public:
        /// <summary>
        /// The memory bank for which block permalock status change is desired
        /// </summary>
        /// <remarks>Currently this must be MemoryBank.User</remarks>
        enum MemoryBank MemoryBank;

        /// <summary>
        /// The pointer to the first block from which status change is desired
        /// </summary>
        /// <remarks>Must be greater than or equal to zero</remarks>
        int BlockPointer;
        /// <summary>
        /// The block mask to lock
        /// </summary>
        /// <remarks>The block mask is a hex string representing
        /// the blocks to lock (ones).  The stirng must be a multiple
        /// of 4 hex characters (16 bits)</remarks>
        string BlockMask;

        /// <summary>
        /// Construct a PrimitiveSetBlockPermalockParams instance
        /// </summary>
        PrimitiveSetBlockPermalockParams();

        /// <summary>
        /// Construct a PrimitiveSetBlockPermalockParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveSetBlockPermalockParams(
            const PrimitiveSetBlockPermalockParams & primitiveSetBlockPermalockParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveParams</returns>
        PrimitiveParams * Clone();
    };
}

#endif /* _TETON_PRIMITIVESETBLOCKPERMALOCKPARAMS_H_ */
