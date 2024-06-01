#ifndef H264_DECODER_H
#define H264_DECODER_H
#include "video_decoder.h"

class H264Decoder: public VideoDecoder
{
private:
    /* data */

public:
    void Decode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len);  

public:
    H264Decoder(/* args */);
    ~H264Decoder();
};



#endif // H264_DECODER_H