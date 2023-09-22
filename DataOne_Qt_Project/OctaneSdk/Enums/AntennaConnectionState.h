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

#ifndef _TETON_ANTENNACONNECTIONSTATE_H_
#define _TETON_ANTENNACONNECTIONSTATE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Indicates the status of an antenna port.
    /// </summary>
    /// <remarks>
    /// The <see cref="Status"/> returned by
    /// <see cref="SpeedwayReader.QueryStatus(Impinj.OctaneSdk.StatusRefresh)"/>
    /// contains status per each antenna port.
    /// This enumeration indicates whether there is an
    /// antenna connected to the antenna port.
    /// </remarks>
    enum AntennaConnectionState
    {
        /// <summary>
        /// The connection status of the antenna port is
        /// not known. This usually means that communication
        /// with the reader is not established.
        /// </summary>
        AntennaConnectionState_Unknown,
        /// <summary>
        /// There is no such antenna port on the reader.
        /// </summary>
        AntennaConnectionState_NotApplicable,
        /// <summary>
        /// An antenna is connected to the antenna port.
        /// Note that a long cable with no antenna can be
        /// interpretted as a connected antenna. The best
        /// way to be certain of an antenna connection
        /// is to verify tags can be seen by the antenna.
        /// </summary>
        AntennaConnectionState_Connected,
        /// <summary>
        /// The antenna port exists but there is no antenna connected.
        /// </summary>
        AntennaConnectionState_NotConnected,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    AntennaConnectionStateEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    AntennaConnectionStateToString (
      AntennaConnectionState        value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryAntennaConnectionStateFromString (
      char *                        str,
      AntennaConnectionState *      outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsAntennaConnectionStateValid (
      AntennaConnectionState        value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_ANTENNACONNECTIONSTATE_H_ */
