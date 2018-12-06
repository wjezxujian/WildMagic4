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
#include "Wm4DelPolygonEdge.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DelPolygonEdge<Real>::DelPolygonEdge (int iV0, int iV1, int iNullIndex,
    DelTriangle<Real>* pkTri)
    :
    VEManifoldMesh::Edge(iV0,iV1)
{
    NullIndex = iNullIndex;
    Tri = pkTri;
}
//----------------------------------------------------------------------------
template <class Real>
VEManifoldMesh::EPtr DelPolygonEdge<Real>::ECreator (int iV0, int iV1)
{
    return WM4_NEW DelPolygonEdge<Real>(iV0,iV1,0,0);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DelPolygonEdge<float>;

template WM4_FOUNDATION_ITEM
class DelPolygonEdge<double>;
//----------------------------------------------------------------------------
}
