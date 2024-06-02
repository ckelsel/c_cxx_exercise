#include "tcp_server.h"
#include <winsock2.h>
#include <WS2tcpip.h>

int32_t TcpServer::Listen()
{
    //----------------------
    // Initialize Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR)
    {
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for
    // incoming connection requests.
    listen_socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_socket_ == INVALID_SOCKET)
    {
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = htons(port_);
    inet_pton(AF_INET, "127.0.0.1", &service.sin_addr);

    if (bind(listen_socket_,
             (SOCKADDR *)&service, sizeof(service)) == SOCKET_ERROR)
    {
        closesocket(listen_socket_);
        WSACleanup();
        return 1;
    }
    //----------------------
    // Listen for incoming connection requests.
    // on the created socket
    if (listen(listen_socket_, 1) == SOCKET_ERROR)
    {
        closesocket(listen_socket_);
        WSACleanup();
        return 1;
    }

    return 0;
}

int32_t TcpServer::Accept(TcpSocket *socket)
{
    SOCKET AcceptSocket;

    //----------------------
    // Accept the connection.
    AcceptSocket = accept(listen_socket_, NULL, NULL);
    if (AcceptSocket == INVALID_SOCKET) {
        closesocket(listen_socket_);
        WSACleanup();
        return 1;
    }
    
    socket->SetSocket(AcceptSocket);
    
    return 0;
}

TcpServer::TcpServer(int32_t port)
{
    port_ = port;
}

TcpServer::~TcpServer()
{
    WSACleanup();
}