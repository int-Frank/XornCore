#include "xnLineProperties.h"

namespace xn
{
  LineProperties::LineProperties(uint32_t _clr, float _thickness)
  {
    clr.rgba32 = _clr;
    thickness = _thickness;
  }

  LineProperties::LineProperties()
  {
    Reset();
  }

  void LineProperties::Reset()
  {
    clr.rgba32 = 0xFF00FFFF;
    thickness = 2.0;
  }
}