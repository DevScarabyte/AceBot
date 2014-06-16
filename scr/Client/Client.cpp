/*

*/

#include "Client.h"

Client::Client(void)
{
    initialized_ = 0;
    error_ = 0;
}

Client::Client(const char *server, u_short port)
{
    initialized_ = 0;
    error_ = 0;
    (void)open(server, port);
}

int Client::open(const char *server, u_short port)
{
    ACE_SOCK_Connector connector;
    ACE_INET_Addr addr(port, server);
    if(connector.connect(*this, addr) == -1)
    {
        ACE_ERROR_RETURN((LM_ERROR, "%p\n", "open"), -1);
    }
    initialized_ = 1;
    return 0;
}

Client & Client::operator<<( ACE_SString & str )
{
    if( initialized() && !error() )
    {
        const char *cp = str.rep();
        if( this->send_n(cp,strlen(cp)) == -1 )
        {
            error_ = 1;
        }
    }
    else
    {
        error_ = 1;
    }

    return *this ;
}

Client & Client::operator<< ( char * str )
{
    ACE_SString newStr(str);
    *this << newStr;
    return *this ;
}

Client & Client::operator<< ( int n )
{
    char buf[1024];
    ACE_OS::sprintf(buf,"(%d)\n",n);

    ACE_SString newStr(buf);
    *this << newStr;

    return *this;
}

//int Client::Connect(string host, int port)
int Client::Connect(Settings settings)
{
    string host = settings.host;
    u_short server_port = settings.port;
    string nick = settings.nick;
    string nickPass = settings.nickPass;
    string channel = settings.channel;
    string channelPass = settings.channelPass;

    //const char *server_host = argc > 1 ? argv[1]        : ACE_DEFAULT_SERVER_HOST;
    //u_short server_port     = argc > 2 ? ACE_OS::atoi (argv[2]) : ACE_DEFAULT_SERVER_PORT;
    //int max_iterations      = argc > 3 ? ACE_OS::atoi (argv[3]) : 4;
    printf("Loading Data...\nPlease wait 5 seconds.\n");
    ACE_OS::sleep(5);
    // convert string into const char
    const char *server_host = host.c_str();
    //u_short server_port = port;

    ACE_INET_Addr server_addr;

    Client server;
    bool connected = false;

    if( server.open(server_host,server_port) == -1 )
    {
        ACE_ERROR_RETURN ((LM_ERROR, "Can't connect to %s:%i\n", server_host, server_port), -1);
        return 1;
    }
    else
    {
        //ACE_DEBUG((LM_DEBUG, "(%P | %t) Connected to %s:%i", server_host, server_port), -1);
        printf("Connected to %s:%i\n", server_host, server_port);
        connected = true;
    }

    if(connected)
    {
        char buffer[BUFFERLIMIT] = {0};
        int counter = 0;
        ssize_t currentSize = 0;
        vector<string> recvData;
    //    for (int i = 0; i < max_iterations; i++)
        while(1)
        {
            if ( server.error() )
            {
                printf("We have a error\n");
                ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "send"), -1);
                break;
            }
            else
            {
                if(counter<15)
                {
                    counter++;
                    switch(counter)
                    {
                        case 1:
                            server << "USER test test test : test\n";
                            printf("Sent User Data\n");
                            server << "NICK AceBot\n";
                            printf("Sent Nick Data\n");
                            break;
                        case 11:
                            server << "PRIVMSG nickserv identify test\n";
                            printf("Sent Register Data\n");
                            break;
                        case 5:
                            server << "JOIN #transfers\n";
                            printf("Sent Join Data\n");
                        default:
                            break;
                    }
                }
                ssize_t tempSize = 0;
                currentSize = tempSize;
                tempSize = server.recv(buffer, sizeof(buffer));
                if(10<tempSize)
                {
    //                printf("Counter: %i | %s\n", counter, buffer);

                    string tempStr = "";
                    for(int x = 0;x<sizeof(buffer);x++)
                    {
                        if(buffer[x] != ' ' && buffer[x] != '\r' && buffer[x] != '\n')
                        {
                            tempStr += buffer[x];
                        }
                        else
                        {
                            recvData.push_back(tempStr);
                            tempStr = "";
                        }
                    }

                    if(recvData[0] == "PING")
                    {
                        server << "PONG keepalive\n";
                        printf("PING areyouthere?\nPONG keepalive\n");
                    }
    //                ofstream out;
    //                out.open("out.log", ofstream::out);
                    printf("Message Received | Size: %i\n", tempSize);
                    printf("DEBUG: ");

                    for(int y = 0;y<recvData.size();y++)
                    {
                        if(recvData[y] != "")
                        {
                            printf("%i[%s] ", y, recvData[y].c_str());
    //                        out << recvData[y].c_str() << " ";
                        }
                    }
    //                out << "\n";
    //                out.close();
                    printf("\n");
                    //printf("DEBUG: 1[%s] 2[%s] 3[%s]\n", recvData[0].c_str(), recvData[1].c_str(), recvData[2].c_str());

                }
    //            for(int x = 0;tempSize > x;x++)
    //                ACE::write_n(ACE_STDOUT, buffer);
    //            printf("Counter: %i\n%s\n", counter, buffer);

                for(int x = 0;x<2048;x++)
                    buffer[x] = ' ';
                if(!recvData.empty())
                    recvData.clear();
                ACE_OS::sleep (1);
            }
        }

        if (server.close () == -1)
        {
            ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "close"), -1);
        }
    }
    return 0;
}

bool Client::commandCheck(vector<string> recvData)
{
    return true;
}
