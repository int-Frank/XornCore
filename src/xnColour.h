#ifndef A2DCOLOUR_H
#define A2DCOLOUR_H

#include <stdint.h>

#include "a2dLineProperties.h"

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