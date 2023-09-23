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

#ifndef _TETON_REPORTINGMODE_H_
#define _TETON_REPORTINGMODE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Specifies when the reader sends tag reports.
    /// </summary>
    /// <remarks>
    /// The reader can always be queried for tags using
    /// <see cref="SpeedwayReader.QueryTags(int)"/>
    /// even while singulating.
    /// </remarks>
    enum ReportMode
    {
        /// <summary>
        /// Tag reports are only sent when
        /// <see cref="SpeedwayReader.QueryTags(int)"/>
        /// is called.
        /// </summary>
        ReportMode_WaitForQuery,
        /// <summary>
        /// Send a tag report for each individual tag.
        /// Tag reports are buffered for up to 250ms
        /// to maintain network efficiency.
        /// Use this report mode when information about
        /// each singulation is needed.
        /// </summary>
        ReportMode_Individual,
        /// <summary>
        /// Send a tag report for each individual tag.
        /// The tag report is transmitted over the network
        /// immediately.
        /// This report mode uses the most network bandwidth.
        /// </summary>
        ReportMode_IndividualUnbuffered,
        /// <summary>
        /// Send a tag report when the reader stops singulating.
        /// The report contains information about each tag
        /// singulated since the reader started.
        /// The report does not contain information about
        /// each singulation.
        /// </summary>
        ReportMode_BatchAfterStop,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    ReportModeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    ReportModeToString (
      ReportMode                    value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryReportModeFromString (
      char *                        str,
      ReportMode *                  outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsReportModeValid (
      ReportMode                    value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_REPORTINGMODE_H_ */
