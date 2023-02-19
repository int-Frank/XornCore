#ifndef XNIRENDERER_H
#define XNIRENDERER_H

#include "xnColour.h"
#include "xnGeometry.h"

namespace xn
{
  enum RenderFlags : uint32_t
  {
    RF_RoundedEndPoints = 1 << 0
  };

  class IRenderer
  {
  public:

    virtual ~IRenderer() {}

    virtual void DrawLine(seg const &, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawLineGroup(std::vector<seg> const &, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledCircle(vec2 const &centre, float radius, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledCircleGroup(std::vector<vec2> const &centres, float radius, Colour clr, uint32_t flags) = 0;
    virtual void DrawPolygon(DgPolygon const &, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawPolygon(std::vector<vec2> const &vertices, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledPolygon(DgPolygon const &, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledPolygon(PolygonWithHoles const &, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledPolygon(std::vector<vec2> const &vertices, std::vector<int> const &polygonSizes, Colour clr, uint32_t flags) = 0;

  };
}

#endif