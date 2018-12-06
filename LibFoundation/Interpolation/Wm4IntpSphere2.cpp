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
#include "Wm4IntpSphere2.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntpSphere2<Real>::IntpSphere2 (int iQuantity, Real* afTheta, Real* afPhi,
    Real* afF, bool bOwner, Query::Type eQueryType)
{
    // Copy the input data.  The larger arrays are used to support wrap-around
    // in the Delaunay triangulation for the interpolator.  The Vector2<Real>
    // object V corresponds to (V.X(),V.Y()) = (theta,phi).
    int iThreeQuantity = 3*iQuantity;
    Vector2<Real>* akWrapAngles = WM4_NEW Vector2<Real>[iThreeQuantity];
    Real* afWrapF = WM4_NEW Real[iThreeQuantity];
    for (int i = 0; i < iQuantity; i++)
    {
        akWrapAngles[i].X() = afTheta[i];
        akWrapAngles[i].Y() = afPhi[i];
        afWrapF[i] = afF[i];
    }

    if (bOwner)
    {
        WM4_DELETE[] afTheta;
        WM4_DELETE[] afPhi;
        WM4_DELETE[] afF;
    }

    // use periodicity to get wrap-around in the Delaunay triangulation
    int i0 = 0, i1 = iQuantity, i2 = 2*iQuantity;
    for (/**/; i0 < iQuantity; i0++, i1++, i2++)
    {
        akWrapAngles[i1].X() = akWrapAngles[i0].X() + Math<Real>::TWO_PI;
        akWrapAngles[i2].X() = akWrapAngles[i0].X() - Math<Real>::TWO_PI;
        akWrapAngles[i1].Y() = akWrapAngles[i0].Y();
        akWrapAngles[i2].Y() = akWrapAngles[i0].Y();
        afWrapF[i1] = afWrapF[i0];
        afWrapF[i2] = afWrapF[i0];
    }

    m_pkDel = WM4_NEW Delaunay2<Real>(iThreeQuantity,akWrapAngles,(Real)0.001,
        true,eQueryType);
    m_pkInterp = WM4_NEW IntpQdrNonuniform2<Real>(*m_pkDel,afWrapF,true);
}
//----------------------------------------------------------------------------
template <class Real>
IntpSphere2<Real>::~IntpSphere2 ()
{
    WM4_DELETE m_pkDel;
    WM4_DELETE m_pkInterp;
}
//----------------------------------------------------------------------------
template <class Real>
void IntpSphere2<Real>::GetSphericalCoords (Real fX, Real fY, Real fZ,
    Real& rfTheta, Real& rfPhi)
{
    // Assumes (x,y,z) is unit length.  Returns -PI <= theta <= PI and
    // 0 <= phiAngle <= PI.

    if (fZ < (Real)1.0)
    {
        if (fZ > -(Real)1.0)
        {
            rfTheta = Math<Real>::ATan2(fY,fX);
            rfPhi = Math<Real>::ACos(fZ);
        }
        else
        {
            rfTheta = -Math<Real>::PI;
            rfPhi = Math<Real>::PI;
        }
    }
    else
    {
        rfTheta = -Math<Real>::PI;
        rfPhi = (Real)0.0;
    }
}
//----------------------------------------------------------------------------
template <class Real>
bool IntpSphere2<Real>::Evaluate (Real fTheta, Real fPhi, Real& rfF)
{
    Vector2<Real> kAngles(fTheta,fPhi);
    Real fThetaDeriv, fPhiDeriv;
    return m_pkInterp->Evaluate(kAngles,rfF,fThetaDeriv,fPhiDeriv);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntpSphere2<float>;

template WM4_FOUNDATION_ITEM
class IntpSphere2<double>;
//----------------------------------------------------------------------------
}
