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
#ifndef _TETON_PROGRAMEPCRESULT_H_
#define _TETON_PROGRAMEPCRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the results of a SpeedwayReader.ProgramEpc operation
    /// </summary>
    class ProgramEpcResult : public CommonAccessResult
    {
      public:

        /// <summary>
        /// The result status of the EPC programming
        /// </summary>
        PrimitiveWriteResult WriteResult;

        /// <summary>
        /// The result status of optional verify
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// The result status of optional EPC memory lock operation
        /// </summary>
        PrimitiveLockResult LockResult;

        /// <summary>
        /// Initializes a new instance of the ProgramEpcResult class
        /// </summary>
        ProgramEpcResult();

        /// <summary>
        /// Initializes a new instance of the ProgramEpcResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ProgramEpcResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the ProgramEpcResult class
        /// (copy constructor)
        /// </summary>
        ProgramEpcResult(const ProgramEpcResult & programEpcResult);
    };
}

#endif /*_TETON_PROGRAMEPCRESULT_H_ */
