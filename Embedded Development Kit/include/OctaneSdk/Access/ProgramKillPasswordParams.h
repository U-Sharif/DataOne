/*
 *****************************************************************************
 *                                                                           *
 *                 IMPINJ CONFIDENTIAL AND PROPRIETARY                       *
 *                                                                           *
 * This source code is the sole property of Impinj, Inc.  Reproduction or    *
 * utilization of this source code in whole or in part is forbidden without  *
 * the prior written consent of Impinj, Inc.                                 *
 *                                                                           *
 * (c) Copyright Impinj, Inc. 2010. All rights reserved.                     *
 *                                                                           *
 *****************************************************************************
 */

#ifndef _TETON_PROGRAMKILLPASSWORDPARAMS_H_
#define _TETON_PROGRAMKILLPASSWORDPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ProgramKillPassword operation
    /// </summary>
    class ProgramKillPasswordParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// The new kill password (change to) for the tag.
        /// </summary>
        /// <remarks>
        /// In C1G2, settings a tag with a zero (00000000)
        /// kill password cannot be killed.  The kill password
        /// string must contain 8 hexidecimal characters
        /// ( i.e. [0-9a-fA-f])
        /// </remarks>
        string NewKillPassword;

        /// <summary>
        /// Verify the kill password program operation with a read
        /// </summary>
        bool IsWriteVerified;

        /// <summary>
        /// use block write to write the new kill password
        /// </summary>
        bool IsBlockWriteUsed;

        /// <summary>
        /// If block write is used above, specifies the size of the
        /// block
        /// </summary>
        int BlockWriteWordCount;

        /// <summary>
        /// sets theh lock status for the kill password memory after the program
        /// </summary>
        enum LockType LockType;

        /// <summary>
        /// Initializes a new instance of the ProgramKillPasswordParams class
        /// </summary>
        ProgramKillPasswordParams();

        /// <summary>
        /// Initializes a new instance of the ProgramKillPasswordParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        ProgramKillPasswordParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ProgramKillPasswordParams class
        /// (copy constructor)
        /// </summary>
        ProgramKillPasswordParams(const ProgramKillPasswordParams & programKillPasswordParams);
    };
}

#endif /* _TETON_PROGRAMKILLPASSWORDPARAMS_H_ */

