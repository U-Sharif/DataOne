#ifndef _TETON_PRIMITIVEGETQTCONFIGRESULT_H_
#define _TETON_PRIMITIVEGETQTCONFIGRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the GetQtConfigResults
    /// results.
    /// </summary>
    class PrimitiveGetQtConfigResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the get QT config primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// The current data profile of the tag
        /// </summary>
        QtDataProfile DataProfile;

        /// <summary>
        /// The current access range setting of the tag
        /// </summary>
        QtAccessRange AccessRange;

        /// <summary>
        /// The current persistence setting.
        /// </summary>
        /// <remarks>When gettings results, persistence may be
        /// returned as QtPersistence.None</remarks>
        QtPersistence Persistence;

        /// <summary>
        /// Construct a PrimitiveGetQtConfigResult instance
        /// </summary>
        PrimitiveGetQtConfigResult();

        /// <summary>
        /// Construct a PrimitiveGetQtConfigResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveGetQtConfigResult(const PrimitiveGetQtConfigResult & primitiveGetQtConfigResult);
        
        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveGetQtConfigResult</returns>
        PrimitiveResult * Clone();
    };
}
#endif /* _TETON_PRIMITIVEGETQTCONFIGRESULT_H_ */
