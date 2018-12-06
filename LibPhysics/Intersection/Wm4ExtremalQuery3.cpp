// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4PhysicsPCH.h"
#include "Wm4ExtremalQuery3.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3<Real>::ExtremalQuery3 (
    const ConvexPolyhedron3<Real>& rkPolytope)
    :
    m_rkPolytope(rkPolytope)
{
    // Create the triangle normals.
    const Vector3<Real>* akVertex = m_rkPolytope.GetVertices();
    int iTQuantity = m_rkPolytope.GetTQuantity();
    const int* piIndex = m_rkPolytope.GetIndices();
    m_akFaceNormal = WM4_NEW Vector3<Real>[iTQuantity];
    for (int i = 0; i < iTQuantity; i++)
    {
        const Vector3<Real>& rkV0 = akVertex[*piIndex++];
        const Vector3<Real>& rkV1 = akVertex[*piIndex++];
        const Vector3<Real>& rkV2 = akVertex[*piIndex++];
        Vector3<Real> kEdge1 = rkV1 - rkV0;
        Vector3<Real> kEdge2 = rkV2 - rkV0;
        m_akFaceNormal[i] = kEdge1.UnitCross(kEdge2);
    }
}
//----------------------------------------------------------------------------
template <class Real>
ExtremalQuery3<Real>::~ExtremalQuery3 ()
{
    WM4_DELETE[] m_akFaceNormal;
}
//----------------------------------------------------------------------------
template <class Real>
const ConvexPolyhedron3<Real>& ExtremalQuery3<Real>::GetPolytope () const
{
    return m_rkPolytope;
}
//----------------------------------------------------------------------------
template <class Real>
const Vector3<Real>* ExtremalQuery3<Real>::GetFaceNormals () const
{
    return m_akFaceNormal;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_PHYSICS_ITEM
class ExtremalQuery3<float>;

template WM4_PHYSICS_ITEM
class ExtremalQuery3<double>;
//----------------------------------------------------------------------------
}
