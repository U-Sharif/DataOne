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

#ifndef _TETON_TAGFILTEROP_H_
#define _TETON_TAGFILTEROP_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Individual tag filters define a particular memory pattern
    /// within a tag's memory. When a tag with that particular memory
    /// pattern is seen, whether that tag is reported by the reader is
    /// determined by this enumeration.
    /// </summary>
    enum TagFilterOp
    {
        /// <summary>
        /// This is an invalid value and is used to identify
        /// uninitialized object properties of this type.
        /// </summary>
        TagFilterOp_None,
        /// <summary>
        /// When a tag is seen with memory content matching the
        /// information found in the filter, the tag should be
        /// reported by the reader.
        /// </summary>
        TagFilterOp_Match,
        /// <summary>
        /// When a tag is seen with memory content not matching the
        /// information found in the filter, the tag should be
        /// reported by the reader.
        /// </summary>
        TagFilterOp_NotMatch,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    TagFilterOpEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    TagFilterOpToString (
      TagFilterOp                   value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryTagFilterOpFromString (
      char *                        str,
      TagFilterOp *                 outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsTagFilterOpValid (
      TagFilterOp                   value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TAGFILTEROP_H_ */
