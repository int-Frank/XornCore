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

    virtual void AddLine(xn::seg const &, float thickness, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World) = 0;
    virtual void AddLineGroup(std::vector<xn::seg> const &, float thickness, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World) = 0;
    virtual void AddFilledNGon(xn::vec2 const &centre, uint32_t sides, float radius, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World) = 0;
    virtual void AddFilledNGonGroup(std::vector<xn::vec2> const &centres, uint32_t sides, float radius, uint32_t flags, uint32_t layer, xn::Colour clr, xn::mat33 T_Model_World) = 0;
    virtual void AddPolygon(xn::DgPolygon const &, float thickness, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World) = 0;
    virtual void AddFilledPolygon(xn::DgPolygon const &, xn::Colour clr, uint32_t flags, uint32_t layer, xn::mat33 T_Model_World) = 0;
  };
}

#endif