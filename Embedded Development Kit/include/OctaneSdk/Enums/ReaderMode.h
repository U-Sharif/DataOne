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

#ifndef _TETON_READERMODE_H_
#define _TETON_READERMODE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// A reader mode controls the bit rates, modulation, and other air
    /// protocol particulars.
    /// </summary>
    /// <remarks>
    /// Not all modes are available on all models or in all regions.
    /// As a rule, higher data rates are more
    /// susceptibility to and source of interference.
    /// Lower data rates cause less intereference and are more tolerant.
    /// </remarks>
    enum ReaderMode
    {
        /// <summary>
        /// The reader automatically optimizes singulation
        /// and data rates in environments with many
        /// RFID readers.
        /// </summary>
        ReaderMode_AutoSetDenseReader      = 1000,
        /// <summary>
        /// The reader automatically optimizes singulation
        /// and data rates in environments with one
        /// or very few well separated RFID readers.
        /// </summary>
        ReaderMode_AutoSetSingleReader     = 1001,
        /// <summary>
        /// The reader will use the mode with the highest
        /// potential throughput
        /// regardless of interference
        /// </summary>
        /// <remarks>This may not yield the highest tag read
        /// rate as interference potential is much greater with this
        /// mode</remarks>
        ReaderMode_MaxThroughput           = 0,
        /// <summary>
        ///
        /// </summary>
        ReaderMode_Hybrid                  = 1,
        /// <summary>
        /// A mode that uses a Miller sub-carrier to isolate tag and reader
        /// communications in frequency allowing multiple readers to
        /// operate in close proximity
        /// </summary>
        ReaderMode_DenseReaderM4           = 2,
        /// <summary>
        /// A mode similar to DenseReaderM4 which uses a lower data rate
        /// and further separates the tag and reader communications
        /// frequencies
        /// </summary>
        ReaderMode_DenseReaderM8           = 3,
        /// <summary>
        /// A mode similar to DenseReaderM4 which uses a higher data rate
        /// and minimally separates the tag and reader communications
        /// frequencies
        /// </summary>
        ReaderMode_MaxMiller               = 4,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    ReaderModeEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    ReaderModeToString (
      ReaderMode                    value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryReaderModeFromString (
      char *                        str,
      ReaderMode *                  outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsReaderModeValid (
      ReaderMode                    value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_READERMODETYPE_H_ */
