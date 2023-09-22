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

#ifndef _TETON_LISTOFGPOSTATUS_H_
#define _TETON_LISTOFGPOSTATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup status */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="GpoStatus"/> objects. Different reader products
    /// support different numbers of general purpose inputs (GPOs)
    /// and this class encapsulates that varying number.
    /// </summary>
    /// <seealso cref="GpoStatus"/>	
    class ListOfGpoStatus
    {
      public:
	/// <summary>
        /// An array of <see cref="GpoStatus"/>
        /// objects.
        /// </summary>
        GpoStatus                       Elements[Constants::MaxGpoPortNumber];

        /// <summary>
        /// Initializes a new instance of the ListOfGpoStatus class.
        /// </summary>
        ListOfGpoStatus(void);

        /// <summary>
        /// Initializes a new instance of the ListOfGpoStatus class
        /// (copy constructor).
        /// </summary>
        /// <param name="listOfGpoStatus">
        /// The object instance to copy.
        /// </param>
        ListOfGpoStatus(
          const ListOfGpoStatus &       listOfGpoStatus);

	/// <summary>
	/// Destructor for this instance of the ListOfGpoStatus object
	/// </summary>
        ~ListOfGpoStatus();

	/// <summary>
	/// Array operator
	/// </summary>
        GpoStatus &
        operator[](
          int                           gpoPortNumber);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LISTOFGPOSTATUS_H_ */
