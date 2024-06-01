#ifndef H264_ENCODER_FACTORY_H
#define H264_ENCODER_FACTORY_H
#include "video_encoder_factory.h"

class H264EncoderFactory : public VideoEncoderFactory
{
private:
    /* data */

public:
    VideoEncoder *Create();

public:
    H264EncoderFactory(/* args */);
    ~H264EncoderFactory();
};


#endif // H264_ENCODER_FACTORY_H