/*
 * Programmer: Heihachi
 * Reason: This file will contain all includes and other data for main
 *
 */

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <cstdio>
#include <string>
#include "ace/ACE.h"
#include "ace/SOCK_Connector.h"
#include "ace/INET_Addr.h"
#include "ace/Log_Msg.h"

using namespace std;

struct Settings
{
    char const* configFile;
    string host;
    int port;
    string nick;
    string nickPass;
    string channel;
    string channelPass;

};

#endif // MAIN_H_INCLUDED
