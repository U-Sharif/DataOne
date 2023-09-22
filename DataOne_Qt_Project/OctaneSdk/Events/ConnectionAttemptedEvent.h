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

#ifndef _TETON_CONNECTIONATTEMPTEDEVENT_H_
#define _TETON_CONNECTIONATTEMPTEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries connection attempt information to the 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When a connection is attempted to the reader, the 
    /// the SpeedwayReader class 
    /// SpeedwayReader.OnConnectionChanged method
    /// is called and an instance of this class is passed by reference. 
    /// </remarks>
    class ConnectionAttemptedEventArgs
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

#endif /* _TETON_CONNECTIONATTEMPTEDEVENT_H_ */
