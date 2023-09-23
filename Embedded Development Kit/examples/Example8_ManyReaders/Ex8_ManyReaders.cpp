// Copyright (c) 2010 Impinj, Inc. All rights reserved.

//
// Example8 -- Many Readers
//
// This example shows a way to manage multiple readers. Each
// reader is connected, prepared, and started. The tag reports
// are gathered into a Dictionary<>, which is NOT a thread safe
// structure, and this example shows how to lock it. After a
// ten second run all the readers are stopped and cleared.
// Finally the contents of the Dictionary<> are shown.
//
// The main concern with multiple readers is proper multi-threaded
// techniques. While this example introduces the concern, it should
// not be considered a complete solution. 
//

#include <stdio.h>
#include <algorithm>
#include <list>
#include <string>
#include <exception>

#include "OctaneSdk.h"

using namespace std; // exceptions
using namespace Impinj_OctaneSdk;

// forward
int main(int ac, char *av[]);
bool getline(char *buf, int nBuf);
void split(char * inputBuf, char * readerNames[], int * readerCount);



namespace Example8_ManyReaders
{

class AccumuTags
{
  public:
    AccumuTags(const Tag & tag);
    ~AccumuTags(); 
    bool operator==(const AccumuTags& tag);
    int Add(const Tag &tag);
    list<Tag*> Tags;
};


AccumuTags::AccumuTags(const Tag & tag)
{
   Tags.push_back(new Tag(tag));
}

AccumuTags::~AccumuTags()
{
   while (!Tags.empty())
   {
       delete Tags.front();
       Tags.pop_front();
   }
}

int AccumuTags::Add(const Tag &tag)
{
    Tags.push_back(new Tag(tag));
    return Tags.size();
}

bool AccumuTags::operator==(const AccumuTags& accumuTag)
{
    list<Tag*>::iterator elem =  Tags.begin();

    if (Tags.empty() || accumuTag.Tags.empty())
    {
        return false;
    }
    return (*((Tag*) *Tags.begin()) == *((Tag*) *accumuTag.Tags.begin()));
}

class MyReader : public SpeedwayReader
{
  public:
    ~MyReader();
    // a list of tag EPC's, each of element of which is a list 
    // of observation of the same same tag
    list<AccumuTags*> TagTable;
    Impinj_OctaneSdk::Lock TagTableLock;

    void DisplayTags();
    // override
    void OnLogging     (LoggingEventArgs & args);
    void OnStarted     (StartedEventArgs & args);
    void OnStopped     (StoppedEventArgs & args);
    void OnTagsReported(TagsReportedEventArgs & args);

};

class Example
{
  public:
    list<MyReader*> Readers;

    void Run(char * readerNames[]);
    void ConnectAndPrepareAllReaders();
    void StartAllReaders();
    void StopAllReaders(); 
    void ClearAndDisconnectAllReaders();
};

void 
Main(
  int argc,
  char *argv[])
{
#define _MAX_READER_COUNT 32 
    bool isInteractive = false;
    char * readerNames[_MAX_READER_COUNT+1]; // 32 readers at most
    char inputBuf[_MAX_READER_COUNT*64]; // reasonably big
    int readerCount = _MAX_READER_COUNT;
    if (argc < 2)
    {
        isInteractive = true;
        printf("Example 8 Reader(s) => ");
        if (!getline(inputBuf, sizeof inputBuf))
        {
            return;
        }
    }
    else
    {
        strncpy(inputBuf, argv[1],(sizeof inputBuf) - 1);
    }

    split(inputBuf, readerNames, &readerCount);
    readerNames[readerCount] = NULL;

    Example example;
    example.Run(readerNames);

    if (isInteractive)
    {
        printf("Done => ");
        getline(inputBuf, sizeof inputBuf);
    }
}

void 
Example::Run(char * readerNames[])
{
    int i = 0;
    while (readerNames[i])
    {
        MyReader * reader = new MyReader();

        // Set the reader identity. It can be any object.
        // This is passed back with events and tag reports.
        reader->ReaderIdentity = (void*) readerNames[i];
        Readers.push_back(reader);
        i++;
    }

    ConnectAndPrepareAllReaders();
    StartAllReaders();
    Impinj_OctaneSdk::Thread::Sleep(10*1000); // 10 seconds
    StopAllReaders();
    Impinj_OctaneSdk::Thread::Sleep(1*1000); // 1 second
    ClearAndDisconnectAllReaders();

    for (list<MyReader*>::iterator 
         elem  = Readers.begin();
         elem != Readers.end();
         elem++)
    {
        MyReader * reader = *elem;
        reader->DisplayTags();
    }

    // release resource
    while (!Readers.empty())
    {
        delete Readers.front();
        Readers.pop_front();
    }
}

void 
Example::ConnectAndPrepareAllReaders()
{
    for(list<MyReader*>::iterator 
        elem  = Readers.begin();
        elem != Readers.end();
        elem++)
    {
        MyReader * reader = *elem;

        try
        {
            // Change the level of logging detail. The default is Error.
            reader->LogLevel = LogLevel_Error;

            reader->Connect((const char*) reader->ReaderIdentity);

            Settings settings = reader->QueryFactorySettings();
            settings.Report.Mode = ReportMode_Individual;
            settings.Report.IncludeFirstSeenTime = true;
            settings.Report.IncludeAntennaPortNumber = true;

            reader->ApplySettings(settings);
        }
        catch (exception ex)
        {
            printf("Exception %s for reader %s\n", ex.what(), (char*) reader->ReaderIdentity);
            try
            {
                reader->Disconnect();
            }
            catch (...)
            {
            }
        }
    }
}

void 
Example::StartAllReaders()
{
    for(list<MyReader*>::iterator 
        elem  = Readers.begin();
        elem != Readers.end();
        elem++)
    {
        MyReader * reader = *elem;
        try
        {
            reader->Start();
        }
        catch (OctaneSdkException ex)
        {
            printf("Reader %s start: OctaneSdk detected %s\n",
                (char*) reader->ReaderIdentity, ex.what());
        }
        catch (exception ex)
        {
            // Any other kind of exception deteced by the system.
            printf("Reader %s start: Exception %s\n",
                (char*) reader->ReaderIdentity, ex.what());
        }
    }
}

void 
Example::StopAllReaders()
{
    for(list<MyReader*>::iterator 
        elem  = Readers.begin();
        elem != Readers.end();
        elem++)
    {
        MyReader * reader = *elem;
        try
        {
            reader->Stop();
        }
        catch (OctaneSdkException ex)
        {
            printf("Reader %s stop: OctaneSdk detected %s\n",
                (char*) reader->ReaderIdentity, ex.what());
        }
        catch (exception ex)
        {
            printf("Reader %s stop: Exception %s\n",
                (char*) reader->ReaderIdentity, ex.what());
        }
    }
}

void 
Example::ClearAndDisconnectAllReaders()
{
    for(list<MyReader*>::iterator 
        elem  = Readers.begin();
        elem != Readers.end();
        elem++)
    {
        MyReader * reader = *elem;
        try
        {
            reader->ClearSettings();
        }
        catch (OctaneSdkException ex)
        {
            printf("Reader %s clear: OctaneSdk detected %s\n",
                (char*) reader->ReaderIdentity, ex.what());
        }
        catch (exception ex)
        {
            // Any other kind of exception deteced by the system.
            printf("Reader %s clear: Exception %s\n",
                (char*) reader->ReaderIdentity, ex.what());
        }

        try
        {
            reader->Disconnect();
        }
        catch (...)
        {
        }
    }
}

MyReader::~MyReader()
{
   while (!TagTable.empty())
   {
       delete TagTable.front();
       TagTable.pop_front();
   }

}

void MyReader::DisplayTags()
{
    for (list<AccumuTags*>::iterator 
        elem1  = TagTable.begin();
        elem1 != TagTable.end();
        elem1++)
    {
        Tag *        tag;
        AccumuTags * accumuTags = *elem1;
        tag = (Tag *) *accumuTags->Tags.begin();
        printf("EPC %s observed %d times on:\n", tag->Epc, accumuTags->Tags.size());
        for (list<Tag*>::iterator 
            elem2  = accumuTags->Tags.begin();
            elem2 != accumuTags->Tags.end();
            elem2++)
        {
            char buf[128];
            tag = *elem2;
            printf("reader %s antenna %d at %s\n", 
                (char *) tag->ReaderIdentity, 
                tag->AntennaPortNumber, 
                tag->FirstSeenTime.Formatter(buf, 127));
        }

    }
}

// The event handler methods below are invoked while running
// on a callback thread. There is one callback thread per a
// SpeedwayReader instance. Be sure to use thread safe techniques.

void 
MyReader::OnStarted(StartedEventArgs & args)
{
    printf("Reader %s started\n", (char*) args.ReaderIdentity);
}

void 
MyReader::OnStopped(StoppedEventArgs & args)
{
    printf("Reader %s stopped\n", (char*) args.ReaderIdentity);
}

void 
MyReader::OnTagsReported(TagsReportedEventArgs & args)
{
    // Lock TagTable to protect if from multiple thread concerns.
    // There is a thread per reader and reports might show up
    // at about the same time.
    TagTableLock.lock();
    {
        for (int i = 0; i < args.TagReport.nTags; i++)
        {
            bool found = false;
            Tag tag = args.TagReport.Tags[i];
            AccumuTags * accumuTags = new AccumuTags(tag);
            // check if the same EPC is already in the TagTable
            for (list<AccumuTags*>::iterator 
                elem  = TagTable.begin();
                elem != TagTable.end();
                elem++)
            {
                if (*((AccumuTags *) *elem) == *accumuTags)
                {
                    found = true;
                    delete accumuTags;
                    accumuTags = (AccumuTags *) *elem;
                    break;
                }
            }

            if (found)
            {
                accumuTags->Add(tag);
            }
            else
            {
                TagTable.push_back(accumuTags);
            }
        }
    }
    TagTableLock.unlock();
}

// The logging event handler can be invoked from a variety
// of threads. Be sure to use thread safe techniques.

void 
MyReader::OnLogging(LoggingEventArgs & args)
{
    LogEntry entry = args.Entry;
    printf("Log level=%s reader=%s: %s\n", LogLevelToString(entry.Level), (char*) entry.ReaderIdentity, entry.Message);
    if (entry.ReaderIdentity != (void*) this->ReaderIdentity)
    {
        printf("what's going on ??\n");
    }
}
}

int
main (int ac, char *av[])
{
    Example8_ManyReaders::Main(ac, av);
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

void split(char * inputBuf, char * readerNames[], int * readerCount)
{
    char * separator;
    char * ptr;
    int count = 0;
    ptr = inputBuf;
    while (count < *readerCount)
    {
        separator = strchr(ptr, (int) ',');
        if (separator)
        {
            readerNames[count] = ptr;
            *separator = 0;
            ptr = separator + 1;
            count++;
        }
        else if (strlen(ptr))
        {
            readerNames[count] = ptr;
            count++;
            break;
        }
        else
        {
            break;
        }
    }
    *readerCount = count;
}
