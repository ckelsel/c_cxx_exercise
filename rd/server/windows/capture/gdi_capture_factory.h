#ifndef GDI_CAPTURE_FACTORY_H
#define GDI_CAPTURE_FACTORY_H
#include "capture_factory.h"

class GdiCaptureFactory : public CaptureFactory
{
private:
    /* data */

public:
    Capture* CreateCapture();

public:
    GdiCaptureFactory(/* args */) = default;
    ~GdiCaptureFactory() = default;
};



#endif /* GDI_CAPTURE_FACTORY_H */
