
#include <iostream>
#include <sstream>
#include <filesystem>
#include <fstream>

#include "xnRenderer.h"
#include "xnGeometry.h"
#include "xnCommon.h"
#include "xnLogger.h"
#include "xnRenderer.h"

namespace xn
{
  Transform::Transform()
    : position(0.f, 0.f)
    , rotation(0.f)
    , scale(1.f, 1.0f)
  {
    Reset();
  }

  void Transform::Reset()
  {
    position = vec2(0.f, 0.f);
    rotation = 0.f;
    scale = vec2(1.f, 1.f);
  }

  mat33 Transform::ToMatrix33() const
  {
    mat33 mScale, mRotation, mTranslation;

    mScale.Scaling(scale);
    mRotation.Rotation(rotation);
    mTranslation.Translation(position);

    return mScale * mRotation * mTranslation;
  }

  SegmentCollection SegmentCollection::GetTransformed(mat33 const &t) const
  {
    SegmentCollection result;

    for (seg const &s : segments)
    {
      vec3 p0(s.GetP0().x(), s.GetP0().y(), 1.f);
      vec3 p1(s.GetP1().x(), s.GetP1().y(), 1.f);
      p0 = p0 * t;
      p1 = p1 * t;
      result.segments.push_back(seg(vec2(p0.x(), p0.y()), vec2(p1.x(), p1.y())));
    }

    return result;
  }

  Polygon Polygon::GetTransformed(mat33 const &t) const
  {
    Polygon result;

    for (auto it = cPointsBegin(); it != cPointsEnd(); it++)
    {
      vec3 v3(it->x(), it->y(), 1.f);
      v3 = v3 * t;
      result.PushBack(vec2(v3.x(), v3.y()));
    }

    return result;
  }

  void Polygon::Render(Renderer *pRenderer, mat33 const &T_World_View, LineProperties const &opts, Transform const &transform) const
  {
    if (Size() < 2)
      return;

    mat33 T_Model_World = transform.ToMatrix33();
    mat33 view = T_Model_World * T_World_View;

    Polygon transformed = GetTransformed(view);

    for (auto it = transformed.cEdgesBegin(); it != transformed.cEdgesEnd(); it++)
      pRenderer->DrawLine(*it, opts);
  }

  void PolygonGroup::Render(Renderer *pRenderer, mat33 const &T_World_View, LineProperties const &opts, Transform const &transform) const
  {
    for (auto const &polygon : polygons)
      polygon.Render(pRenderer, T_World_View, opts, transform);
  }

  Dg::ErrorCode PolygonGroup::GetAABB(aabb *pOut) const
  {
    aabb *pTemp = nullptr;
    Dg::ErrorCode result = Dg::ErrorCode::NotFound;

    for (auto const &polygon : polygons)
    {
      for (auto it = polygon.cPointsBegin(); it != polygon.cPointsEnd(); it++)
      {
        if (pTemp == nullptr)
          pTemp = new aabb(*it, *it);
        else
          (*pTemp) += *it;
      }
    }

    if (pTemp != nullptr)
    {
      *pOut = *pTemp;
      delete pTemp;
      result = Dg::ErrorCode::None;
    }
    return result;
  }

  bool ReadPointsFromOBJ(std::string const &file, std::vector<vec2> &out)
  {
    std::ifstream ifs(file);
    if (!ifs.good())
      return false;

    std::string line;
    while (std::getline(ifs, line))
    {
      std::istringstream iss(line);
      std::string tag;
      iss >> tag;

      if (tag == "v")
      {
        vec2 v;
        if (!(iss >> v.x() >> v.y()))
          return false;

        out.push_back(v);
      }
    }

    return true;
  }

  bool PolygonGroup::ReadFromOBJ(std::string const &file)
  {
    std::vector<vec2> points;
    if (!ReadPointsFromOBJ(file, points))
      return false;

    std::ifstream ifs(file);
    if (!ifs.good())
      return false;

    std::string line;
    while (std::getline(ifs, line))
    {
      std::istringstream iss(line);
      std::string tag;
      iss >> tag;

      if (tag == "l")
      {
        Polygon polygon;
        int index;
        while (iss >> index)
          polygon.PushBack(points[index - 1]);
        polygons.push_back(polygon);
      }
    }

    return true;
  }

  void GeometryCollection::Clear()
  {
    m_list.clear();
  }

  std::vector<char> GeometryCollection::ToImGuiNameString() const
  {
    std::vector<char> result;
    for (auto const &kv : m_list)
    {
      for (char c : kv.first)
        result.push_back(c);
      result.push_back(0);
    }
    result.push_back(0);
    return result;
  }

  std::vector<std::string> GeometryCollection::GetModelNames() const
  {
    std::vector<std::string> result;
    for (auto const &kv : m_list)
      result.push_back(kv.first);
    return result;
  }

  int GeometryCollection::GetIndex(std::string const &name) const
  {
    int i = 0;
    for (auto const &kv : m_list)
    {
      if (name == kv.first)
        return i;
      i++;
    }
    return -1;
  }

  PolygonGroup const *GeometryCollection::Find(std::string const &name) const
  {
    auto it = m_list.find(name);
    if (it != m_list.end())
      return &(it->second);
    return nullptr;
  }

  PolygonGroup *GeometryCollection::Find(std::string const &name)
  {
    auto it = m_list.find(name);
    if (it != m_list.end())
      return &(it->second);
    return nullptr;
  }

  bool GeometryCollection::Exists(std::string const &name) const
  {
    auto it = m_list.find(name);
    return it != m_list.end();
  }

  void GeometryCollection::PushBack(std::string const &name, PolygonGroup const &geom)
  {
    m_list[name] = geom;
  }

  bool GeometryCollection::GetNameFromIndex(int index, std::string &name)
  {
    if (index < 0 || index >= m_list.size())
      return false;

    auto it = m_list.begin();
    for (int i = 0; i < index; i++)
      it++;

    name = it->first;
    return true;
  }

  PolygonGroup const *GeometryCollection::GetFromIndex(int index) const
  {
    if (index < 0 || index >= m_list.size())
      return nullptr;

    auto it = m_list.begin();
    for (int i = 0; i < index; i++)
      it++;

    return &(it->second);
  }

  PolygonGroup *GeometryCollection::GetFromIndex(int index)
  {
    if (index < 0 || index >= m_list.size())
      return nullptr;

    auto it = m_list.begin();
    for (int i = 0; i < index; i++)
      it++;

    return &(it->second);
  }

  std::map<std::string, PolygonGroup> const *GeometryCollection::GetList() const
  {
      return &m_list;
  }
}