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
#ifndef _TETON_PROGRAMUSERBLOCKRESULT_H_
#define _TETON_PROGRAMUSERBLOCKRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class that contains the result of SpeedwayReader.ProgramUserBlock
    /// operation
    /// </summary>
    class ProgramUserBlockResult : public CommonAccessResult
    {
      public:
        /// <summary>
        /// The result status of the user block programming
        /// </summary>
        PrimitiveWriteResult WriteResult;

        /// <summary>
        /// The result status of optional verify
        /// </summary>
        PrimitiveReadResult ReadResult;

        /// <summary>
        /// The result status of optional user lock operation
        /// </summary>
        PrimitiveLockResult LockResult;

        /// <summary>
        /// The result status of optional user block lock operation.
        /// </summary>
        PrimitiveSetBlockPermalockResult BlockPermalockResult;

        /// <summary>
        /// Initializes a new instance of the ProgramUserBlockResult class
        /// </summary>
        ProgramUserBlockResult();

        /// <summary>
        /// Initializes a new instance of the ProgramUserBlockResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        ProgramUserBlockResult(const CommonAccessResult & commonAccessResult);
        
        /// <summary>
        /// Initializes a new instance of the ProgramUserBlockResult class
        /// (copy constructor)
        /// </summary>
        ProgramUserBlockResult(const ProgramUserBlockResult & programUserBlockResult);
    };

}
#endif /* _TETON_PROGRAMUSERBLOCKRESULT_H_ */
