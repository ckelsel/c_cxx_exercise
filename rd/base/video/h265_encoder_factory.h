#ifndef H265_ENCODER_FACTORY_H
#define H265_ENCODER_FACTORY_H
#include "video_encoder_factory.h"

class H265EncoderFactory : public VideoEncoderFactory
{
private:
    /* data */

public:
    VideoEncoder *Create();

public:
    H265EncoderFactory(/* args */);
    ~H265EncoderFactory();
};


#endif // H265_ENCODER_FACTORY_H