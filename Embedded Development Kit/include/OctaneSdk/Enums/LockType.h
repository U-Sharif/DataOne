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

#ifndef _TETON_LOCKTYPE_H_
#define _TETON_LOCKTYPE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// This enumeration conveys the lock state of the memory block on the tag.
    /// </summary>
    /// <remarks>
    /// For more information on tag lock state, see the
    /// EPCglobal C1G2 Specification.
    /// When a memory block is PermaLocked, it can never be unlocked.
    /// When a memory block is PermaUnlocked, it can never be locked.
    /// </remarks>
    enum LockType
    {
        /// <summary>
        /// The lock type is unknown.
        /// </summary>
        /// <remarks>During set commands, this conveys that the
        /// lock state should not be changed</remarks>
        LockType_None,
        /// <summary>
        /// Tag memory is locked.  Writing of this memory requires the tag
        /// acccess password
        /// </summary>
        LockType_Unlocked,
        /// <summary>
        /// Tag memory is unlocked.  Writing of this memory is permitted without
        /// the tag access password.
        /// </summary>
        LockType_Locked,
        /// <summary>
        /// Tag memory is unlocked permanently and can not be locked in the future
        /// </summary>
        LockType_PermaUnlocked,
        /// <summary>
        /// Tag memory is locked permanently and can not be unlocked in the future
        /// </summary>
        LockType_PermaLocked,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    LockTypeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    LockTypeToString (
      LockType                      value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryLockTypeFromString (
      char *                        str,
      LockType *                    outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsLockTypeValid (
      LockType                      value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LOCKTYPE_H_ */
