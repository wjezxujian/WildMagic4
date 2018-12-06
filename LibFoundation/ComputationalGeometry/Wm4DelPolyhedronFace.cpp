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
#include "Wm4DelPolyhedronFace.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DelPolyhedronFace<Real>::DelPolyhedronFace (int iV0, int iV1, int iV2,
    int iNullIndex, DelTetrahedron<Real>* pkTetra)
    :
    ETManifoldMesh::Triangle(iV0,iV1,iV2)
{
    NullIndex = iNullIndex;
    Tetra = pkTetra;
}
//----------------------------------------------------------------------------
template <class Real>
ETManifoldMesh::TPtr DelPolyhedronFace<Real>::TCreator (int iV0, int iV1,
    int iV2)
{
    return WM4_NEW DelPolyhedronFace<Real>(iV0,iV1,iV2,0,0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DelPolyhedronFace<float>;

template WM4_FOUNDATION_ITEM
class DelPolyhedronFace<double>;
//----------------------------------------------------------------------------
}
