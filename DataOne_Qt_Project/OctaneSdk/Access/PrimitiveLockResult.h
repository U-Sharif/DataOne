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

#ifndef _TETON_PRIMITIVELOCKRESULT_H_
#define _TETON_PRIMITIVELOCKRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the lock primitive
    /// results.
    /// </summary>
    class PrimitiveLockResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the lock primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// Construct a PrimitiveLockResult instance
        /// </summary>
        PrimitiveLockResult();

        /// <summary>
        /// Construct a PrimitiveLockResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveLockResult(const PrimitiveLockResult &primitiveLockResult);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        PrimitiveResult * Clone();
    };
}

#endif /* _TETON_PRIMITIVELOCKRESULT_H_ */
