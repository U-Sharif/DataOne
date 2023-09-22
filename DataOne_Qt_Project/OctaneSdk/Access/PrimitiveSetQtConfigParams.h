#ifndef _TETON_PRIMITIVESETQTCONFIGPARAMS_H_
#define _TETON_PRIMITIVESETQTCONFIGPARAMS_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for setting QT configuration
    ///  on a tag
    /// </summary>
    class PrimitiveSetQtConfigParams : public PrimitiveParams
    {
      public:
        /// <summary>
        /// The desired data profile of the tag
        /// </summary>
        /// <remarks>A value of QtDataProfile.Unknown is not permitted</remarks>
        QtDataProfile DataProfile;

        /// <summary>
        /// The desired access range setting of the tag
        /// </summary>
        /// <remarks>A value of QtAccessRange.Unknown is not permitted</remarks>
        QtAccessRange AccessRange;

        /// <summary>
        /// The desired persistence setting.
        /// </summary>
        /// <remarks>A value of QtPersistence.Unknown is not permitted</remarks>
        QtPersistence Persistence;

        /// <summary>
        /// Construct a PrimitiveSetQtConfigParams instance
        /// </summary>
        PrimitiveSetQtConfigParams();

        /// <summary>
        /// Construct a PrimitiveSetQtConfigParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveSetQtConfigParams(const PrimitiveSetQtConfigParams & primitiveSetQtConfigParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveParams</returns>
        PrimitiveParams * Clone();
    };

}
#endif /* _TETON_PRIMITIVESETQTCONFIGPARAMS_H_ */
