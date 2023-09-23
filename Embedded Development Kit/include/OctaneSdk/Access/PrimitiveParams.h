#ifndef _TETON_PRIMITIVEPARAMS_H_
#define _TETON_PRIMITIVEPARAMS_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The base class for carrying parameters for all primitive tag
    /// access operations
    /// </summary>
    class PrimitiveParams
    {
      public:
        /// <summary>
        /// Default destructor
        /// </summary>
        virtual ~PrimitiveParams(){};
        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveParams</returns>
        virtual PrimitiveParams * Clone() = 0;
    };
}
#endif /* _TETON_PRIMITIVEPARAMS_H_ */
