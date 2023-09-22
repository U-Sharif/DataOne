/*
 ****************************************************************************
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

#ifndef _TETON_SPEEDWAYREADER_H_
#define _TETON_SPEEDWAYREADER_H_

namespace Impinj_OctaneSdk_Internals {
    class LtkProxy;
};

namespace Impinj_OctaneSdk
{
    /*! @ingroup core */
    /// <summary>
    /// The main class for the OctaneSDK
    /// </summary>
    /// <remarks>
    /// This class contains the information for operating a single
    /// reader via the Octane SDK.  
    /// </remarks>
    class SpeedwayReader
    {
      public:
        SpeedwayReader (void);
        virtual ~SpeedwayReader ();

        /// <summary> This is the value set by the application. It may be used as
        /// a back pointer to application specific data. The default is a hex
        /// string with the reader’s unique identity (see
        /// FeatureSet.ReaderIdentity ).
        /// </summary>
        void *    ReaderIdentity;

        /// <summary>
        /// The amount of detail the application wants logged from
        /// this SpeedwayReader. Example: LogLevel.Warning. Possible
        /// values are Off, Error, Warning, Information, Verbose, Trace,
        /// Debug.
        /// </summary>
        enum LogLevel  LogLevel;

        // Access  related methods
//        ProgramEpcResult ProgramEpc(ProgramEpcParams * accessParams);

        // Command related methods

        /// <summary>Connect the instance to a reader</summary>
        /// <param name="readerName">the reader IP address or hostname </param>
        /// <remarks>Connect to a reader. The readerName is a string with
        /// the host name or IP address of the reader. After
        /// connection either ChangeSettings or
        /// ResumeEventsAndReports must be called before
        /// events or tag reports are delivered.
        /// Events and reports are held until either ApplySettings,
        /// ApplyFactorySettings, or ResumeEventsAndReports is done.
        /// </remarks>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayConnectException">
        /// Thrown when the connection attempt fails.
        /// Most likely the reader name is invalid, the reader
        /// is busy, or there is already a connection.</exception>
        void Connect(const char * readerName);

        /// <summary>Disconnect the instance from a reader</summary>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        void Disconnect();

        /// <summary>Clears the settings on the reader to factory 
        /// default </summary>
        /// <remarks>
        /// This returns the reader to a factory state where no
        /// settings are on the reader. In this state the
        /// reader can do no RFID operations.
        /// </remarks>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        void ClearSettings();

        /// <summary>Return the FeatureSet of the reader. This includes
        /// supported modes, powers, frequencies, and optional
        /// features. 
        /// </summary>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        FeatureSet QueryFeatureSet();
        
        /// <summary>
        /// Query the status of the reader including antennas, GPIs,
        /// and operation.
        /// </summary>
        /// <remarks>
        /// The status includes connection status, operation (RFID)
        /// status, antenna connectivity, GPI levels, etc.
        /// <para>
        /// Normally the status is maintained internally based on
        /// event notifications from the reader.
        /// There are times when the application wants to be sure
        /// the reader is checked for status even though the checking
        /// takes longer. For example, GPIs that are not enabled
        /// do not produce events when the input level changes and
        /// the reader must be asked to check the GPIs.
        /// </para>
        /// <para>
        /// Typically an application is only interested in the status
        /// that is maintained and needs the speed of not checking
        /// the reader.
        /// </para>
        /// </remarks>
        /// <param name="statusRefresh">What status to assure
        /// is retrieved from the reader.</param>
        /// <returns>Status of the reader.</returns>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        Status QueryStatus(StatusRefresh statusRefresh);

        /// <summary>
        /// Query the status of the reader. Same as
        /// QueryStatus(StatusRefresh.None).
        /// </summary>
        /// <returns>Status of the reader.</returns>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        Status QueryStatus();

        /// <summary>
        /// Query the Settings according to the reader defaults.
        /// </summary>
        /// <remarks>
        /// Typically an application queries the factory settings,
        /// then adjusts them to suit the application's purpose,
        /// the uses ApplySettings.
        /// </remarks>
        /// <returns>Settings based on the factory values
        /// of the reader.
        /// </returns>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        Settings QueryFactorySettings();

        /// <summary>Return the current Settings on the reader.</summary>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        Settings QuerySettings();

        /// <summary>
        /// Change the settings of the reader to those passed in.
        /// </summary>
        /// <remarks>
        /// The settings on the reader are first cleared the
        /// same way <see cref="ClearSettings"/> does.
        /// Then the passed-in settings are put on the reader.
        /// <para>
        /// Events and reports are delivered after a successful
        /// ApplySettings.
        /// </para>
        /// </remarks>
        /// <param name="settings">The settings to put on the reader.</param>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        void ApplySettings(Settings settings);

        /// <summary>
        /// Change the settings of the reader to factory settings.
        /// </summary>
        /// <remarks>
        /// The settings on the reader are first cleared the
        /// same way <see cref="ClearSettings"/> does.
        /// Then the factory settings, the same settings
        /// returned by <see cref="QueryFactorySettings"/>,
        /// are put on the reader.
        /// <para>
        /// Events and reports are delivered after a successful
        /// ApplyFactorySettings.
        /// </para>
        /// </remarks>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        void ApplyFactorySettings();

        /// <summary>
        /// Allow events and reports to be delivered to the application.
        /// </summary>
        /// <remarks>
        /// After connecting to a reader that is already set up an
        /// application may need to prepare for events and reports
        /// before they are delivered.
        /// Therefor events and reports are held until ResumeEventsAndReports
        /// is called. Once the application is ready it calls
        /// ResumeEventsAndReports and anything held is delivered.
        /// Note that the timestamps of the previously held events
        /// and reports may be in the past.
        /// </remarks>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        void ResumeEventsAndReports();

        /// <summary>
        /// Returns the tags currently in the readers accumulator.
        /// </summary>
        /// <remarks>
        /// This call may be used while the reader is singulating or
        /// idle. This call only makes sense if the reader is set to
        /// use ReportMode.WaitForQuery or
        /// ReportMode.BatchAfterStop.
        /// </remarks>
        TagReport QueryTagReport();

        /// <summary>
        /// Start the reader, singulate for a time, stop, and
        /// report the tags read during that interval.
        /// </summary>
        /// <remarks>
        /// The settings on the reader are temporarily changed while
        /// this procedure is done. Because of this it is possible
        /// for automatic start and stop triggers to be missed.
        /// </remarks>
        /// <param name="seconds">The number of seconds to singulate</param>
        /// <returns>A possibly empty tag report.</returns>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        TagReport QueryTags(int seconds);

        /// <summary>
        /// Start the reader, singulate for a time, stop, and
        /// report the tags read during that interval.
        /// </summary>
        /// <remarks>
        /// The settings on the reader are temporarily changed while
        /// this procedure is done. Because of this it is possible
        /// for automatic start and stop triggers to be missed.
        /// </remarks>
        /// <param name="seconds">The number of seconds to singulate.
        /// Fractions of seconds are allowed (example 7.500)</param>
        /// <returns>A possibly empty tag report.</returns>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        TagReport QueryTags(double seconds);

        /// <summary>
        /// Set a General Purpose Output level
        /// </summary>
        /// <param name="gpoPortNumber">The GPO port number
        /// starting with 1.</param>
        /// <param name="level">true for high, false for low</param>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection, when the port
        /// number is invalid, or when the
        /// reader replies with an error.</exception>
        void SetGpo(int gpoPortNumber, bool level);

        /// <summary>
        /// Start the reader singulating for tags.
        /// </summary>
        /// <remarks>
        /// It is OK to explictly start the reader with
        /// this interface even if the reader has automatic
        /// start triggers set.
        /// </remarks>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection, when the
        /// reader is not set up, or when the
        /// reader replies with an error.</exception>
       void Start();

        /// <summary>
        /// Stop the reader singulating.
        /// </summary>
        /// <remarks>
        /// It is OK to explictly stop the reader with
        /// this interface even if the reader has automatic
        /// stop triggers set.
        /// It is OK to use this interface if the reader
        /// is already stopped.
        /// </remarks>
        /// <exception cref="Impinj.OctaneSdk.SpeedwayException">
        /// Thrown when there is no connection or when the
        /// reader replies with an error.</exception>
        void Stop();
        //Access

        /// <summary>Kill a tag</summary>
        KillTagResult KillTag(KillTagParams & accessParams);
        /// <summary>Lock a tag</summary>
        LockTagResult LockTag(LockTagParams & accessParams);

        /// <summary> Program the access password of a tag.</summary>
        ProgramAccessPasswordResult ProgramAccessPassword(ProgramAccessPasswordParams & accessParams);

        /// <summary>Program the kill password of a tag.</summary>
        ProgramKillPasswordResult ProgramKillPassword(ProgramKillPasswordParams & accessParams);
        /// <summary>Program the EPC and PC Bits on a tag, optionally setting the
        /// access password, and optionally locking the tag. PC Bits are calculated automatically.
        /// Number of EPC words written is the specified EPC word length + 1 for the PC Bits
        /// </summary>
        ProgramEpcResult ProgramEpc(ProgramEpcParams & accessParams);
        /// <summary>Program a portion of a tags user memory.</summary>
        ProgramUserBlockResult ProgramUserBlock(ProgramUserBlockParams & accessParams);
        /// <summary>Program all of a tags user memory</summary>
        ProgramUserMemoryResult ProgramUserMemory(ProgramUserMemoryParams & accessParams);
        /// <summary>Reads the current access password on the device</summary>
        ReadAccessPasswordResult ReadAccessPassword(ReadAccessPasswordParams & accessParams);
        /// <summary>Reads the current kill password on the device</summary>
        ReadKillPasswordResult ReadKillPassword(ReadKillPasswordParams & accessParams);
        /// <summary>Reads the TID (Tag ID) memory on a tag</summary>
        ReadTidMemoryResult ReadTidMemory(ReadTidMemoryParams & accessParams);
        /// <summary>Reads the user memory on a tag</summary>
        ReadUserMemoryResult ReadUserMemory(ReadUserMemoryParams & accessParams);
        /// <summary>Runs a sequence of primitive Access operations </summary>
        /// <remarks>See PrimitiveParams for possible access operations</remarks>
        RunPrimitiveSequenceResult RunPrimitiveSequence(RunPrimitiveSequenceParams & accessParams);

        // event related methods

        /// <summary>Deliver a log message. </summary>
        /// <remarks>The base class discards the message. </remarks>
        virtual void OnLogging(LoggingEventArgs & args);

        /// <summary>
        /// The status of the network connection to the reader
        /// changed.
        /// </summary>
        /// <remarks> The base class demultiplexes to
        /// OnConnected, OnDisconnected, or OnConnectionLost.
        /// </remarks>
        virtual void OnConnectionChanged(ConnectionChangedEventArgs & args);

        /// <summary>The network connection to the reader was just
        /// established. </summary>
        virtual void OnConnected(ConnectionChangedEventArgs & args);

        /// <summary>The network connection was just disconnected upon
        /// request.</summary>
        virtual void OnDisconnected(ConnectionChangedEventArgs & args);

        /// <summary> The network connection unexpectedly dropped. The
        /// situation must be cleaned up by calling Disconnect.</summary>
        virtual void OnConnectionLost(ConnectionChangedEventArgs & args);

        /// <summary>Another application tried to connect to the reader.</summary>
        virtual void OnConnectionAttempted(ConnectionAttemptedEventArgs & args);

        /// <summary>An antenna was just connected or disconnected.</summary>
        virtual void OnAntennaChanged(AntennaChangedEventArgs & args);

        /// <summary>An enabled general purpose input (GPI) just changed.
        /// </summary>
        /// <remarks>
        /// The base class demultiplexes to OnGpi1Changed,
        /// OnGpi2Changed, OnGpi3Changed, or
        /// OnGpi4Changed. </remarks>
        virtual void OnGpiChanged(GpiChangedEventArgs & args);

        /// <summary>GPI 1 just changed.</summary>
        virtual void OnGpi1Changed(GpiChangedEventArgs & args);

        /// <summary>GPI 2 just changed.</summary>
        virtual void OnGpi2Changed(GpiChangedEventArgs & args);

        /// <summary>GPI 3 just changed.</summary>
        virtual void OnGpi3Changed(GpiChangedEventArgs & args);

        /// <summary>GPI 4 just changed.</summary>
        virtual void OnGpi4Changed(GpiChangedEventArgs & args);

        /// <summary>The report buffer on the reader could not hold any
        /// more tag reports.
        /// </summary>
        /// <remarks>The number of tag reports that can
        /// be held on the reader depends on the what report
        /// options are enabled. Usually it is a very big number.
        /// Use QueryTags to resolve the situation. </remarks>
        virtual void OnReportBufferOverflowed(ReportBufferOverflowedEventArgs & args);

        /// <summary>
        /// The report buffer on the reader is nearly full.
        /// <summary>
        /// <remarks>The
        /// application should soon do a QueryTags to resolve the
        /// situation.
        /// </remarks>
        virtual void OnReportBufferWarned(ReportBufferWarnedEventArgs & args);

        /// <summary>
        /// Called when a reader exception occurs on the connected device
        /// <summary>
        /// <remarks>
        /// This is not a code exception, but a device exceptions and
        /// typically occurs when an unexpected failure occurs on the 
        /// reader device.
        /// </remarks>
        virtual void OnReaderExceptionOccured(ReaderExceptionOccuredEventArgs & args);

        /// <summary>The reader has started</summary>
        virtual void OnStarted(StartedEventArgs & args);

        /// <summary>The reader has stopped</summary>
        virtual void OnStopped(StoppedEventArgs & args);

        /// <summary>
        /// This is the delivery of tag reports.
        /// </summary>
        /// <remarks>
        /// This happens for
        /// ReportModes BatchAfterStop, Individual, and
        /// IndividualUnbuffered.
        /// </remarks>
        virtual void OnTagsReported(TagsReportedEventArgs & args);

        /// <summary>Include an application generated log message into the
        /// log stream. </summary>
        void Log(enum LogLevel level, const char* format, ...);

      private:
        Impinj_OctaneSdk_Internals::LtkProxy* ltkProxy;
    };

} /* namespace Impinj_OctaneSdk */

#endif /* _TETON_SPEEDWAYREADER_H_ */
