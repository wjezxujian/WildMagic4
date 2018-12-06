// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4DELTRIANGLE_H
#define WM4DELTRIANGLE_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM DelTriangle
{
public:
    DelTriangle (int iV0, int iV1, int iV2);

    bool IsInsertionComponent (int i, DelTriangle* pkAdj,
        const Query2<Real>* pkQuery, const int* aiSupervertex);
    int DetachFrom (int iAdj, DelTriangle* pkAdj);

    int V[3];
    DelTriangle* A[3];
    int Time;
    bool IsComponent;
    bool OnStack;
};

typedef DelTriangle<float> DelTrianglef;
typedef DelTriangle<double> DelTriangled;

}

#endif
