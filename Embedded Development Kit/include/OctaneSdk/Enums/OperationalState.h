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

#ifndef _TETON_OPERATIONALSTATE_H_
#define _TETON_OPERATIONALSTATE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Indicates the status of the reader's RFID operations.
    /// </summary>
    /// <remarks>
    /// The <see cref="Status"/> returned by
    /// <see cref="SpeedwayReader.QueryStatus(Impinj.OctaneSdk.StatusRefresh)"/>
    /// contains the state of RFID operations.
    /// </remarks>
    enum OperationalState
    {
        /// <summary>
        /// The operational state is
        /// not known. This usually means that communication
        /// with the reader is not established.
        /// </summary>
        OperationalState_Unknown,
        /// <summary>
        /// The reader has no <see cref="Settings"/>.
        /// </summary>
        OperationalState_NotSet,
        /// <summary>
        /// There are settings on the reader that
        /// are not from Octane SDK. Usually means
        /// some other application left settings
        /// on the reader.
        /// Use <see cref="SpeedwayReader.ClearSettings"/>.
        /// </summary>
        OperationalState_ForeignSettings,
        /// <summary>
        /// The reader has <see cref="Settings"/>
        /// and is idle.
        /// No power is emitted by the antennas.
        /// </summary>
        OperationalState_Ready,
        /// <summary>
        /// The reader is singulating.
        /// Power is emitted by the enabled antennas.
        /// </summary>
        OperationalState_Singulating,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    OperationalStateEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    OperationalStateToString (
      OperationalState              value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryOperationalStateFromString (
      char *                        str,
      OperationalState *            outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsOperationalStateValid (
      OperationalState              value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_OPERATIONALSTATE_H_ */
