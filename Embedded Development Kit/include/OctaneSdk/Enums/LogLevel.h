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

#ifndef _TETON_LOGLEVEL_H_
#define _TETON_LOGLEVEL_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// The level (severity) of a log message.
    /// </summary>
    /// <remarks>
    /// This level is used in log messages such as those
    /// recorded by <see cref="SpeedwayReader.Log"/>.
    /// It is also used as a threshold
    /// in <see cref="SpeedwayReader.LogLevel"/>
    /// for delivering log messages to the application using
    /// <see cref="SpeedwayReader.OnLogging"/>.
    /// </remarks>
    enum LogLevel
    {
        /// <summary>
        /// Only used in <see cref="SpeedwayReader.LogLevel"/> to
        /// turn all log messages off.
        /// </summary>
        LogLevel_Off,
        /// <summary>
        /// An error occured and the desired action could
        /// not be done.
        /// </summary>
        LogLevel_Error,
        /// <summary>
        /// Something was not quite right but the
        /// desired action was done.
        /// </summary>
        LogLevel_Warning,
        /// <summary>
        /// The log message is information about a significant
        /// and successful event. Exampe: the reader
        /// connection being established.
        /// </summary>
        LogLevel_Information,
        /// <summary>
        /// Detailed information that is useful when troubleshooting.
        /// This generally shows internal steps to carry out a
        /// desired action.
        /// </summary>
        LogLevel_Verbose,
        /// <summary>
        /// Extra detailed information that is useful when
        /// troubleshooting. This generally shows internal methods
        /// used to carry out a desired action.
        /// </summary>
        LogLevel_Trace,
        /// <summary>
        /// Used for the LTKXML of all message sent to
        /// or received from the reader. Such messages
        /// are quite large.
        /// </summary>
        LogLevel_Debug,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    LogLevelEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
   extern const char *
    LogLevelToString (
      LogLevel                      value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryLogLevelFromString (
      char *                        str,
      LogLevel *                    outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsLogLevelValid (
      LogLevel                      value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LOGLEVEL_H_ */
