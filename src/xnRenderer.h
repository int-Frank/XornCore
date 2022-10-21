#ifndef XNRENDERER_H
#define XNRENDERER_H

#include "DgVector.h"
#include "DgSegment.h"
#include "xnDraw.h"

namespace xn
{
  class Renderer
  {
  public:

    virtual ~Renderer() {}

    virtual void Set(Dg::Vector2<float> const &p0, Dg::Vector2<float> const &p1) = 0;
    virtual void BeginDraw() = 0;
    virtual void DrawLine(Dg::Segment2<float> const &, Draw::Stroke) = 0;
    virtual void DrawNGon(Dg::Vector2<float> const &centre, float radius, uint32_t sides, Draw::Stroke) = 0;
    virtual void DrawFilledNGon(Dg::Vector2<float> const &centre, uint32_t sides, float radius, Draw::Fill) = 0;
    virtual void DrawFilledTriangle(Dg::Vector2<float> const &p0, Dg::Vector2<float> const &p1, Dg::Vector2<float> const &p2, Draw::Fill) = 0;
    virtual void EndDraw() = 0;
  };
}

#endif