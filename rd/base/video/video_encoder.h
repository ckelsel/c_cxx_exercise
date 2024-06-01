#ifndef VIDEO_ENCODER_H
#define VIDEO_ENCODER_H
#include <stdint.h>

class VideoEncoder
{
private:
    /* data */

public:
    virtual void Encode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len) = 0;  
public:
    VideoEncoder(/* args */) = default;
    ~VideoEncoder()  = default;
};


#endif // VIDEO_ENCODER_H