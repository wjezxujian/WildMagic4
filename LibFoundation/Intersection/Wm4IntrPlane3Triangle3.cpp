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
#include "Wm4IntrPlane3Triangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
IntrPlane3Triangle3<Real>::IntrPlane3Triangle3 (const Plane3<Real>& rkPlane,
    const Triangle3<Real>& rkTriangle, Real fEpsilon)
    :
    m_rkPlane(rkPlane),
    m_rkTriangle(rkTriangle)
{
    if (fEpsilon >= (Real)0.0)
    {
        m_fEpsilon = fEpsilon;
    }
    else
    {
        m_fEpsilon = (Real)0.0;
    }
}
//----------------------------------------------------------------------------
template <class Real>
const Plane3<Real>& IntrPlane3Triangle3<Real>::GetPlane () const
{
    return m_rkPlane;
}
//----------------------------------------------------------------------------
template <class Real>
const Triangle3<Real>& IntrPlane3Triangle3<Real>::GetTriangle () const
{
    return m_rkTriangle;
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Triangle3<Real>::Test ()
{
    // Compute the signed distances from the vertices to the plane.
    Real fZero = (Real)0.0;
    Real afSD[3];
    for (int i = 0; i < 3; i++)
    {
        afSD[i] = m_rkPlane.DistanceTo(m_rkTriangle.V[i]);
        if (Math<Real>::FAbs(afSD[i]) <= m_fEpsilon)
        {
            afSD[i] = fZero;
        }
    };

    // The triangle intersects the plane if not all vertices are on the
    // positive side of the plane and not all vertices are on the negative
    // side of the plane.
    return !(afSD[0] > fZero && afSD[1] > fZero && afSD[2] > fZero)
        && !(afSD[0] < fZero && afSD[1] < fZero && afSD[2] < fZero);
}
//----------------------------------------------------------------------------
template <class Real>
bool IntrPlane3Triangle3<Real>::Find ()
{
    // Compute the signed distances from the vertices to the plane.
    Real fZero = (Real)0.0;
    Real afSD[3];
    for (int i = 0; i < 3; i++)
    {
        afSD[i] = m_rkPlane.DistanceTo(m_rkTriangle.V[i]);
        if (Math<Real>::FAbs(afSD[i]) <= m_fEpsilon)
        {
            afSD[i] = fZero;
        }
    };

    const Vector3<Real>& rkV0 = m_rkTriangle.V[0];
    const Vector3<Real>& rkV1 = m_rkTriangle.V[1];
    const Vector3<Real>& rkV2 = m_rkTriangle.V[2];

    if (afSD[0] > fZero)
    {
        if (afSD[1] > fZero)
        {
            if (afSD[2] > fZero)
            {
                // ppp
                m_iQuantity = 0;
                m_iIntersectionType = IT_EMPTY;
            }
            else if (afSD[2] < fZero)
            {
                // ppm
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[2]))*(rkV2-rkV0);
                m_akPoint[1] = rkV1+(afSD[1]/(afSD[1]-afSD[2]))*(rkV2-rkV1);
                m_iIntersectionType = IT_SEGMENT;
            }
            else
            {
                // ppz
                m_iQuantity = 1;
                m_akPoint[0] = rkV2;
                m_iIntersectionType = IT_POINT;
            }
        }
        else if (afSD[1] < fZero)
        {
            if (afSD[2] > fZero)
            {
                // pmp
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[1]))*(rkV1-rkV0);
                m_akPoint[1] = rkV1+(afSD[1]/(afSD[1]-afSD[2]))*(rkV2-rkV1);
                m_iIntersectionType = IT_SEGMENT;
            }
            else if (afSD[2] < fZero)
            {
                // pmm
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[1]))*(rkV1-rkV0);
                m_akPoint[1] = rkV0+(afSD[0]/(afSD[0]-afSD[2]))*(rkV2-rkV0);
                m_iIntersectionType = IT_SEGMENT;
            }
            else
            {
                // pmz
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[1]))*(rkV1-rkV0);
                m_akPoint[1] = rkV2;
                m_iIntersectionType = IT_SEGMENT;
            }
        }
        else
        {
            if (afSD[2] > fZero)
            {
                // pzp
                m_iQuantity = 1;
                m_akPoint[0] = rkV1;
                m_iIntersectionType = IT_POINT;
            }
            else if (afSD[2] < fZero)
            {
                // pzm
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[2]))*(rkV2-rkV0);
                m_akPoint[1] = rkV1;
                m_iIntersectionType = IT_SEGMENT;
            }
            else
            {
                // pzz
                m_iQuantity = 2;
                m_akPoint[0] = rkV1;
                m_akPoint[1] = rkV2;
                m_iIntersectionType = IT_SEGMENT;
            }
        }
    }
    else if (afSD[0] < fZero)
    {
        if (afSD[1] > fZero)
        {
            if (afSD[2] > fZero)
            {
                // mpp
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[1]))*(rkV1-rkV0);
                m_akPoint[1] = rkV0+(afSD[0]/(afSD[0]-afSD[2]))*(rkV2-rkV0);
                m_iIntersectionType = IT_SEGMENT;
            }
            else if (afSD[2] < fZero)
            {
                // mpm
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[1]))*(rkV1-rkV0);
                m_akPoint[1] = rkV1+(afSD[1]/(afSD[1]-afSD[2]))*(rkV2-rkV1);
                m_iIntersectionType = IT_SEGMENT;
            }
            else
            {
                // mpz
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[1]))*(rkV1-rkV0);
                m_akPoint[1] = rkV2;
                m_iIntersectionType = IT_SEGMENT;
            }
        }
        else if (afSD[1] < fZero)
        {
            if (afSD[2] > fZero)
            {
                // mmp
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[2]))*(rkV2-rkV0);
                m_akPoint[1] = rkV1+(afSD[1]/(afSD[1]-afSD[2]))*(rkV2-rkV1);
                m_iIntersectionType = IT_SEGMENT;
            }
            else if (afSD[2] < fZero)
            {
                // mmm
                m_iQuantity = 0;
                m_iIntersectionType = IT_EMPTY;
            }
            else
            {
                // mmz
                m_iQuantity = 1;
                m_akPoint[0] = m_rkTriangle.V[2];
                m_iIntersectionType = IT_POINT;
            }
        }
        else
        {
            if (afSD[2] > fZero)
            {
                // mzp
                m_iQuantity = 2;
                m_akPoint[0] = rkV0+(afSD[0]/(afSD[0]-afSD[2]))*(rkV2-rkV0);
                m_akPoint[1] = rkV1;
                m_iIntersectionType = IT_SEGMENT;
            }
            else if (afSD[2] < fZero)
            {
                // mzm
                m_iQuantity = 1;
                m_akPoint[0] = rkV1;
                m_iIntersectionType = IT_POINT;
            }
            else
            {
                // mzz
                m_iQuantity = 2;
                m_akPoint[0] = rkV1;
                m_akPoint[1] = rkV2;
                m_iIntersectionType = IT_SEGMENT;
            }
        }
    }
    else
    {
        if (afSD[1] > fZero)
        {
            if (afSD[2] > fZero)
            {
                // zpp
                m_iQuantity = 1;
                m_akPoint[0] = rkV0;
                m_iIntersectionType = IT_POINT;
            }
            else if (afSD[2] < fZero)
            {
                // zpm
                m_iQuantity = 2;
                m_akPoint[0] = rkV1+(afSD[1]/(afSD[1]-afSD[2]))*(rkV2-rkV1);
                m_akPoint[1] = rkV0;
                m_iIntersectionType = IT_SEGMENT;
            }
            else
            {
                // zpz
                m_iQuantity = 2;
                m_akPoint[0] = rkV0;
                m_akPoint[1] = rkV2;
                m_iIntersectionType = IT_SEGMENT;
            }
        }
        else if (afSD[1] < fZero)
        {
            if (afSD[2] > fZero)
            {
                // zmp
                m_iQuantity = 2;
                m_akPoint[0] = rkV1+(afSD[1]/(afSD[1]-afSD[2]))*(rkV2-rkV1);
                m_akPoint[1] = rkV0;
                m_iIntersectionType = IT_SEGMENT;
            }
            else if (afSD[2] < fZero)
            {
                // zmm
                m_iQuantity = 1;
                m_akPoint[0] = rkV0;
                m_iIntersectionType = IT_POINT;
            }
            else
            {
                // zmz
                m_iQuantity = 2;
                m_akPoint[0] = rkV0;
                m_akPoint[1] = rkV2;
                m_iIntersectionType = IT_SEGMENT;
            }
        }
        else
        {
            if (afSD[2] > fZero)
            {
                // zzp
                m_iQuantity = 2;
                m_akPoint[0] = rkV0;
                m_akPoint[1] = rkV1;
                m_iIntersectionType = IT_SEGMENT;
            }
            else if (afSD[2] < fZero)
            {
                // zzm
                m_iQuantity = 2;
                m_akPoint[0] = rkV0;
                m_akPoint[1] = rkV1;
                m_iIntersectionType = IT_SEGMENT;
            }
            else
            {
                // zzz
                m_iQuantity = 3;
                m_akPoint[0] = rkV0;
                m_akPoint[1] = rkV1;
                m_akPoint[2] = rkV2;
                m_iIntersectionType = IT_POLYGON;
            }
        }
    }

    return m_iIntersectionType != IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real>
int IntrPlane3Triangle3<Real>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& IntrPlane3Triangle3<Real>::GetPoint (int i) const
{
    assert( 0 <= i && i < m_iQuantity );
    return m_akPoint[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class IntrPlane3Triangle3<float>;

template WM4_FOUNDATION_ITEM
class IntrPlane3Triangle3<double>;
//----------------------------------------------------------------------------
}
