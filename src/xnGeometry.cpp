
#include "DgQueryPolygonPolygon.h"
#include "DgDoublyLinkedList.h"

#include "xnGeometry.h"
#include "xnCommon.h"
#include "xnLogger.h"

namespace xn
{
  PolygonLoop PolygonLoop::GetTransformed(mat33 const &t) const
  {
    PolygonLoop result;

    for (auto it = cPointsBegin(); it != cPointsEnd(); it++)
    {
      vec3 v3(it->x(), it->y(), 1.f);
      v3 = v3 * t;
      result.PushBack(vec2(v3.x(), v3.y()));
    }

    return result;
  }

  Dg::ErrorCode PolygonLoop::GetAABB(aabb *pOut) const
  {
    Dg::ErrorCode result;
    vec2 p0;

    DG_ERROR_IF(Size() == 0, Dg::ErrorCode::NotFound);

    p0 = *cPointsBegin();
    *pOut = aabb(p0, p0);

    for (auto it = cPointsBegin(); it != cPointsEnd(); it++)
      (*pOut) += *it;

    result = Dg::ErrorCode::None;
  epilogue:

    return result;
  }

  PolygonWithHoles PolygonWithHoles::GetTransformed(mat33 const &transform) const
  {
    PolygonWithHoles newPolygon;

    for (auto it = loops.cbegin(); it != loops.cend(); it++)
      newPolygon.loops.push_back(it->GetTransformed(transform));

    return newPolygon;
  }

  Dg::ErrorCode PolygonWithHoles::GetAABB(aabb *pOut) const
  {
    Dg::ErrorCode result;
    aabb bbox;

    DG_ERROR_IF(loops.size() == 0, Dg::ErrorCode::NotFound);
    DG_ERROR_CHECK(loops.front().GetAABB(&bbox));

    result = Dg::ErrorCode::None;
  epilogue:

    return result;
  }

  bool PolygonWithHoles::Add(PolygonLoop const &loop)
  {
    // Boundary...
    if (loops.empty())
    {
      auto winding = loop.Winding();
      if (winding != Dg::Orientation::CCW && winding != Dg::Orientation::CW)
        return false;

      if (winding != Dg::Orientation::CCW)
      {
        auto newLoop = loop;
        newLoop.SetWinding(Dg::Orientation::CCW);
        loops.push_back(newLoop);
      }
      else
      {
        loops.push_back(loop);
      }
      return true;
    }

    // Holes...
    auto winding = loop.Winding();
    if (winding != Dg::Orientation::CCW && winding != Dg::Orientation::CW)
      return false;

    auto it = loops.cbegin();

    Dg::TI2PolygonPolygon<float> query;
    Dg::TI2PolygonPolygon<float>::Result result = query(*it, loop);

    if (result.code != Dg::QueryCode::B_in_A)
      return false;

    it++;
    for (; it != loops.cend(); it++)
    {
      result = query(*it, loop);

      if (result.code != Dg::QueryCode::NotIntersecting)
        return false;
    }

    if (winding == Dg::Orientation::CCW)
    {
      auto newLoop = loop;
      newLoop.SetWinding(Dg::Orientation::CW);
      loops.push_back(newLoop);
    }
    else
    {
      loops.push_back(loop);
    }

    return true;
  }

  std::vector<PolygonWithHoles> BuildPolygonsWithHoles(std::vector<PolygonLoop> const &loops)
  {
    Dg::DoublyLinkedList<PolygonLoop const*> loopList;
    for (auto const &loop : loops)
      loopList.push_back(&loop);
    loopList.sort([](PolygonLoop const *pLoopA, PolygonLoop const *pLoopB) 
      {
        return pLoopA->Area() > pLoopB->Area();
      });

    std::vector<PolygonWithHoles> result;

    bool nextFound = true;
    while (nextFound)
    {
      nextFound = false;

      PolygonWithHoles polygon;
      for (auto it = loopList.begin(); it != loopList.end();)
      {
        if (polygon.Add(**it))
          it = loopList.erase(it);
        else
          it++;
      }

      if (!polygon.loops.empty())
      {
        result.push_back(polygon);
        nextFound = true;
      }
    }

    return result;
  }
}