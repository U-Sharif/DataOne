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

#ifndef _TETON_MEMORYBANK_H_
#define _TETON_MEMORYBANK_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// This enumeration defines the memory banks available in Class1
    /// Generation2 (C1G2) compliant tags. Not all memory banks are
    /// available on all tags. For more information regarding tag
    /// memory banks, see the EPCglobal C1G2 Specification.
    /// </summary>
    enum MemoryBank
    {
        /// <summary>
        /// This is an invalid memory bank not defined by C1G2. It is
        /// used to denote an uninitialized object property.
        /// </summary>
        MemoryBank_None = -1,
        /// <summary>
        /// The Reserved memory bank is where the access and kill
        /// passwords are stored on the tag.
        /// </summary>
        MemoryBank_Reserved = 0,
        /// <summary>
        /// The EPC memory bank contains the Electronic Product Code
        /// (EPC) information of the tag. It also contains a CRC word
        /// and a Protocol Control (PC) word.
        /// </summary>
        MemoryBank_Epc = 1,
        /// <summary>
        /// The TID memory bank contains Tag Identification (TID)
        /// information. Information such as manufacturer and/or
        /// serial numbers may be stored here.
        /// </summary>
        MemoryBank_Tid = 2,
        /// <summary>
        /// The User memory bank contains information related to the
        /// RFID use case and is not defined specifically by C1G2.
        /// </summary>
        MemoryBank_User = 3,
    };

    /// <summary>
    /// A table containing the mapping between enumerations and strings.
    /// </summary>
    /// <remarks>
    /// It should not be necessary to use this table directly
    /// </remarks>
    extern EnumStrEntry
    MemoryBankEnumStrTable[];

    /// <summary>
    /// Converts the enumeration to human readable string
    /// </summary>
    /// <param name="value">enumeration</param>
    /// <returns>null terminated string. If the result
    /// cannot be properly converted, returns the string unknown</returns>
    extern const char *
    MemoryBankToString (
      MemoryBank                    value);

    /// <summary>
    /// Converts enumeration to human readable string
    /// </summary>
    /// <param name="str">string to convert</param>
    /// <param name="outValue">enumeration returned by reference</param>
    /// <returns>true if conversion was successful</returns>
    extern bool
    TryMemoryBankFromString (
      char *                        str,
      MemoryBank *                  outValue);

    /// <summary>
    /// returns true if the enumeration is a valid value
    /// </summary>
    /// <param name="value">enumeration</param>
    extern bool
    IsMemoryBankValid (
      MemoryBank                    value);

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_MEMORYBANK_H_ */
