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

#ifndef _TETON_READEREXCEPTIONOCCUREDEVENT_H_
#define _TETON_READEREXCEPTIONOCCUREDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries reader hardware exceptions to the 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When a reader exception occurs (a hardware or system error on 
    /// the reader that is unexpected during normal operation)
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnReaderExceptionOccured method 
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class ReaderExceptionOccuredEventArgs
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
        /// A string message describing the exception associated with this event
        /// </summary>
        char                            Message[128];
    };
} /* namespace Impinj_OctaneSdk */

#endif /*  _TETON_READEREXCEPTIONOCCUREDEVENT_H_ */
