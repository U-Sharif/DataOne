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

#ifndef _TETON_PROGRAMEPCPARAMS_H_
#define _TETON_PROGRAMEPCPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the configuration for a SpeedwayReader.ProgramEpc
    /// operation
    /// </summary>
    class ProgramEpcParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// The epc value to program as a string of hex values
        /// </summary>
        /// <remarks>
        /// The string consists of hexidecimal characters (i.e.
        /// [0-9a-fA-F]). The string must contain a multiple of
        /// 4 hexadecimal characters to enforce the 16-bit
        /// resolution of C1G2 epcs. A maximum length of 124
        /// hexadecimal characters (496 bits) is permitted in
        /// the OctaneSDK and the C1G2 specification.  NOTE:
        /// not all tags contain 496 bits of EPC memory.s
        /// </remarks>
        string NewEpc;

        /// <summary>
        /// Verify the program operation with a read
        /// </summary>
        bool IsWriteVerified;

        /// <summary>
        /// use block write to write the new EPCs
        /// </summary>
        bool IsBlockWriteUsed;

        /// <summary>
        /// If block write is used above, specifies the size of the
        /// block
        /// </summary>
        int BlockWriteWordCount;

        /// <summary>
        /// sets theh lock status for the EPC memory bank after the program
        /// </summary>
        enum LockType LockType;

        /// <summary>
        /// Initializes a new instance of the ProgramEpcParams class
        /// </summary>
        ProgramEpcParams();

        /// <summary>
        /// Initializes a new instance of the ProgramEpcParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        ProgramEpcParams(const CommonAccessParams & commonAccessParams);
        
        /// <summary>
        /// Initializes a new instance of the ProgramEpcParams class
        /// (copy constructor)
        /// </summary>
        ProgramEpcParams(const ProgramEpcParams & programEpcParams);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_PROGRAMEPCPARAMS_H_ */
