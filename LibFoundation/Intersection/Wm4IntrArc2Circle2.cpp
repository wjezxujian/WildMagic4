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
#include "Wm4IntrArc2Circle2.h"
#include "Wm4IntrCircle2Circle2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrArc2Circle2<Real>::IntrArc2Circle2 (const Arc2<Real>& rkArc,
    const Circle2<Real>& rkCircle)
    :
    m_rkArc(rkArc),
    m_rkCircle(rkCircle)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Arc2<Real>& IntrArc2Circle2<Real>::GetArc () const
{
    return m_rkArc;
}
//----------------------------------------------------------------------------
template <class Real>
const Circle2<Real>& IntrArc2Circle2<Real>::GetCircle () const
{
    return m_rkCircle;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrArc2Circle2<Real>::Find ()
{
    m_iQuantity = 0;

    Circle2<Real> kCircleOfArc(m_rkArc.Center,m_rkArc.Radius);
    IntrCircle2Circle2<Real> kIntr(m_rkCircle,kCircleOfArc);
    if (!kIntr.Find())
    {
        // arc and circle do not intersect
        m_iIntersectionType = IT_EMPTY;
        return false;
    }

    if (kIntr.GetIntersectionType() == IT_OTHER)
    {
        // arc is on the circle
        m_iIntersectionType = IT_OTHER;
        return true;
    }

    // test if circle-circle intersection points are on the arc
    for (int i = 0; i < kIntr.GetQuantity(); i++)
    {
        if (m_rkArc.Contains(kIntr.GetPoint(i)))
        {
            m_akPoint[m_iQuantity++] = kIntr.GetPoint(i);
        }
    }

    m_iIntersectionType = (m_iQuantity > 0 ? IT_POINT : IT_EMPTY);
    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
int IntrArc2Circle2<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& IntrArc2Circle2<Real>::GetPoint (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akPoint[i];
}
//----------------------------------------------------------------------------
template <class Real>
const Arc2<Real>& IntrArc2Circle2<Real>::GetIntersectionArc () const
{
    return m_rkArc;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrArc2Circle2<float>;

template WM4_FOUNDATION_ITEM
class IntrArc2Circle2<double>;
//----------------------------------------------------------------------------
}
