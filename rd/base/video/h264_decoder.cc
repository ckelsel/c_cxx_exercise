#include "h264_decoder.h"
#include <iostream>

void H264Decoder::Decode(uint8_t *in, uint32_t in_len, uint8_t **out, uint32_t *out_len)
{
    *out = new uint8_t[in_len];
    memcpy(*out, in, in_len);
    *out_len = in_len;
}

H264Decoder::H264Decoder()
{
}

H264Decoder::~H264Decoder()
{
}
