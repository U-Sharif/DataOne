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
#ifndef _TETON_RUNPRIMITIVESEQUENCEPARAMS_H_
#define _TETON_RUNPRIMITIVESEQUENCEPARAMS_H_
#include <list>

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// Class used to carry the configuration for the
    /// <see cref="SpeedwayReader.RunPrimitiveSequence"/> method
    /// </summary>
    class RunPrimitiveSequenceParams : public CommonAccessParams
    {
      public:

        /// <summary> The list of primitive operations to perform</summary>
        list<PrimitiveParams*> PrimitiveParameters;

        /// <summary>
        /// Initializes a new instance of the RunPrimitiveSequenceParams class
        /// from a commonAccessParams instance
        /// </summary>
        /// <param name="commonAccessParams">initializer</param>
        RunPrimitiveSequenceParams(const CommonAccessParams & commonAccessParams);

        /// <summary>
        /// Initializes a new instance of the RunPrimitiveSequenceParams class
        /// (copy constructor)
        /// </summary>
        RunPrimitiveSequenceParams(const RunPrimitiveSequenceParams & runPrimitiveSequenceParams);

        /// <summary>
        /// Destroy the instance
        /// </summary>
        ~RunPrimitiveSequenceParams();
    };
}

#endif /* _TETON_RUNPRIMITIVESEQUENCEPARAMS_H_ */
