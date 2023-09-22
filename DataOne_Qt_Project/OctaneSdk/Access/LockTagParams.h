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

#ifndef _TETON_LOCKTAGPARAMS_H_
#define _TETON_LOCKTAGPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a SpeedwayReader.LockTag
    /// operation
    /// </summary>
    /// <remarks>
    /// Constructors set asll Lock variables below to LockType_None
    /// </remarks>
    class LockTagParams : public CommonAccessParams 
    {
      public:
        /// <summary>
        /// The LockType for the access password of the tag
        /// </summary>
        LockType LockAccessPassword;

        /// <summary>
        /// The LockType for the kill password of the tag
        /// </summary>
        LockType LockKillPassword;

        /// <summary>
        /// The LockType for the Epc memory region of the tag
        /// </summary>
        LockType LockEpcMemory;

        /// <summary>
        /// The LockType for the TID (Tag ID) memory region of the tag
        /// </summary>
        LockType LockTidMemory;

        /// <summary>
        /// The LockType for the user memory region of the tag
        /// </summary>
        LockType LockUserMemory;

        /// <summary>
        /// Initializes a new instance of the LockTagParams class
        /// </summary>
        LockTagParams();

        /// <summary>
        /// Initializes a new instance of the LockTagParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        LockTagParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the LockTagParams class
        /// (copy constructor)
        /// </summary>
        LockTagParams(const LockTagParams & lockTagParams);

    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LOCKTAGPARAMS_H_ */
