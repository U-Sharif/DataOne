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

#ifndef _TETON_KEEPALIVESETTINGS_H_
#define _TETON_KEEPALIVESETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains all the settings for monitoring the
    /// connection to the reader.
    /// </summary>
    /// <remarks>
    /// When a connection to a reader is subject to disruptions (such
    /// as over a multi-hop IP network) it is helpful to monitor the
    /// health of these connections. These settings enable the
    /// exchange of periodic keep-alive messages with the reader, and
    /// allow the connection to be torn down if a threshold number of
    /// messages are lost. This allows the reader to enter into its
    /// disconnected operational state, retaining tag information if
    /// so configured.
    /// </remarks>
    class KeepAliveSettings
    {
      public:
        /// <summary>
        /// This property determines if the keep-alive mechanism is
        /// enabled. When enabled, the library will monitor the state
        /// of the connection to the reader by configuring the reader
        /// to send periodic keep-alive messages.
        /// </summary>
        bool                            IsEnabled;

	/// <summary>
        /// When the keep-alive mechanism is enabled, this is the
        /// frequency in which the reader will send the keep-alive
        /// messages. The duration is specified in milliseconds.
        /// </summary>
	int                             PeriodInMs;
        
	/// <summary>
        /// When the keep-alive mechanism is enabled, this is the
        /// threshold of missed messages at which time the connection
        /// is declared down.
        /// </summary>
	int                             LinkDownThreshold;

	/// <summary>
        /// Initializes a new instance of the KeepAliveSettings class.
        /// </summary>
	KeepAliveSettings(void);
        
	/// <summary>
        /// Initializes a new instance of the KeepAliveSettings class
        /// (copy constructor).
        /// </summary>
        /// <param name="keepAliveSettings">
        /// The object instance to copy.
        /// </param>
	KeepAliveSettings(const KeepAliveSettings & keepAliveSettings);
        
	/// <summary>
	/// Destructor for the current instance of the KeepAliveSettings class
	/// </summary>
	~KeepAliveSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_KEEPALIVESETTINGS_H_ */
