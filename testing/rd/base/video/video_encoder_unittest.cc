#include "gtest/gtest.h"
#include "base/video/h264_encoder_factory.h"
#include "base/video/h265_encoder_factory.h"
#include "base/video/video_encoder_simple_factory.h"

/**
 * 工厂方法测试
*/
TEST(Factory, encode) {
    VideoEncoderFactory *factory = new H264EncoderFactory();
    VideoEncoder *encoder = factory->Create();
    encoder->Encode(nullptr, 0, nullptr, 0);

    factory = new H265EncoderFactory();
    encoder = factory->Create();
    encoder->Encode(nullptr, 0, nullptr, 0);
}

/**
 * 简单工厂测试
*/
TEST(SimpleFactory, encode) {
    VideoEncoder *encoder = CreateVideoEncoder(VIDEO_ENCODER_H264);
    encoder->Encode(nullptr, 0, nullptr, 0);
}