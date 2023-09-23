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

#ifndef _TETON_TXPOWERENTRY_H_
#define _TETON_TXPOWERENTRY_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// Describes a single transmit power that is available on the reader.
    /// </summary>
    class TxPowerEntry
    {
      public:
	/// <summary>
        /// Initializes a new instance of the Impinj_OctaneSdk class.
        /// </summary>	   	      
        TxPowerEntry (void);
        ~TxPowerEntry ();

	/// <summary>
        /// The LLRP code used to select the reader mode.
        /// Applications should not need this.
        /// </summary>
        int                     LlrpCode;

	/// <summary>
        /// The transmit power in dBm (decibel milliwatts)
        /// as used in <see cref="AntennaSettings"/>.
        /// Typically between 10.00 and 30.00 dBm in 0.25 dBm steps.
        /// </summary>
        double                  Dbm;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TXPOWERENTRY_H_ */
