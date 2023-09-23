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
#ifndef _TETON_READACCESSPASSWORDPARAMS_H_
#define _TETON_READACCESSPASSWORDPARAMS_H_ 

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ReadAccessPassword operation
    /// </summary>
    class ReadAccessPasswordParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// Initializes a new instance of the ReadAccessPasswordParams class
        /// </summary>
        ReadAccessPasswordParams();

        /// <summary>
        /// Initializes a new instance of the ReadAccessPasswordParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams"></param>
        ReadAccessPasswordParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ReadAccessPasswordParams class
        /// (copy constructor)
        /// </summary>
        ReadAccessPasswordParams(const ReadAccessPasswordParams & readAccessPasswordParams);
    };
}
#endif /* _TETON_READACCESSPASSWORDPARAMS_H_ */
