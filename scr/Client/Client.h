/*

Programmer: Heihachi

*/

#ifndef CONNECTION_
#define CONNECTION_

#include "../main.h"
#include <vector>
#include <fstream>
#include "ace/SOCK_Connector.h"
#include "ace/SString.h"
#include "ace/Log_Msg.h"

using namespace std;

class Client : public ACE_SOCK_Stream
{
    public:
        Client(void);
        Client(const char *server, u_short port);

        int open(const char *server, u_short port);
        inline int initialized(void) { return initialized_; }
        inline int error(void)       { return error_; }
        Client &operator<<(ACE_SString &str);
        Client &operator<<(char *str);
        Client &operator<<(int n);
        //int Connect(string, int);
        int Connect(Settings);
    private:
        ACE_INET_Addr addr;
        bool commandCheck(vector<string>);
        static const int BUFFERLIMIT = 2048;
    protected:
        unsigned char initialized_;
        unsigned char error_;
};

#endif

