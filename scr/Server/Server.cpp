/*

*/

#include "Server.h"

ACE_Reactor *g_reactor;

static const u_short PORT = ACE_DEFAULT_SERVER_PORT;

int Server::start()
{
    g_reactor = new ACE_Reactor;
    ACE_INET_Addr addr(PORT);
    Logging_Acceptor *peer_acceptor = new Logging_Acceptor();
    if(peer_acceptor->open(addr,g_reactor) == -1)
        ACE_ERROR_RETURN((LM_ERROR, "Opening Acceptor\n"), -1);
    ACE_DEBUG((LM_DEBUG, "(%P|%t) starting up server logging daemon\n"));
    while(1)
        g_reactor->handle_events();
    return 0;
}
