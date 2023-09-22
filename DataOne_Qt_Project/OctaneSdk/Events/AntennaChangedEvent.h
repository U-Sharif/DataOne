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

#ifndef _TETON_ANTENNACHANGEDEVENT_H_
#define _TETON_ANTENNACHANGEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries antenna state change information to the 
    /// user application.
    /// </summary>
    /// <remarks>
    /// When a reader antenna changes state (connects or disconnects 
    /// from the reader) the SpeedwayReader class 
    /// SpeedwayReader.OnAntennaChanged function  
    /// is called and an instance of this class is passed by reference. 
    /// </remarks>
    class AntennaChangedEventArgs
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
        /// The antenna port number associated with thhis event
        /// </summary>
        int                             PortNumber;
        /// <summary>
        /// The new antenna connection state associated with this event
        /// </summary>
        AntennaConnectionState          State;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_ANTENNACHANGEDEVENT_H_ */
