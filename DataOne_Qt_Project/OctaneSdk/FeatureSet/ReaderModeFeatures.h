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

#ifndef _TETON_READERMODEFEATURES_H_
#define _TETON_READERMODEFEATURES_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="ReaderModeEntry"/> objects. Different reader
    /// products support different modes and this class
    /// encapsulates that varying number.
    /// </summary>
    /// <seealso cref="ReaderModeEntry"/>	
    class ReaderModeFeatures
    {
      public:

	/// <summary>
        /// Initializes a new instance of the
        /// ReaderModeFeatures class.
        /// </summary>
        ReaderModeFeatures (void);
      
	/// <summary>
	/// Destroys the current instance of the ReaderModeFeatures class
	/// </summary>
        ~ReaderModeFeatures ();

	/// <summary>
	/// the maximum number of entries in the 
	/// ReaderModeEntry array
	/// </summary>
        static const int        DimEntries = 10;

	/// <summary>
	/// The number of entries in the ReaderModeEntry array
	/// </summary>      
        int                     nEntries;

	/// <summary>
        /// An array of
        /// <see cref="ReaderModeEntry"/> objects.
        /// </summary>
        ReaderModeEntry         Entries[DimEntries];
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_READERMODEFEATURES_H_ */
