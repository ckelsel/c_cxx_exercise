#ifndef CAPTURE_FACTORY_H
#define CAPTURE_FACTORY_H
#include "capture.h"

class CaptureFactory
{
private:
    /* data */

public:
    virtual Capture* CreateCapture() = 0;

public:
    CaptureFactory(/* args */) = default;
    ~CaptureFactory() = default;
};



#endif /* CAPTURE_FACTORY_H */
