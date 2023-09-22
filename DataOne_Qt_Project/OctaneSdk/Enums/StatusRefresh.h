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

#ifndef _TETON_STATUSREFRESH_H_
#define _TETON_STATUSREFRESH_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Advise <see cref="SpeedwayReader.QueryStatus(Impinj.OctaneSdk.StatusRefresh)"/>
    /// what should be retrieved from the reader.
    /// </summary>
    /// <remarks>
    /// A StatusRefresh value is passed to SpeedwayReader.QueryStatus.
    /// Status is normally maintained internally and updated
    /// based on event notifications from the reader.
    /// Sometimes the application needs to make
    /// sure the status is refreshed from the actual reader.
    /// When QueryStatus must interact with the reader it takes
    /// longer (runs slower), especially when checking antenna status.
    /// </remarks>
    enum StatusRefresh
    {
        /// <summary>
        /// Return internally maintained status,
        /// do not check the reader.
        /// This is fastest.
        /// </summary>
        StatusRefresh_None,
        /// <summary>
        /// Refresh all status information from the reader.
        /// This causes several transactions with the reader.
        /// This level of refresh takes longer than all others.
        /// </summary>
        StatusRefresh_Everything,
        /// <summary>
        /// Refresh just the antenna status from the reader.
        /// This can take a substantial fraction of a second
        /// because the reader must apply power to each antenna
        /// port in order to test the antenna and its connection.
        /// </summary>
        StatusRefresh_JustAntennas,
        /// <summary>
        /// Refresh just the General Purpose Input (GPI) status
        /// from the reader.
        /// This is necessary for GPIs that are not enabled and,
        /// therefor, the reader does not send notifications
        /// when the input changes.
        /// </summary>
        StatusRefresh_JustGpis,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    StatusRefreshEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    StatusRefreshToString (
      StatusRefresh                 value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryStatusRefreshFromString (
      char *                        str,
      StatusRefresh *               outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsStatusRefreshValid (
      StatusRefresh                 value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_STATUSREFRESH_H_ */
