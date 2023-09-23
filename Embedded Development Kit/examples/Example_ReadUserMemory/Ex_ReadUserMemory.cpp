// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- ReadUserMemory
//
// This example shows how to read tag user memory using the OctaneSDK
//
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

namespace Example_ReadUserMemory
{
class Example : public SpeedwayReader
{
    // When this Example class is instantiated so is the
    // SpeedwayReader class.
  public:
    void Run(const char * readerName);

    // overrides
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
    try
    {
        ReadUserMemoryParams readParams;
        ReadUserMemoryResult result;

        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Configure the reader with the factory deafult settings.
        SpeedwayReader::ApplyFactorySettings();

        // Define how we want to perform the read.
        // Use any antenna 
        readParams.AntennaPortNumber = 0;
        // No access password required for this tag. 
        readParams.AccessPassword.clear();
        // Start reading from the base of user memory (address 0).
        readParams.WordPointer = 0;
        // Read 2 words of user memory (32-bits).
        readParams.WordCount = 2;
        // Read the first tag we see.
        // Alternatively, we could choose a specific
        // tag by EPC or other identifier.
        readParams.TargetTag.clear();
        // Timeout in 5 seconds if the read operation fails.
        readParams.TimeoutInMs = 5000;                      
 
         // Perform the read and check the results.
        result = SpeedwayReader::ReadUserMemory(readParams);

        if (result.ReadResult.Result == AccessResult_Success)
        {
            printf("Tag read successful. Memory contents : %s\n",
                result.ReadResult.ReadData.c_str());
        }
        else
        {
            printf("Error reading tag : %s\n",
                AccessResultToString(result.ReadResult.Result));
        }
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
} // namespace Example_ReadUserMemory

int
main (int ac, char *av[])
{
    Example_ReadUserMemory::Main(ac, av);
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
