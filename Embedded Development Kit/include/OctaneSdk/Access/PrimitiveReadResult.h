#ifndef _TETON_PRIMITIVEREADRESULT_H_
#define _TETON_PRIMITIVEREADRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the read primitive
    /// results.
    /// </summary>
    class PrimitiveReadResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the read primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// The data read by the PrimitiveReadParam
        /// </summary>
        string ReadData;

        /// <summary>
        /// construct a PrimitiveReadResult instance
        /// </summary>
        PrimitiveReadResult();

        /// <summary>
        /// construct a PrimitiveReadResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveReadResult(const PrimitiveReadResult & primitiveReadResult);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        PrimitiveResult * Clone();
    };

}
#endif /* _TETON_PRIMITIVEREADRESULT_H_ */
