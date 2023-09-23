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

#ifndef _TETON_PRIMITIVEGETQTCONFIGPARAMS_H_
#define _TETON_PRIMITIVEGETQTCONFIGPARAMS_H_ 
namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// The low level access primitive for getting the QT configuration
    /// status from a tag
    /// </summary>
    class PrimitiveGetQtConfigParams : PrimitiveParams
    {
      public:
        /// <summary>
        /// Construct a PrimitiveGetQtConfigParams instance
        /// </summary>
        PrimitiveGetQtConfigParams();

        /// <summary>
        /// Construct a PrimitiveGetQtConfigParams instance
        /// (copy constructor)
        /// </summary>
        PrimitiveGetQtConfigParams(const PrimitiveGetQtConfigParams & primitiveGetQtConfigParams);

        /// <summary>
        /// Duplicate the instance
        /// </summary>
        /// <returns>PrimitiveGetQtConfigParams</returns>
        PrimitiveParams * Clone();
    };
}
#endif /* _TETON_PRIMITIVEGETQTCONFIGPARAMS_H_ */
