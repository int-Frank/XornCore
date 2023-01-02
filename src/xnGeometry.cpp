
#include "xnGeometry.h"
#include "xnCommon.h"
#include "xnLogger.h"

namespace xn
{
  Transform::Transform()
    : translation(0.f, 0.f)
    , rotation(0.f)
    , scale(1.f, 1.0f)
  {
    Reset();
  }

  void Transform::Reset()
  {
    translation = vec2(0.f, 0.f);
    rotation = 0.f;
    scale = vec2(1.f, 1.f);
  }

  mat33 Transform::ToMatrix33() const
  {
    mat33 mScale, mRotation, mTranslation;

    mScale.Scaling(scale);
    mRotation.Rotation(rotation);
    mTranslation.Translation(translation);

    return mScale * mRotation * mTranslation;
  }

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

  void PolygonWithHoles::Push(PolygonLoop const &loop)
  {
    float frontArea = loops.size() == 0 ? 0.f : loops.front().Area();
    if (loop.Area() > frontArea)
      loops.push_front(loop);
    else
      loops.push_back(loop);
  }
}