#ifndef _TETON_PRIMITIVEREADPARAMS_H_
#define _TETON_PRIMITIVEREADPARAMS_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for reading memory on a tag
    /// </summary>
    class PrimitiveReadParams : public PrimitiveParams
    {
      public:
        /// <summary>
        /// The tag memory bank to read from
        /// </summary>
        enum MemoryBank MemoryBank;

        /// <summary>
        /// The offset within the memory bank to start the read
        /// </summary>
        /// <remarks>Must be greater than or equal to zero
        /// </remarks>
        int WordPointer;

        /// <summary>
        /// The number of words to read
        /// </summary>
        /// <remarks>Must be greater than zero and
        /// less than or equal to <see cref="Constants.MaxReadWordCount"/>
        /// </remarks>
        int WordCount;

        /// <summary>
        /// construct a PrimitiveReadParams instance
        /// </summary>
        PrimitiveReadParams();

        /// <summary>
        /// construct a PrimitiveReadParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveReadParams(const PrimitiveReadParams & primitiveReadParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveParams</returns>
        PrimitiveParams * Clone();
    };
}
#endif /* _TETON_PRIMITIVEREADPARAMS_H_ */
