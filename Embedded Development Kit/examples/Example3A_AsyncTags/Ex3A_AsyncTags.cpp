// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example3A -- Async Tags Periodic 
//
// This example show how to use the periodic triggers to automatically
// start and stop the reader
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


namespace Example3A_AsyncTags
{

class Example : public SpeedwayReader
{
    // When this Example class is instantiated so is the
    // SpeedwayReader class.
  public:
    void Run(const char * readerName);

    // overrides
    void OnConnected(ConnectionChangedEventArgs & args);
    void OnDisconnected(ConnectionChangedEventArgs & args);
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
        printf("Example 3 Reader => ");
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

        // Reading tags for 5 seconds every 10 seconds
        settings.AutoStart.Mode = AutoStartMode_Periodic;
        settings.AutoStart.PeriodInMs = 10000;
        settings.AutoStop.Mode = AutoStopMode_Duration;
        settings.AutoStop.DurationInMs = 5000;

        // Order the reader to change its settings to these.
        SpeedwayReader::ApplySettings(settings);

        // Start the reader.
        SpeedwayReader::Start();

        // wait for user input
	    printf("Press enter when done.");
        getline(inputBuf, sizeof inputBuf);

        // Stop the reader.
        SpeedwayReader::Stop();

        // Tidy up
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
Example::OnConnected(ConnectionChangedEventArgs & args)
{
    char            timeStrBuf[32];

    printf("Reader connected as of %s\n",
        args.Timestamp.Formatter(timeStrBuf, sizeof timeStrBuf));

    SpeedwayReader::OnConnected(args);
}

void
Example::OnDisconnected(ConnectionChangedEventArgs & args)
{
    char            timeStrBuf[32];

    printf("Reader disconnected as of %s\n",
        args.Timestamp.Formatter(timeStrBuf, sizeof timeStrBuf));

    SpeedwayReader::OnDisconnected(args);
}

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

} // namespace Example3_AsyncTags


int
main (int ac, char *av[])
{
    Example3A_AsyncTags::Main(ac, av);
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
