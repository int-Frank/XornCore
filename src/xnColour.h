#ifndef XNCOLOUR_H
#define XNCOLOUR_H

#include <stdint.h>

#include "xnLineProperties.h"

namespace xn
{
  class Colour
  {
  public:

    union
    {
      uint32_t rgba32;
      uint8_t rgba8[4];
    };
  };
}

#endif