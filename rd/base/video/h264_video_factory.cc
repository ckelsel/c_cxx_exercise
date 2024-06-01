#include "h264_video_factory.h"
#include "h264_encoder.h"
#include "h264_decoder.h"

VideoEncoder *H264VideoFactory::CreateEncoder()
{
    return new H264Encoder();
}

VideoDecoder *H264VideoFactory::CreateDecoder()
{
    return new H264Decoder();
}
