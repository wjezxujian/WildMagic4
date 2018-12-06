// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DELPOLYHEDRONFACE_H
#define WM4DELPOLYHEDRONFACE_H

#include "Wm4FoundationLIB.h"
#include "Wm4ETManifoldMesh.h"
#include "Wm4DelTetrahedron.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DelPolyhedronFace : public ETManifoldMesh::Triangle
{
public:
    DelPolyhedronFace (int iV0 = -1, int iV1 = -1, int iV2 = -1,
        int iNullIndex = -1, DelTetrahedron<Real>* pkTri = 0);

    static ETManifoldMesh::TPtr TCreator (int iV0, int iV1, int iV2);

    int NullIndex;
    DelTetrahedron<Real>* Tetra;
};

typedef DelPolyhedronFace<float> DelPolyhedronFacef;
typedef DelPolyhedronFace<double> DelPolyhedronFaced;

}

#endif
