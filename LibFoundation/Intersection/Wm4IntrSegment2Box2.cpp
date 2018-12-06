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
#include "Wm4IntrSegment2Box2.h"
#include "Wm4IntrLine2Box2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrSegment2Box2<Real>::IntrSegment2Box2 (const Segment2<Real>& rkSegment,
    const Box2<Real>& rkBox, bool bSolid)
    :
    m_rkSegment(rkSegment),
    m_rkBox(rkBox)
{
    m_bSolid = bSolid;
}
//----------------------------------------------------------------------------
template <class Real>
const Segment2<Real>& IntrSegment2Box2<Real>::GetSegment () const
{
    return m_rkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
const Box2<Real>& IntrSegment2Box2<Real>::GetBox () const
{
    return m_rkBox;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment2Box2<Real>::Test ()
{
    Vector2<Real> kDiff = m_rkSegment.Origin - m_rkBox.Center;

    Real fAWdU[2], fADdU[2], fRhs;
    fAWdU[0] = Math<Real>::FAbs(m_rkSegment.Direction.Dot(m_rkBox.Axis[0]));
    fADdU[0] = Math<Real>::FAbs(kDiff.Dot(m_rkBox.Axis[0]));
    fRhs = m_rkBox.Extent[0] + m_rkSegment.Extent*fAWdU[0];
    if (fADdU[0] > fRhs)
    {
        return false;
    }

    fAWdU[1] = Math<Real>::FAbs(m_rkSegment.Direction.Dot(m_rkBox.Axis[1]));
    fADdU[1] = Math<Real>::FAbs(kDiff.Dot(m_rkBox.Axis[1]));
    fRhs = m_rkBox.Extent[1] + m_rkSegment.Extent*fAWdU[1];
    if (fADdU[1] > fRhs)
    {
        return false;
    }

    Vector2<Real> kPerp = m_rkSegment.Direction.Perp();
    Real fLhs = Math<Real>::FAbs(kPerp.Dot(kDiff));
    Real fPart0 = Math<Real>::FAbs(kPerp.Dot(m_rkBox.Axis[0]));
    Real fPart1 = Math<Real>::FAbs(kPerp.Dot(m_rkBox.Axis[1]));
    fRhs = m_rkBox.Extent[0]*fPart0 + m_rkBox.Extent[1]*fPart1;
    return fLhs <= fRhs;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment2Box2<Real>::Find ()
{
    Real fT0 = -m_rkSegment.Extent, fT1 = m_rkSegment.Extent;
    return IntrLine2Box2<Real>::DoClipping(fT0,fT1,m_rkSegment.Origin,
        m_rkSegment.Direction,m_rkBox,m_bSolid,m_iQuantity,m_akPoint,
        m_iIntersectionType);
}
//----------------------------------------------------------------------------
template <class Real>
int IntrSegment2Box2<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector2<Real>& IntrSegment2Box2<Real>::GetPoint (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akPoint[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrSegment2Box2<float>;

template WM4_FOUNDATION_ITEM
class IntrSegment2Box2<double>;
//----------------------------------------------------------------------------
}
