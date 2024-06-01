#ifndef VIDEO_DECODER_H
#define VIDEO_DECODER_H
#include <stdint.h>

class VideoDecoder
{
private:
    /* data */

public:
    virtual void Decode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len) = 0;  
public:
    VideoDecoder(/* args */) = default;
    ~VideoDecoder()  = default;
};


#endif // VIDEO_DECODER_H