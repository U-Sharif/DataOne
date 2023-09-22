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

#ifndef _TETON_APPLICATIONCONNECTIONSTATE_H_
#define _TETON_APPLICATIONCONNECTIONSTATE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Indicates the status of the network connected between
    /// the application and the reader.
    /// </summary>
    /// <remarks>
    /// The <see cref="Status"/> returned by
    /// <see cref="SpeedwayReader.QueryStatus(Impinj.OctaneSdk.StatusRefresh)"/>,
    /// the ConnectionChangedEventArgs, and OctaneConnectException
    /// indicate the status of the LLRP connection or a connection
    /// attempt.
    /// </remarks>
    enum ApplicationConnectionState
    {
        /// <summary>
        /// There is no current LLRP connection.
        /// </summary>
        ApplicationConnectionState_NotConnected,
        /// <summary>
        /// There is a good LLRP connection.
        /// </summary>
        ApplicationConnectionState_Connected,
        /// <summary>
        /// The connection was ended by the application's call
        /// to SpeedwayReader.Disconnect.
        /// This value only appears in ConnectionChangedEventArgs.
        /// </summary>
        ApplicationConnectionState_Disconnected,
        /// <summary>
        /// The connection was unexpectedely lost. The connection
        /// persists in this state until SpeedwayReader.Disconnect
        /// is called.
        /// </summary>
        ApplicationConnectionState_ConnectionLost,
        /// <summary>
        /// An attempt to connect to the reader using
        /// SpeedwayReader.Connect failed because the
        /// reader name could not be looked up or because
        /// the reader did not respond to the connection
        /// request.
        /// This usually means that the name or address
        /// given to Connect is invalid.
        /// This value only appears in ConnectionChangedEventArgs and
        /// OctaneConnectException.
        /// </summary>
        ApplicationConnectionState_FailedReaderNotOnNetwork,
        /// <summary>
        /// An attempt to connect to the reader using
        /// SpeedwayReader.Connect failed because the
        /// reader is already connected to another application.
        /// There was a very brief LLRP connection to receive
        /// this status.
        /// This value only appears in ConnectionChangedEventArgs and
        /// OctaneConnectException.
        /// </summary>
        ApplicationConnectionState_FailedReaderConnectedToAnother,
        /// <summary>
        /// An attempt to connect to the reader using
        /// SpeedwayReader.Connect failed for an unusual reason.
        /// This usually means there is something wrong with the
        /// reader and its best to log onto the reader with ssh
        /// or telnet and check the log.
        /// This value only appears in ConnectionChangedEventArgs and
        /// OctaneConnectException.
        /// </summary>
        ApplicationConnectionState_FailedReaderOtherReason
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    ApplicationConnectionStateEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    ApplicationConnectionStateToString (
      ApplicationConnectionState    value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryApplicationConnectionStateFromString (
      char *                        str,
      ApplicationConnectionState *  outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsApplicationConnectionStateValid (
      ApplicationConnectionState    value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_APPLICATIONCONNECTIONSTATE_H_ */
