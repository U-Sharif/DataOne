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

#ifndef _TETON_CONNECTIONCHANGEDEVENT_H_
#define _TETON_CONNECTIONCHANGEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries connection state change information to the 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When the application connection state to the reader changes 
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnConnected, 
    /// SpeedwayReader.OnConnectionChanged,
    /// SpeedwayReader.OnConnectionLost, and
    /// SpeedwayReader.OnDisconnected methods  
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class ConnectionChangedEventArgs
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
        /// The new connection state associated with this event
        /// </summary>
        ApplicationConnectionState      State;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_CONNECTIONCHANGEDEVENT_H_ */
