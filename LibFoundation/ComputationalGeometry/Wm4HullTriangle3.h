// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4HULLTRIANGLE3_H
#define WM4HULLTRIANGLE3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query3.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM HullTriangle3
{
public:
    HullTriangle3 (int iV0, int iV1, int iV2);

    int GetSign (int i, const Query3<Real>* pkQuery);

    void AttachTo (HullTriangle3* pkAdj0, HullTriangle3* pkAdj1,
        HullTriangle3* pkAdj2);

    int DetachFrom (int iAdj, HullTriangle3* pkAdj);

    int V[3];
    HullTriangle3* A[3];
    int Sign;
    int Time;
    bool OnStack;
};

}

#endif
