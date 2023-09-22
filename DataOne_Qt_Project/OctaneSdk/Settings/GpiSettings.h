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

#ifndef _TETON_GPISETTINGS_H_
#define _TETON_GPISETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains all the settings for a single general
    /// purpose input (GPI).
    /// </summary>
    /// <remarks>
    /// This Settings object contains one instance of this object for
    /// each GPI provided by the reader. Within each object are all
    /// the settings that can be configured on a per-GPI basis within
    /// the reader.
    /// </remarks>	
    class GpiSettings
    {
      public:
	      
	/// <summary>
	/// The default GPI debounce value, in Milliseconds
	/// </summary>
        static const int                DefaultGpiDebounceInMs = 20;

        /// <summary>
        /// The reader GPI port for which these settings are applied.
        /// GPI ports range from 1-4 depending on the reader model.
        /// </summary>      
        int                             PortNumber;

        /// <summary>
        /// Whether the GPI port is monitored by the reader for level
        /// changes. When this property is set to true, the reader
        /// will monitor the GPI level for transitions and report
        /// those events. When this property is set to false, the GPI
        /// is ignored by the reader. Note that to use a GPI for an
        /// AutoStart or AutoStop trigger, it must be set to enabled.
        /// </summary>
	bool                            IsEnabled;

        /// <summary>
        /// If the input source to a GPI is noisy or not debounced via
        /// a hardware circuit, this property can be used to limit the
        /// reporting of transitional changes (a software debounce).
        /// This value is specified in milliseconds and must be a
        /// multiple of 10 ms.
        /// </summary>
	int                             DebounceInMs;

        /// <summary>
        /// Initializes a new instance of the GpiSettings class.
        /// </summary>
        GpiSettings(void);

	/// <summary>
        /// Initializes a new instance of the GpiSettings class (copy
        /// constructor).
        /// </summary>
        /// <param name="gpiSettings">
        /// The object instance to copy.
        /// </param>
	GpiSettings(const GpiSettings & gpiSettings);
	
	/// <summary>
	/// Destructor for this instance of the GpiSettings class
	/// </summary>
        ~GpiSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_GPISETTINGS_H_ */
