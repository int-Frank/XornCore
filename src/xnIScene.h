#ifndef XNISCENE_H
#define XNISCENE_H

#include "xnColour.h"
#include "xnGeometry.h"

namespace xn
{
  enum RenderFlags : uint32_t
  {
    RF_RoundedEndPoints = 1 << 0
  };

  class IScene
  {
  public:

    virtual ~IScene() {}

    virtual void AddLine(xn::seg const &, float thickness, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World = xn::mat33()) = 0;
    virtual void AddLineGroup(std::vector<xn::seg> const &, float thickness, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World = xn::mat33()) = 0;
    virtual void AddFilledCircle(xn::vec2 const &centre, float radius, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World = xn::mat33()) = 0;
    virtual void AddFilledCircleGroup(std::vector<xn::vec2> const &centres, float radius, uint32_t flags, uint32_t layer, xn::Colour clr, xn::mat33 T_Model_World = xn::mat33()) = 0;
    virtual void AddPolygon(xn::DgPolygon const &, float thickness, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World = xn::mat33()) = 0;
    virtual void AddFilledPolygon(xn::DgPolygon const &, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World = xn::mat33()) = 0;
  };
}

#endif