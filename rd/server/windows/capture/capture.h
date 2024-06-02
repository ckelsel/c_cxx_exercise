#ifndef CAPTURE_H
#define CAPTURE_H
#include <stdint.h>

class Capture
{
private:
    /* data */

public:
    virtual void Snap(uint8_t *out, uint32_t out_len) = 0;

public:
    Capture(/* args */) = default;
    ~Capture() = default;
};


#endif /* CAPTURE_H */
