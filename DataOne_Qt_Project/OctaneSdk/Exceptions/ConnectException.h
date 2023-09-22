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

#ifndef _TETON_CONNECTEXCEPTION_H_
#define _TETON_CONNECTEXCEPTION_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup exceptions */
    /// <summary>
    /// An exception thrown when a connection cannot be made to a reader
    /// </summary>
    /// <remarks>
    /// This exception is thrown when a connection cannot be made to a 
    /// reader.
    /// </remarks>
    class ConnectException : public OctaneSdkException
    {
      public:
        /// <summary>
        /// The state of the application connection upon generation of this event
        /// </summary>
        ApplicationConnectionState State;

        /// <summary>
        /// Constructor for a ConnectionException
        /// </summary>
        /// <param name="message">a string message</param>
        /// <param name="state">current connection state</param>
        ConnectException(
          const char *                  message,
          ApplicationConnectionState    state);
    };
};

#endif /* _TETON_CONNECTEXCEPTION_H_ */
