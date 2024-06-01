#ifndef VIDEO_ENCODER_FACTORY_H
#define VIDEO_ENCODER_FACTORY_H
#include "video_encoder.h"

/**
 * 工厂方法，纯虚函数只有1个，只负责单一的功能
*/
class VideoEncoderFactory
{
private:
    /* data */
public:
    virtual VideoEncoder *Create() = 0;

public:
    VideoEncoderFactory(/* args */) = default;
    ~VideoEncoderFactory() = default;
};


#endif // VIDEO_ENCODER_FACTORY_H