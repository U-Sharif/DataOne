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

#ifndef _TETON_RXSENSITIVITYFEATURES_H_
#define _TETON_RXSENSITIVITYFEATURES_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="RxSensitivityEntry"/> objects. Different reader
    /// products support different sensitivities and this class
    /// encapsulates that varying number.
    /// </summary>
    /// <seealso cref="RxSensitivityEntry"/>
    class RxSensitivityFeatures
    {
      public:
	/// <summary>
	/// Initializes a new instance of the RxSensitivityFeatures class
	/// </summary>
        RxSensitivityFeatures (void);
      
	/// <summary>
	/// Destroys the current instance of the RxSensitivityFeatures class
	/// </summary>
        ~RxSensitivityFeatures ();

	/// <summary>
	/// The maximum number of entries in the <see cref="RxSensitivityEntry"/> array
	/// </summary>
        static const int        DimEntries = 60;

	/// <summary>
	/// The number of entries in the RxSensitivityEntry array
	/// </summary>
        int                     nEntries;
      
	/// <summary>
        /// An array of <see cref="RxSensitivityEntry"/> objects.
        /// </summary>
       RxSensitivityEntry      Entries[DimEntries];
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_RXSENSITIVITYFEATURES_H_ */
