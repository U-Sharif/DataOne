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

#ifndef _TETON_AUTOSTOPSETTINGS_H_
#define _TETON_AUTOSTOPSETTINGS_H_

namespace Impinj_OctaneSdk
{
	
    /*! @ingroup settings */
    /// <summary>
    /// This class contains the settings that allow the reader to
    /// operate autonomously. It is used in association with the
    /// AutoStartSettings class.
    /// </summary>
    /// <remarks>
    /// The reader can be configured to stop singulating
    /// automatically based on certain input parameters, such as a
    /// general purpose input (GPI) transitioning or a timer
    /// expiring. This class contains those settings.
    /// </remarks>	
    class AutoStopSettings
    {
      public:
	/// <summary>
        /// The auto-stop mode. This setting dictates whether the
        /// reader will stop singulating automatically or not. The
        /// remaining properties contained within this class are
        /// processed or ignored based on this value.
        /// </summary>
        AutoStopMode                    Mode;

        /// <summary>
        /// The GPI on which to stop singulating. GPI ports are
        /// numbered from 1-4 and may vary by reader model. This value
        /// is only used when Mode is set to GpiTrigger.
        /// </summary>
	int                             GpiPortNumber;

	/// <summary>
        /// The level of the GPI on which the reader will stop
        /// singulating. A value of true means that the reader will
        /// auto-stop when the GPI transitions high. A value of false
        /// means that the reader will auto-stop when the the GPI
        /// transitions low. This value is only used when Mode is set
        /// to GpiTrigger.
        /// </summary>
	bool                            GpiLevel;
        
	/// <summary>
        /// The duration after which the reader will stop singulating.
        /// This value can be used as either a guard timer against a
        /// GPI state change, or an absolute timer duration. This
        /// duration is specified in milliseconds. This value is only
        /// used when Mode is set to either GpiTrigger or Duration.
        /// </summary>
	int                             DurationInMs;

        /// <summary>
        /// Initializes a new instance of the AutoStopSettings class.
        /// </summary>
        AutoStopSettings(void);

        /// <summary>
        /// Initializes a new instance of the AutoStopSettings class
        /// (copy constructor).
        /// </summary>
        /// <param name="autoStopSettings">
        /// The object instance to copy.
        /// </param>
	AutoStopSettings(const AutoStopSettings &autoStopSettings);
	
	/// <summary>
	/// Destructor for this instance of the AutoStopSettings class
	/// </summary>
	~AutoStopSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_AUTOSTOPSETTINGS_H_ */
