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

#ifndef _TETON_TXFREQUENCYFEATURES_H_
#define _TETON_TXFREQUENCYFEATURES_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="TxFrequencyEntry"/> objects. Different reader
    /// products use different frequencies encapsulates that varying
    /// number.
    /// </summary>
    /// <seealso cref="TxFrequencyEntry"/>
    class TxFrequencyFeatures
    {
      public:
	/// <summary>
	/// Initializes a new instance of the
	/// TxFrequencyFeatures class
	/// </summary>
        TxFrequencyFeatures (void);
        
	/// <summary>
	/// Destroys the current instance
	/// of the TxFrequencyFeatures class
	/// </summary>
	~TxFrequencyFeatures ();

	/// <summary>
	/// the maximum number of entries in the
	/// TxFrequencyEntry array
	/// </summary>
        static const int        DimEntries = 60;

	/// <summary>
	/// The number of items in the TxFrequencyEntry array
	/// </summary>
        int                     nEntries;
      
        /// <summary>
        /// A array of
        /// <see cref="TxFrequencyEntry"/> objects.
        /// </summary>
        TxFrequencyEntry        Entries[DimEntries];
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TXFREQUENCYFEATURES_H_ */
