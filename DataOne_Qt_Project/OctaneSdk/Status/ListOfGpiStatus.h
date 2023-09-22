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

#ifndef _TETON_LISTOFGPISTATUS_H_
#define _TETON_LISTOFGPISTATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup status */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="GpiStatus"/> objects. Different reader products
    /// support different numbers of general purpose inputs (GPIs)
    /// and this class encapsulates that varying number.
    /// </summary>
    /// <seealso cref="GpiStatus"/>
    class ListOfGpiStatus
    {
      public:

	/// <summary>
        /// A variable-length array of <see cref="GpiStatus"/>
        /// objects.
        /// </summary>
	GpiStatus                       Elements[Constants::MaxGpiPortNumber];

        /// <summary>
        /// Initializes a new instance of the ListOfGpiStatus class.
        /// </summary>
        ListOfGpiStatus(void);

        /// <summary>
        /// Initializes a new instance of the ListOfGpiStatus class
        /// (copy constructor).
        /// </summary>
        /// <param name="listOfGpiStatus">
        /// The object instance to copy.
        /// </param>
        ListOfGpiStatus(
          const ListOfGpiStatus &       listOfGpiStatus);

	/// <summary>
	/// Destructor for this instance of the ListOfGpiStatus object
	/// </summary>
        ~ListOfGpiStatus();

	/// <summary>
	/// Array operator
	/// </summary>
        GpiStatus &
        operator[](
          int                           gpiPortNumber);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LISTOFGPISTATUS_H_ */
