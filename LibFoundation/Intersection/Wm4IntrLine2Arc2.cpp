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
#include "Wm4IntrLine2Arc2.h"
#include "Wm4IntrLine2Circle2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrLine2Arc2<Real>::IntrLine2Arc2 (const Line2<Real>& rkLine,
    const Arc2<Real>& rkArc)
    :
    m_rkLine(rkLine),
    m_rkArc(rkArc)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Line2<Real>& IntrLine2Arc2<Real>::GetLine () const
{
    return m_rkLine;
}
//----------------------------------------------------------------------------
template <class Real>
const Arc2<Real>& IntrLine2Arc2<Real>::GetArc () const
{
    return m_rkArc;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrLine2Arc2<Real>::Find ()
{
    Real afT[2];
    int iQuantity;
    bool bIntersects = IntrLine2Circle2<Real>::Find(m_rkLine.Origin,
        m_rkLine.Direction,m_rkArc.Center,m_rkArc.Radius,iQuantity,afT);

    m_iQuantity = 0;
    if (bIntersects)
    {
        for (int i = 0; i < iQuantity; i++)
        {
            Vector2<Real> kPoint = m_rkLine.Origin +
                m_rkLine.Direction*afT[i];
            if ( m_rkArc.Contains(kPoint) )
                m_akPoint[m_iQuantity++] = kPoint;
        }
    }

    m_iIntersectionType = (m_iQuantity > 0 ? IT_POINT : IT_EMPTY);
    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
int IntrLine2Arc2<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& IntrLine2Arc2<Real>::GetPoint (int i)
    const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akPoint[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrLine2Arc2<float>;

template WM4_FOUNDATION_ITEM
class IntrLine2Arc2<double>;
//----------------------------------------------------------------------------
}
