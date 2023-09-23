#ifndef _TETON_PRIMITIVESETBLOCKPERMALOCKRESULT_H_
#define _TETON_PRIMITIVESETBLOCKPERMALOCKRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the set block
    /// permalock result
    /// </summary>
    class PrimitiveSetBlockPermalockResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the setBlockPermalock primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// Construct a PrimitiveSetBlockPermalockResult instance
        /// </summary>
        PrimitiveSetBlockPermalockResult();

        /// <summary>
        /// Construct a PrimitiveSetBlockPermalockResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveSetBlockPermalockResult(
            const PrimitiveSetBlockPermalockResult & primitiveSetBlockPermalockResult);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        PrimitiveResult * Clone();
    };

}
#endif /* _TETON_PRIMITIVESETBLOCKPERMALOCKRESULT_H_ */

