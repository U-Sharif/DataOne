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

#ifndef _TETON_SETTINGFILEEXCEPTION_H_
#define _TETON_SETTINGFILEEXCEPTION_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup exceptions */
    /// <summary>
    /// An exception thrown when the settings file is invalid or illegal
    /// </summary>
    /// <remarks>
    /// This exception is thrown when a illegal or invalid settings
    /// are found constructing a
    /// <see cref="SpeedwayReader.Settings"/> instance and the instance
    /// cannot be handled.
    /// </remarks>
    class SettingsFileException : public OctaneSdkException
    {
      public:

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="message">a string message describing the exception</param>
        SettingsFileException(
          const char *                  message);
    };
};

#endif /*  _TETON_SETTINGFILEEXCEPTION_H_ */
