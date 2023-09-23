#ifndef _TETON_PRIMITIVEGETBLOCKPERMALOCKRESULT_H_
#define _TETON_PRIMITIVEGETBLOCKPERMALOCKRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the GetBlockPermalock
    /// results.
    /// </summary>
    class PrimitiveGetBlockPermalockResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the get block permalock primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// A string describing the permalock status.
        /// </summary>
        /// <remarks>The result is a string containing a uint16 array
        /// (e.g. FE13 AA2E)</remarks>
        string PermalockStatus;

        /// <summary>
        /// Initializes a new instance of the PrimitiveGetBlockPermalockResult class
        /// </summary>
        PrimitiveGetBlockPermalockResult();

        /// <summary>
        /// Initializes a new instance of the PrimitiveGetBlockPermalockResult class
        /// (copy constructor)
        /// </summary>
        PrimitiveGetBlockPermalockResult(
            const PrimitiveGetBlockPermalockResult & primitiveGetBlockPermalockResult);

        /// <summary>
        /// Create a copy of the PrimitiveGetBlockPermalockResult
        /// </summary>
        /// <returns>PrimitiveGetBlockPermalockResult</returns>
        PrimitiveResult * Clone();
    };
}
#endif /* _TETON_PRIMITIVEGETBLOCKPERMALOCKRESULT_H_ */
