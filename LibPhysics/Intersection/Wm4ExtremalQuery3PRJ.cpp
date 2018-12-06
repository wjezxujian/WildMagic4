// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4PhysicsPCH.h"
#include "Wm4ExtremalQuery3PRJ.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3PRJ<Real>::ExtremalQuery3PRJ (
    const ConvexPolyhedron3<Real>& rkPolytope)
    :
    ExtremalQuery3<Real>(rkPolytope)
{
    m_kCentroid = m_rkPolytope.ComputeVertexAverage();
}
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3PRJ<Real>::~ExtremalQuery3PRJ ()
{
}
//----------------------------------------------------------------------------
template <class Real>
void ExtremalQuery3PRJ<Real>::GetExtremeVertices (
    const Vector3<Real>& rkDirection, int& riPositiveDirection,
    int& riNegativeDirection)
{
    Vector3<Real> kDiff = m_rkPolytope.GetVertex(0) - m_kCentroid;
    Real fMin = rkDirection.Dot(kDiff), fMax = fMin;
    riNegativeDirection = 0;
    riPositiveDirection = 0;

    for (int i = 1; i < m_rkPolytope.GetVQuantity(); i++)
    {
        kDiff = m_rkPolytope.GetVertex(i) - m_kCentroid;
        Real fDot = rkDirection.Dot(kDiff);
        if (fDot < fMin)
        {
            riNegativeDirection = i;
            fMin = fDot;
        }
        else if (fDot > fMax)
        {
            riPositiveDirection = i;
            fMax = fDot;
        }
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_PHYSICS_ITEM
class ExtremalQuery3PRJ<float>;

template WM4_PHYSICS_ITEM
class ExtremalQuery3PRJ<double>;
//----------------------------------------------------------------------------
}
