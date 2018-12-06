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
#include "Wm4DistVector3Tetrahedron3.h"
#include "Wm4DistVector3Triangle3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DistVector3Tetrahedron3<Real>::DistVector3Tetrahedron3 (
    const Vector3<Real>& rkVector, const Tetrahedron3<Real>& rkTetrahedron)
    :
    m_rkVector(rkVector),
    m_rkTetrahedron(rkTetrahedron)
{
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>& DistVector3Tetrahedron3<Real>::GetVector () const
{
    return m_rkVector;
}
//----------------------------------------------------------------------------
template <class Real>
const Tetrahedron3<Real>& DistVector3Tetrahedron3<Real>::GetTetrahedron ()
    const
{
    return m_rkTetrahedron;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Tetrahedron3<Real>::Get ()
{
    Real fSqrDist = GetSquared();
    return Math<Real>::Sqrt(fSqrDist);
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Tetrahedron3<Real>::GetSquared ()
{
    // Construct the planes for the faces of the tetrahedron.  The normals
    // are outer pointing, but specified not to be unit length.  We only need
    // to know sidedness of the query point, so we will save cycles by not
    // computing unit-length normals.
    Plane3<Real> akPlane[4];
    m_rkTetrahedron.GetPlanes(akPlane,false);

    // Determine which faces are visible to the query point.  Only these
    // need to be processed by point-to-triangle distance queries.
    Real fMinSqrDistance = Math<Real>::MAX_REAL;
    Vector3<Real> kMinTetraClosest = Vector3<Real>::ZERO;
    for (int i = 0; i < 4; i++)
    {
        if (akPlane[i].WhichSide(m_rkVector) >= 0)
        {
            int aiIndex[3] = { 0, 0, 0 };
            m_rkTetrahedron.GetFaceIndices(i,aiIndex);
            Triangle3<Real> kTri(
                m_rkTetrahedron.V[aiIndex[0]],
                m_rkTetrahedron.V[aiIndex[1]],
                m_rkTetrahedron.V[aiIndex[2]]);

            DistVector3Triangle3<Real> kDQuery(m_rkVector,kTri);
            Real fSqrDistance = kDQuery.GetSquared();
            if (fSqrDistance < fMinSqrDistance)
            {
                fMinSqrDistance = fSqrDistance;
                kMinTetraClosest = kDQuery.GetClosestPoint1();
            }
        }
    }

    m_kClosestPoint0 = m_rkVector;
    if (fMinSqrDistance != Math<Real>::MAX_REAL)
    {
        // The query point is outside the "solid" tetrahedron.
        m_kClosestPoint1 = kMinTetraClosest;
    }
    else
    {
        // The query point is inside the "solid" tetrahedron.  Report a zero
        // distance.  The closest points are identical.
        fMinSqrDistance = (Real)0.0;
        m_kClosestPoint1 = m_rkVector;
    }

    return fMinSqrDistance;
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Tetrahedron3<Real>::Get (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Vector3<Real> kMV0 = m_rkTetrahedron.V[0] + fT*rkVelocity1;
    Vector3<Real> kMV1 = m_rkTetrahedron.V[1] + fT*rkVelocity1;
    Vector3<Real> kMV2 = m_rkTetrahedron.V[2] + fT*rkVelocity1;
    Vector3<Real> kMV3 = m_rkTetrahedron.V[3] + fT*rkVelocity1;
    Tetrahedron3<Real> kMTetrahedron(kMV0,kMV1,kMV2,kMV3);
    return DistVector3Tetrahedron3<Real>(kMVector,kMTetrahedron).Get();
}
//----------------------------------------------------------------------------
template <class Real>
Real DistVector3Tetrahedron3<Real>::GetSquared (Real fT,
    const Vector3<Real>& rkVelocity0, const Vector3<Real>& rkVelocity1)
{
    Vector3<Real> kMVector = m_rkVector + fT*rkVelocity0;
    Vector3<Real> kMV0 = m_rkTetrahedron.V[0] + fT*rkVelocity1;
    Vector3<Real> kMV1 = m_rkTetrahedron.V[1] + fT*rkVelocity1;
    Vector3<Real> kMV2 = m_rkTetrahedron.V[2] + fT*rkVelocity1;
    Vector3<Real> kMV3 = m_rkTetrahedron.V[3] + fT*rkVelocity1;
    Tetrahedron3<Real> kMTetrahedron(kMV0,kMV1,kMV2,kMV3);
    return DistVector3Tetrahedron3<Real>(kMVector,kMTetrahedron).GetSquared();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DistVector3Tetrahedron3<float>;

template WM4_FOUNDATION_ITEM
class DistVector3Tetrahedron3<double>;
//----------------------------------------------------------------------------
}
