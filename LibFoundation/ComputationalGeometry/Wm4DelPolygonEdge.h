// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DELPOLYGONEDGE_H
#define WM4DELPOLYGONEDGE_H

#include "Wm4FoundationLIB.h"
#include "Wm4VEManifoldMesh.h"
#include "Wm4DelTriangle.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DelPolygonEdge : public VEManifoldMesh::Edge
{
public:
    DelPolygonEdge (int iV0 = -1, int iV1 = -1, int iNullIndex = -1,
            DelTriangle<Real>* pkTri = 0);

    static VEManifoldMesh::EPtr ECreator (int iV0, int iV1);

    int NullIndex;
    DelTriangle<Real>* Tri;
};

typedef DelPolygonEdge<float> DelPolygonEdgef;
typedef DelPolygonEdge<double> DelPolygonEdged;

}

#endif
