#include "h265_encoder_factory.h"
#include "h265_encoder.h"

VideoEncoder *H265EncoderFactory::Create()
{
    return new H265Encoder();
}

H265EncoderFactory::H265EncoderFactory(/* args */)
{
}

H265EncoderFactory::~H265EncoderFactory()
{
}
