#include "gtest/gtest.h"
#include "base/video/h264_encoder_factory.h"
#include "base/video/h265_encoder_factory.h"
#include "base/video/video_encoder_simple_factory.h"
#include "base/video/video_factory.h"
#include "base/video/h264_video_factory.h"
#include "base/video/h265_video_factory.h"

/**
 * 工厂方法测试
*/
TEST(Factory, encode) {
    uint8_t *out = nullptr;
    uint32_t out_len;
    VideoEncoderFactory *factory = new H264EncoderFactory();
    VideoEncoder *encoder = factory->Create();
    encoder->Encode(nullptr, 0, &out, &out_len);

    factory = new H265EncoderFactory();
    encoder = factory->Create();
    encoder->Encode(nullptr, 0, &out, &out_len);
}

/**
 * 简单工厂测试
*/
TEST(SimpleFactory, encode) {
    uint8_t *out = nullptr;
    uint32_t out_len;
    VideoEncoder *encoder = CreateVideoEncoder(VIDEO_ENCODER_H264);
    encoder->Encode(nullptr, 0, &out, &out_len);
}

/**
 * 抽象工厂测试
*/
TEST(AbstractFactory, test) {
    uint8_t *out = nullptr;
    uint32_t out_len;

    VideoFactory *factory = new H264VideoFactory();
    VideoEncoder *encoder = factory->CreateEncoder();
    encoder->Encode(nullptr, 0, &out, &out_len);
    VideoDecoder *decoder = factory->CreateDecoder();
    decoder->Decode(nullptr, 0, &out, &out_len);

    factory = new H265VideoFactory();
    encoder = factory->CreateEncoder();
    encoder->Encode(nullptr, 0, nullptr, 0);
    decoder = factory->CreateDecoder();
    decoder->Decode(nullptr, 0, nullptr, 0);
}