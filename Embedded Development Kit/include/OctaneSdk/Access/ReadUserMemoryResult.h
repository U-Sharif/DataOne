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
#ifndef _TETON_READUSERMEMORYRESULT_H_
#define _TETON_READUSERMEMORYRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ReadUserMemory
    /// operation
    /// </summary>
    class ReadUserMemoryResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result of the user memory read operation
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// Initializes a new instance of the ReadUserMemoryResult class
        /// </summary>
        ReadUserMemoryResult();

        /// <summary>
        /// Initializes a new instance of the ReadUserMemoryResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ReadUserMemoryResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ReadUserMemoryResult class
        /// (copy constructor)
        /// </summary>
        ReadUserMemoryResult(const ReadUserMemoryResult & readUserMemoryResult);
    };
}
#endif /* _TETON_READUSERMEMORYRESULT_H_ */
