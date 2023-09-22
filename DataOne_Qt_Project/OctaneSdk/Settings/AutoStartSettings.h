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

#ifndef _TETON_AUTOSTARTSETTINGS_H_
#define _TETON_AUTOSTARTSETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains the settings that allow the reader to
    /// operate autonomously. It is used in association with the
    /// AutoStopSettings class.
    /// </summary>
    /// <remarks>
    /// The reader can be configured to start singulating
    /// automatically based on certain input parameters, such as a
    /// general purpose input (GPI) transitioning or a timer
    /// expiring. This class contains those settings.
    /// </remarks>
    class AutoStartSettings
    {
      public:

        /// <summary>
        /// The auto-start mode. This setting dictates whether the
        /// reader will start singulating automatically or not. The
        /// remaining properties contained within this class are
        /// processed or ignored based on this value.
        /// </summary>
        AutoStartMode                   Mode;

        /// <summary>
        /// The GPI on which to start singulating. GPI ports are
        /// numbered from 1-4 and may vary by reader model. This value
        /// is only used when Mode is set to GpiTrigger.
        /// </summary>
        int                             GpiPortNumber;

        /// <summary>
        /// The level of the GPI on which the reader will start
        /// singulating. A value of true means that the reader will
        /// auto-start when the GPI transitions high. A value of false
        /// means that the reader will auto-start when the the GPI
        /// transitions low. This value is only used when Mode is set
        /// to GpiTrigger.
        /// </summary>
        bool                            GpiLevel;

        /// <summary>
        /// The initial delay for when the reader will start
        /// singulating. This delay is specified in milliseconds.
        /// This value is only used when Mode is set to Periodic.
        /// </summary>
        int                             FirstDelayInMs;

        /// <summary>
        /// The periodic delay for which the reader will start
        /// singulating. A value of 5000 means that the reader would
        /// start singulating automatically every 5 seconds. Note that
        /// for the reader to start singulating, it must have stopped,
        /// so an appropriate AutoStopSettings Mode also needs to have
        /// been set. This delay is specified in milliseconds. This
        /// value is only used when Mode is set to Periodic.
        /// </summary>
        int                             PeriodInMs;

        /// <summary>
        /// Initializes a new instance of the AutoStartSettings class.
        /// </summary>
        AutoStartSettings(void);

        /// <summary>
        /// Initializes a new instance of the AutoStartSettings class
        /// (copy constructor).
        /// </summary>
        /// <param name="autoStartSettings">
        /// The object instance to copy.
        /// </param>
	AutoStartSettings(const AutoStartSettings & autoStartSettings);

	/// <summary>
	/// Destructor for the current instance of the AutoStartSettings Class
	/// </summary>
	~AutoStartSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_AUTOSTARTSETTINGS_H_ */
