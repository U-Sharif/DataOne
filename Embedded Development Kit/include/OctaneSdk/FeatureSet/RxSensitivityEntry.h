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

#ifndef _TETON_RXSENSITIVITYENTRY_H_
#define _TETON_RXSENSITIVITYENTRY_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// Describes a single receive sensitivity that is available on the reader.
    /// </summary>
    class RxSensitivityEntry
    {
      public:
	/// <summary>
	/// Initializes a new instance of the RxSensitivityEntry class
	/// </summary>
        RxSensitivityEntry (void);
      
	/// <summary>
	/// Destroys the current instance of the RxSensitivityEntry class
	/// </summary>
        ~RxSensitivityEntry ();

        /// <summary>
        /// The LLRP code used to select the reader mode.
        /// Applications should not need this.
        /// </summary>
        int                     LlrpCode;

	/// <summary>
        /// The receive sensitivity in dBm (decibel milliwatts)
        /// as used in <see cref="AntennaSettings"/>.
        /// Typically between -80 and -30 dBm.
        /// </summary>
        int                     Dbm;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_RXSENSITIVITYENTRY_H_ */
