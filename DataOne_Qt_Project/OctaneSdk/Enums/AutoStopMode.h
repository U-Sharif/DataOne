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

#ifndef _TETON_AUTOSTOPMODE_H_
#define _TETON_AUTOSTOPMODE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// This enumeration defines the various modes in which the reader
    /// stops scanning for tags automatically.
    /// </summary>
    /// <remarks>
    /// When the reader is configured to operate autonomously (without
    /// application intervention), it can stop scanning for tags based
    /// on some outside trigger. This enumeration defines those
    /// various triggers.
    /// </remarks>
    enum AutoStopMode
    {
        /// <summary>
        /// Do not stop scanning for tags once a scan has started. The
        /// reader will only stop scanning if the application invokes
        /// the Stop method of the Reader class. This is the default
        /// behavior.
        /// </summary>
        AutoStopMode_None,
        /// <summary>
        /// Stop scanning when a general-purpose input (GPI) changes
        /// state (either a logic high or a logic low). GPIs are
        /// numbered 1-4 and may vary in number by reader model.
        /// </summary>
        AutoStopMode_GpiTrigger,
        /// <summary>
        /// Stop scanning after a specific duration has elapsed since
        /// the scan first started.
        /// </summary>
        AutoStopMode_Duration,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    AutoStopModeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    AutoStopModeToString (
      AutoStopMode                  value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryAutoStopModeFromString (
      char *                        str,
      AutoStopMode *                outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsAutoStopModeValid (
      AutoStopMode                  value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_AUTOSTOPMODE_H_ */
