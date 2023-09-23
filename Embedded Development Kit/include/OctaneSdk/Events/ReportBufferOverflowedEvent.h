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

#ifndef _TETON_REPORTBUFFEROVERFLOWEDEVENT_H_
#define _TETON_REPORTBUFFEROVERFLOWEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries report buffer overflow information 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When the readers on-board report buffer overflows 
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnReportBufferOverflow method
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class ReportBufferOverflowedEventArgs
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
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_REPORTBUFFEROVERFLOWEDEVENT_H_ */
