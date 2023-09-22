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
#ifndef _TETON_PROGRAMUSERBLOCKPARAMS_H_
#define _TETON_PROGRAMUSERBLOCKPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ProgramUserBlock operation
    /// </summary>
    class ProgramUserBlockParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// The offset in words (16-bits) within the memory bank
        /// to begin programming
        /// </summary>
        int WordPointer;

        /// <summary>
        /// A hexidecimal string representing the data to program.
        /// </summary>
        /// <remarks>
        /// This string must be a multiple of 4 hexadecimal characters.
        /// The string cannot be longer than the Constants.MaxWriteWordCount
        /// words (with 4 hexadecimal characters per word).
        /// </remarks>
        string NewUserBlock;

        /// <summary>
        /// Verify the user block program operation with a read
        /// </summary>
        bool IsWriteVerified;

        /// <summary>
        /// use block write to write the new user block
        /// </summary>
        bool IsBlockWriteUsed;

        /// <summary>
        /// If block write is used above, specifies the size of the
        /// block
        /// </summary>
        int BlockWriteWordCount;

        /// <summary>
        /// sets theh lock status for the block after the program
        /// </summary>
        enum LockType LockType;

        /// <summary>
        /// The block to lock when lock type is set to LockType.PermaLocked
        /// </summary>
        int BlockNumber;

        /// <summary>
        /// Initializes a new instance of the ProgramUserBlockParams class
        /// </summary>
        ProgramUserBlockParams();

        /// <summary>
        /// Initializes a new instance of the ProgramUserBlockParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        ProgramUserBlockParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ProgramUserBlockParams class
        /// (copy constructor)
        /// </summary>
        ProgramUserBlockParams(const ProgramUserBlockParams & programUserBlockParams);
    };

}


#endif /* _TETON_PROGRAMUSERBLOCKPARAMS_H_ */
