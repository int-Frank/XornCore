#ifndef XNRENDERER_H
#define XNRENDERER_H

#include "DgVector.h"
#include "DgSegment.h"
#include "xnLineProperties.h"

namespace xn
{
  class Renderer
  {
  public:

    virtual ~Renderer() {}

    virtual void Set(Dg::Vector2<float> const &p0, Dg::Vector2<float> const &p1) = 0;
    virtual void BeginDraw() = 0;
    virtual void DrawLine(Dg::Segment2<float> const &, LineProperties const &) = 0;
    virtual void DrawNGon(Dg::Vector2<float> const &centre, float radius, uint32_t sides, LineProperties const &) = 0;
    virtual void DrawFilledNGon(Dg::Vector2<float> const &centre, uint32_t sides, float radius, Colour) = 0;
    virtual void DrawFilledTriangle(Dg::Vector2<float> const &p0, Dg::Vector2<float> const &p1, Dg::Vector2<float> const &p2, Colour) = 0;
    virtual void EndDraw() = 0;
  };
}

#endif