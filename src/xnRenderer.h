#ifndef A2DRENDERER_H
#define A2DRENDERER_H

#include "DgVector.h"
#include "DgSegment.h"
#include "a2dLineProperties.h"

namespace xn
{
  class Renderer
  {
  public:

    virtual ~Renderer() {}

    virtual void Set(Dg::Vector2<float> const &p0, Dg::Vector2<float> const &p1) = 0;
    virtual void BeginDraw() = 0;
    virtual void DrawLine(Dg::Segment2<float> const &, LineProperties const &) = 0;
    virtual void DrawFilledTriangle(Dg::Vector2<float> const &p0, Dg::Vector2<float> const &p1, Dg::Vector2<float> const &p2, Colour) = 0;
    virtual void EndDraw() = 0;
  };
}

#endif