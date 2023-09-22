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

#ifndef _TETON_STOPPEDEVENT_H_
#define _TETON_STOPPEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries RFID stop information to the
    /// user application.
    /// </summary>
    /// <remarks>
    /// When the reader turns off its RF interface to perform and RFID
    /// operation
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnStopped method
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class StoppedEventArgs
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
        /// Operational state of the reader associated with this event
        /// </summary>
        OperationalState                State;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_STOPPEDEVENT_H_ */
