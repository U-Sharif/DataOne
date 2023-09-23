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

#ifndef _TETON_ENUMSTRING_H_
#define _TETON_ENUMSTRING_H_
#define _ENUM_STR_UNKNOWN "unknown"
namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /// <summary>
    /// A helper class for OctaneSDK enumerations
    /// </summary>
    /// <remarks>
    /// The EnumStrEntry class provides methods to handle OctaneSDK
    /// enums as either strings or integers.
    /// </remarks>
    struct EnumStrEntry
    {
        /// <summary> The enumerated value </summary>
        int                             Value;
        /// <summary> A matching human readable text string </summary>
        const char *                    Text;
    };

    /*! \relates EnumStrEntry */
    /// <summary> Returns a string from an enumeration </summary>
    /// <param name="table">A pointer to the enum string table</param>
    /// <param name="value">The enumeration value to convert</param>
    /// <returns>a pointer to a constant C-string containing the enum</returns>
    extern const char *
    EnumToString (
      EnumStrEntry *                    table,
      int                               value);

    /*! \relates EnumStrEntry */
    /// <summary>Tries to convert an string to an enum value</summary>
    /// <param name="table"> A pointer to the enum string table </param>
    /// <param name="str">The enum string to try to convert</param>
    /// <param name="outValue">The enum interger returned by reference </param>
    /// <returns>true if enum string was located in the table</returns>
    extern bool
    TryEnumFromString (
      EnumStrEntry *                    table,
      char *                            str,
      int *                             outValue);

    /*! \relates EnumStrEntry */
    /// <summary>Validates and enum value</summary>
    /// <param name="table">A pointer to an enum string table</param>
    /// <param name="value">The enum integer to validate</param>
    /// <returns>true if the enum value is valid for the table</returns>
    extern bool
    IsEnumValid (
      EnumStrEntry *                    table,
      int                               value);

    /*! \relates EnumStrEntry */
    /// <summary>Converts boolean value to string</summary>
    /// <param name="value">Boolean value to convert</param>
    /// <returns>pointer to constant boolean string</returns>
    extern const char *
    BoolToString (
      bool                              value);

    /*! \relates EnumStrEntry */
    /// <summary>Tries to convert a boolean value from a string</summary>
    /// <param name="str">string representation of boolean</param>
    /// <param name="outValue">Boolean return value by reference</param>
    /// <returns>true if the boolean value was converted from string</returns>
    extern bool
    TryBoolFromString (
      char *                            str,
      bool *                            outValue);

} /* namespace Impinj_OctaneSdk_Internals */

#endif /* _TETON_ENUMSTRING_H_ */
