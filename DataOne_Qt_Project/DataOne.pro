#-------------------------------------------------
#
# Project created by QtCreator 2011-11-29T22:55:03
#
#-------------------------------------------------

# Include exclude Qt modules.
QT       += core
QT       += network
QT       -= gui

# Target name of the application.
TARGET = DataOne

# Type of target application.
CONFIG   += console
CONFIG   -= app_bundle

# This is an executable application, not a library.
TEMPLATE = app

# Header files to include in compilation.
HEADERS += \
    mainthread.h \
    Enums/enums.h \
    FileWriter/filteredfilewriter.h \
    FileWriter/datafilewriter.h \
    Reader/systemmonitor.h \
    Reader/gpiohandler.h \
    Settings/settings.h \
    TcpClient/tcpconsoleclient.h \
    TcpServer/tcpfilteredserver.h \
    TcpServer/tcpdataserver.h \
    TcpServer/tcpconsoleserver.h \
    Reader/reader.h \
    FileWriter/consolefilewriter.h \
    Structures/structures.h \
    Tag/tagrecord.h \
    TcpClient/tcptelnetclient.h \
    TcpClient/tcpserverconnection.h \
    WebUploader/webuploader.h


# Source files to include in compilation.
SOURCES += main.cpp \
    mainthread.cpp \
    FileWriter/filteredfilewriter.cpp \
    FileWriter/datafilewriter.cpp \
    Reader/systemmonitor.cpp \
    Reader/gpiohandler.cpp \
    Settings/settings.cpp \
    TcpClient/tcpconsoleclient.cpp \
    TcpServer/tcpfilteredserver.cpp \
    TcpServer/tcpdataserver.cpp \
    TcpServer/tcpconsoleserver.cpp \
    Reader/reader.cpp \
    FileWriter/consolefilewriter.cpp \
    Tag/tagrecord.cpp \
    TcpClient/tcptelnetclient.cpp \
    TcpClient/tcpserverconnection.cpp \
    WebUploader/webuploader.cpp

# Other files included in the project. Will not be include in compilation.
OTHER_FILES += \
    compile \
    DataOne.ini \
    Requirements-Phase-IV.txt \
    Requirements-Phase-III.txt \
    Requirements-Phase-II.txt \
    Requirements-Phase-I.txt \
    ReaderID.ini \
    ReaderSettings.xml \
    List of Commands.txt \
    Commands.txt \
    Prerequisites.txt \
    How to - Impinj Dev Environment with Qt Framework.pdf \
    TimeZone.ini \
    ntp.conf \
    DataOne.ini.master \
    Changes.txt \
    cap_desc.in \
    ReaderStatus.ini \
    start.sh


# Include paths for Octane SDK and other Impinj libraries.
# These will be included in the make file when compile script is executed in EDK virtual machine.
unix{
INCLUDEPATH += /opt/impinj/include/OctaneSdk
INCLUDEPATH += /opt/impinj/lib

OCTANESDK_INCLUDE_DIR += /opt/impinj/include/OctaneSdk
OCTANESDK_LIBRARY_DIR += /opt/impinj/lib
LTKCPP_LIBRARY_DIR += /opt/impinj/lib

LIBS += -L $$OCTANESDK_LIBRARY_DIR -loctanesdk_atmel \
        -L $$LTKCPP_LIBRARY_DIR \
        -lltkcpp_atmel -lltkcppimpinj_atmel -lxml2_atmel \
        -lpthread
}

# Include path for octane SDK. Impinj libraries for windows OS are only usable with C# language, so they are not included here.
# We do the compilation on windows only to check syntex errors. The comiplation always aborts with errors because Impinj libraries can not be linked.
win32{
INCLUDEPATH += OctaneSdk
}
































