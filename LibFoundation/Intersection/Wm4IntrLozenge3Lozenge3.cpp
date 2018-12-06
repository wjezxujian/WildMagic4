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
#include "Wm4IntrLozenge3Lozenge3.h"
#include "Wm4DistRectangle3Rectangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrLozenge3Lozenge3<Real>::IntrLozenge3Lozenge3 (
    const Lozenge3<Real>& rkLozenge0, const Lozenge3<Real>& rkLozenge1)
    :
    m_rkLozenge0(rkLozenge0),
    m_rkLozenge1(rkLozenge1)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Lozenge3<Real>& IntrLozenge3Lozenge3<Real>::GetLozenge0 () const
{
    return m_rkLozenge0;
}
//----------------------------------------------------------------------------
template <class Real>
const Lozenge3<Real>& IntrLozenge3Lozenge3<Real>::GetLozenge1 () const
{
    return m_rkLozenge1;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrLozenge3Lozenge3<Real>::Test ()
{
    Real fDist = DistRectangle3Rectangle3<Real>(m_rkLozenge0.Rectangle,
        m_rkLozenge1.Rectangle).Get();
    Real fRSum = m_rkLozenge0.Radius + m_rkLozenge1.Radius;
    return fDist <= fRSum;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrLozenge3Lozenge3<float>;

template WM4_FOUNDATION_ITEM
class IntrLozenge3Lozenge3<double>;
//----------------------------------------------------------------------------
}
