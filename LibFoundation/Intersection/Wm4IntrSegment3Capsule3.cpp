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
#include "Wm4IntrSegment3Capsule3.h"
#include "Wm4DistSegment3Segment3.h"
#include "Wm4IntrLine3Capsule3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrSegment3Capsule3<Real>::IntrSegment3Capsule3 (
    const Segment3<Real>& rkSegment, const Capsule3<Real>& rkCapsule)
    :
    m_rkSegment(rkSegment),
    m_rkCapsule(rkCapsule)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Segment3<Real>& IntrSegment3Capsule3<Real>::GetSegment () const
{
    return m_rkSegment;
}
//----------------------------------------------------------------------------
template <class Real>
const Capsule3<Real>& IntrSegment3Capsule3<Real>::GetCapsule () const
{
    return m_rkCapsule;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment3Capsule3<Real>::Test ()
{
    Real fDist =
        DistSegment3Segment3<Real>(m_rkSegment,m_rkCapsule.Segment).Get();
    return fDist <= m_rkCapsule.Radius;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrSegment3Capsule3<Real>::Find ()
{
    int iQuantity = IntrLine3Capsule3<Real>::Find(m_rkSegment.Origin,
        m_rkSegment.Direction,m_rkCapsule,m_afParameter);

    m_iQuantity = 0;
    for (int i = 0; i < iQuantity; i++)
    {
        if (Math<Real>::FAbs(m_afParameter[i]) <= m_rkSegment.Extent)
        {
            m_akPoint[m_iQuantity++] = m_rkSegment.Origin +
                m_afParameter[i]*m_rkSegment.Direction;
        }
    }

    if (m_iQuantity == 2)
    {
        m_iIntersectionType = IT_SEGMENT;
    }
    else if (m_iQuantity == 1)
    {
        m_iIntersectionType = IT_POINT;
    }
    else
    {
        m_iIntersectionType = IT_EMPTY;
    }

    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
int IntrSegment3Capsule3<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& IntrSegment3Capsule3<Real>::GetPoint (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_akPoint[i];
}
//----------------------------------------------------------------------------
template <class Real>
Real IntrSegment3Capsule3<Real>::GetParameter (int i) const
{
    assert(0 <= i && i < m_iQuantity);
    return m_afParameter[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrSegment3Capsule3<float>;

template WM4_FOUNDATION_ITEM
class IntrSegment3Capsule3<double>;
//----------------------------------------------------------------------------
}
