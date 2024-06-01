#ifndef VIDEO_FACTORY_H
#define VIDEO_FACTORY_H
#include "video_encoder.h"
#include "video_decoder.h"

class VideoFactory
{
private:
    /* data */

public:
    virtual VideoEncoder* CreateEncoder() = 0;
    virtual VideoDecoder* CreateDecoder() = 0;

public:
    VideoFactory(/* args */) = default;
    ~VideoFactory()  = default;
};



#endif // VIDEO_FACTORY_H