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

#ifndef _TETON_THREAD_H_
#define _TETON_THREAD_H_

namespace Impinj_OctaneSdk
{
    /// <summary>
    /// The function handle type used in the thread class
    /// </summary>
    typedef void   (*ThreadFunc)(void*);
    /// <summary>
    /// The threadID type used in the thread class to 
    /// uniquely identify a thread
    /// </summary>
    typedef void * ThreadId;

    /// <summary>
    /// A Thread class for use in the OctaneSDK 
    /// </summary>
    /// <remarks>
    /// The intention of this class is to allow OctaneSDK C++ code to be portable
    /// accross platforms and to facilitate use of threading in your application
    /// </remarks>
    class Thread
    {
      public:
        /// <summary>
        /// Default constructor
        /// </summary>
        Thread();
        /// <summary>
        /// Construct a thread object with a calling function
        /// </summary>
        /// <param name="func">entry point for the thread</param>
        /// <param name="cookie">argument to pass to the thread</param>
        Thread(ThreadFunc func, void * cookie);
        /// <summary>
        /// Default destructor
        /// </summary>
        ~Thread();
        /// <summary>
        /// Does thread match the current thread
        /// </summary>
        /// <returns>true if this thread is the current running thread</returns>
        bool IsCurrentThread();
        /// <summary>
        /// Static method to check current thread against an ID
        /// </summary>
        /// <param name="id">ThreadId of a valid thread</param>
        /// <returns>true if this thread is the current running thread</returns>
        static bool IsCurrentThread(ThreadId id);
        /// <summary>
        /// Starts a thread
        /// </summary>
        bool Start();
        /// <summary>
        /// Starts a thread
        /// </summary>
        /// <param name="func">entry point for the thread</param>
        /// <param name="cookie">argument to pass to the thread</param>
        /// <returns>true if this thread started</returns>
        bool Start(ThreadFunc func, void * cookie);
        /// <summary>
        /// Creates and starts a new thread
        /// </summary>
        /// <param name="func">entry point for the thread</param>
        /// <param name="cookie">argument to pass to the thread</param>
        /// <returns>valid ThreadId on success, 0 on error</returns>
        static ThreadId Launch(ThreadFunc func, void * cookie);
        /// <summary>
        /// Makes the current thread sleep
        /// </summary>
        /// <param name="millisec">Number of milliseconds to sleep</param>
        static void Sleep(int millisec);
      private:
#ifdef linux
        ThreadId    ID;
        ThreadFunc  Func;
        void *      Cookie;
#else 
        // figure out later 
        ThreadId    ID;
#endif
    };
}

#endif /* _TETON_THREAD_H_ */
