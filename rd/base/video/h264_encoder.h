#ifndef H264_ENCODER_H
#define H264_ENCODER_H
#include "video_encoder.h"

class H264Encoder: public VideoEncoder
{
private:
    /* data */

public:
    void Encode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len);  

public:
    H264Encoder(/* args */);
    ~H264Encoder();
};



#endif // H264_ENCODER_H