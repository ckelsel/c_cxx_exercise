#include "gdi_capture_factory.h"
#include "gdi_capture.h"

Capture *GdiCaptureFactory::CreateCapture()
{
    return new GdiCapture();
}