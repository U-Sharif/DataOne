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

#ifndef _TETON_LISTOFGPISETTINGS_H_
#define _TETON_LISTOFGPISETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /// <summary>
    /// This class contains a variable-length array of
    /// <see cref="GpiSettings"/> objects. Different reader products
    /// support different numbers of general purpose inputs (GPIs)
    /// and this class encapsulates that varying number.
    /// </summary>
    /// <seealso cref="GpiSettings"/>
    class ListOfGpiSettings
    {
      public:
        /// <summary>
        /// An array of <see cref="GpiSettings"/>
        /// objects.
        /// </summary>
        GpiSettings                     Elements[Constants::MaxGpiPortNumber];

        /// <summary>
        /// Initializes a new instance of the ListOfGpiSettings class.
        /// </summary>	
        ListOfGpiSettings(void);

        /// <summary>
        /// Initializes a new instance of the ListOfGpiSettings class
        /// (copy constructor).
        /// </summary>
        /// <param name="listOfGpiSettings">
        /// The object instance to copy.
        /// </param>      
        ListOfGpiSettings(
          const ListOfGpiSettings &     listOfGpiSettings);

	/// <summary>
	/// Destructor for the current instance of the ListOfGpiSettings class
	/// </summary>
        ~ListOfGpiSettings();

	/// <summary>
	/// Retrieve a specific Gpi Setting
	/// <summary>
	/// <param name="gpiPortNumber"> 
	/// the GPI port number to fetch 1...N
	/// </param>
        GpiSettings &
        operator[](
          int                           gpiPortNumber);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_LISTOFGPISETTINGS_H_ */
