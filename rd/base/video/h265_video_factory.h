#ifndef H265_VIDEO_FACTORY_H
#define H265_VIDEO_FACTORY_H
#include "video_factory.h"

class H265VideoFactory : public VideoFactory
{
private:
    /* data */

public:
    VideoEncoder* CreateEncoder();
    VideoDecoder* CreateDecoder();

public:
    H265VideoFactory(/* args */) = default;
    ~H265VideoFactory() = default;
};



#endif // H265_VIDEO_FACTORY_H