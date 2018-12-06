// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "MinimalCycleBasis.h"

WM4_WINDOW_APPLICATION(MinimalCycleBasis);

#define EXTRACT_PRIMITIVES

//----------------------------------------------------------------------------
MinimalCycleBasis::MinimalCycleBasis ()
    :
    WindowApplication2("MinimalCycleBasis",0,0,400,152,
        ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
    m_akColor = 0;
}
//----------------------------------------------------------------------------
bool MinimalCycleBasis::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    // Load the vertices and edges.  These are from the image PlanarGraph.wmif
    // which is an example in the MinimalCycleBasis.pdf document.  The image
    // is 400-by-152, which is why the application window size was chosen as
    // it is.
    std::ifstream kIStr("PlanarGraph.txt");
    assert(kIStr);

    int iVQuantity;
    kIStr >> iVQuantity;
    int i;
    for (i = 0; i < iVQuantity; i++)
    {
        int iX, iY;
        kIStr >> iX;
        kIStr >> iY;
        iY = GetHeight() - 1 - iY;
        m_kGraph.InsertVertex(IVector2(iX,iY),i);
    }

    int iEQuantity;
    kIStr >> iEQuantity;
    for (i = 0; i < iEQuantity; i++)
    {
        int iV0, iV1;
        kIStr >> iV0;
        kIStr >> iV1;
        m_kGraph.InsertEdge(iV0,iV1);
    }

#ifdef EXTRACT_PRIMITIVES
    m_kGraph.ExtractPrimitives(m_kPrimitives);
    m_akColor = WM4_NEW Color[m_kPrimitives.size()];
    for (i = 0; i < (int)m_kPrimitives.size(); i++)
    {
        m_akColor[i].r = rand() % 256;
        m_akColor[i].g = rand() % 256;
        m_akColor[i].b = rand() % 256;
    }
#endif

    DoFlip(true);
    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void MinimalCycleBasis::OnTerminate ()
{
    for (int i = 0; i < (int)m_kPrimitives.size(); i++)
    {
        WM4_DELETE m_kPrimitives[i];
    }
    WM4_DELETE[] m_akColor;

    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
void MinimalCycleBasis::OnDisplay ()
{
    ClearScreen();

#ifdef EXTRACT_PRIMITIVES
    IVector2 kV0, kV1;
    int iX0, iY0, iX1, iY1, j0, j1;

    int i, iPQuantity = (int)m_kPrimitives.size();
    for (i = 0; i < iPQuantity; i++)
    {
        Graph::Primitive* pkPrimitive = m_kPrimitives[i];
        int iSQuantity = (int)pkPrimitive->Sequence.size();
        switch (pkPrimitive->Type)
        {
        case Graph::PT_ISOLATED_VERTEX:
            kV0 = pkPrimitive->Sequence[0].first;
            iX0 = (int)kV0.X();
            iY0 = (int)kV0.Y();
            SetThickPixel(iX0,iY0,1,m_akColor[i]);
            break;
        case Graph::PT_FILAMENT:
            for (j0 = 0, j1 = 1; j1 < iSQuantity; j0++, j1++)
            {
                kV0 = pkPrimitive->Sequence[j0].first;
                iX0 = (int)kV0.X();
                iY0 = (int)kV0.Y();
                kV1 = pkPrimitive->Sequence[j1].first;
                iX1 = (int)kV1.X();
                iY1 = (int)kV1.Y();
                DrawLine(iX0,iY0,iX1,iY1,m_akColor[i]);
            }
            break;
        case Graph::PT_MINIMAL_CYCLE:
            for (j0 = iSQuantity-1, j1 = 0; j1 < iSQuantity; j0 = j1++)
            {
                kV0 = pkPrimitive->Sequence[j0].first;
                iX0 = (int)kV0.X();
                iY0 = (int)kV0.Y();
                kV1 = pkPrimitive->Sequence[j1].first;
                iX1 = (int)kV1.X();
                iY1 = (int)kV1.Y();
                DrawLine(iX0,iY0,iX1,iY1,m_akColor[i]);
            }
            break;
        default:
            assert(false);
        }
    }
#else
    // Draw the edges.
    const Graph::Edges& rkEdges = m_kGraph.GetEdges();
    Graph::Edges::const_iterator pkEIter;
    for (pkEIter = rkEdges.begin(); pkEIter != rkEdges.end(); pkEIter++)
    {
        EdgeKey kEdge = pkEIter->first;
        IVector2 kV0 = m_kGraph.GetVertex(kEdge.V[0])->Position;
        IVector2 kV1 = m_kGraph.GetVertex(kEdge.V[1])->Position;
        int iX0 = (int)kV0.X();
        int iY0 = (int)kV0.Y();
        int iX1 = (int)kV1.X();
        int iY1 = (int)kV1.Y();
        DrawLine(iX0,iY0,iX1,iY1,Color(192,192,192));
    }

    // Draw the vertices.
    const Graph::Vertices& rkVertices = m_kGraph.GetVertices();
    Graph::Vertices::const_iterator pkVIter;
    for (pkVIter = rkVertices.begin(); pkVIter != rkVertices.end(); pkVIter++)
    {
        Graph::Vertex* pkVertex = pkVIter->second;
        int iX = (int)pkVertex->Position.X();
        int iY = (int)pkVertex->Position.Y();
        SetThickPixel(iX,iY,1,Color(0,0,255));
    }
#endif

    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------

