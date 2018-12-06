// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DELTETRAHEDRON_H
#define WM4DELTETRAHEDRON_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DelTetrahedron
{
public:
    DelTetrahedron (int iV0, int iV1, int iV2, int iV3);

    bool IsInsertionComponent (int i, DelTetrahedron* pkAdj,
        const Query3<Real>* pkQuery, const int* aiSupervertex);
    int DetachFrom (int iAdj, DelTetrahedron* pkAdj);

    int V[4];
    DelTetrahedron* A[4];
    int Time;
    bool IsComponent;
    bool OnStack;
};

typedef DelTetrahedron<float> DelTetrahedronf;
typedef DelTetrahedron<double> DelTetrahedrond;

}

#endif
