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
#include "Wm4IntpLinearNonuniform2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntpLinearNonuniform2<Real>::IntpLinearNonuniform2 (
    const Delaunay2<Real>& rkDT, Real* afF, bool bOwner)
    :
    m_rkDT(rkDT)
{
    assert(afF);
    m_afF = afF;
    m_bOwner = bOwner;
}
//----------------------------------------------------------------------------
template <class Real>
IntpLinearNonuniform2<Real>::~IntpLinearNonuniform2 ()
{
    if (m_bOwner)
    {
        WM4_DELETE[] m_afF;
    }
}
//----------------------------------------------------------------------------
template <class Real>
bool IntpLinearNonuniform2<Real>::Evaluate (const Vector2<Real>& rkP,
    Real& rfF)
{
    int i = m_rkDT.GetContainingTriangle(rkP);
    if (i == -1)
    {
        return false;
    }

    // Get the barycentric coordinates of P with respect to the triangle,
    // P = b0*V0 + b1*V1 + b2*V2, where b0+b1+b2 = 1.
    Real afBary[3];
    bool bValid = m_rkDT.GetBarycentricSet(i,rkP,afBary);
    assert(bValid);
    if (!bValid)
    {
        return false;
    }

    // get the vertex indices for look up into the function-value array
    int aiIndex[3];
    bValid = m_rkDT.GetIndexSet(i,aiIndex);
    assert(bValid);
    if (!bValid)
    {
        return false;
    }

    // result is a barycentric combination of function values
    rfF = afBary[0]*m_afF[aiIndex[0]] + afBary[1]*m_afF[aiIndex[1]] +
        afBary[2]*m_afF[aiIndex[2]];

    return true;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntpLinearNonuniform2<float>;

template WM4_FOUNDATION_ITEM
class IntpLinearNonuniform2<double>;
//----------------------------------------------------------------------------
}
