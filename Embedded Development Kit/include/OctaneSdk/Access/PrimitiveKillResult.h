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

#ifndef _TETON_PRIMITIVEKILLRESULT_H_
#define _TETON_PRIMITIVEKILLRESULT_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the kill primitive
    /// results.
    /// </summary>
    class PrimitiveKillResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the kill primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// Construct a PrimitiveKillResult instance
        /// </summary>
        PrimitiveKillResult();

        /// <summary>
        /// Construct a PrimitiveKillResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveKillResult(const PrimitiveKillResult & primitiveKillResult);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        PrimitiveResult * Clone();
    };
}
#endif /* _TETON_PRIMITIVEKILLRESULT_H_ */
