#ifndef VIDEO_ENCODER_FACTORY_H
#define VIDEO_ENCODER_FACTORY_H
#include "video_encoder.h"

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