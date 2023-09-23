#ifndef _TETON_PRIMITIVEWRITERESULT_H_
#define _TETON_PRIMITIVEWRITERESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the write
    /// results.
    /// </summary>
    class PrimitiveWriteResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the Write primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// The number of words written to the tag
        /// </summary>
        int NumWordsWritten;

        /// <summary>
        /// Construct a PrimitiveWriteResult instance
        /// </summary>
        PrimitiveWriteResult();

        /// <summary>
        /// Construct a PrimitiveWriteResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveWriteResult(const PrimitiveWriteResult & primitiveWriteResult);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        PrimitiveResult * Clone();
    };

}
#endif /* _TETON_PRIMITIVEWRITERESULT_H_ */
