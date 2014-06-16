#ifndef SERVER_INCLUDED
#define SERVER_INCLUDED

#include "ace/Reactor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Event_Handler.h"
#include "../Handler/Client_Handler.h"

class Logging_Acceptor : public ACE_Event_Handler
{
    friend class Logging_Handler;
    public:
        int open(const ACE_INET_Addr &_addr, ACE_Reactor *_reactor)
        {
            if(this->peer_acceptor_.open(_addr, 1) == -1)
                return -1;
            reactor_ = _reactor;

            return _reactor->register_handler(this, ACE_Event_Handler::ACCEPT_MASK);
        }
    private:
        ACE_HANDLE get_handle(void) const
        {
            return this->peer_acceptor_.get_handle();
        }
        int handle_input(ACE_HANDLE)
        {
            Logging_Handler *svc_handler = new Logging_Handler;
            if(this->peer_acceptor_.accept(*svc_handler) == -1)
                ACE_ERROR_RETURN((LM_ERROR,"%p", "accept failed"), -1);
            if(svc_handler->open(reactor_) == -1)
                svc_handler->close();
            return 0;
        }
    protected:
        ACE_SOCK_Acceptor peer_acceptor_;
        ACE_Reactor *reactor_;
};

class Server
{
    public:
        int start();
};

#endif /* SERVER_INCLUDED */
