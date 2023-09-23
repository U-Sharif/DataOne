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

#ifndef _TETON_REPORTBUFFERWARNEDEVENT_H_
#define _TETON_REPORTBUFFERWARNEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries reader report buffer warning events to the 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When the on reader report buffer reaches a warning level
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnReportBufferWarned method
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class ReportBufferWarnedEventArgs
    {
      public:
        /// <summary>
        /// The identity of the reader reporting this event
        /// </summary>
        void *                          ReaderIdentity;
        /// <summary>
        /// The time associated with the event
        /// </summary>
        Time                            Timestamp;
        /// <summary>
        /// Reports how full the buffer is as a percent of the total buffer size
        /// </summary>
        int                             PercentFull;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_REPORTBUFFERWARNEDEVENT_H_ */
