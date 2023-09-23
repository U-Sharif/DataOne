// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example4 -- General Purpose Input/Output ports
//
// Set the reader to automatically start/stop when GPI1 is turned on/off.
// While the reader is running a light connected to GPO1 is turned on.
//

#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"


using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);


namespace Example4_GPIO
{

class Example : public SpeedwayReader
{
  public:
    void Run(const char * readerName);

    // override
    void OnLogging     (LoggingEventArgs & args);
    void OnStarted     (StartedEventArgs & args);
    void OnStopped     (StoppedEventArgs & args);
    void OnTagsReported(TagsReportedEventArgs & args);
    void OnGpi1Changed (GpiChangedEventArgs & args);
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
        printf("Example 4 Reader => ");
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
        // In this example the reader is set to automatically
        // start when GPI1 goes high and stop when GPI1 goes low.
        // GPI1 is essentially an on/off switch. Note that GPI1
        // must be explicitly enabled.
        //
        // The tags are reported in one batch when the reader stops.
        Settings settings = SpeedwayReader::QueryFactorySettings();
        settings.Gpis[1].IsEnabled = true;
        settings.Gpis[1].DebounceInMs = 50;
        settings.AutoStart.Mode = AutoStartMode_GpiTrigger;
        settings.AutoStart.GpiPortNumber = 1;
        settings.AutoStart.GpiLevel = true;
        settings.AutoStop.Mode = AutoStopMode_GpiTrigger;
        settings.AutoStop.GpiPortNumber = 1;
        settings.AutoStop.GpiLevel = false;
        settings.Report.Mode = ReportMode_BatchAfterStop;

        // Order the reader to change its settings to these.
        SpeedwayReader::ApplySettings(settings);

        // Example runs until Enter is pressed. Use GPI1
        // to start/stop the reader.
        printf("Press enter when done --> ");
        getline(inputBuf, sizeof inputBuf);

        // Tidy up
        SpeedwayReader::ClearSettings();
    }
    catch (OctaneSdkException ex)
    {
        // SpeedwayExceptions are detected by the Speedway SDK
        // library. These exceptions usually indicate either
        // something wrong with the reader or something wrong
        // with the applications request.
        printf("OctaneSdk detected %s", ex.what());
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        printf("Exception %s", ex.what());
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
Example::OnStarted(StartedEventArgs & args)
{
    (void)(&args);  // suppress compiler warning

    // Turn activity light on
    SpeedwayReader::SetGpo(1, true);
}

void 
Example::OnStopped(StoppedEventArgs & args)
{
    (void)(&args);  // suppress compiler warning

    // Turn activity light off
    SpeedwayReader::SetGpo(1, false);
}

void 
Example::OnTagsReported(TagsReportedEventArgs & args)
{
    // Invoked each time the reader stops
    for (int i = 0; i < args.TagReport.nTags; i++)
    {
        printf("Reader saw %s on ant#%d\n",
            args.TagReport.Tags[i].Epc, 
            args.TagReport.Tags[i].AntennaPortNumber);
    }
}

void 
Example::OnGpi1Changed(GpiChangedEventArgs & args)
{
    printf("GPI1 now %s\n", GpioStateToString(args.State));
}

// The logging event handler can be invoked from a variety
// of threads. Be sure to use thread safe techniques.

void Example::OnLogging(LoggingEventArgs & args)
{
    LogEntry entry = args.Entry;
    printf("Log level=%s %s", LogLevelToString(entry.Level), entry.Message);
}
}

int
main (int ac, char *av[])
{
    Example4_GPIO::Main(ac, av);
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
