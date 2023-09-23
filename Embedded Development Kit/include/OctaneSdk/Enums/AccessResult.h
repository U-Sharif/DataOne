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

#ifndef _TETON_ACCESSRESULT_H_
#define _TETON_ACCESSRESULT_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Defines the result codes for access operations.
    /// </summary>
    enum AccessResult
    {
        /// <summary>
        /// The default value when constructing objects with AccessResult
        /// elements.
        /// </summary>
        AccessResult_None,
        /// <summary>
        /// The access operation succeeded
        /// </summary>
        AccessResult_Success,
        /// <summary>
        /// An unspecified error occurred during the access operation
        /// </summary>
        AccessResult_Error,
        /// <summary>
        /// An interal library error occurred during the access operation
        /// </summary>
        AccessResult_InternalError,

        // Generic access errors
        /// <summary>
        /// An unexpected failure occurred when performing a block write access operation
        /// </summary>
        AccessResult_BlockWriteFailure,
        /// <summary>
        /// An unexpected failure occurred when getting the block permalock status.
        /// </summary>
        AccessResult_GetBlockPermalockFailure,
        /// <summary>
        /// An unexpected failure occurred when getting the tag Qt configuration
        /// </summary>
        AccessResult_GetQtConfigFailure,
        /// <summary>
        /// An unexpected failure occurred when performing a tag kill operation.
        /// </summary>
        AccessResult_KillFailure,
        /// <summary>
        /// An unexpected failure occurred when performing a tag lock operation.
        /// </summary>
        AccessResult_LockFailure,
        /// <summary>
        /// An unexpected failure occurred when performing a tag read operation.
        /// </summary>
        AccessResult_ReadFailure,
        /// <summary>
        /// An unexpected failure occurred when setting the block permalock status
        /// </summary>
        AccessResult_SetBlockPermalockFailure,
        /// <summary>
        /// An unexpected failure occurred when setting the tag Qt configuration
        /// </summary>
        AccessResult_SetQtConfigFailure,
        /// <summary>
        /// An unexpected failure occurred when performing a tag write operation.
        /// </summary>
        AccessResult_WriteFailure,
        /// <summary>
        /// The tag program operation succeeded but the verification failed
        /// </summary>
        AccessResult_WriteVerifyFailure,

        // Specific access errors
        /// <summary>
        /// The tag did not respond to the acccess operation
        /// </summary>
        AccessResult_NoResponseFromTag,
        /// <summary>
        /// The tag reported an error during this access operation,
        /// but the error was not specified.
        /// </summary>
        AccessResult_NonSpecificTagError,
        /// <summary>
        /// There was an unspecified reader error when performing this
        /// access operation
        /// </summary>
        AccessResult_NonSpecificReaderError,
        /// <summary>
        /// Attempt to access tag memory outside the available memory
        /// range defined on the tag.
        /// </summary>
        AccessResult_TagMemoryOverrun,
        /// <summary>
        /// Attempt to access tag memory that was locked.  This can occur
        /// if a write is attempted to a locked memory area
        /// </summary>
        AccessResult_TagMemoryLocked,
        /// <summary>
        /// There was insufficient power (at the tag) to perform the access
        /// operation.  NOTE: Some access operations (like write) require
        /// more power than an inventory operation. It's possible that your
        /// application can inventory the tag but will be unable to write the
        /// tag due to insufficient power
        /// </summary>
        AccessResult_InsufficientPower,
        /// <summary>
        /// The tag could not be killed because it has a zero
        /// kill password.  The EpcGlobal C1G2 specification
        /// requires that a tag have a non-zero kill password for
        /// the kill operation to succeed.
        /// </summary>
        AccessResult_ZeroKillPassword,
        /// <summary>
        /// The password provided for the tag was incorrect.
        /// </summary>
        AccessResult_IncorrectPassword,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    AccessResultEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    AccessResultToString (
      AccessResult                  value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryAccessResultFromString (
      char *                        str,
      AccessResult *                outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsAccessResultValid (
      AccessResult                  value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_ACCESSRESULT_H_ */
