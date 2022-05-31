#ifndef XNGEOMETRICQUERIES_H
#define XNGEOMETRICQUERIES_H

#include "DgError.h"
#include "DgQuery.h"
#include "xnGeometry.h"

namespace xn
{
  // Intersecting, NotIntersecting
  Dg::QueryCode IntersectsBoundary(DgPolygon const &p, seg const &s);

}

#endif