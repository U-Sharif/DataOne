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

#ifndef _TETON_LOWDUTYCYCLESETTINGS_H_
#define _TETON_LOWDUTYCYCLESETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains all the settings for the low duty cycle
    /// feature of the reader. This feature allows for reduced RF
    /// activity when there are no tags in the readers field of view.
    /// </summary>
    /// <remarks>
    /// This custom parameter provides fine-grained control of the RF
    /// duty cycle of the reader. While singulating, if the Reader
    /// reads zero tags on a particular enabled antenna for a total of
    /// EmptyFieldTimeoutInMs milliseconds, the reader will enter low
    /// duty cycle mode. In this mode, the reader will revisit this
    /// antenna every FieldPingIntervalInMs milliseconds checking for
    /// tags. When a tag is read, full duty cycle will resume.
    /// </remarks>
    class LowDutyCycleSettings
    {
      public:
        /// <summary>
        /// This property determines if the low duty cycle mechanism
        /// is enabled. When enabled, the reader will periodically
        /// pause singulation on an antenna if it has not detected any
        /// tags in its field of view. When disabled, the reader will
        /// constantly attempt to singulate tags, even in the absence
        /// of any tags read.
        /// </summary>
        bool                            IsEnabled;

        /// <summary>
        /// This property dictates how long the reader will attempt to
        /// singulate tags after it has determined that there are no
        /// tags present in its field of view. After this time has
        /// elapsed and no tags are seen, the antenna will enter low
        /// duty cycle mode where it will pause singulation to reduce
        /// the RF energy transmitted.
        /// </summary>
        int                             EmptyFieldTimeoutInMs;
	
	/// <summary>
        /// This property dictates how long singulation is paused once
        /// the reader has entered low duty cycle mode. After entering
        /// this mode, the reader will resume singulation after this
        /// time has elapsed. If tags are detected, full duty cycle is
        /// resumed.
        /// </summary>

	int                             FieldPingIntervalInMs;

        /// <summary>
        /// Initializes a new instance of the LowDutyCycleSettings
        /// class.
        /// </summary>
        LowDutyCycleSettings(void);
	
	

        /// <summary>
        /// Initializes a new instance of the LowDutyCycleSettings
        /// class (copy constructor).
        /// </summary>
        /// <param name="lowDutyCycleSettings">
        /// The object instance to copy.
        /// </param>
        LowDutyCycleSettings(const LowDutyCycleSettings & lowDutyCycleSettings);

	/// <summary>
	/// Destructor for the current instance of the LowDutyCycleSettings class
	/// </summary>
	~LowDutyCycleSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LOWDUTYCYCLESETTINGS_H_ */
