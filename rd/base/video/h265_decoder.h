#ifndef H265_DECODER_H
#define H265_DECODER_H
#include "video_decoder.h"

class H265Decoder: public VideoDecoder
{
private:
    /* data */

public:
    void Decode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len);  

public:
    H265Decoder(/* args */);
    ~H265Decoder();
};



#endif // H265_DECODER_H