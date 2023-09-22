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

#ifndef _TETON_FEATURESET_H_
#define _TETON_FEATURESET_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup features */
    /*! @ingroup core */
    /// <summary>
    /// This class reports the capabilities and feautures of a reader
    /// </summary>
    /// <remarks>
    /// Reader features can be queried through the SpeedwayReader class
    /// SpeedwayReader.QueryFeatureSet method.  This method returns
    /// an instance of this class.  The features set describes the 
    /// features of the reader that may vary from model to model, 
    /// from one regulatory region to another, and between one individual
    /// reader and another. 
    /// </remarks>
    class FeatureSet
    {
      public:
	
	/// <summary>
        /// Initializes a new instance of the FeatureSet class.
        /// </summary>	      
        FeatureSet (void);
 
	/// <summary>
        /// Destroys the current instance of the FeatureSet class.
        /// </summary>      
      ~FeatureSet ();

        /// <summary>Max size of ModelName </summary>
        static const int        DimModelName        = 64;
        /// <summary>Max size of SerialNumber </summary>
        static const int        DimSerialNumber     = 64;
        /// <summary>Max size of SoftwareVersion </summary>
        static const int        DimSoftwareVersion  = 64;
        /// <summary>Max size of FirmwareVersion </summary>
        static const int        DimFirmwareVersion  = 64;
        /// <summary>Max size of FpgaVersion </summary>
        static const int        DimFpgaVersion      = 64;
        /// <summary>Max size of PcbaVersion </summary>
        static const int        DimPcbaVersion      = 64;
        /// <summary>Max size of ReaderIdentity </summary>
        static const int        DimReaderIdentity   = 20;

        /// <summary>
        /// The common model name of the reader, example: Speedway R420
        /// </summary>
        char                    ModelName[DimModelName];

	/// <summary>
        /// The serial number of the reader, example: 940-09-22-0001
        /// </summary>
        char                    SerialNumber[DimSerialNumber];

	/// <summary>
        /// The software version, example: 4.4.0.240
        /// </summary>
        char                    SoftwareVersion[DimSoftwareVersion];

	/// <summary>
        /// The firmware (modem) version, example: 4.4.0.20
        /// </summary>
        char                    FirmwareVersion[DimSoftwareVersion];

	/// <summary>
        /// The FPGA mask program version, example: 4.4.0.64
        /// </summary>
        char                    FpgaVersion[DimFpgaVersion];

	/// <summary>
        /// The Printed Circuit Board Assembly version, example: 250-002-000
        /// </summary>
        char                    PcbaVersion[DimFpgaVersion];

        /// <summary>
        /// The integer model number from LLRP, example: 2001002
        /// </summary>
        unsigned int            ModelNumber;

        /// <summary>
        /// The regulatory region the reader complies to,
        /// example: FCC_Part_15_247.
        /// </summary>
	const char *            Subregion;

        /// <summary>
        /// Whether the readers region uses hopping.
        /// False means the frequency may be selected
        /// by the application.
        /// </summary>
	bool                    IsHoppingRegion;

	/// <summary>
        /// The readers unique identity, 16 hex digits,
        /// example: 001625FFFF0000C3
        /// </summary>
        char                    ReaderIdentity[DimReaderIdentity];

	/// <summary>
        /// The number of antenna ports on the reader.
        /// </summary>
	int                     AntennaCount;

	/// <summary>
        /// The number of General Purpose Input (GPI) ports on the reader.
        /// </summary>
        int                     GpiCount;

	/// <summary>
        /// The number of General Purpose Output (GPO) ports on the reader.
        /// </summary>
        int                     GpoCount;

	/// <summary>
        /// The number of access specs suppored by the reader.
        /// This is important internally but rarely of interest
        /// to the application.
        /// </summary>
        int                     MaxAccessSpecs;

        /// <summary>
        /// Whether the reader can do tag access, such as
        /// change tag EPC, r/w tag user memory.
        /// </summary>
        bool                    IsTagAccessAvailable;

	/// <summary>
        /// Whether the reader supports TagFilter filters.
        /// <see cref="FilterSettings"/>
        /// </summary>
	bool                    IsFilteringAvailable;

	/// <summary>
        /// Whether the reader supports debouncing general
        /// purpose inputs.
        /// See <see cref="GpiSettings"/>
        /// </summary>
        bool                    IsGpiDebounceAvailable;

	/// <summary>
        /// Whether the reader supports link monitoring.
        /// See <see cref="KeepAliveSettings"/>
        /// </summary>
        bool                    IsLinkMonitorAvailable;

	/// <summary>
        /// Whether the reader supports multiword block write.
        /// </summary>
        bool                    IsMultiwordBlockWriteAvailable;

        /// <summary>
        /// Whether the reader supports phase angle reporting.
        /// See <see cref="ReportSettings"/> and <see cref="Tag"/>.
        /// </summary>
        bool                    IsPhaseAngleReportingAvailable;

	/// <summary>
        /// Whether the reader supports automatic reading
        /// of serialized TID (Tag ID).
        /// See <see cref="ReportSettings"/> and <see cref="Tag"/>.
        /// </summary>
        bool                    IsSerializedTidReportingAvailable;

	/// <summary>
        /// Whether the reader supports higher precission RSSI
        /// reporting.
        /// See <see cref="ReportSettings"/> and <see cref="Tag"/>.
        /// </summary>
        bool                    IsImpinjRssiReportingAvailable;

        /// <summary>
        /// Reader modes supported by the reader. These
        /// control RF modulation and data encoding.
        /// </summary>
        ReaderModeFeatures      ReaderModes;

        /// <summary>
        /// Search modes supported by the reader.
        /// </summary>
	SearchModeFeatures      SearchModes;

        /// <summary>
        /// Transmit powers available on the reader.
        /// </summary>
	TxPowerFeatures         TxPowers;

	/// <summary>
        /// Receive sensitivities available on the reader.
        /// </summary>
	RxSensitivityFeatures   RxSensitivities;

        /// <summary>
        /// Transmit frequencies used by the reader.
        /// In non-hopping regions these are the frequencies
        /// that may be requested by the application.
        /// </summary>
	TxFrequencyFeatures     TxFrequencies;

        /// <summary>
        /// Frequencies that may have their power reduced.
        /// Used to mitigate interference. Only available
        /// in the FCC region.
        /// </summary>
	TxFrequencyFeatures     ReducedPowerTxFrequencies;

        /// <summary>
        /// The <see cref="Settings"/> crafted from factory values
        /// on the reader.
        /// </summary>
        Settings                FactorySettings;

	/// TODO: document this
        void
        Save (
          char *                path);

	/// TODO: document this
        Settings
        QueryFactorySettings (
          void);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_FEATURESET_H_ */
