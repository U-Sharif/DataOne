#ifndef ENUMS_H
#define ENUMS_H

// Enumerator definition for source of Reading start trigger.
// Used in reader.h
enum StartTrigger
{
    NoTrigger,
    TriggeredByGpi2,
    TriggeredByGpi3,
    TriggeredByTcpCommand
};

// Enumerator definition for differentiating telent client threads.
// Used in tcptelnetclient.h
enum TelnetClientType
{
    NoClient,
    TelnetDataClient,
    TelnetFilteredClient
};

#endif // ENUMS_H
