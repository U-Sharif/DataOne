// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example7 -- Write Tags
//
// Find all the tags in the field of view, then one-by-one change
// their EPC.
//

#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"


using namespace std; // exceptions
using namespace Impinj_OctaneSdk;


// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);


namespace Example7_WriteTags
{

class Example : public SpeedwayReader
{
    // When this Example class is instantiated so is the
    // SpeedwayReader class.
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
        printf("Example 7 Reader => ");
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
        SpeedwayReader::LogLevel = LogLevel_Error;

        // Connect to the reader. The name is the host name
        // or IP address.
        SpeedwayReader::Connect(readerName);
        SpeedwayReader::ClearSettings();

        Settings settings = SpeedwayReader::QueryFactorySettings();
        SpeedwayReader::ApplySettings(settings);

        printf("Querying Tags...\n");
        TagReport tagReport = SpeedwayReader::QueryTags(5.000);

        printf("Found %d tags:\n", tagReport.nTags);
        for (int i = 0; i < tagReport.nTags; i++)
        {
            Tag *           tag = &tagReport.Tags[i];
            char            buf[256];
            printf("%s\n", tag->Formatter(buf, sizeof buf));
        }

        string NewEpcBase = "aaaa-bbbb-cccc-dddd-eeee-";
        int index = 0;

        for (int i = 0; i < tagReport.nTags; i++)
        {
            ProgramEpcParams accessParams;
            ProgramEpcResult accessResult;
            char lastWord[5];
            char epc[256];

            accessParams.TargetTag = tagReport.Tags[i].Epc;
            accessParams.AccessPassword.clear();
            accessParams.TimeoutInMs = 5000;
            accessParams.AntennaPortNumber = 1;
            sprintf(lastWord, "%4.4x", index);
            accessParams.NewEpc = NewEpcBase + lastWord;
            accessParams.IsWriteVerified = true;
            accessParams.LockType = LockType_Locked;

            if (strcmp(accessParams.TargetTag.c_str(), "<nullEpc>")==0)
            {
                printf("skipping null EPC...\n");
                continue;
            }

            accessResult = SpeedwayReader::ProgramEpc(accessParams);

            printf("Programmed tag %s: %s\n",
                accessResult.TagAccessed.Formatter(epc, sizeof epc), 
                AccessResultToString(accessResult.WriteResult.Result));
            index++;
        }

        printf("Querying Tags after programming EPC...\n");
        tagReport = SpeedwayReader::QueryTags(5.000);

        printf("Found %d tags:\n", tagReport.nTags);
        for (int i = 0; i < tagReport.nTags; i++)
        {
            Tag *           tag = &tagReport.Tags[i];
            char            buf[256];
            printf("%s\n", tag->Formatter(buf, sizeof buf));
        }

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

} // namespace Example7_WriteTags


int
main (int ac, char *av[])
{
    Example7_WriteTags::Main(ac, av);
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
