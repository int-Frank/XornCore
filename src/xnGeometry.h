#ifndef XNGEOMETRY_H
#define XNGEOMETRY_H

#include <vector>
#include <string>
#include <map>

#include "DgMath.h"
#include "DgVector.h"
#include "DgSegment.h"
#include "DgMatrix33.h"
#include "DgAABB.h"
#include "DgPolygon.h"
#include "DgDoublyLinkedList.h"
#include "xnDraw.h"

namespace xn
{
  typedef Dg::Vector2<float> vec2;
  typedef Dg::Vector3<float> vec3;
  typedef Dg::Segment2<float> seg;
  typedef Dg::Matrix33<float> mat33;
  typedef Dg::AABB<float, 2> aabb;
  typedef Dg::Polygon2<float> DgPolygon;

  class Renderer;

  class Transform
  {
  public:

    Transform();

    void Reset();
    mat33 ToMatrix33() const;

    vec2 translation;
    float rotation;
    vec2 scale;
  };

  class PolygonLoop : public DgPolygon
  {
  public:

    void Render(Renderer *pRenderer, Draw::Stroke const &stroke) const;
    PolygonLoop GetTransformed(mat33 const &) const;
    Dg::ErrorCode GetAABB(aabb *pOut) const;
  };

  // The first loop will be the boundary and will have a CCW winding.
  // Subsequent loops will be holes and will have CW windings.
  class PolygonWithHoles
  {
  public:

    void Render(Renderer *pRenderer, Draw::Stroke const &stroke) const;
    PolygonWithHoles GetTransformed(mat33 const &) const;
    Dg::ErrorCode GetAABB(aabb *pOut) const;

    // Use to properly sort loops by size.
    // This ensures the boundary will be the first loop.
    void Push(PolygonLoop const &);

    Dg::DoublyLinkedList<PolygonLoop> loops;
  };
}

#endif