#ifndef A2DGEOMETRY_H
#define A2DGEOMETRY_H

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
  };

  class PolygonGroup
  {
  public:

    void Render(Renderer *pRenderer, mat33 const &T_World_View, LineProperties const &opts, Transform const &transform = Transform()) const;
    bool ReadFromOBJ(std::string const &file);
    Dg::ErrorCode GetAABB(aabb *pOut) const;

    std::vector<Polygon> polygons;
  };

  class GeometryCollection
  {
  public:

    void Clear();
    std::vector<std::string> GetModelNames() const;
    std::vector<char> ToImGuiNameString() const;
    int GetIndex(std::string const &) const;
    PolygonGroup const *Find(std::string const &) const;
    PolygonGroup *Find(std::string const &);
    bool Exists(std::string const &) const;
    void PushBack(std::string const &, PolygonGroup const &);

    bool GetNameFromIndex(int index, std::string &);
    PolygonGroup const *GetFromIndex(int index) const;
    PolygonGroup *GetFromIndex(int index);

    std::map<std::string, PolygonGroup> const * GetList() const;

  private:

    std::map<std::string, PolygonGroup> m_list;
  };
}

#endif