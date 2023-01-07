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

    virtual void AddLine(seg const &, float thickness, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
    virtual void AddLineGroup(std::vector<seg> const &, float thickness, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
    virtual void AddFilledCircle(vec2 const &centre, float radius, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
    virtual void AddFilledCircleGroup(std::vector<vec2> const &centres, float radius, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
    virtual void AddPolygon(DgPolygon const &, float thickness, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
    virtual void AddFilledPolygon(DgPolygon const &, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
    virtual void AddFilledPolygon(PolygonWithHoles const &, Colour clr, uint32_t flags, uint32_t layer = 0) = 0;
  };
}

#endif