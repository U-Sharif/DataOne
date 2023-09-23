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

#ifndef _TETON_LOCK_H_
#define _TETON_LOCK_H_
//TODO: get this from makefile
#ifndef PLATFORM
#define PLATFORM _PLATFORM_LINUX
#endif
#if PLATFORM == _PLATFORM_LINUX
#include "pthread.h"
#elif PLATFORM == _PLATFORM_WINDOWS
#endif

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// Internal class to provide mutual exclusion.
    /// </summary>
    /// <remarks>
    /// This class is not related to C1G2 lock operations
    /// </remarks>
    class Lock
    {
      public:
        /// <summary>
        /// Default constructor
        /// </summary>
        Lock();
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="isRecursive">If true, lock can be taken
        /// (locked) multiple times by the same thread without deadlock
        /// </param>
        Lock(bool isRecursive);
        /// <summary>
        /// Default destructor
        /// </summary>
        ~Lock();
        /// <summary>
        /// Blocks until the lock is acquired
        /// </summary>
        void lock();
        /// <summary>
        /// Unlocks the lock
        /// </summary>
        void unlock();
      private:
#if PLATFORM == _PLATFORM_LINUX
        pthread_mutex_t Mutex;
        pthread_mutexattr_t MutexAttr;
        int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);

#endif
    };
}

#endif /* _TETON_LOCK_H_ */
