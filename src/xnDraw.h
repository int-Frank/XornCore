#ifndef XNDRAW_H
#define XNDRAW_H

#include <stdint.h>
#include "xnColour.h"

namespace xn
{
  namespace Draw
  {
    class Stroke
    {
    public:

      Stroke(Colour _clr, float _thickness);
      Stroke();

      Colour clr;
      float thickness;
    };

    class Fill
    {
    public:

      Fill(Colour _clr);
      Fill();

      Colour clr;
    };
  }
}

#endif