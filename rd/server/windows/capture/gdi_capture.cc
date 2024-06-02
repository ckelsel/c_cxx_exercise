#include "gdi_capture.h"
#include <iostream>

void GdiCapture::Snap(uint8_t *out, uint32_t out_len)
{
    memcpy(out, "win gdi", strlen("win gdi"));
}