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
#ifndef _TETON_PROGRAMUSERMEMORYPARAMS_H_
#define _TETON_PROGRAMUSERMEMORYPARAMS_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ProgramUserMemory operation
    /// </summary>
    class ProgramUserMemoryParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// A hexidecimal string representing the data to program.
        /// </summary>
        /// <remarks>
        /// This string must be a multiple of 4 hexadecimal characters.
        /// The string cannot be longer than the Constants.MaxWriteWordCount
        /// words (with 4 hexadecimal characters per word).
        /// </remarks>
        string NewUserMemory;

        /// <summary>
        /// Verify the user memory program operation with a read
        /// </summary>
        bool IsWriteVerified;

        /// <summary>
        /// Use block write to write the user memory
        /// </summary>
        bool IsBlockWriteUsed;

        /// <summary>
        /// If block write is used above, specifies the size of the
        /// block
        /// </summary>
        int BlockWriteWordCount;

        /// <summary>
        /// Sets theh lock status for the user memory after the program
        /// </summary>
        enum LockType LockType;

        /// <summary>
        /// Initializes a new instance of the ProgramUserMemoryParams class
        /// </summary>
        ProgramUserMemoryParams();

        /// <summary>
        /// Initializes a new instance of the ProgramUserMemoryParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams"></param>
        ProgramUserMemoryParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ProgramUserMemoryParams class
        /// (copy constructor)
        /// </summary>
        ProgramUserMemoryParams(const ProgramUserMemoryParams & programUserMemoryParams);
    };
}
#endif /* _TETON_PROGRAMUSERMEMORYPARAMS_H_ */
