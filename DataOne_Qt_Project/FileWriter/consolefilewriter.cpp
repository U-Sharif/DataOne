#include "consolefilewriter.h"

//CONSTRUCTOR
ConsoleFileWriter::ConsoleFileWriter(DataOneSettings *SysSettings, QObject *parent) :
    QThread(parent)
{
    printf("\n<<STATUS>> Console file writer running.\n");

    SystemSettings = SysSettings;
    OpenConsoleLogFile();
}

//PROTECTED FUNCTION
void ConsoleFileWriter::run()
{
    // Start eventloop of new thread.
    exec();
}



//PRIVATE FUNCTION
void ConsoleFileWriter::OpenConsoleLogFile()
{
    if (SystemSettings->isUSBDevicePresent)
    {
        printf("<<ACTION>> Opening console log file.\n");

        // Create the log directory if the directory does not already exist.
        QDir FileWritePath;
        FileWritePath.mkpath(SystemSettings->ConsoleLogFolderPath);

        // Set the log file name.
        ConsoleLogFile.setFileName(SystemSettings->ConsoleLogFolderPath + "log.txt");

        // If already open, close the log file.
        // This is just a precution, if for some reason USB memory device is changed during execution.
        if (ConsoleLogFile.isOpen()) ConsoleLogFile.close();

        // Open log file, and write new log header text.
        if (ConsoleLogFile.open(QIODevice::Append))
        {
            ConsoleLogFile.write(QByteArray("\n\n\n[[[" + SystemSettings->GetCurrentDateTimeString().toLocal8Bit() + "]]]\n\n"));

            printf("<<ACTION>> Setting console log filename to : %s \n\n", ConsoleLogFile.fileName().toLocal8Bit().data());
        }
    }
}




//PUBLIC SLOT
void ConsoleFileWriter::USBMemoryPlugged()
{
    // Open the console log file for writing when USB memory is plugged-in after application start.
    OpenConsoleLogFile();
}

//PUBLIC SLOT
void ConsoleFileWriter::RecordLog(QByteArray LogStatement)
{
    // Write new log entry, when only USB memory device is present and console file writing is enabled.

    if (SystemSettings->isUSBDevicePresent && SystemSettings->DataOneApplicationSettings.EnableWriteConsoleLog)
    {
        // Always check to see if file handle is still valid.
        // This will prevent application crash if USB device is removed during execution.
        if (!ConsoleLogFile.isWritable())
            return;

        ConsoleLogFile.write("[" + SystemSettings->GetCurrentDateTimeString().toLocal8Bit() + "] "+ LogStatement);

        // Always flush the write buffer, to prevent losing the logs on unclean application exit.
        ConsoleLogFile.flush();
    }
}

//PUBLIC SLOT
void ConsoleFileWriter::Shutdown()
{
    RecordLog("Shutting down Console File Writer thread.\n");
    RecordLog("\r\nBye Bye.\r\n");

    if (ConsoleLogFile.isOpen()) ConsoleLogFile.close();

    this->quit();
}
