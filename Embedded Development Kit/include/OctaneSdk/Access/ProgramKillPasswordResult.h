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
#ifndef _TETON_PROGRAMKILLPASSWORDRESULT_H_
#define _TETON_PROGRAMKILLPASSWORDRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ProgramKillPassword
    /// operation
    /// </summary>
    class ProgramKillPasswordResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result status of the kill password programming
        /// </summary>
        PrimitiveWriteResult WriteResult;

        /// <summary>
        /// The result status of optional verify
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// The result status of optional kill Password lock operation
        /// </summary>
        PrimitiveLockResult LockResult;

        /// <summary>
        /// Initializes a new instance of the ProgramKillPasswordResult class
        /// </summary>
        ProgramKillPasswordResult();

        /// <summary>
        /// Initializes a new instance of the ProgramKillPasswordResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ProgramKillPasswordResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ProgramKillPasswordResult class
        /// (copy constructor)
        /// </summary>
        ProgramKillPasswordResult(const ProgramKillPasswordResult & programKillPasswordResult);
    };
}
#endif /* _TETON_PROGRAMKILLPASSWORDRESULT_H_ */
