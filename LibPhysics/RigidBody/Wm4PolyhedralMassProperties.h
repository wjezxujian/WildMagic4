// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4POLYHEDRALMASSPROPERTIES_H
#define WM4POLYHEDRALMASSPROPERTIES_H

#include "Wm4PhysicsLIB.h"
#include "Wm4Matrix3.h"

namespace Wm4
{

// The input triangle mesh must represent a polyhedron.  The triangles are
// represented as triples of indices <V0,V1,V2> into the vertex array.
// The connectivity array has iTQuantity such triples.  The Boolean value
// bBodyCoords is 'true' if you want the inertia tensor to be relative to
// body coordinates, 'false' if you want it in world coordinates.

template <class Real> WM4_PHYSICS_ITEM
void ComputeMassProperties (const Vector3<Real>* akVertex, int iTQuantity,
    const int* aiIndex, bool bBodyCoords, Real& rfMass,
    Vector3<Real>& rkCenter, Matrix3<Real>& rkInertia);

}

#endif
