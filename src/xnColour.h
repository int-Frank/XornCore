#ifndef XNCOLOUR_H
#define XNCOLOUR_H

#include <stdint.h>

namespace xn
{
  class Colour
  {
  public:

    Colour() { rgba32 = 0; }
    Colour(uint32_t uint) { rgba32 = uint; }

    float r() const { return (float)rgba.r / 255.f; }
    float g() const { return (float)rgba.g / 255.f; }
    float b() const { return (float)rgba.b / 255.f; }
    float a() const { return (float)rgba.a / 255.f; }

    union
    {
      uint32_t rgba32;
      uint8_t rgba8[4];
      struct RBGA
      {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
      } rgba;
    };
  };
}

#endif