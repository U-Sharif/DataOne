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

#ifndef _TETON_TXPOWERFEATURES_H_
#define _TETON_TXPOWERFEATURES_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// This class contains an array of
    /// <see cref="TxPowerEntry"/> objects. Different reader
    /// products support different transmit powers and this class
    /// encapsulates that varying number.
    /// </summary>
    /// <seealso cref="TxPowerEntry"/>
    class TxPowerFeatures
    {
      public:
	/// <summary>
	/// Initializes a new instance of the TxPowerFeatures class
	/// </summary>
        TxPowerFeatures (void);
        
	/// <summary>
	/// Destroys the current instance of the TxPowerFeatures class
	/// </summary>
	~TxPowerFeatures ();

	/// <summary>
	/// The maximum number of entries in the
	/// TxPowerEntry array
	/// </summary>
        static const int        DimEntries = 99;

        /// <summary>
	/// The number of entries in the TxPowerEntry array
	/// </summary>
        int                     nEntries;
      
        /// <summary>
        /// An array of
        /// <see cref="TxPowerEntry"/> objects.
        /// </summary>
        TxPowerEntry            Entries[DimEntries];
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TXPOWERFEATURES_H_ */
