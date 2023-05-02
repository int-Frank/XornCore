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
    virtual void DrawLineGroup(seg const *pSegs, size_t segCount, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawCircle(vec2 const &centre, float size, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawCircleGroup(vec2 const *pCentres, size_t circleCount, float size, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledCircle(vec2 const &centre, float size, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledCircleGroup(vec2 const *pCentres, size_t circleCount, float size, Colour clr, uint32_t flags) = 0;
    virtual void DrawPolygon(DgPolygon const &, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawPolygon(vec2 const *pVerts, size_t vertCount, float thickness, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledPolygon(DgPolygon const &, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledPolygon(PolygonWithHoles const &, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledPolygon(vec2 const *pVerts, size_t vertCount, int const *pPolygonSizes, size_t polyCount, Colour clr, uint32_t flags) = 0;
    virtual void DrawFilledConvexPolygon(vec2 const *pVerts, size_t vertCount, Colour clr, uint32_t flags) = 0;
  };
}

#endif