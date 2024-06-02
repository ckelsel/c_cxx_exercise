#ifndef GDI_CAPTURE_H
#define GDI_CAPTURE_H
#include "capture.h"

class GdiCapture : public Capture
{
private:
    /* data */

public:
    void Snap(uint8_t *out, uint32_t out_len);

public:
    GdiCapture(/* args */) = default;
    ~GdiCapture() = default;
};



#endif /* GDI_CAPTURE_H */
