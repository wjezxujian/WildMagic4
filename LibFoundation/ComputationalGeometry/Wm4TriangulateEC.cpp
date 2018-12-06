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
#include "Wm4TriangulateEC.h"
#include "Wm4Query2Filtered.h"
#include "Wm4Query2Int64.h"
#include "Wm4Query2TInteger.h"
#include "Wm4Query2TRational.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
TriangulateEC<Real>::TriangulateEC (int iQuantity,
    const Vector2<Real>* akPosition, Query::Type eQueryType, Real fEpsilon,
    int*& raiIndex)
{
    assert(iQuantity >= 3 && akPosition);
    if (eQueryType == Query::QT_FILTERED)
    {
        assert((Real)0.0 <= fEpsilon && fEpsilon <= (Real)1.0);
    }

    Vector2<Real>* akSPosition = 0;
    Vector2<Real> kMin, kMax, kRange;
    Real fScale;
    int i;

    switch (eQueryType)
    {
    case Query::QT_INT64:
        // Transform the vertices to the square [0,2^{20}]^2.
        Vector2<Real>::ComputeExtremes(iQuantity,akPosition,kMin,kMax);
        kRange = kMax - kMin;
        fScale = (kRange[0] >= kRange[1] ? kRange[0] : kRange[1]);
        fScale *= (Real)(1 << 20);
        akSPosition = WM4_NEW Vector2<Real>[iQuantity];
        for (i = 0; i < iQuantity; i++)
        {
            akSPosition[i] = (akPosition[i] - kMin)*fScale;
        }
        m_pkQuery = WM4_NEW Query2Int64<Real>(iQuantity,akSPosition);
        break;
    case Query::QT_INTEGER:
        // Transform the vertices to the square [0,2^{24}]^2.
        Vector2<Real>::ComputeExtremes(iQuantity,akPosition,kMin,kMax);
        kRange = kMax - kMin;
        fScale = (kRange[0] >= kRange[1] ? kRange[0] : kRange[1]);
        fScale *= (Real)(1 << 24);
        akSPosition = WM4_NEW Vector2<Real>[iQuantity];
        for (i = 0; i < iQuantity; i++)
        {
            akSPosition[i] = (akPosition[i] - kMin)*fScale;
        }
        m_pkQuery = WM4_NEW Query2TInteger<Real>(iQuantity,akSPosition);
        break;
    case Query::QT_REAL:
        // Transform the vertices to the square [0,1]^2.
        Vector2<Real>::ComputeExtremes(iQuantity,akPosition,kMin,kMax);
        kRange = kMax - kMin;
        fScale = (kRange[0] >= kRange[1] ? kRange[0] : kRange[1]);
        akSPosition = WM4_NEW Vector2<Real>[iQuantity];
        for (i = 0; i < iQuantity; i++)
        {
            akSPosition[i] = (akPosition[i] - kMin)*fScale;
        }
        m_pkQuery = WM4_NEW Query2<Real>(iQuantity,akSPosition);
        break;
    case Query::QT_RATIONAL:
        // No transformation of the input data.
        m_pkQuery = WM4_NEW Query2TRational<Real>(iQuantity,akPosition);
        break;
    case Query::QT_FILTERED:
        // No transformation of the input data.
        m_pkQuery = WM4_NEW Query2Filtered<Real>(iQuantity,akPosition,
            fEpsilon);
        break;
    }

    int iQm1 = iQuantity - 1;
    raiIndex = WM4_NEW int[3*iQm1];
    int* piIndex = raiIndex;

    m_akVertex = WM4_NEW Vertex[iQuantity];
    m_iCFirst = -1;
    m_iCLast = -1;
    m_iRFirst = -1;
    m_iRLast = -1;
    m_iEFirst = -1;
    m_iELast = -1;

    // Create a circular list of the polygon vertices for dynamic removal of
    // vertices.  Keep track of two linear sublists, one for the convex
    // vertices and one for the reflex vertices.  This is an O(N) process
    // where N is the number of polygon vertices.
    for (i = 0; i <= iQm1; i++)
    {
        // link the vertices
        Vertex& rkV = V(i);
        rkV.VPrev = (i > 0 ? i-1 : iQm1);
        rkV.VNext = (i < iQm1 ? i+1 : 0);

        // link the convex/reflex vertices
        if (IsConvex(i))
        {
            InsertAfterC(i);
        }
        else
        {
            InsertAfterR(i);
        }
    }

    if (m_iRFirst == -1)
    {
        // polygon is convex, just triangle fan it
        for (i = 1; i < iQm1; i++)
        {
            *piIndex++ = 0;
            *piIndex++ = i;
            *piIndex++ = i+1;
        }
        return;
    }

    // Identify the ears and build a circular list of them.  Let V0, V1, and
    // V2 be consecutive vertices forming a triangle T.  The vertex V1 is an
    // ear if no other vertices of the polygon lie inside T.  Although it is
    // enough to show that V1 is not an ear by finding at least one other
    // vertex inside T, it is sufficient to search only the reflex vertices.
    // This is an O(C*R) process where C is the number of convex vertices and
    // R is the number of reflex vertices, N = C+R.  The order is O(N^2), for
    // example when C = R = N/2.
    for (i = m_iCFirst; i != -1; i = V(i).SNext)
    {
        if (IsEar(i))
        {
            InsertEndE(i);
        }
    }
    V(m_iEFirst).EPrev = m_iELast;
    V(m_iELast).ENext = m_iEFirst;

    // Remove the ears, one at a time.
    while (true)
    {
        // add triangle of ear to output
        int iVPrev = V(m_iEFirst).VPrev;
        int iVNext = V(m_iEFirst).VNext;
        *piIndex++ = iVPrev;
        *piIndex++ = m_iEFirst;
        *piIndex++ = iVNext;

        // remove the vertex corresponding to the ear
        RemoveV(m_iEFirst);
        if (--iQuantity == 3)
        {
            // Only one triangle remains, just remove the ear and copy it.
            RemoveE();
            iVPrev = V(m_iEFirst).VPrev;
            iVNext = V(m_iEFirst).VNext;
            *piIndex++ = iVPrev;
            *piIndex++ = m_iEFirst;
            *piIndex++ = iVNext;
            break;
        }

        // removal of the ear can cause an adjacent vertex to become an ear
        bool bWasReflex;

        Vertex& rkVPrev = V(iVPrev);
        if (!rkVPrev.IsEar)
        {
            bWasReflex = !rkVPrev.IsConvex;
            if (IsConvex(iVPrev))
            {
                if (bWasReflex)
                {
                    RemoveR(iVPrev);
                }

                if (IsEar(iVPrev))
                {
                    InsertBeforeE(iVPrev);
                }
            }
        }

        Vertex& rkVNext = V(iVNext);
        if (!rkVNext.IsEar)
        {
            bWasReflex = !rkVNext.IsConvex;
            if (IsConvex(iVNext))
            {
                if (bWasReflex)
                {
                    RemoveR(iVNext);
                }

                if (IsEar(iVNext))
                {
                    InsertAfterE(iVNext);
                }
            }
        }

        // remove the ear
        RemoveE();
    }

    WM4_DELETE[] akSPosition;
    WM4_DELETE m_pkQuery;
}
//----------------------------------------------------------------------------
template <class Real>
TriangulateEC<Real>::~TriangulateEC ()
{
}
//----------------------------------------------------------------------------
template <class Real>
bool TriangulateEC<Real>::IsConvex (int i)
{
    Vertex& rkV = V(i);
    rkV.IsConvex = (m_pkQuery->ToLine(i,rkV.VPrev,rkV.VNext) > 0);
    return rkV.IsConvex;
}
//----------------------------------------------------------------------------
template <class Real>
bool TriangulateEC<Real>::IsEar (int i)
{
    Vertex& rkV = V(i);

    if (m_iRFirst == -1)
    {
        // The remaining polygon is convex.
        rkV.IsEar = true;
        return true;
    }

    // Search the reflex vertices and test if any are in the triangle
    // <V[prev],V[i],V[next]>.
    rkV.IsEar = true;
    for (int j = m_iRFirst; j != -1; j = V(j).SNext)
    {
        if (m_pkQuery->ToTriangle(j,rkV.VPrev,i,rkV.VNext) < 0)
        {
            rkV.IsEar = false;
            break;
        }
    }

    return rkV.IsEar;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::InsertAfterC (int i)
{
    if (m_iCFirst == -1)
    {
        // add first convex vertex
        m_iCFirst = i;
    }
    else
    {
        V(m_iCLast).SNext = i;
        V(i).SPrev = m_iCLast;
    }
    m_iCLast = i;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::InsertAfterR (int i)
{
    if (m_iRFirst == -1)
    {
        // add first reflex vertex
        m_iRFirst = i;
    }
    else
    {
        V(m_iRLast).SNext = i;
        V(i).SPrev = m_iRLast;
    }
    m_iRLast = i;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::InsertEndE (int i)
{
    if (m_iEFirst == -1)
    {
        // add first ear
        m_iEFirst = i;
        m_iELast = i;
    }
    V(m_iELast).ENext = i;
    V(i).EPrev = m_iELast;
    m_iELast = i;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::InsertAfterE (int i)
{
    Vertex& rkVFirst = V(m_iEFirst);
    int iCurrENext = rkVFirst.ENext;
    Vertex& rkV = V(i);
    rkV.EPrev = m_iEFirst;
    rkV.ENext = iCurrENext;
    rkVFirst.ENext = i;
    V(iCurrENext).EPrev = i;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::InsertBeforeE (int i)
{
    Vertex& rkVFirst = V(m_iEFirst);
    int iCurrEPrev = rkVFirst.EPrev;
    Vertex& rkV = V(i);
    rkV.EPrev = iCurrEPrev;
    rkV.ENext = m_iEFirst;
    rkVFirst.EPrev = i;
    V(iCurrEPrev).ENext = i;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::RemoveV (int i)
{
    int iCurrVPrev = V(i).VPrev;
    int iCurrVNext = V(i).VNext;
    V(iCurrVPrev).VNext = iCurrVNext;
    V(iCurrVNext).VPrev = iCurrVPrev;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::RemoveE ()
{
    int iCurrEPrev = V(m_iEFirst).EPrev;
    int iCurrENext = V(m_iEFirst).ENext;
    V(iCurrEPrev).ENext = iCurrENext;
    V(iCurrENext).EPrev = iCurrEPrev;
    m_iEFirst = iCurrENext;
}
//----------------------------------------------------------------------------
template <class Real>
void TriangulateEC<Real>::RemoveR (int i)
{
    assert(m_iRFirst != -1 && m_iRLast != -1);

    if (i == m_iRFirst)
    {
        m_iRFirst = V(i).SNext;
        if (m_iRFirst != -1)
        {
            V(m_iRFirst).SPrev = -1;
        }
        V(i).SNext = -1;
    }
    else if (i == m_iRLast)
    {
        m_iRLast = V(i).SPrev;
        if (m_iRLast != -1)
        {
            V(m_iRLast).SNext = -1;
        }
        V(i).SPrev = -1;
    }
    else
    {
        int iCurrSPrev = V(i).SPrev;
        int iCurrSNext = V(i).SNext;
        V(iCurrSPrev).SNext = iCurrSNext;
        V(iCurrSNext).SPrev = iCurrSPrev;
        V(i).SNext = -1;
        V(i).SPrev = -1;
    }
}
//----------------------------------------------------------------------------
template <class Real>
typename TriangulateEC<Real>::Vertex& TriangulateEC<Real>::V (int i)
{
    return m_akVertex[i];
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class TriangulateEC<float>;

template WM4_FOUNDATION_ITEM
class TriangulateEC<double>;
//----------------------------------------------------------------------------
}
