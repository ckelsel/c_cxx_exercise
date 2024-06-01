#ifndef H265_ENCODER_H
#define H265_ENCODER_H
#include "video_encoder.h"

class H265Encoder: public VideoEncoder
{
private:
    /* data */

public:
    void Encode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len);  

public:
    H265Encoder(/* args */);
    ~H265Encoder();
};



#endif // H265_ENCODER_H