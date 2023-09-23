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

#ifndef _TETON_PRIMITIVESETQTCONFIGRESULT_H_
#define _TETON_PRIMITIVESETQTCONFIGRESULT_H_
namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for conveying the set QT
    /// configuration result
    /// </summary>
    class PrimitiveSetQtConfigResult : public PrimitiveResult
    {
      public:
        /// <summary>
        /// The access result of the SetQtConfig primitive operation
        /// </summary>
        AccessResult Result;

        /// <summary>
        /// Construct a PrimitiveSetQtConfigResult instance
        /// </summary>
        PrimitiveSetQtConfigResult();
        /// <summary>
        /// Construct a PrimitiveSetQtConfigResult instance
        /// (copy constructor)
        /// </summary>
        PrimitiveSetQtConfigResult(const PrimitiveSetQtConfigResult & primitiveSetQtConfigResult);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveResult</returns>
        PrimitiveResult * Clone();
    };
}

#endif /* _TETON_PRIMITIVESETQTCONFIGRESULT_H_ */
