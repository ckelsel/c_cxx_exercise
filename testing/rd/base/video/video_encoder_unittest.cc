#include "gtest/gtest.h"
#include "base/video/h264_encoder_factory.h"

TEST(H264EncoderFactory, encode) {
    H264EncoderFactory *factory = new H264EncoderFactory();
    VideoEncoder *encoder = factory->Create();
    encoder->Encode(nullptr, 0, nullptr, 0);
}