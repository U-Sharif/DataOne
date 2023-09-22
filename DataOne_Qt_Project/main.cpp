#include <QtCore/QCoreApplication>

#include "mainthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Kill all unnecessary processes in OS.
    //system("killall linkmonitor_wra");
    //system("killall linkmonitor");
    system("killall snmpd");
    //system("killall syslogd");
    //system("killall klogd");

    // Start the main application object.
    MainThread Background;

    return a.exec();
}
