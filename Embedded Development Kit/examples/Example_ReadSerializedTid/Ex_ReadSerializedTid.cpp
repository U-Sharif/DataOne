// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example -- Query Tags
//
// Demonstrates getting the serialized TID from Monza tags
//

#include <stdio.h>
#include <exception>

#include "OctaneSdk.h"

using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);

namespace Example_ReadSerializedTid
{

class Example : public SpeedwayReader
{
  private:
	  string ReadTid(string epc);

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

std::string 
Example::ReadTid(string epc)
{
    ReadTidMemoryParams readParams;
	ReadTidMemoryResult result;

	// No password set.
    readParams.AccessPassword.clear();
    // Read from all antennas.
    readParams.AntennaPortNumber = 0;
    // Specify which tag to read by EPC.
    readParams.TargetTag = epc;
    // Read the entire TID bank (two 16-bit words).
    readParams.WordCount = 2;
    // Set the read timeout in milliseconds.
    readParams.TimeoutInMs = 5000;
    // Read the TID memory and return the data.
	result = SpeedwayReader::ReadTidMemory(readParams);
    return result.ReadResult.ReadData;
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

        // Clear the reader of any RFID operation and configuration.
        SpeedwayReader::ClearSettings();

        // Query the default settings for the reader. Settings
        // include which antennas are enabled, when to report and
        // optional report fields. Typically you will prepare the
        // reader by getting the default settings and adjusting them.
        //
        // In this example we make sure the reader holds
        // tag reports until we query for them, and also
        // include which antenna the tag was seen on.
        Settings settings = SpeedwayReader::QueryFactorySettings();
        settings.Report.Mode = ReportMode_WaitForQuery;
        settings.Report.IncludeAntennaPortNumber = true;

		// tell the tags to backscatter their serialized TID
        settings.Report.IncludeSerializedTid = true;

        // Order the reader to change its settings to these.
        SpeedwayReader::ApplySettings(settings);

        // Order the reader to turn on for a few seconds and
        // then report all tags seen.
        printf("Querying tags...\n");
        TagReport tagReport = SpeedwayReader::QueryTags(3);

        // Show how many tags were seen. Then show each tag report
        // entry. The Tag.ToString() method takes care of including
        // optional information that is in the tag report.
        printf("%d tags\n", tagReport.nTags);
        for(int i = 0; i < tagReport.nTags; i++)
        {
            Tag *           tag = &tagReport.Tags[i];
            char            buf[256];
			
			printf("%s ", tag->Formatter(buf, sizeof(buf)));

			// print the TID if the tag backscattered it
			if (tag->IsSerializedTidPresent) 
			{
				printf(" M4 -> %s\n", tag->SerializedTid);
			}
			else
			{
				// if the tag didn't backscatter it, go
				// out and fetch from the tag.  
				string tid = ReadTid(tag->Epc);
				printf(" M3 -> %s\n", tid.c_str());
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
} // namespace Example_ReadSerializedTid

int
main (int ac, char *av[])
{
    Example_ReadSerializedTid::Main(ac, av);
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
