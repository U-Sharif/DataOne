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

#ifndef _TETON_LISTOFANTENNASTATUS_H_
#define _TETON_LISTOFANTENNASTATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup status */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="AntennaStatus"/> objects. Different reader
    /// products support different numbers of antennas and this class
    /// encapsulates that varying number.
    /// </summary>
    /// <seealso cref="AntennaStatus"/>
    class ListOfAntennaStatus
    {
      public:
        /// <summary>
        /// An array of <see cref="AntennaStatus"/>
        /// objects.
        /// </summary>
        AntennaStatus                   Elements[Constants::MaxAntennaPortNumber];

	/// <summary>
        /// Initializes a new instance of the ListOfAntennaStatus
        /// class.
        /// </summary>
        ListOfAntennaStatus(void);

        /// <summary>
        /// Initializes a new instance of the ListOfAntennaStatus
        /// class (copy constructor).
        /// </summary>
        /// <param name="listOfAntennaStatus">
        /// The object instance to copy.
        /// </param>
        ListOfAntennaStatus(
          const ListOfAntennaStatus &   listOfAntennaStatus);

	/// <summary>
	/// Destructor for this instance of the ListOfAntennaStatus object
	/// </summary>
        ~ListOfAntennaStatus();

	/// <summary>
	/// Array operator
	/// </summary>
        AntennaStatus &
        operator[](
          int                           antennaPortNumber);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LISTOFANTENNASTATUS_H_ */
