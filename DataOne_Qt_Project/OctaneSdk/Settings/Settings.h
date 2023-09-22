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

#ifndef _TETON_SETTINGS_H_
#define _TETON_SETTINGS_H_

namespace Impinj_OctaneSdk
{
    /*! @ingroup settings */
    /*! @ingroup core */
    /// <summary>
    /// This class contains all the settings necessary for a reader to
    /// begin singulating. 
    /// </summary> 
    /// <remarks>It is a composite class consisting of other
    /// composite classes containing individual settings.
    /// </remarks>
    class Settings
    {
      public:
        /// <summary> Maximum size of Label string </summary>
        static const int                DimLabel = 100;
        /// <summary> Maximum size of Description string </summary>
        static const int                DimDescription = 100;
        /// <summary> Maximum size of TxFrequenciesInMhz string </summary>
        static const int                DimTxFrequenciesInMhz = 10;

        /// <summary>
        /// A short name, like a file name, for these settings.
        /// </summary>
        char                            Label[DimLabel];

        /// <summary>
        /// A short description of these settings, like a comment
        /// or remark.
        /// </summary>
        char                            Description[DimDescription];

        /// <summary>
        /// The reader mode controls modulation and data rate.
        /// </summary>
        /// <remarks> Not
        /// all modes are available on all models and regions. Example:
        /// ReaderMode.AutoSetDenseReader. Possible values are
        /// AutoSetDenseReader, AutSetSingleReader, MaxThroughput,
        /// Hybrid, DenseReaderM4, DenseReaderM8, and MaxMiller.
        /// </remarks>
        enum ReaderMode                 ReaderMode;

        /// <summary>
        /// The search mode controls whether tags are singulated
        /// repeatedly or once.
        /// </summary>
        /// <remarks>
        /// Example SearchMode.DualTarget. Possible
        /// values are: ReaderSelected, DualTarget, SingleTarget,
        /// SingleTargetWithSuppression.
        /// </remarks>
        enum SearchMode                 SearchMode;

        /// <summary>
        /// The session the reader should use.
        /// </summary>
        /// <remarks>Sessions have different
        /// persistence characteristics after the tag no longer receives
        /// power from the reader. Possible values are 0-3.
        /// </remarks>
        int                             Session;

        /// <summary>
        /// An estimate of how many tags will be in the reader’s field of
        /// view at one time.
        /// </summary>
        int                             TagPopulationEstimate;

        /// <summary>
        /// Controls which tags the reader singulates and reports.
        /// </summary>
        FilterSettings                  Filters;

        /// <summary>The per-antenna reader settings </summary>
        ListOfAntennaSettings           Antennas;

        /// <summary>
        /// This is a set of transmit frequencies the reader should use.
        /// </summary>
        /// <remarks> It is an error to have any elements in this list if the reader is
        /// operating in a hopping region. In non-hopping regions and empty
        /// list means the reader selects the frequencies to use. Use only
        /// frequencies supported by the reader. Typical values vary by
        /// region. Example: TxFrequenciesInMhz.Add(866.9)
        /// </remarks>
        double                          TxFrequenciesInMhz[DimTxFrequenciesInMhz];
        
        /// <summary>
        /// The number of transmit frequencies configured for the reader
        /// in Settings.TxFrequenciesInMhz.
        /// </summary>
        int                             nTxFrequenciesInMhz;
   
        /// <summary>
        /// This is a set of transmit frequencies the reader should
        /// use reduced power rather than the power specified by
        /// AntennaSettings.TxPowerInDbm.
        /// </summary>
        /// <remarks>This is only available in the FCC region and is
        /// used to mitigate spectrum interference. Example:
        /// ReducedPowerTxFreqeunciesInMhz.Add(910.250)
        /// </remarks>
        double                          ReducedPowerTxFrequenciesInMhz[DimTxFrequenciesInMhz];

        /// <summary>
        /// The number of reduced power frequencies configured for the reader
        /// as specified in Settings.ReducedPowerTxFrequenciesInMhz
        /// </summary>
        int                             nReducedPowerTxFrequenciesInMhz;

        /// <summary> The settings that control a reduced duty cycle
        /// mode of the reader which reduces interference</summary>
        LowDutyCycleSettings            LowDutyCycle;

        /// <summary> The settings that control a readers
        /// auto-start feature</summary>
        AutoStartSettings               AutoStart;

        /// <summary> The settings that control a readers
        /// auto-stop feature</summary>
        AutoStopSettings                AutoStop;

        /// <summary>
        /// The report settings control how often the reader sends a report
        /// of tags singulated, and which optional fields are reported.
        /// </summary>
        ReportSettings                  Report;

        /// <summary>
        /// Table of GPI settings. The GPI is selected by its port number in
        /// the range 1-4.
        /// </summary>
        ListOfGpiSettings               Gpis;

        /// </summary>
        /// The reader can send a keep-alive message at regular intervals.
        /// </summary>
        KeepAliveSettings               KeepAlive;

        /// <summary>
        /// unknown
        /// </summary>
        bool                            IsTimestampCorrectionEnabled;

        /// <summary> Default constructor </summary>
        Settings(void);
        /// <summary> Copy constructor </summary>
        Settings(const Settings & settings);
        /// <summary> Default destructor </summary>
        ~Settings();

        /// <summary>
        /// Loads and inializes a Settings object from a file
        /// </summary>
        /// <param name="path">a C-string path to the file</param>
        /// <returns>The newly constructed Settings object</returns>
        static Settings
        Load(const char * path);

        /// <summary>
        /// Saves the setting object to a ascii XML file
        /// <param name="path">a C-string path to the file</param>
        /// </summary>
        void
        Save(const char * path);

        /// <summary>
        /// Loads and inializes a Settings object from a file
        /// </summary>
        /// <param name="path">a C-string path to the file</param>
        /// <param name="outSettings">The newly constructed settings
        ///                       returned by reference</param>
        /// <returns>true if the settings object was retrieved</returns>
        static bool
        TryLoad(const char * path, Settings *outSettings);

        /// <summary>
        /// Saves the settings object to an ascii XML file
        /// </summary>
        /// <param name="path">a C-string path to the file</param>
        /// <returns>true if the settings were saved</returns>
        bool
        TrySave(const char * path);
    };
} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_SETTINGS_H_ */
