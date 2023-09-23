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
#ifndef _TETON_READUSERMEMORYPARAMS_H_
#define _TETON_READUSERMEMORYPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ReadUserMemory operation
    /// </summary>
    class ReadUserMemoryParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// The start address of the user memory read in 16-bit words
        /// </summary>
        int WordPointer;

        /// <summary>
        /// The number of 16-bit words to read
        /// <summary>
        int WordCount;

        /// <summary>
        /// Initializes a new instance of the ReadUserMemoryParams class
        /// </summary>
        ReadUserMemoryParams();

        /// <summary>
        /// Initializes a new instance of the ReadUserMemoryParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        ReadUserMemoryParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ReadUserMemoryParams class
        /// (copy constructor)
        /// </summary>
        ReadUserMemoryParams(const ReadUserMemoryParams & readUserMemoryParams);
    };
}

#endif /* _TETON_READUSERMEMORYPARAMS_H_ */
