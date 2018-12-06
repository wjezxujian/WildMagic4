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
#include "Wm4IntrPlane3Box3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrPlane3Box3<Real>::IntrPlane3Box3 (const Plane3<Real>& rkPlane,
    const Box3<Real>& rkBox)
    :
    m_rkPlane(rkPlane),
    m_rkBox(rkBox)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrPlane3Box3<Real>::GetPlane () const
{
    return m_rkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
const Box3<Real>& IntrPlane3Box3<Real>::GetBox () const
{
    return m_rkBox;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Box3<Real>::Test ()
{
    Real afTmp[3] =
    {
        m_rkBox.Extent[0]*(m_rkPlane.Normal.Dot(m_rkBox.Axis[0])),
        m_rkBox.Extent[1]*(m_rkPlane.Normal.Dot(m_rkBox.Axis[1])),
        m_rkBox.Extent[2]*(m_rkPlane.Normal.Dot(m_rkBox.Axis[2]))
    };

    Real fRadius = Math<Real>::FAbs(afTmp[0]) + Math<Real>::FAbs(afTmp[1]) +
        Math<Real>::FAbs(afTmp[2]);

    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkBox.Center);
    return Math<Real>::FAbs(fSignedDistance) <= fRadius;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Box3<Real>::BoxIsCulled () const
{
    Real afTmp[3] =
    {
        m_rkBox.Extent[0]*(m_rkPlane.Normal.Dot(m_rkBox.Axis[0])),
        m_rkBox.Extent[1]*(m_rkPlane.Normal.Dot(m_rkBox.Axis[1])),
        m_rkBox.Extent[2]*(m_rkPlane.Normal.Dot(m_rkBox.Axis[2]))
    };

    Real fRadius = Math<Real>::FAbs(afTmp[0]) + Math<Real>::FAbs(afTmp[1]) +
        Math<Real>::FAbs(afTmp[2]);

    Real fSignedDistance = m_rkPlane.DistanceTo(m_rkBox.Center);
    return fSignedDistance <= -fRadius;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrPlane3Box3<float>;

template WM4_FOUNDATION_ITEM
class IntrPlane3Box3<double>;
//----------------------------------------------------------------------------
}
