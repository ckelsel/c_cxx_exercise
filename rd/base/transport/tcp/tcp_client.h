#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H
#include "tcp_socket.h"

class TcpClient
{
private:
    /* data */

public:
    int32_t Connect(char* ip, int32_t port, TcpSocket *tcp_socket);

public:
    TcpClient(/* args */);
    ~TcpClient();
};




#endif /* TCP_CLIENT_H */
