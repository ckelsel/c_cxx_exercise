#include "h264_encoder_factory.h"
#include "h264_encoder.h"

VideoEncoder *H264EncoderFactory::Create()
{
    return new H264Encoder();
}

H264EncoderFactory::H264EncoderFactory(/* args */)
{
}

H264EncoderFactory::~H264EncoderFactory()
{
}
