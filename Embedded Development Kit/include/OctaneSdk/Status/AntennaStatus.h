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

#ifndef _TETON_ANTENNASTATUS_H_
#define _TETON_ANTENNASTATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup status */
    /// <summary>
    /// The status information for an antenna port.
    /// </summary>
    class AntennaStatus
    {
      public:
        /// <summary>
        /// The antenna port number, 1-4.
        /// </summary>
        /// <remarks>
        /// This is advisory so the port number is known
        /// when using foreach, or when passing a
        /// single antenna status as an argument.
        /// </remarks>
        int PortNumber;

	/// <summary>
        /// Whether the antenna port is connected
        /// to an antenna.
        /// </summary>
        AntennaConnectionState State;

	/// <summary>
        /// Whether the application enabled this antenna.
        /// </summary>
        bool IsEnabled;

        /// <summary>
        /// Initializes a new instance of the AntennaStatus class.
        /// </summary>
        AntennaStatus();

        /// <summary>
        /// Initializes a new instance of the AntennaStatus class
        /// (copy constructor).
        /// </summary>
        /// <param name="antennaStatus">
        /// The object instance to copy.
        /// </param>
	AntennaStatus(const AntennaStatus &antennaStatus);

	/// <summary>
        /// Initializes a new instance of the AntennaStatus class
        /// (assignment constructor).
        /// </summary>
        /// The object instance to copy.
        /// </param>
	AntennaStatus& operator=(const AntennaStatus &);

	/// <summary>
        /// True if the anntena port is connected to an antenna.
        /// </summary>
        bool IsConnected();
    };
}

#endif /* _TETON_ANTENNASTATUS_H_ */
