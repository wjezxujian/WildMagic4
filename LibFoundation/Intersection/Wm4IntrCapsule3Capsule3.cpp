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
#include "Wm4IntrCapsule3Capsule3.h"
#include "Wm4DistSegment3Segment3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrCapsule3Capsule3<Real>::IntrCapsule3Capsule3 (
    const Capsule3<Real>& rkCapsule0, const Capsule3<Real>& rkCapsule1)
    :
    m_rkCapsule0(rkCapsule0),
    m_rkCapsule1(rkCapsule1)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Capsule3<Real>& IntrCapsule3Capsule3<Real>::GetCapsule0 () const
{
    return m_rkCapsule0;
}
//----------------------------------------------------------------------------
template <class Real>
const Capsule3<Real>& IntrCapsule3Capsule3<Real>::GetCapsule1 () const
{
    return m_rkCapsule1;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrCapsule3Capsule3<Real>::Test ()
{
    Real fDistance = DistSegment3Segment3<Real>(m_rkCapsule0.Segment,
        m_rkCapsule1.Segment).Get();
    Real fRSum = m_rkCapsule0.Radius + m_rkCapsule1.Radius;
    return fDistance <= fRSum;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrCapsule3Capsule3<float>;

template WM4_FOUNDATION_ITEM
class IntrCapsule3Capsule3<double>;
//----------------------------------------------------------------------------
}
