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
#ifndef _TETON_READKILLPASSWORDRESULT_H_
#define _TETON_READKILLPASSWORDRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ReadKillPassword
    /// operation
    /// </summary>
    class ReadKillPasswordResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result of the kill password read operation
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// Initializes a new instance of the ReadKillPasswordResult class
        /// </summary>
        ReadKillPasswordResult();

        /// <summary>
        /// Initializes a new instance of the ReadKillPasswordResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ReadKillPasswordResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ReadKillPasswordResult class
        /// (copy constructor)
        /// </summary>
        ReadKillPasswordResult(const ReadKillPasswordResult & readKillPasswordResult);
    };
}

#endif /* _TETON_READKILLPASSWORDRESULT_H_ */
