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

#ifndef _TETON_LOGENTRY_H_
#define _TETON_LOGENTRY_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Contains the information carried in an OctaneSdk log.
    /// </summary>
    class LogEntry
    {
      public:
	/// <summary>
	/// Default Constructor
	/// </summary>
        LogEntry() {};
	/// <summary>
	/// Copy Constructor
	/// </summary>
        LogEntry(const LogEntry & entry);
	/// <summary>
	/// Assignment operator
	/// </summary>
        LogEntry& operator=(const LogEntry & entry);
        /// <summary>
        /// See <see cref="SpeedwayReader.ReaderIdentity"/>
        /// </summary>
        void *           ReaderIdentity;
        /// <summary>
        /// The time the log information was recorded
        /// </summary>
        Time             Timestamp;
        /// <summary>
        /// The level of severity of the log
        /// </summary>
        enum LogLevel    Level;
        /// <summary>
        /// The code component that originated the log
        /// </summary>
        enum LogOrigin   Origin;
        /// <summary>
        /// A human readable string describing the log message
        /// </summary>
        char *           Message;
    };

} // namespace Impinj_OctaneSdk

#endif /* _TETON_LOGENTRY_H_ */
