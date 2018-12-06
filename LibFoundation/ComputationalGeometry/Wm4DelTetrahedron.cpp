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
#include "Wm4DelTetrahedron.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
DelTetrahedron<Real>::DelTetrahedron (int iV0, int iV1, int iV2, int iV3)
{
    V[0] = iV0;
    V[1] = iV1;
    V[2] = iV2;
    V[3] = iV3;
    A[0] = 0;
    A[1] = 0;
    A[2] = 0;
    A[3] = 0;
    Time = -1;
    IsComponent = false;
    OnStack = false;
}
//----------------------------------------------------------------------------
template <class Real>
bool DelTetrahedron<Real>::IsInsertionComponent (int i, DelTetrahedron* pkAdj,
    const Query3<Real>* pkQuery, const int* aiSupervertex)
{
    // Indexing for the vertices of the triangle opposite a vertex.  The
    // triangle opposite vertex j is
    //   <aaiIndex[j][0], aaiIndex[j][1], aaiIndex[j][2]>
    // and is listed in counterclockwise order when viewed from outside the
    // tetrahedron.
    const int aaiIndex[4][3] = { {1,2,3}, {0,3,2}, {0,1,3}, {0,2,1} };

    if (i != Time)
    {
        Time = i;

        // Determine if the circumsphere of the tetrahedron contains the
        // input point.
        int iRelation = pkQuery->ToCircumsphere(i,V[0],V[1],V[2],V[3]);
        IsComponent = (iRelation <= 0 ? true : false);
        if (IsComponent)
        {
            return true;
        }

        // It is possible that a tetrahedron that shares a supervertex does
        // not have the circumsphere-containing property, but all faces of
        // it (other than the shared one with the calling tetrahedron) are
        // visible.  These are also included in the insertion polyhedron.
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (V[j] == aiSupervertex[k])
                {
                    // Tetrahedron shares a supervertex.  It is safe to reuse
                    // k as a loop index because we are returning from the
                    // function.
                    int iNumInvisible = 0;
                    for (k = 0; k < 4; k++)
                    {
                        if (A[k] != pkAdj)
                        {
                            int iV0 = V[aaiIndex[k][0]];
                            int iV1 = V[aaiIndex[k][1]];
                            int iV2 = V[aaiIndex[k][2]];
                            iRelation = pkQuery->ToPlane(i,iV0,iV1,iV2);
                            if (iRelation > 0)
                            {
                                iNumInvisible++;
                            }
                        }
                    }
                    IsComponent = (iNumInvisible == 0 ? true : false);
                    return IsComponent;
                }
            }
        }
    }

    return IsComponent;
}
//----------------------------------------------------------------------------
template <class Real>
int DelTetrahedron<Real>::DetachFrom (int iAdj, DelTetrahedron* pkAdj)
{
    assert(0 <= iAdj && iAdj < 4 && A[iAdj] == pkAdj);
    A[iAdj] = 0;
    for (int i = 0; i < 4; i++)
    {
        if (pkAdj->A[i] == this)
        {
            pkAdj->A[i] = 0;
            return i;
        }
    }
    return -1;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class DelTetrahedron<float>;

template WM4_FOUNDATION_ITEM
class DelTetrahedron<double>;
//----------------------------------------------------------------------------
}
