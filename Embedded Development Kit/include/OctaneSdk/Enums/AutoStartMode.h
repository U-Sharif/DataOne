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

#ifndef _TETON_AUTOSTARTMODE_H_
#define _TETON_AUTOSTARTMODE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// This enumeration defines the various modes in which the reader
    /// starts scanning for tags automatically.
    /// </summary>
    /// <remarks>
    /// When the reader is configured to operate autonomously (without
    /// application intervention), it can start scanning for tags
    /// based on some outside trigger. This enumeration defines those
    /// various triggers.
    /// </remarks>
    enum AutoStartMode
    {
        /// <summary>
        /// Do not start scanning for tags automatically. The reader
        /// will only start scanning if the application invokes the
        /// Start method of the Reader class. This is the default
        /// behavior.
        /// </summary>
        AutoStartMode_None,

        /// <summary>
        /// Start scanning for tags immediately. The reader will start
        /// scanning for tags immediately after the Settings object is
        /// applied to the reader via the ChangeSettings method of the
        /// Reader class.
        /// </summary>
        AutoStartMode_Immediate,

        /// <summary>
        /// Start scanning when a general-purpose input (GPI) changes
        /// state (either a logic high or a logic low). GPIs are
        /// numbered 1-4 and may vary in number by reader model.
        /// </summary>
        AutoStartMode_GpiTrigger,

        /// <summary>
        /// Start scanning for tags periodically. The reader will
        /// automatically start scanning after a specified duration.
        /// Note that this mode is typically associated with an
        /// auto-stop mode.
        /// </summary>
        AutoStartMode_Periodic,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    AutoStartModeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    AutoStartModeToString (
      AutoStartMode                 value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryAutoStartModeFromString (
      char *                        str,
      AutoStartMode *               outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsAutoStartModeValid (
      AutoStartMode                 value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_AUTOSTARTMODE_H_ */
