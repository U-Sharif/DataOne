// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- ProgramEpc
//
// This example shows how to program a Tags Epc
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


namespace Example_ProgramEpc {

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
        ProgramEpcParams epcParams;
        ProgramEpcResult result;

        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Configure the reader with the factory deafult settings.
        SpeedwayReader::ApplyFactorySettings();

        // Define how we want to perform the programming.
        // Use any antenna 
        epcParams.AntennaPortNumber = 0;
        // No access password required for this tag. 
        epcParams.AccessPassword.clear();

        epcParams.NewEpc = "0123-4567-89AB-CDEF-0123-4567";
        // Read the first tag we see.
        // Alternatively, we could choose a specific
        // tag by EPC or other identifier.
        epcParams.TargetTag.clear();
        // Timeout in 5 seconds if the read operation fails.
        epcParams.TimeoutInMs = 5000;                      
 
         // Perform the read and check the results.
        result = SpeedwayReader::ProgramEpc(epcParams);

        if (result.WriteResult.Result == AccessResult_Success)
        {
            printf("EPC Programing successful : %d words written \n",
                result.WriteResult.NumWordsWritten);

            printf("Querying tag...");
            TagReport report;
            report = SpeedwayReader::QueryTags(2);
            printf(" Read tag %s\n", report.Tags[0].Epc);

        }
        else
        {
            printf("Error Programming EPC : %s\n",
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
} // namespace Example_ProgramEpc

int
main (int ac, char *av[])
{
    Example_ProgramEpc::Main(ac, av);
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
