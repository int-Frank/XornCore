#ifndef XNLINEPROPERTIES_H
#define XNLINEPROPERTIES_H

#include <stdint.h>
#include "xnColour.h"

namespace xn
{
  class LineProperties
  {
  public:

    LineProperties(uint32_t _clr, float _thickness);
    LineProperties();
    void Reset();

    Colour clr;
    float thickness;
  };
}

#endif