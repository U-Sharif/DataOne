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

#ifndef _TETON_QTACCESSRANGE_H_
#define _TETON_QTACCESSRANGE_H_ 

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Defines the access range settings for the Impinj QT tag command
    /// </summary>
    enum QtAccessRange
    {
        /// <summary>
        /// Access range setting is unknown
        /// </summary>
        QtAccessRange_Unknown,
        /// <summary>
        /// Tag access can take place at normal range.
        /// </summary>
        QtAccessRange_NormalRange,
        /// <summary>
        /// Tag access can only occur at short range.
        /// </summary>
        /// <remarks>Inventory will still happen at normal range.
        /// </remarks>
        QtAccessRange_ShortRange,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    QtAccessRangeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    QtAccessRangeToString (
      QtAccessRange                 value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryQtAccessRangeFromString (
      char *                        str,
      QtAccessRange *               outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsQtAccessRangeValid (
      QtAccessRange                 value);

}
#endif /* _TETON_QTACCESSRANGE_H_ */
