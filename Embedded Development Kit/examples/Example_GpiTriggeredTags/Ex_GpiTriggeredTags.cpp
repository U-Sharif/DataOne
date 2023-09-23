// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- GpiTriggeredTags
//
// This example shows how to use GPI triggers to start and stop
// tag inventory on the reader.
//

#include <stdio.h>
#include <exception>
#include <unistd.h>  // sleep

#include "OctaneSdk.h"

using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);

namespace Example_GpiTriggeredTags
{
class Example : public SpeedwayReader
{
    // When this Example class is instantiated so is the
    // SpeedwayReader class.
  public:
    void Run(const char * readerName);

    // overrides
    void OnStarted(StartedEventArgs & args);
    void OnStopped(StoppedEventArgs & args);
    void OnTagsReported(TagsReportedEventArgs & args);
    void OnLogging(LoggingEventArgs & args);
};

void
Main(
  int argc,
  char *argv[])
{
    bool isInteractive = false;
    char * readerName = NULL;
    char inputBuf[100];

    if (argc < 2)
    {
        isInteractive = true;
        printf("Example Reader => ");
        if (!getline(inputBuf, sizeof inputBuf))
        {
            return;
        }
        readerName = inputBuf;
    }
    else
    {
        readerName = argv[1];
    }

    Example example;
    example.Run(readerName);

    if (isInteractive)
    {
        printf("Done => ");
        getline(inputBuf, sizeof inputBuf);
    }
}

void
Example::Run(const char * readerName)
{
    char inputBuf[100];
    try
    {
        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Clear the reader of any RFID operation and configuration.
        SpeedwayReader::ClearSettings();

        // Query the default settings for the reader. Settings
        // include which antennas are enabled, when to report and
        // optional report fields. Typically you will prepare the
        // reader by getting the default settings and adjusting them.
        //
        // This example sets the reader to send a tag report
        // immediately on every tag observation. Message buffering
        // improves overall efficiency but introduces a small
        // delay before the application is notified of a tag.
        // Message buffering is enabled by default.
        Settings settings = SpeedwayReader::QueryFactorySettings();
        settings.Report.Mode = ReportMode_Individual;
        settings.Report.IncludeAntennaPortNumber = true;

        // Start reading tags when GPI #1 goes high.
        settings.Gpis[1].IsEnabled = true;
        settings.Gpis[1].DebounceInMs = 50;
        settings.AutoStart.Mode = AutoStartMode_GpiTrigger;
        settings.AutoStart.GpiPortNumber = 1;
        settings.AutoStart.GpiLevel = true;

        // Stop reading tags when GPI #1 goes low.
        settings.AutoStop.Mode = AutoStopMode_GpiTrigger;
        settings.AutoStop.GpiPortNumber = 1;
        settings.AutoStop.GpiLevel = false;

        // Order the reader to change its settings to these.
        SpeedwayReader::ApplySettings(settings);

        // wait for user input so we can flip some GPIs
        printf("Press enter when done.");
        getline(inputBuf, sizeof inputBuf);
        
        // Leave the reader in a clean state before exiting
        SpeedwayReader::ClearSettings();
    }
    catch (OctaneSdkException ex)
    {
        // OctaneSdkExceptions are detected by the Octane SDK
        // library. These exceptions usually indicate either
        // something wrong with the reader or something wrong
        // with the application's request.
        printf("OctaneSdk detected %s\n", ex.what());
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        printf("Exception %s\n", ex.what());
    }

    // Safely disconnect from the reader.
    try
    {
        SpeedwayReader::Disconnect();
    }
    catch (...)
    {
    }
}

// The event handler methods below are invoked while running
// on a callback thread. There is one callback thread per a
// SpeedwayReader instance. Be sure to use thread safe techniques.

void
Example::OnStarted(StartedEventArgs & args)
{
    char            timeStrBuf[32];

    printf("Reader started as of %s\n",
        args.Timestamp.Formatter(timeStrBuf, sizeof timeStrBuf));

    SpeedwayReader::OnStarted(args);
}

void
Example::OnStopped(StoppedEventArgs & args)
{
    char            timeStrBuf[32];

    printf("Reader stopped as of %s\n",
        args.Timestamp.Formatter(timeStrBuf, sizeof timeStrBuf));

    SpeedwayReader::OnStopped(args);
}

void
Example::OnTagsReported(TagsReportedEventArgs & args)
{
    for (int i = 0; i < args.TagReport.nTags; i++)
    {
        printf("Reader saw %s ant#%d\n",
            args.TagReport.Tags[i].Epc,
            args.TagReport.Tags[i].AntennaPortNumber);
    }

    SpeedwayReader::OnTagsReported(args);
}

// The logging event handler can be invoked from a variety
// of threads. Be sure to use thread safe techniques.

void
Example::OnLogging(LoggingEventArgs & args)
{
    LogEntry   entry = args.Entry;

    printf("Log level=%s %s\n",
        LogLevelToString(entry.Level),
        entry.Message);

    SpeedwayReader::OnLogging(args);
}
} // namespace Example_GpiTriggeredTags

int
main (int ac, char *av[])
{
    Example_GpiTriggeredTags::Main(ac, av);
    return 0;
}

bool
getline (char *buf, int nBuf)
{
    if (NULL != fgets(buf, nBuf, stdin))
    {
        char * p = strchr(buf, '\n');
        if (NULL != p)
        {
            *p = 0;
            return true;
        }
    }
    return false;
}
