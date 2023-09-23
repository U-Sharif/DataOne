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
#ifndef _TETON_QTDATAPROFILE_H_
#define _TETON_QTDATAPROFILE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Defines the data profile for Impinj silicon implementing the QT
    /// features set
    /// </summary>
    /// <remarks>QT allows the tag to have a dual memory layout.
    /// These two layouts are called public and private. </remarks>
    enum QtDataProfile
    {
        /// <summary>
        /// The tag QT data profile is not known
        /// </summary>
        QtDataProfile_Unknown,
        /// <summary>
        /// The tag QT data profile is private.  See the Impinj QT
        /// documentation for tag memory layout in the private profile
        /// </summary>
        QtDataProfile_Private,
        /// <summary>
        /// The tag QT data profile is public.  See the Impinj QT
        /// documentation for tag memory layout in the public profile
        /// </summary>
        QtDataProfile_Public,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    QtDataProfileEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    QtDataProfileToString (
      QtDataProfile                 value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryQtDataProfileFromString (
      char *                        str,
      QtDataProfile *               outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsQtDataProfileValid (
      QtDataProfile                 value);

}
#endif /*  _TETON_QTDATAPROFILE_H_ */
