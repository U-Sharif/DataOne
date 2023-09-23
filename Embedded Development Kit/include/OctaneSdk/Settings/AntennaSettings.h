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

#ifndef _TETON_ANTENNASETTINGS_H_
#define _TETON_ANTENNASETTINGS_H_

namespace Impinj_OctaneSdk
{
	
    /*! @ingroup settings */
    /// <summary>
    /// This class contains all the settings for a single antenna.
    /// </summary>
    /// <remarks>
    /// This Settings object contains one instance of this object for
    /// each antenna provided by the reader. Within each object are
    /// all the settings that can be configured on a per-antenna
    /// basis within the reader.
    /// </remarks>
    class AntennaSettings
    {
      public:
        /// <summary>
        /// The reader antenna port for which these settings are
        /// applied. Antenna ports range from 1-4 depending on the
        /// reader model.
        /// </summary>
        int                             PortNumber;

        /// <summary>
        /// Whether this antenna port is enabled or not. When set to
        /// true, the antenna will be used to singulate tags.
        /// </summary>
	bool                            IsEnabled;

	/// <summary>
        /// The power at the antenna port applied when the antenna is
        /// active. Transmit power is specified in dBm (e.g. 30.00).
        /// </summary>
	double                          TxPowerInDbm;
        
	/// <summary>
        /// The minimum signal strength received by the reader for
        /// the tag response to be processed. This value can be used
        /// to filter tag responses such that only strong tags are
        /// seen. A value of 0 accepts all tags (max sensitivity).
        /// </summary>
	int                             RxSensitivityInDbm;

        /// <summary>
        /// Initializes a new instance of the AntennaSettings class.
        /// </summary>
        AntennaSettings(void);

	/// <summary>
        /// Initializes a new instance of the AntennaSettings class
        /// (copy constructor).
        /// </summary>
        /// <param name="antennaSettings">
        /// The object instance to copy.
        /// </param>
        AntennaSettings(const AntennaSettings & antennaSettings);
	
	/// <summary>
	/// Destructor for the current instance of the AntennaSettings class
	/// </summary>
        ~AntennaSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_ANTENNASETTINGS_H_ */
