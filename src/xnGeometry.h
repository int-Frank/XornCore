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

namespace xn
{
  typedef Dg::Vector2<float> vec2;
  typedef Dg::Vector3<float> vec3;
  typedef Dg::Vector4<float> vec4;
  typedef Dg::Segment2<float> seg;
  typedef Dg::Matrix33<float> mat33;
  typedef Dg::AABB<float, 2> aabb;
  typedef Dg::Polygon2<float> DgPolygon;

  class PolygonLoop : public DgPolygon
  {
  public:

    PolygonLoop GetTransformed(mat33 const &) const;
    Dg::ErrorCode GetAABB(aabb *pOut) const;
  };

  // The first loop will be the boundary and will have a CCW winding.
  // Subsequent loops will be holes and will have CW windings.
  class PolygonWithHoles
  {
  public:

    PolygonWithHoles GetTransformed(mat33 const &) const;
    Dg::ErrorCode GetAABB(aabb *pOut) const;

    // Use to construct a valid polygon with holes.
    // This ensures the boundary will be the first loop, and subsequent
    // loops do not intersect, are contined inside the boundary, and
    // are correctly wound.
    bool Add(PolygonLoop const &);

    Dg::DoublyLinkedList<PolygonLoop> loops;
  };

  // Helper function to organise the loops into valid polygons with holes.
  std::vector<PolygonWithHoles> BuildPolygonsWithHoles(std::vector<PolygonLoop> const &);
}

#endif