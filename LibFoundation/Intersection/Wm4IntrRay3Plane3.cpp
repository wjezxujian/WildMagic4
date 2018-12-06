// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4FoundationPCH.h"
#include "Wm4IntrRay3Plane3.h"
#include "Wm4IntrLine3Plane3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrRay3Plane3<Real>::IntrRay3Plane3 (const Ray3<Real>& rkRay,
    const Plane3<Real>& rkPlane)
    :
    m_rkRay(rkRay),
    m_rkPlane(rkPlane)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Ray3<Real>& IntrRay3Plane3<Real>::GetRay () const
{
    return m_rkRay;
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrRay3Plane3<Real>::GetPlane () const
{
    return m_rkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrRay3Plane3<Real>::Test ()
{
    return Find();
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrRay3Plane3<Real>::Find ()
{
    Line3<Real> kLine(m_rkRay.Origin,m_rkRay.Direction);
    IntrLine3Plane3<Real> kIntr(kLine,m_rkPlane);
    if (kIntr.Find())
    {
        // The line intersects the plane, but possibly at a point that is
        // not on the ray.
        m_iIntersectionType = kIntr.GetIntersectionType();
        m_fRayT = kIntr.GetLineT();
        return m_fRayT >= (Real)0.0;
    }

    m_iIntersectionType = IT_EMPTY;
    return false;
}
//----------------------------------------------------------------------------
template <class Real>
Real IntrRay3Plane3<Real>::GetRayT () const
{
    return m_fRayT;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrRay3Plane3<float>;

template WM4_FOUNDATION_ITEM
class IntrRay3Plane3<double>;
//----------------------------------------------------------------------------
}
