// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example6 -- Disconnected Operation
//
// The reader can gather tag information while the application
// is not connected.
//
// Connect to the reader, prepare it, and start it. The reader
// is set to scan for three seconds at 10 second intervals.
// Then disconnect from the reader and let it work automatically.
// After a minute -- about six cycles -- reconnect to the reader
// and retrieve the tag report.
//

#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"

using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);


namespace Example6_DisconnectedOps
{
class Example : public SpeedwayReader
{
  public:
    void Run(const char * readerName);

    // override
    void OnLogging     (LoggingEventArgs & args);
    void OnConnected   (ConnectionChangedEventArgs & args);
    void OnDisconnected(ConnectionChangedEventArgs & args);
    void OnStarted     (StartedEventArgs & args);
    void OnStopped     (StoppedEventArgs & args);
    void OnTagsReported(TagsReportedEventArgs & args);
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
        printf("Example 6 Reader => ");
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
    
void Example::Run(const char * readerName)
{
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
        // This example sets the reader to start once every ten
        // seconds. After it starts it stops after three seconds.
        // Note that this works out to on for 3, off for 7.
        // The tag report is maintained on the reader until
        // retrieved.
        Settings settings = SpeedwayReader::QueryFactorySettings();
        settings.AutoStart.Mode = AutoStartMode_Periodic;
        settings.AutoStart.FirstDelayInMs = 0; // no initial delay
        settings.AutoStart.PeriodInMs = 10*1000; // 10 seconds
        settings.AutoStop.Mode = AutoStopMode_Duration;
        settings.AutoStop.DurationInMs = 3*1000; // 3 seconds
        settings.Report.Mode = ReportMode_WaitForQuery;
        settings.Report.IncludeFirstSeenTime = true;
        settings.Report.IncludeLastSeenTime = true;

        // Order the reader to change its settings to these.
        SpeedwayReader::ApplySettings(settings);

        // The reader will start automatically.

        // Disconnect from the reader and let it work automatically.
        SpeedwayReader::Disconnect();
        // Pause for a little over a minute
        Impinj_OctaneSdk::Thread::Sleep(65*1000);

        // Reconnect to the reader.
        SpeedwayReader::Connect(readerName);


        // The reader holds events and reports until it is told
        // to send them. This allows the application to connect
        // and prepare.
        //
        // This short pause allows you to see the connection event.
        // Notice, though, that there are no other events delivered
        // during this pause.
        Impinj_OctaneSdk::Thread::Sleep(5*1000);

        // Allow the reader to send events and reports.
        // There will be a sudden burst of event reports.
        // Notice that their times are in the past.
        SpeedwayReader::ResumeEventsAndReports();

        // Get the tag report. Note that the report might be empty.
        TagReport tagReport = SpeedwayReader::QueryTagReport();

        // Show how many tags were seen. Then show each tag report
        // entry. The Tag.ToString() method takes care of including
        // optional information that is in the tag report.
        printf("First report %d tags\n", tagReport.nTags);
        for (int i = 0; i < tagReport.nTags; i++)
        {
            Tag *           tag = &tagReport.Tags[i];
            char            buf[256];

            printf("%s\n", tag->Formatter(buf, sizeof buf));
        }

        // During this pause you will see the events reported
        // promptly rather than held by the reader.
        Impinj_OctaneSdk::Thread::Sleep(25*1000);

        // Get the tag report. These are the tags that were
        // seen since the last QueryTags.
        tagReport = SpeedwayReader::QueryTagReport();
        printf("Final report %d tags\n", tagReport.nTags);
        for (int i = 0; i < tagReport.nTags; i++)
        {
            Tag *           tag = &tagReport.Tags[i];
            char            buf[256];

            printf("%s\n", tag->Formatter(buf, sizeof buf));
        }

        // Tidy up
        SpeedwayReader::ClearSettings();
    }
    catch (OctaneSdkException ex)
    {
        // SpeedwayExceptions are detected by the Speedway SDK
        // library. These exceptions usually indicate either
        // something wrong with the reader or something wrong
        // with the applications request.
        printf("OctaneSdk detected: %s\n", ex.what());
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        printf("Exception: %s\n", ex.what());
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

// The override methods below are invoked while running
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
        printf("Reader saw %s on ant#%d\n",
            args.TagReport.Tags[i].Epc, 
            args.TagReport.Tags[i].AntennaPortNumber);
    }
}

// The logging event handler can be invoked from a variety
// of threads. Be sure to use thread safe techniques.

void 
Example::OnLogging(LoggingEventArgs & args)
{
    LogEntry entry = args.Entry;
    printf("Log level=%s %s\n", LogLevelToString(entry.Level), entry.Message);
}
}

int
main (int ac, char *av[])
{
    Example6_DisconnectedOps::Main(ac, av);
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
