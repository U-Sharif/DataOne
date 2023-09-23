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

#ifndef _TETON_OCTANESDKEXCEPTION_H_
#define _TETON_OCTANESDKEXCEPTION_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /*! @ingroup exceptions */
    /// <summary>
    /// The main exception class for the OctaneSDK
    /// </summary>
    /// <remarks>
    /// All OctaneSDK exceptions are derived from this class
    /// </remarks>
    class OctaneSdkException : public std::exception
    {
      public:
        /// <summary> a pointer to the exception message </summary>
        const char *                    Message;

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="message">a string message describing the exception</param>
        OctaneSdkException(
          const char *                  message);

        /// <summary> Returns the exception string message </summary>
        /// <returns> a pointer to the string message </returns>
        const char *
        what(void);
    };
} /* namespace Impinj_OctaneSdk */

#endif /*  _TETON_OCTANESDKEXCEPTION_H_ */
