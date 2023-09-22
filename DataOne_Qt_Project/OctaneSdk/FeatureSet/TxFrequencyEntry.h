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

#ifndef _TETON_TXFREQUENCYENTRY_H_
#define _TETON_TXFREQUENCYENTRY_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// Describes a single transmit frequency that is
    /// used by or available on the reader.
    /// </summary>	
    class TxFrequencyEntry
    {
      public:
	/// <summary>
	/// initializes a new instance of the TxFrequencyEntry class
	/// </summary>
        TxFrequencyEntry (void);
        
	/// <summary>
	/// Destroys the current instance of the TxFrequencyEntry class
	/// </summary>
	~TxFrequencyEntry ();

	/// <summary>
        /// The LLRP code used to select the reader mode.
        /// Applications should not need this.
        /// </summary>
        int                     LlrpCode;

        /// <summary>
        /// The transmit frequency in Mhz (megahertz)
        /// as used in <see cref="Settings"/>.
        /// </summary>	
	double                  Mhz;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TXFREQUENCYENTRY_H_ */
