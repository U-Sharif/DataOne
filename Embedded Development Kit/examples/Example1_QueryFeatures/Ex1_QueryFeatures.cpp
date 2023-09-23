// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example1 -- Query Features
//
// Connect to a Speedway reader and report its model name,
// version information, and the status of each antenna port.
//


#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"


using namespace std; // exceptions
using namespace Impinj_OctaneSdk;


// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);


namespace Example1_QueryFeatures
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
        printf("Example 1 Reader => ");
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
    try
    {
        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Clear the reader of any RFID operation and configuration.
        SpeedwayReader::ClearSettings();

        // Query the features of the reader. This includes model
        // name, version information, subregion, transmit powers,
        // frequencies, sensitivities, modes, etc.
        FeatureSet featureSet = SpeedwayReader::QueryFeatureSet();

        printf("Model              %s\n", featureSet.ModelName);
        printf("Software Version   %s\n", featureSet.SoftwareVersion);
        printf("Firmware Version   %s\n", featureSet.FirmwareVersion);
        printf("PCBA Version       %s\n", featureSet.PcbaVersion);
        printf("FPGA Version       %s\n", featureSet.FpgaVersion);
        printf("Regulatory Region  %s\n", featureSet.Subregion);

        // Query the status of the reader. This includes the
        // connection state of each antenna, the state of each
        // general purpose input (GPI), the state of the RFID
        // operation, etc.
        Status status = SpeedwayReader::QueryStatus(StatusRefresh_Everything);

        printf("Antennas           ");

        for (
            int portNumber = Constants::MinAntennaPortNumber;
            portNumber <= Constants::MaxAntennaPortNumber;
            portNumber++)
        {
            AntennaStatus *     antStat = &status.Antennas[portNumber];
            const char *        stateStr = "";

            switch (antStat->State)
            {
                // The port present on the reader and connected
                // to an antenna.
                case AntennaConnectionState_Connected:
                    stateStr = "Connected";
                    break;

                // The port is present on the reader but is not
                // connected to an antenna, or the connection is bad.
                case AntennaConnectionState_NotConnected:
                    stateStr = "Unconnected";
                    break;

                // No such port on the reader.
                case AntennaConnectionState_NotApplicable:
                    stateStr = "N/A";
                    break;

                // Unknown state. This usually means something
                // went wrong communicating with the reader.
                case AntennaConnectionState_Unknown:
                    stateStr = "Unknown";
                    break;

                // Should never happen.
                default:
                    stateStr = "??";
                    break;
            }
            printf(" %d:%s", antStat->PortNumber, stateStr);
        }
        printf("\n");
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

} // namespace Example1_QueryFeatures


int
main (int ac, char *av[])
{
    Example1_QueryFeatures::Main(ac, av);
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
