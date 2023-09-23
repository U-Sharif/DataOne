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

#ifndef _TETON_LOGORIGIN_H_
#define _TETON_LOGORIGIN_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// The origin of a situation that resulted in a log message.
    /// This gives a clue of where to investigate issues.
    /// </summary>
    /// <remarks>
    /// This origin is used in log messages generated
    /// withing the Octane SDK.
    /// </remarks>
    enum LogOrigin
    {
        /// <summary>
        /// Unknown or unspecific origin.
        /// </summary>
        LogOrigin_Unknown,
        /// <summary>
        /// There is a problem with the user's input.
        /// Reserved to the application developer.
        /// </summary>
        LogOrigin_UserInput,      // Reserved to apps developer
        /// <summary>
        /// The application generated the log message.
        /// Reserved to the application developer.
        /// This is the origin used for messaged logged
        /// using <see cref="SpeedwayReader.Log"/>
        /// </summary>
        LogOrigin_Application,    // Reserved to apps developer
        /// <summary>
        /// There is a problem with an argument from
        /// the application to the Octane SDK.
        /// Examples: something in the <see cref="Settings"/>
        /// is incorrect or invalid port number to
        /// <see cref="SpeedwayReader.SetGpo"/>.
        /// </summary>
        LogOrigin_ApiInput,       // Bad Settings value, port in SetGpo(),
                                  // duration in QueryTags(), etc
        /// <summary>
        /// A settings file had a problem.
        /// </summary>
        LogOrigin_File,           // Bad/missing file
        /// <summary>
        /// Message concerns the Octane SDK internals.
        /// This is used, for example, by
        /// <see cref="LogLevel.Verbose"/> and
        /// <see cref="LogLevel.Trace"/> log messages.
        /// </summary>
        LogOrigin_OctaneSdkLibrary,  // Something hinky inside the SpeedwaySdk library
        /// <summary>
        /// The situation was detected by the LLRP Tool Kit (LTK).
        /// </summary>
        LogOrigin_LlrpToolKit,    // Error detected in or caused by LTK library
        /// <summary>
        /// Something on the platform (Windows, Linux, framework library, etc).
        /// </summary>
        LogOrigin_Platform,       // Windows, Linux, framework library, etc
        /// <summary>
        /// Reader detected or sent a bad or unexpected message.
        /// </summary>
        LogOrigin_Reader,         // Reader detected or sent a bad or unexpected message
        /// <summary>
        /// Catch-all for origins that do not match the other origins.
        /// </summary>
        LogOrigin_Other,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    LogOriginEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    LogOriginToString (
      LogOrigin                     value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryLogOriginFromString (
      char *                        str,
      LogOrigin *                   outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsLogOriginValid (
      LogOrigin                     value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LOGORIGIN_H_ */
