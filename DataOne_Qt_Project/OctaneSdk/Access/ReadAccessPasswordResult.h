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
#ifndef _TETON_READACCESSPASSWORDRESULT_H_
#define _TETON_READACCESSPASSWORDRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ReadAccessPassword
    /// operation
    /// </summary>
    class ReadAccessPasswordResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result of the access password read operation
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// Initializes a new instance of the ReadAccessPasswordResult class
        /// </summary>
        ReadAccessPasswordResult();

        /// <summary>
        /// Initializes a new instance of the ReadAccessPasswordResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ReadAccessPasswordResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ReadAccessPasswordResult class
        /// (copy constructor)
        /// </summary>
        ReadAccessPasswordResult(const ReadAccessPasswordResult & readAccessPasswordResult);
    };
}

#endif /* _TETON_READACCESSPASSWORDRESULT_H_ */
