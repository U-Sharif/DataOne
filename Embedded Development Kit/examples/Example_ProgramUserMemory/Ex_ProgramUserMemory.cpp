// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- ProgramUserMemory
//
// This example shows how to program a portion of a tags user memory 
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

namespace Example_ProgramUserMemory {

class Example : public SpeedwayReader
{
    // When this Example class is instantiated so is the
    // SpeedwayReader class.
  public:
    void Run(const char * readerName);

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
        ProgramUserBlockParams writeParams;
        ProgramUserBlockResult result;

        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Configure the reader with the factory deafult settings.
        SpeedwayReader::ApplyFactorySettings();

        // Define how we want to perform the programming.
        // Use any antenna 
        writeParams.AntennaPortNumber = 0;
        // No access password required for this tag. 
        writeParams.AccessPassword.clear();

        writeParams.NewUserBlock = "0123456789ABCDEF";
        // Read the first tag we see.
        // Alternatively, we could choose a specific
        // tag by EPC or other identifier.
        writeParams.TargetTag.clear();
        // Timeout in 5 seconds if the read operation fails.
        writeParams.TimeoutInMs = 5000;                      
 
         // Perform the program and check the results.
        result = SpeedwayReader::ProgramUserBlock(writeParams);

        if (result.WriteResult.Result == AccessResult_Success)
        {
            printf("User Memory Programing successful : %d words written \n",
                result.WriteResult.NumWordsWritten);
        }
        else
        {
            printf("Error Programming User Memory : %s\n",
                AccessResultToString(result.WriteResult.Result));
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

void
Example::OnLogging(LoggingEventArgs & args)
{
    LogEntry   entry = args.Entry;

    printf("Log level=%s %s\n",
        LogLevelToString(entry.Level),
        entry.Message);

    SpeedwayReader::OnLogging(args);
}
} // namespace Example_ProgramUserMemory

int
main (int ac, char *av[])
{
    Example_ProgramUserMemory::Main(ac, av);
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
