#ifndef _TETON_PRIMITIVERESULT_H_
#define _TETON_PRIMITIVERESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    ///  The base class for all tag access primitive results
    /// </summary>
    class PrimitiveResult
    {
      public:
        /// <summary>
        /// Default destructor
        /// </summary>
        virtual ~PrimitiveResult(){};
        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        virtual PrimitiveResult * Clone() = 0;
    };
}
#endif /* _TETON_PRIMITIVERESULT_H_ */
