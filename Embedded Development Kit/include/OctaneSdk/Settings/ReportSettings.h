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

#ifndef _TETON_REPORTSETTINGS_H_
#define _TETON_REPORTSETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains all the settings for determining when the
    /// reader sends reports, and what the reader sends in those
    /// reports.
    /// </summary>
    class ReportSettings
    {
	
      public:
        /// <summary>
        /// This property determines when the reader sends a report.
        /// </summary>
        ReportMode                      Mode;

        /// <summary>
        /// This boolean enables the reporting of the peak RSSI at
        /// which a tag was read during the reporting interval.
        /// </summary>
        bool                            IncludePeakRssi;
        /// <summary>
        /// This boolean enables the reporting of the antenna port
        /// number on which the tag was read. If the tag was read on
        /// multiple antennas during the reporting interval, the
        /// report will contain multiple entries, one for each antenna
        /// on which the tag was read.
        /// </summary>
        bool                            IncludeAntennaPortNumber;
        /// <summary>
        /// This boolean enables the reporting of the first time at
        /// which the tag was read during the reporting interval.
        /// </summary>
        bool                            IncludeFirstSeenTime;
        /// <summary>
        /// This boolean enables the reporting of the last time at
        /// which the tag was read during the reporting interval.
        /// </summary>
        bool                            IncludeLastSeenTime;
        /// <summary>
        /// This boolean enables the reporting of the number of times
        /// the tag was read during the reporting interval.
        /// </summary>
        bool                            IncludeSeenCount;
        /// <summary>
        /// This boolean enables the reporting of the channel at
        /// which the tag was read. If the tag was read multiple times
        /// during the reporting interval, this is the frequency the
        /// reader was on when the tag was first seen.
        /// </summary>
        bool                            IncludeChannel;
        /// <summary>
        /// This boolean enables the reporting of the phase angle of
        /// the tag response when the tag was read. If the tag was
        /// read multiple times during the reporting interval, this
        /// is the phase angle when the tag was last seen.
        /// </summary>
        bool                            IncludePhaseAngle;
        /// <summary>
        /// This boolean enables the reporting of the Serialized TID
        /// feature of some Monza4 tags. This feature is not supported
        /// on all tag types.
        /// </summary>
        bool                            IncludeSerializedTid;

        /// <summary> Default constructor </summary>
        ReportSettings(void);
        /// <summary> Copy constructor </summary>
        ReportSettings(const ReportSettings & reportSettings);
        /// <summary> Default destructor </summary>
        ~ReportSettings();
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_REPORTSETTINGS_H_ */
