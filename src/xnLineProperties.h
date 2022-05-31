#ifndef A2DLINEPROPERTIES_H
#define A2DLINEPROPERTIES_H

#include <stdint.h>
#include "a2dColour.h"

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