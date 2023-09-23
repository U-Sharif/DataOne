// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- Power Ramp
//
// This examples perform a simple link test
//
// This exercise will enable you to code a power ramp test.
// The idea is to find out the lowest power that still finds all
// tags. The transmit power is steadily increased.  As the power 
// increases you report how many tags were singulated at each 
// transmit power level and their RSSI (Return Signal Strength
// Indicator) .The complete series takes about a minute.
//

#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"

using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);


namespace Example_PowerRamp
{
class Example : public SpeedwayReader
{
  public:
    void Run(const char * readerName);

    // override
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
    double minTx, maxTx;
    Settings settings;
    FeatureSet features;

    try
    {
        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Query the reader features to get the min and max Tx power.
        features = SpeedwayReader::QueryFeatureSet();
        minTx = features.TxPowers.Entries[0].Dbm;
        maxTx = features.TxPowers.Entries[features.TxPowers.nEntries-1].Dbm;

        // Remove all settings from the reader.
        SpeedwayReader::ClearSettings();

        // Get the factory default settings
        // We'll use these as a starting point
        // and then modify the settings we're 
        // interested in
        settings = SpeedwayReader::QueryFactorySettings();

        // Tell the reader to include the Peak RSSI
        // in all tag reports. Other fields can be added
        // to the reports in the same way by setting the 
        // appropriate Report.IncludeXXXXXXX property.
        settings.Report.IncludePeakRssi = true;

        // Send a tag report for every tag read.
        settings.Report.Mode = ReportMode_Individual;   

       // Loop, increasing the transmit power in 1 dBm steps. 
        for (double power = minTx; power <= maxTx; power += 1.0)
        {
            printf("testing at power level %f\n", power);
            // Set the transmit power (in dBm).
            settings.Antennas[1].TxPowerInDbm = power;
            
            // Apply the new transmit power settings.
            SpeedwayReader::ApplySettings(settings);
            
            // Read tags for two seconds.
            TagReport report = SpeedwayReader::QueryTags(2);

            // Loop through all the tags in the report
            // and print out the EPC, Tx Power and Peak RSSI.
            for(int i = 0; i < report.nTags; i++)
            {
                Tag *           tag = &report.Tags[i];
                char            buf[256];

                printf("%s\n", tag->Formatter(buf, sizeof buf));
            }        
        }
        // Clear the reader of any RFID operation and configuration.
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
} // namespace Example_PowerRamp

int
main (int ac, char *av[])
{
    Example_PowerRamp::Main(ac, av);
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
