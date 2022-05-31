
#include "a2dGeometricQueries.h"

#include "DgQuerySegmentSegment.h"

namespace xn
{
  Dg::QueryCode IntersectsBoundary(DgPolygon const &poly, seg const &s)
  {
    Dg::QueryCode result = Dg::QueryCode::NotIntersecting;

    for (auto it = poly.cEdgesBegin(); it != poly.cEdgesEnd(); it++)
    {
      Dg::TI2SegmentSegment<float> query;
      Dg::TI2SegmentSegment<float>::Result qr = query(s, *it);
      if (qr.code != Dg::QueryCode::NotIntersecting)
      {
        result = Dg::QueryCode::Intersecting;
        break;
      }
    }

    return result;
  }
}