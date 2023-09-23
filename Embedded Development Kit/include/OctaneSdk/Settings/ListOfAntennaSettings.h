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

#ifndef _TETON_LISTOFANTENNASETTINGS_H_
#define _TETON_LISTOFANTENNASETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains an array of
    /// <see cref="AntennaSettings"/> objects. Different reader
    /// products support different numbers of antennas and this class
    /// encapsulates that varying number.
    /// </summary>
    /// <seealso cref="AntennaSettings"/>
    class ListOfAntennaSettings
    {
      public:
        /// <summary>
        /// An array of <see cref="AntennaSettings"/>
        /// objects.
        /// </summary>	      
        AntennaSettings                 Elements[Constants::MaxAntennaPortNumber];

        /// <summary>
        /// Initializes a new instance of the ListOfAntennaSettings
        /// class.
        /// </summary>
        ListOfAntennaSettings(void);

        /// <summary>
        /// Initializes a new instance of the ListOfAntennaSettings
        /// class (copy constructor).
        /// </summary>
        /// <param name="listOfAntennaSettings">
        /// The object instance to copy.
        /// </param>
        ListOfAntennaSettings(
          const ListOfAntennaSettings & listOfAntennaSettings);

	/// <summary>
	/// Destructor for the current instance of the ListOfAntennaSettings object
	/// </summary>
        ~ListOfAntennaSettings();

	/// <summary>
	///  Retrieve a specific Antenna Setting
	/// </summary>
	/// <param name="antennaPortNumber">
	/// the antenna port number, 1... N
	/// </param>
        AntennaSettings &
        operator[](
          int                           antennaPortNumber);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LISTOFANTENNASETTINGS_H_ */
