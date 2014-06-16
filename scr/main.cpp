//http://ipnweb.in2p3.fr/~godas/TAO/ACE_wrappers/docs/tutorials/004/page01.html
#include "main.h"
#include "Configuration/Config.h"
//#include "Database/DatabaseEnv.h"
#include "Client/Client.h"
//#include "Server/Server.h"
//#include "Window/Window.h"

#ifndef _IRC_CONFIG
# define _IRC_CONFIG  "bot.conf"
#endif


int main(int argc, char *argv[])
{

    // Set up config
    Settings settings;
    char const* configFile = _IRC_CONFIG;

    if (!sConfigMgr->LoadInitial(configFile))
    {
        printf("Invalid or missing configuration file : %s\n", configFile);
        printf("Verify that the file exists and has \'[irc]\' written in the top of the file!\n");
        return 1;
    }

    // Prepare Clients data and connect
    settings.host = sConfigMgr->GetStringDefault("Server", "");
    settings.port = sConfigMgr->GetIntDefault("Port", 6667);

    Client client(settings.host.c_str(), settings.port);
    client.Connect(settings);

    // Prepare Servers data and start waiting for connection
//    Server server;
//    server.start();

    // Prepare Curses window to output and accept data
    //Curses gui;
    return 0;
}
