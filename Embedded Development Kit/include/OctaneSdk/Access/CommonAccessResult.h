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

#ifndef _TETON_COMMONACCESSRESULT_H_
#define _TETON_COMMONACCESSRESULT_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup simpleaccess */
    /// <summary>
    /// This class contains all the common results for tag access.
    /// </summary>
    /// <remarks>
    /// Several properties required for tag access results are shared
    /// between the various methods. To avoid duplicating these
    /// properties in the results class of each individual method,
    /// this class is used to encapsulate them. As this class should
    /// always be a base class, it is declared abstract.
    /// </remarks>
    class CommonAccessResult
    {
      public:
        /// <summary>
        /// The tag on which the operation was performed.
        /// </summary>
        Tag TagAccessed;

        /// <summary>
        /// The overall result of the operation.
        /// </summary>
        AccessResult Result;

      protected: 
        /// <summary>
        /// This protected routine is called from the various copy
        /// constructors to assign the common properties from one
        /// object instance to another.
        /// </summary>
        /// <param name="commonAccessResult">
        /// The object instance to copy.
        /// </param>
        void assignCommonResult(const CommonAccessResult & commonAccessResult);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_COMMONACCESSRESULT_H_ */
