// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example5 -- Settings Files
//
// This example shows how settings files may be used.
//
// Connect to the reader, get the default settings and save them to a file.
// Give the user a chance to edit the file. Load the settings from the
// file, prepare the reader, and start it.
//
// This is an easy way to experiment with different settings.
//
#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"

using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);

namespace Example5_SettingsFiles
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
};

void 
Main(
  int   argc,
  char *argv[])
{
    bool isInteractive = false;
    char * readerName = NULL;
    char inputBuf[100];
    if (argc < 2)
    {
        isInteractive = true;
        printf("Example 5 Reader => ");
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
        // In this example, the settings are adjusted by the user
        // by editing a file rather than the more usual adjusting
        // the settings in code.
        Settings settings = SpeedwayReader::QueryFactorySettings();

        // Save the settings.
        settings.Save((char*) "TheSettings.xml");

        // Give the user a chance to edit them.
        printf("Edit TheSettings.xml file, then press Enter --> ");
        getline(inputBuf, sizeof inputBuf);

        // Load the settings from the file.
        settings = Settings::Load((char*)"TheSettings.xml");

        // Order the reader to change its settings to these.
        SpeedwayReader::ApplySettings(settings);

        // If the reader isn't set to automatically start
        // explicitly start it now.
        if (AutoStartMode_None == settings.AutoStart.Mode)
        {
            SpeedwayReader::Start();
        }

        printf("Press Enter when done --> ");
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
        printf("OctaneSdk detected: %s", ex.what());
    }
    catch (exception ex)
    {
        // Any other kind of exception deteced by the system.
        printf("Exception: %s", ex.what());
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
    char buf[128];
    printf("Reader started as of %s\n", args.Timestamp.Formatter(buf, 127));
}

void 
Example::OnStopped(StoppedEventArgs & args)
{
    char buf[128];
    printf("Reader stopped as of %s", args.Timestamp.Formatter(buf, 127));
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
    Example5_SettingsFiles::Main(ac, av);
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
