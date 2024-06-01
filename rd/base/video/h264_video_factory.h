#ifndef H264_VIDEO_FACTORY_H
#define H264_VIDEO_FACTORY_H
#include "video_factory.h"

class H264VideoFactory : public VideoFactory
{
private:
    /* data */

public:
    VideoEncoder* CreateEncoder();
    VideoDecoder* CreateDecoder();

public:
    H264VideoFactory(/* args */) = default;
    ~H264VideoFactory() = default;
};



#endif // H264_VIDEO_FACTORY_H