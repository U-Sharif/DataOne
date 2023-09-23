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

#ifndef _TETON_TAGFILTERMODE_H_
#define _TETON_TAGFILTERMODE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// This enumeration defines how the two individual filters within
    /// the reader's filter settings are combined.
    /// </summary>
    enum TagFilterMode
    {
        /// <summary>
        /// This is an invalid value and is used to identify
        /// uninitialized object properties of this type.
        /// </summary>
        TagFilterMode_None,
        /// <summary>
        /// Only the information contained within the TagFilter1
        /// property will be used to identify the target tag
        /// population.
        /// </summary>
        TagFilterMode_OnlyFilter1,
        /// <summary>
        /// The target tag population are tags that match both
        /// TagFilter1 AND TagFilter2.
        /// </summary>
        TagFilterMode_Filter1AndFilter2,
        /// <summary>
        /// The target tag population are tags that match either
        /// TagFilter1 OR TagFilter2.
        /// </summary>
        TagFilterMode_Filter1OrFilter2,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    TagFilterModeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    TagFilterModeToString (
      TagFilterMode                 value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryTagFilterModeFromString (
      char *                        str,
      TagFilterMode *               outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsTagFilterModeValid (
      TagFilterMode                 value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TAGFILTERMODE_H_ */
