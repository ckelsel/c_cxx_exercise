#ifndef VIDEO_ENCODER_SIMPLE_FACTORY_H
#define VIDEO_ENCODER_SIMPLE_FACTORY_H
#include "video_encoder.h"
#include "video_encoder_type.h"

#ifdef __cplusplus
extern "C" {
#endif

VideoEncoder *CreateVideoEncoder(VideoEncoderType type);

#ifdef __cplusplus
}
#endif
#endif // VIDEO_ENCODER_SIMPLE_FACTORY_H