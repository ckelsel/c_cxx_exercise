#ifndef SOCKET_H
#define SOCKET_H
#include <stdint.h>

class Socket
{
private:
    /* data */

public:
    virtual int32_t Read(uint8_t *buf, int32_t buf_len) = 0;
    
    virtual int32_t Write(uint8_t *buf, int32_t buf_len) = 0;

public:
    Socket(/* args */) = default;
    ~Socket() = default;
};


#endif /* SOCKET_H */
