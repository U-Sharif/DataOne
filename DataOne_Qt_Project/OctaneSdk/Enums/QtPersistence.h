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

#ifndef _TETON_PERSISTENCE_H_
#define _TETON_PERSISTENCE_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Defines the persistence of the QT information sent to  the tag.
    /// </summary>
    enum QtPersistence
    {
        /// <summary>
        /// QT persistence is unknown.
        /// </summary>
        QtPersistence_Unknown,
        /// <summary>
        /// The QT command information is considered temporary. QT information
        /// will return to the last persisted settings when the
        /// tag loses power.
        /// </summary>
        /// <remarks>NOTE: The data store in memory is always persistent.
        /// This persistence refers only to the QT configuration bits</remarks>
        QtPersistence_Temporary,
        /// <summary>
        /// The QT command information is permanent.  The tag will retain
        /// the QT configuration bits through power loss.
        /// </summary>
        /// <remarks>NOTE: The data store in memory is always persistent.
        /// This persistence refers only to the QT configuration bits</remarks>
        QtPersistence_Permanent,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    QtPersistenceEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    QtPersistenceToString (
      QtPersistence                 value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryQtPersistenceFromString (
      char *                        str,
      QtPersistence *               outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsQtPersistenceValid (
      QtPersistence                 value);

}
#endif /*  _TETON_PERSISTENCE_H_ */
