// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- KillTag
//
// This example shows how to Kill a tag.
//
// Killing a tag is permanent.  Once you run this and kill a tag
// you cannot undo this operation
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


namespace Example_KillTag
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
        char inputBuf[256];
        ProgramKillPasswordParams pwParams;
        ProgramKillPasswordResult pwResult;

        // Change the level of logging detail. The default is Error.
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);

        // Configure the reader with the factory deafult settings.
        SpeedwayReader::ApplyFactorySettings();

        // find a tag to kill 
        printf("Querying for a tag to kill...");
        TagReport report;
        report = SpeedwayReader::QueryTags(2);

        // prompt the user since this is permanent
        if(report.nTags > 0) {
            printf(" Read tag %s -- type 'yes' followed by enter to kill \n", 
                report.Tags[0].Epc);
            getline(inputBuf, sizeof inputBuf);
        }
        else
        {
            printf(" Did not find any tags\n");
        }

        if (strncmp(inputBuf, "yes", 3) == 0) {

            // Set this string to the new kill password.
            const string NEW_KILL_PW = "12345678";

            // First, set the kill password
            // since a zero password is not allowed.
            // Use any antenna
            pwParams.AntennaPortNumber = 0;
            // No access password required for this tag. 
            pwParams.AccessPassword.clear();
            // Specify the target tag by EPC.
            pwParams.TargetTag = report.Tags[0].Epc;
            // Timeout in 5 seconds if the operation fails.
            pwParams.TimeoutInMs = 5000;
            // Specify the new kill password (32-bits).
            pwParams.NewKillPassword = NEW_KILL_PW;

            // Program the password and check the result.
            pwResult = SpeedwayReader::ProgramKillPassword(pwParams);

            if (pwResult.WriteResult.Result == AccessResult_Success)
            {
                KillTagParams killParams;
                KillTagResult killResult;

                // We've successfully set the kill password.
                // Now issue the kill command.
                printf("Successfully set kill password.\n");
                // Use any antenna.
                killParams.AntennaPortNumber = 0;
                // Set the kill password. 
                killParams.KillPassword = NEW_KILL_PW;
                // No access password required for this tag. 
                killParams.AccessPassword.clear();
                // Specify the target tag by EPC.
                killParams.TargetTag = report.Tags[0].Epc;
                // Timeout in 5 seconds if the kill operation fails.
                killParams.TimeoutInMs = 5000;

                // Perform the kill and check the results.
                killResult = SpeedwayReader::KillTag(killParams);
                if (killResult.KillResult.Result == AccessResult_Success)
                {
                    printf("Successfully killed tag.\n");
                }
                else
                {
                    printf("Error killing tag : %s\n",
                        AccessResultToString(killResult.KillResult.Result));
                }
            }
            else
            {
                printf("Error setting kill password : %s\n", 
                    AccessResultToString(pwResult.WriteResult.Result));
            }
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
} // namespace Example_KillTag

int
main (int ac, char *av[])
{
    Example_KillTag::Main(ac, av);
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
