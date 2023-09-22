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

#ifndef _TETON_TAGSREPORTEDEVENT_H_
#define _TETON_TAGSREPORTEDEVENT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup events */
    /// <summary>
    /// The event that carries RFID tag information to the
    /// user application.
    /// </summary>
    /// <remarks>
    /// The reader receives tag information through RF inventory
    /// operation
    /// the application is notified through the the SpeedwayReader class 
    /// SpeedwayReader.OnTagsReported method
    /// and an instance of this class is passed by reference. 
    /// </remarks>
    class TagsReportedEventArgs
    {
      public:
        /// <summary>
        /// The identity of the reader reporting this event
        /// </summary>
        void *                          ReaderIdentity;
        /// <summary>
        /// The time associated with this event
        /// </summary>
        Time                            Timestamp;
        /// <summary>
        /// The tag report associated with this event
        /// </summary>
        class TagReport                 TagReport;
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_TAGSREPORTEDEVENT_H_ */
