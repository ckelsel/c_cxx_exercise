#include "h264_encoder.h"
#include <iostream>
void H264Encoder::Encode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len)
{
    *out = new uint8_t[in_len];
    memcpy(*out, in, in_len);
    *out_len = in_len;
}
H264Encoder::H264Encoder(/* args */)
{
}

H264Encoder::~H264Encoder()
{
}