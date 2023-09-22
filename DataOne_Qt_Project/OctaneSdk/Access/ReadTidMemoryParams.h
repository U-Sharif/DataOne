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
#ifndef _TETON_READTIDMEMORYPARAMS_H_
#define _TETON_READTIDMEMORYPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ReadTidMemory operation
    /// </summary>
    class ReadTidMemoryParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// The number of 16-bit TID words to read
        /// </summary>
        int WordCount;

        /// <summary>
        /// Initializes a new instance of the ReadTidMemoryParams class
        /// </summary>
        ReadTidMemoryParams();

        /// <summary>
        /// Initializes a new instance of the ReadTidMemoryParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        ReadTidMemoryParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ReadTidMemoryParams class
        /// (copy constructor)
        /// </summary>
        ReadTidMemoryParams(const ReadTidMemoryParams & readTidMemoryParams);
    };

}

#endif /* _TETON_READTIDMEMORYPARAMS_H_ */ 
