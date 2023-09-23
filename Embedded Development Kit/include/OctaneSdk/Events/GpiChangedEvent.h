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

#ifndef _TETON_GPICHANGEDEVENT_H_
#define _TETON_GPICHANGEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries GPI change information to the 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When the readers GPI port status changes, 
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnGpiChanged, 
    /// SpeedwayReader.OnGpi1Changed, 
    /// SpeedwayReader.OnGpi2Changed, 
    /// SpeedwayReader.OnGpi3Changed, and
    /// SpeedwayReader.OnGpi4Changed methods
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class GpiChangedEventArgs
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
        /// The GPI port number associated with this event
        /// </summary>
        int                             PortNumber;
        /// <summary>
        /// The new GPI port state associated with this event
        /// </summary>
        GpioState                       State;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_GPICHANGEDEVENT_H_ */
