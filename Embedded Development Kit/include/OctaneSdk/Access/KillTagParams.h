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

#ifndef _TETON_KILLTAGPARAMS_H_
#define _TETON_KILLTAGPARAMS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// Class used to carry the configuration for the SpeedwayReader.KillTag
    /// operation
    /// </summary>
    class KillTagParams : public CommonAccessParams 
    {
      public:
        /// <summary> The kill password for the tag
        /// </summary>
        /// <remarks>
        /// string consists of hexidecimal characters (i.e.
        /// [0-9a-fA-F]). The kill password is a 32-bit
        /// number so this string may be up to 8 hexidecimal
        /// characters.
        /// </remarks>
        string KillPassword;

        /// <summary> Default Constructor </summary>
        KillTagParams();

        /// <summary> Construct a KillTagParams from a base class
        /// instance</summary>
        KillTagParams(const CommonAccessParams & commonAccessParams);

        /// <summary> Copy constructor </summary>
        KillTagParams(const KillTagParams &killTagParams);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_KILLTAGPARAMS_H_ */
