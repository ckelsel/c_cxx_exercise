#include "tcp_socket.h"

void TcpSocket::SetSocket(SOCKET socket)
{
    socket_ = socket;
}

int32_t TcpSocket::Read(uint8_t *buf, int32_t buf_len)
{
    return recv(socket_, (char *)buf, buf_len, 0);
}

int32_t TcpSocket::Write(uint8_t *buf, int32_t buf_len)
{
    return send(socket_, (const char *)buf, buf_len, 0);
}

TcpSocket::TcpSocket(/* args */)
{
}

TcpSocket::~TcpSocket()
{
    closesocket(socket_);
}
