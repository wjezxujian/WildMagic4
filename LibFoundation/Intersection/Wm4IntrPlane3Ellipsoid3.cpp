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
#include "Wm4IntrPlane3Ellipsoid3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrPlane3Ellipsoid3<Real>::IntrPlane3Ellipsoid3 (const Plane3<Real>& rkPlane,
    const Ellipsoid3<Real>& rkEllipsoid)
    :
    m_rkPlane(rkPlane),
    m_rkEllipsoid(rkEllipsoid)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrPlane3Ellipsoid3<Real>::GetPlane () const
{
    return m_rkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
const Ellipsoid3<Real>& IntrPlane3Ellipsoid3<Real>::GetEllipsoid () const
{
    return m_rkEllipsoid;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Ellipsoid3<Real>::Test ()
{
    Matrix3<Real> kMInverse;
    m_rkEllipsoid.GetMInverse(kMInverse);
    Real fDiscr = kMInverse.QForm(m_rkPlane.Normal,m_rkPlane.Normal);
    Real fRoot = Math<Real>::Sqrt(Math<Real>::FAbs(fDiscr));
    Real fSDist = m_rkPlane.DistanceTo(m_rkEllipsoid.Center);
    return Math<Real>::FAbs(fSDist) <= fRoot;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Ellipsoid3<Real>::EllipsoidIsCulled () const
{
    Matrix3<Real> kMInverse;
    m_rkEllipsoid.GetMInverse(kMInverse);
    Real fDiscr = kMInverse.QForm(m_rkPlane.Normal,m_rkPlane.Normal);
    Real fRoot = Math<Real>::Sqrt(Math<Real>::FAbs(fDiscr));
    Real fSDist = m_rkPlane.DistanceTo(m_rkEllipsoid.Center);
    return fSDist <= -fRoot;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrPlane3Ellipsoid3<float>;

template WM4_FOUNDATION_ITEM
class IntrPlane3Ellipsoid3<double>;
//----------------------------------------------------------------------------
}
