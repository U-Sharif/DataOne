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

#ifndef _TETON_TIME_H_
#define _TETON_TIME_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// A simple time class for use in the OctaneSDK
    /// </summary>
    /// <remarks>
    /// The intention of this class is to allow OctaneSDK C++ code to be portable
    /// accross platforms and to facilitate use of time in your application
    /// </remarks>
    class Time
    {
      public:
        /// <summary>
        /// Default constructor
        /// </summary>
        Time();
        /// <summary>
        /// Construct a time from a seconds and microseconds value
        /// </summary>
        Time(int seconds, int useconds);
        /// <summary>
        /// Construct from a Time object
        /// </summary>
        Time(const Time & t);
        /// <summary>
        /// equals operator for two time values
        /// </summary>
        Time& operator=(const Time t);

        /// <summary>
        /// Writes a formatted ascii time representation into
        /// the provied buffer
        /// </summary>
        const char *
        Formatter (
          char *                buf,
          int                   nBuf);

        /// <summary>
        /// gets the current UTC time
        /// </summary>
        static const Time UtcNow();
        /// <summary>
        /// Gets the epoch time
        /// </summary>
        static const Time MinValue();

        /// <summary> seconds since the time epoch </summary>
        int Seconds;
        /// <summary> microseconds since the time epoch </summary>
        int USeconds;
    };
}

#endif /* _TETON_TIME_H_ */
