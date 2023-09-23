#ifndef _TETON_PRIMITIVEGETBLOCKPERMALOCKPARAMS_H_
#define _TETON_PRIMITIVEGETBLOCKPERMALOCKPARAMS_H_ 
#include "Enums/MemoryBank.h"
namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for getting the block permalock
    /// status from a tag
    /// </summary>
    class PrimitiveGetBlockPermalockParams : public PrimitiveParams
    {
      public: 
        /// <summary>
        /// The memory bank from which block permalock status is desired
        /// </summary>
        /// <remarks>Currently this must be MemoryBank.User</remarks>
        enum MemoryBank MemoryBank;

        /// <summary>
        /// The pointer to the first block from which status is desired
        /// </summary>
        /// <remarks>Must be greater than or equal to zero</remarks>
        int BlockPointer;

        /// <summary>
        /// The block range from which status is desired
        /// </summary>
        /// <remarks>Must be greater than zero and less than or equal to
        /// Constants.MaxBlockPermalockWordCount </remarks>
        int BlockRange;

        /// <summary>
        /// Consturct a PrimitiveGetBlockPermalockParams instance
        /// </summary>
        PrimitiveGetBlockPermalockParams();

        /// <summary>
        /// construct a PrimitiveGetBlockPermalockParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveGetBlockPermalockParams(const PrimitiveGetBlockPermalockParams & primitiveGetBlockPermalockParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveGetBlockPermalockParams</returns>
        PrimitiveParams * Clone();
    };
}
#endif /* _TETON_PRIMITIVEGETBLOCKPERMALOCKPARAMS_H_ */
