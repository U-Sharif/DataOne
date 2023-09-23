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
#ifndef _TETON_READTIDMEMORYRESULT_H_
#define _TETON_READTIDMEMORYRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ReadTidMemory
    /// operation
    /// </summary>
    class ReadTidMemoryResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result of the tid memory read operation
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// Initializes a new instance of the ReadTidMemoryResult class
        /// </summary>
        ReadTidMemoryResult();

        /// <summary>
        /// Initializes a new instance of the ReadTidMemoryResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ReadTidMemoryResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ReadTidMemoryResult class
        /// (copy constructor)
        /// </summary>
        ReadTidMemoryResult(const ReadTidMemoryResult & readTidMemoryResult);
    };
 
}
#endif /* _TETON_READTIDMEMORYRESULT_H_ */
