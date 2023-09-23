#ifndef _TETON_PRIMITIVEKILLPARAMS_H_ 
#define _TETON_PRIMITIVEKILLPARAMS_H_ 
namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for killing a tag
    /// </summary>
    class PrimitiveKillParams : public PrimitiveParams
    {
      public:
        /// <summary>
        /// The current kill password on the tag
        /// </summary>
        /// <remarks>The tag cannot be killed if the password is
        /// not known.  A tag with a zero password cannot be killed</remarks>
        string KillPassword;

        /// <summary>
        /// Construct a PrimitiveKillParams instance
        /// </summary>
        PrimitiveKillParams();

        /// <summary>
        /// Construct a PrimitiveKillParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveKillParams(const PrimitiveKillParams & primitiveKillParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>a new PrimitiveParams instance</returns>
        PrimitiveParams * Clone();
    };
}
#endif /* _TETON_PRIMITIVEKILLPARAMS_H_ */
