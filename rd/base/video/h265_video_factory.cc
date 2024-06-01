#include "h265_video_factory.h"
#include "h265_encoder.h"
#include "h265_decoder.h"

VideoEncoder *H265VideoFactory::CreateEncoder()
{
    return new H265Encoder();
}

VideoDecoder *H265VideoFactory::CreateDecoder()
{
    return new H265Decoder();
}
