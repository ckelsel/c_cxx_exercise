#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include "tcp_socket.h"

class TcpServer
{
private:
    int32_t port_;
    SOCKET listen_socket_;

public:
    int32_t Listen();

    int32_t Accept(TcpSocket *socket);

public:
    TcpServer(int32_t port);
    ~TcpServer();
};



#endif /* TCP_SERVER_H */
