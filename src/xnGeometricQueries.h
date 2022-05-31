#ifndef A2DGEOMETRICQUERIES_H
#define A2DGEOMETRICQUERIES_H

#include "DgError.h"
#include "DgQuery.h"
#include "a2dGeometry.h"

namespace xn
{
  // Intersecting, NotIntersecting
  Dg::QueryCode IntersectsBoundary(DgPolygon const &p, seg const &s);

}

#endif