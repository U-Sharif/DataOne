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

#ifndef _TETON_LOGGINGEVENT_H_
#define _TETON_LOGGINGEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries logging event information to the  
    /// user application.
    /// </summary>
    /// <remarks>
    /// When log information is added   
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnLogging method
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class LoggingEventArgs
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
        /// The log information associated with this event
        /// </summary>
        LogEntry                        Entry;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LOGGINGEVENT_H_ */
