#include "video_encoder_simple_factory.h"
#include "h264_encoder.h"

/**
 * 简单工厂方法，每次添加新编码器需要修改多处，可能会遗漏，不符合开闭原则
*/
extern "C" VideoEncoder *CreateVideoEncoder(VideoEncoderType type)
{
    switch (type)
    {
    case VIDEO_ENCODER_H264:
        return new H264Encoder();
    
    default:
        return nullptr;
    }
}