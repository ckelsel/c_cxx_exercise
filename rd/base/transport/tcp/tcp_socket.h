#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H
#include "../socket.h"
#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <Ws2tcpip.h>

class TcpSocket : public Socket
{
private:
    SOCKET socket_ = INVALID_SOCKET;

public:
    void SetSocket(SOCKET socket);

    int32_t Read(uint8_t *buf, int32_t buf_len);
    
    int32_t Write(uint8_t *buf, int32_t buf_len);
public:
    TcpSocket(/* args */);
    ~TcpSocket();
};



#endif /* TCP_SOCKET_H */
