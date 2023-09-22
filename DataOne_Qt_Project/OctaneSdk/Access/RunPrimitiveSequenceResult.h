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
#ifndef _TETON_RUNPRIMITIVESEQUENCERESULT_H_
#define _TETON_RUNPRIMITIVESEQUENCERESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup primitiveaccess */
    /// <summary>
    /// Class used to carry the results of a
    /// <see cref="SpeedwayReader.RunPrimitiveSequence"/>
    /// operation
    /// </summary>
     class RunPrimitiveSequenceResult : public CommonAccessResult
    {
      public:
        /// <summary> The list of primitive results</summary>
        list<PrimitiveResult*> PrimitiveResults;

        /// <summary>
        /// Initializes a new instance of the RunPrimitiveSequenceResult class
        /// </summary>
        RunPrimitiveSequenceResult();

        /// <summary>
        /// Initializes a new instance of the RunPrimitiveSequenceResult class
        /// from a commonAccessResult instance
        /// </summary>
        /// <param name="commonAccessResult">initializer</param>
        RunPrimitiveSequenceResult(const CommonAccessResult & commonAccessResult);

        /// <summary>
        /// Initializes a new instance of the RunPrimitiveSequenceResult class
        /// (copy constructor)
        /// </summary>
        RunPrimitiveSequenceResult(const RunPrimitiveSequenceResult & runPrimitiveSequenceResult);

        /// <summary>
        /// Destroy the instance
        /// </summary>
        ~RunPrimitiveSequenceResult();
    };
}


#endif /* _TETON_RUNPRIMITIVESEQUENCERESULT_H_ */
