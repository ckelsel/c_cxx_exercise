#include "gtest/gtest.h"
#include "server/windows/capture/capture_factory.h"
#include "server/windows/capture/gdi_capture_factory.h"


TEST(Capture, gdi) {
    uint8_t out[32];

    CaptureFactory *factory = new GdiCaptureFactory();
    Capture *capture = factory->CreateCapture();
    capture->Snap(out, 32);
}