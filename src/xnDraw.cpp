#include "xnDraw.h"

namespace xn
{
  namespace Draw
  {
    Stroke::Stroke()
      : clr(0xFFFFFFFF)
      , thickness(1.f)
    {

    }

    Stroke::Stroke(Colour _clr, float _thickness)
      : clr(_clr)
      , thickness(_thickness)
    {

    }

    Fill::Fill()
      : clr(0xFFFFFFFF)
    {

    }

    Fill::Fill(Colour _clr)
      : clr(_clr)
    {

    }
  }
}