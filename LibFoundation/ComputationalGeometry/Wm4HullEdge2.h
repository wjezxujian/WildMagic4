// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4HULLEDGE2_H
#define WM4HULLEDGE2_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM HullEdge2
{
public:
    HullEdge2 (int iV0, int iV1);

    int GetSign (int i, const Query2<Real>* pkQuery);

    void Insert (HullEdge2* pkAdj0, HullEdge2* pkAdj1);
    void DeleteSelf ();
    void DeleteAll ();

    void GetIndices (int& riHQuantity, int*& raiHIndex);

    int V[2];
    HullEdge2* A[2];
    int Sign;
    int Time;
};

}

#endif
