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
#ifndef _TETON_PROGRAMUSERMEMORYRESULT_H_
#define _TETON_PROGRAMUSERMEMORYRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ProgramUserMemory
    /// operation
    /// </summary>
    class ProgramUserMemoryResult : public CommonAccessResult
    {
      public: 
        /// <summary>
        /// The result status of the user memory programming
        /// </summary>
        PrimitiveWriteResult WriteResult;

        /// <summary>
        /// The result status of optional verify
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// The result status of optional user memory lock operation
        /// </summary>
        PrimitiveLockResult LockResult;


        /// <summary>
        /// Initializes a new instance of the ProgramUserMemoryResult class
        /// </summary>
        ProgramUserMemoryResult();

        /// <summary>
        /// Initializes a new instance of the ProgramUserMemoryResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ProgramUserMemoryResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ProgramUserMemoryResult class
        /// (copy constructor)
        /// </summary>
        ProgramUserMemoryResult(const ProgramUserMemoryResult & programUserMemoryResult);
    };

}
#endif /* _TETON_PROGRAMUSERMEMORYRESULT_H_ */
