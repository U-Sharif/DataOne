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
#ifndef _TETON_READKILLPASSWORDPARAMS_H_
#define _TETON_READKILLPASSWORDPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class to carry the configuration for a
    /// SpeedwayReader.ReadKillPassword operation
    /// </summary>
    class ReadKillPasswordParams : public CommonAccessParams
    {
      public:
        /// <summary>
        /// Initializes a new instance of the ReadKillPasswordParams class
        /// </summary>
        ReadKillPasswordParams();

        /// <summary>
        /// Initializes a new instance of the ReadKillPasswordParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams"></param>
        ReadKillPasswordParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the ReadKillPasswordParams class
        /// (copy constructor)
        /// </summary>
        ReadKillPasswordParams(const ReadKillPasswordParams & readKillPasswordParams);
    };
}
#endif /* _TETON_READKILLPASSWORDPARAMS_H_ */
