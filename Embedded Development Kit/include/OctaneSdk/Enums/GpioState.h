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

#ifndef _TETON_GPIOSTATE_H_
#define _TETON_GPIOSTATE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Indicates the status of an general purpose input (GPI) port.
    /// </summary>
    /// <remarks>
    /// The <see cref="Status"/> returned by
    /// <see cref="SpeedwayReader.QueryStatus(Impinj.OctaneSdk.StatusRefresh)"/>,
    /// contains status per each GPI port.
    /// </remarks>
    enum GpioState
    {
        /// <summary>
        /// The input level of a GPI port is
        /// not known. This usually means that communication
        /// with the reader is not established.
        /// </summary>
        GpioState_Unknown,
        /// <summary>
        /// There is no such GPI port on the reader.
        /// </summary>
        GpioState_NotApplicable,
        /// <summary>
        /// The GPI port is sensing an input low.
        /// </summary>
        GpioState_Low,
        /// <summary>
        /// The GPI port is sensing an input high.
        /// </summary>
        GpioState_High,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    GpioStateEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    GpioStateToString (
      GpioState                     value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryGpioStateFromString (
      char *                        str,
      GpioState *                   outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsGpioStateValid (
      GpioState                     value);

} /* namespace Impinj_OctaneSdk */

#endif /*  _TETON_GPIOSTATE_H_ */
