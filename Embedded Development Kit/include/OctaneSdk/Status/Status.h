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

#ifndef _TETON_STATUS_H_
#define _TETON_STATUS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /*! @ingroup status */
    /// <summary>
    /// Contains the reader status
    /// </summary>
    /// <remarks>
    /// This class contains the status of the reader.  The 
    /// SpeedwayReader class method SpeedwayReader.QueryStatus method
    /// return the current reader status via an instance of this class.
    /// </remarks>
    class Status
    {
      public:

        /// <summary>
        /// This is the value set on SpeedwayReader.ReaderIdentity
        /// by the application. It may be used as a back pointer to
        /// application specific data. The default is a hex string with the
        /// readers unique identity (see FeatureSet.ReaderIdentity).
        /// </summary>
        void *                      ReaderIdentity;

        /// <summary>
        /// The state of the network connection to the reader.
        /// Example: ApplicationConnectionState.Connected. Possible
        /// values are NotConnected, Connected, Disconnected,
        /// ConnectionLost.
        /// <summary>
        ApplicationConnectionState  Connection;

        /// <summary>
        /// The state of the reader RFID activity. Example:
        /// OperationalState.Ready. Possible values are: Unknown,
        /// NotConfigured, Ready, Singulating.
        /// </summary>
        OperationalState            Operational;

        /// <summary>
        /// Table of antenna status. 
        /// </summary>
        ListOfAntennaStatus         Antennas;

        /// <summary>
        /// Table of GPI status.
        /// </summary>
        ListOfGpiStatus             Gpis;

        /// <summary>
        /// Table of GPO status.
        /// </summary>
        ListOfGpoStatus             Gpos;

        /// <summary>The on-board temperature of the readers power amplifier.
        /// </summary>
        int                         TemperatureInCelsius;

        /// <summary>
        /// Default constructor
        /// </summary>
        Status();
        /// <summary>
        /// Copy constructor
        /// </summary>
        Status(const Status& status);

        /// <summary>Short-hand property that indicates the network connection
        /// to the reader is present and healthy.</summary>
        bool IsConnected();

        /// <summary>
        /// Short-hand property that indicates the reader is actively
        /// singulating tags.
        /// </summary>
        bool IsRunning();
    };
}

#endif /* _TETON_STATUS_H_ */
