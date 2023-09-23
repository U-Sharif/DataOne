#ifndef _TETON_PROGRAMACCESSPASSWORDPARAMS_H_
#define _TETON_PROGRAMACCESSPASSWORDPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ProgramAccessPassword operation
    /// </summary>
    class ProgramAccessPasswordParams : public CommonAccessParams
    {
      public:

        /// <summary>
        /// The new access password (change to) for the tag.
        /// </summary>
        /// <remarks>
        /// In C1G2, settings the password string to 00000000
        /// will turn off protected accesss and let all users
        /// access the tag
        /// </remarks>
        string NewAccessPassword;

        /// <summary>
        /// Verify the write operation with a read
        /// </summary>
        bool IsWriteVerified;

        /// <summary>
        /// use block write to write the new password value
        /// </summary>
        bool IsBlockWriteUsed;

        /// <summary>
        /// If block write is used above, specifies the size of the
        /// block
        /// </summary>
        int BlockWriteWordCount;

        /// <summary>
        /// sets theh lock status for the access password
        /// </summary>
        enum LockType LockType;

        /// <summary>
        /// Initializes a new instance of the ProgramAccessPasswordParams class
        /// </summary>
        ProgramAccessPasswordParams();

        /// <summary>
        /// Initializes a new instance of the ProgramAccessPasswordParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        ProgramAccessPasswordParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ProgramAccessPasswordParams class
        /// (copy constructor)
        /// </summary>
        ProgramAccessPasswordParams(const ProgramAccessPasswordParams & programAccessPasswordParams);
    };
}

#endif /* _TETON_PROGRAMACCESSPASSWORDPARAMS_H_ */ 
