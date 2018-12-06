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
#include "Wm4IntrLine3Lozenge3.h"
#include "Wm4DistLine3Rectangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrLine3Lozenge3<Real>::IntrLine3Lozenge3 (const Line3<Real>& rkLine,
    const Lozenge3<Real>& rkLozenge)
    :
    m_rkLine(rkLine),
    m_rkLozenge(rkLozenge)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Line3<Real>& IntrLine3Lozenge3<Real>::GetLine () const
{
    return m_rkLine;
}
//----------------------------------------------------------------------------
template <class Real>
const Lozenge3<Real>& IntrLine3Lozenge3<Real>::GetLozenge () const
{
    return m_rkLozenge;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrLine3Lozenge3<Real>::Test ()
{
    Real fDist = DistLine3Rectangle3<Real>(m_rkLine,
        m_rkLozenge.Rectangle).Get();

    return fDist <= m_rkLozenge.Radius;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrLine3Lozenge3<float>;

template WM4_FOUNDATION_ITEM
class IntrLine3Lozenge3<double>;
//----------------------------------------------------------------------------
}
