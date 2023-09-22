#ifndef READER_H
#define READER_H

#include <QtCore/QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QMetaType>

#include <stdio.h>
#include <unistd.h>
#include <exception>
#include <OctaneSdk.h>


#include "../Settings/settings.h"
#include "../Tag/tagrecord.h"

using namespace std;                        // For exceptions
using namespace Impinj_OctaneSdk;


/*
Following macro definitions are necessary for using Octane SDK
types in Qt Signal/Slot queued connections.
*/
Q_DECLARE_METATYPE(GpiChangedEventArgs);

Q_DECLARE_METATYPE(Tag);


// This class is the main work horse of DataOne application.
// The Reader class primarily interacts with RFID radio via LLRP protocol.
// Octane SDK provides interface with the LLRP protocol.
// Other functions of this class include processing of tag reports and client commands.
// This class inherits QObject class, which provides baseline functionality of Qt framework.
// This class also inherits SpeedwayReader, which provides interface to LLRP protocol.

class Reader : public QObject, public SpeedwayReader
{
    // QObject delarator for enabling this class to use Qt framework's Signal/Slot mechanism.
    Q_OBJECT

public:
    // Class constructor.
    explicit Reader(QObject *parent = 0);

    // Pointer to System Settings object.
    // There is only one SystemSettings object in  the whole application which is in the main thread.
    DataOneSettings *SystemSettings;

    // Function to initialize the LLRP interface and configuration.
    bool Run(const char *readerName);

private:
    // Persistant name of reader device which will connect to LLRP.
    char *ReaderName;

    // Tag record handler
    TagRecord *CurrentTag;

    // Write lock the database while records are being sent.
    bool WriteLockStartModeDatabase;

    // Local flags.
    bool isConnected;                   // LLRP connected ?
    bool isReading;                     // Is reader reading ?
    bool isSettingChanged;              // Have the settings changed ?
    bool isAntennaChanged;              // Has the antenna configuration changed ?
    bool isPerformingActionAlert;       // Is the application performing an action alert ?

    // Timer to update reader parameters.
    QTimer *ReaderStatusUpdateTimer;

    // Timer to insert delay before application starts auto-reading after restart in case of crash.
    QTimer *PreviousReadingStatusTimer;

    // Timer to process filtered tags in start mode. i.e, FilterLength < 0.
    QTimer *StartModeTimer;

    Settings ReaderSettings;        // OctaneSDK reader settings.
    FeatureSet ReaderFeatureSet;    // OctaneSDK device feature set.
    Status ReaderStatus;            // OctaneSDK reader status parameters.


    void setFrequency(QString FrequencyID);         // Set radio Tx/Rx frequency.
    void setReaderMode(QString ReaderMode);         // Set Reader Mode
    void setSearchMode(QString SearchMode);         // Set Search Mode
    void setSession(int Session);                   // Set Session
    void setTagVolume(QString TagVolume);           // Set Tag Volume
    void setAntennas();                             // Set Antennas
    void setBeep(QString BeepStatus);               // Set Beep
    void setBeepDuration(QString BeepInterval);     // Set Beep Duration

    void setTime(QString DateTimeString);           // Set clock time of reader manually.

    QDateTime AdjustTimeZone(Time);                 // At present, reader OS does not support automatic time zone adjustment
                                                    // Therefore, we do it manually via this function.

    void FlushStartModeDatabase();

    int TotalTagCounter;                            // Used for debugging.

protected:
    // SpeedwayReader's overridden callback functions.
    void OnConnected(ConnectionChangedEventArgs & args);                        // Called when LLRP is connected.
    void OnDisconnected(ConnectionChangedEventArgs & args);                     // Called when LLRP is disconnected.
    void OnStarted(StartedEventArgs & args);                                    // Called when radio starts tag reading.
    void OnStopped(StoppedEventArgs & args);                                    // Called when radio stops tag reading.
    void OnTagsReported(TagsReportedEventArgs & args);                          // Called when radio reports a tag to OctaneSDK via LLRP>
    void OnLogging(LoggingEventArgs & args);                                    // Called when LLRP reports a log.

    void OnGpiChanged (GpiChangedEventArgs & args);                             // Called when a General Purpose Input(GPI) state changes.
    void OnAntennaChanged(AntennaChangedEventArgs & args);                      // Called when an antenna changes its state.

    void OnReportBufferOverflowed(ReportBufferOverflowedEventArgs & args);      // Called when radio tag buffer is about to over flow.

signals:
    void Log(QString, QString);                                 // Send log entry to main thread.
    void Broadcast(QString);                                    // Send message to all connected TCP clients.

    void NewDataRecordAvailable(QByteArray, quint64);        // Signal to indicate that a new data tag record is available.
    void NewFilteredRecordAvailable(QByteArray,quint64);     // Signal to indicate that a new filtered tag record is available.
    void StartTagReportBeep();                                  // When a tag is received from LLRP, beep.

    void GPIChanged(GpiChangedEventArgs args, QDateTime TimeStamp); // Signal for GPIOHandler when an GPI changes state.
    void LLRPConnected(bool);                                   // Signal for other threads, LLRP is connected.
    void ReadingStarted(bool);                                  // Signal for other threads, LLRP is disconnected.

    void UpdateTemperature(int);                                // Update current reader temperature to other threads.
    void UpdateAntennaState(QString);                           // Update current antennas states to other threads.

    void SaveDeviceSettings();                                  // Signal for SystemSettings object to save all latest settings.
    void ClearBuffers();                                        // Signal for other threads to take action on clear_buffer command.
    void ClearAllLogs();                                        // Signal for file writer threads to clear all log files.
    void PerformActionAlert(int);

    void DataOneShutdown();                                     // Signal for other threads, clean exit.

public slots:
    void ConnectLLRP();                                         // Slot to connect DataOne to LLRP.
    void DisconnectLLRP();                                      // Slot to disconnect DataOne from LLRP.

    void StartReading();                                        // Slot to command the radio to start tag reading.
    void StopReading();                                         // Slot to command the radio to stop tag reading.

    void ParseClientCommand(QByteArray);                        // Slot to validate and take actions on commands from clients.

    void setGPO(int PortNumber, bool State);                    // Slot to command hardware to set a General Purpose Output (GPO) state.
    void RefreshAntennas();                                     // Refresh antennas state before manual reading start.

private slots:
    void getReaderStatus();                                     // Update reader parameters at regular intervals

    void ProcessStartModeTags();                                // Process tags stored in filter database in start mode. (FilterLength < 0)

};

#endif // READER_H
