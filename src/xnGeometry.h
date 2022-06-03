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

namespace xn
{
  typedef Dg::Vector2<float> vec2;
  typedef Dg::Vector3<float> vec3;
  typedef Dg::Segment2<float> seg;
  typedef Dg::Matrix33<float> mat33;
  typedef Dg::AABB<float, 2> aabb;
  typedef Dg::Polygon2<float> DgPolygon;

  class LineProperties;
  class Renderer;

  class Transform
  {
  public:

    Transform();

    void Reset();
    mat33 ToMatrix33() const;

    vec2 position;
    float rotation;
    vec2 scale;
  };

  class SegmentCollection
  {
  public:

    SegmentCollection GetTransformed(mat33 const &) const;

    std::vector<seg> segments;
  };

  class Polygon : public DgPolygon
  {
  public:

    void Render(Renderer *pRenderer, mat33 const &T_World_View, LineProperties const &opts, Transform const &transform = Transform()) const;
    Polygon GetTransformed(mat33 const &) const;

    uint32_t GetID() const;
    void SetID(uint32_t id);

  private:
    uint32_t m_id;
  };

  class PolygonGroup
  {
  public:

    void Render(Renderer *pRenderer, mat33 const &T_World_View, LineProperties const &opts, Transform const &transform = Transform()) const;
    bool ReadFromOBJ(std::string const &file);
    Dg::ErrorCode GetAABB(aabb *pOut) const;

    std::vector<Polygon> polygons;
  };
}

#endif