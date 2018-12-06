// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Triangulation.h"

WM4_WINDOW_APPLICATION(Triangulation);

const int g_iSize = 256;

//----------------------------------------------------------------------------
Triangulation::Triangulation ()
    :
    WindowApplication2("Triangulation",0,0,g_iSize,g_iSize,
        ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
    m_akVertex = 0;
    m_aiIndex = 0;
}
//----------------------------------------------------------------------------
bool Triangulation::OnInitialize ()
{
    if (!WindowApplication2::OnInitialize())
    {
        return false;
    }

    // select a polygon
    m_iVQuantity = 10;
    m_akVertex = WM4_NEW Vector2f[m_iVQuantity];
    m_akVertex[0][0] =  29.0f;  m_akVertex[0][1] = 139.0f;
    m_akVertex[1][0] =  78.0f;  m_akVertex[1][1] =  99.0f;
    m_akVertex[2][0] = 125.0f;  m_akVertex[2][1] = 141.0f;
    m_akVertex[3][0] = 164.0f;  m_akVertex[3][1] = 116.0f;
    m_akVertex[4][0] = 201.0f;  m_akVertex[4][1] = 168.0f;
    m_akVertex[5][0] = 157.0f;  m_akVertex[5][1] = 163.0f;
    m_akVertex[6][0] = 137.0f;  m_akVertex[6][1] = 200.0f;
    m_akVertex[7][0] =  98.0f;  m_akVertex[7][1] = 134.0f;
    m_akVertex[8][0] =  52.0f;  m_akVertex[8][1] = 146.0f;
    m_akVertex[9][0] =  55.0f;  m_akVertex[9][1] = 191.0f;

    // construct the triangulation
    m_iTQuantity = m_iVQuantity-2;
    TriangulateEC<float>(m_iVQuantity,m_akVertex,Query::QT_FILTERED,
        0.001f,m_aiIndex);

    OnDisplay();
    return true;
}
//----------------------------------------------------------------------------
void Triangulation::OnTerminate ()
{
    WM4_DELETE[] m_akVertex;
    WM4_DELETE[] m_aiIndex;
    WindowApplication2::OnTerminate();
}
//----------------------------------------------------------------------------
void Triangulation::OnDisplay ()
{
    ClearScreen();

    Color kBlue(0,0,255), kBlack(0,0,0), kGray(128,128,128);
    int i, iX0, iY0, iX1, iY1;

    // draw the triangulation edges
    const int* piIndex = m_aiIndex;
    for (i = 0; i < m_iTQuantity; i++)
    {
        int iV0 = *piIndex++;
        int iV1 = *piIndex++;
        int iV2 = *piIndex++;

        iX0 = (int)m_akVertex[iV0][0];
        iY0 = (int)m_akVertex[iV0][1];
        iX1 = (int)m_akVertex[iV1][0];
        iY1 = (int)m_akVertex[iV1][1];
        DrawLine(iX0,iY0,iX1,iY1,kGray);

        iX0 = (int)m_akVertex[iV1][0];
        iY0 = (int)m_akVertex[iV1][1];
        iX1 = (int)m_akVertex[iV2][0];
        iY1 = (int)m_akVertex[iV2][1];
        DrawLine(iX0,iY0,iX1,iY1,kGray);

        iX0 = (int)m_akVertex[iV2][0];
        iY0 = (int)m_akVertex[iV2][1];
        iX1 = (int)m_akVertex[iV0][0];
        iY1 = (int)m_akVertex[iV0][1];
        DrawLine(iX0,iY0,iX1,iY1,kGray);
    }

    // draw the polygon edges
    for (int i0 = m_iVQuantity-1, i1 = 0; i1 < m_iVQuantity; i0 = i1++)
    {
        iX0 = (int)m_akVertex[i0][0];
        iY0 = (int)m_akVertex[i0][1];
        iX1 = (int)m_akVertex[i1][0];
        iY1 = (int)m_akVertex[i1][1];
        DrawLine(iX0,iY0,iX1,iY1,kBlue);
    }

    // draw the polygon vertices
    for (i = 0; i < m_iVQuantity; i++)
    {
        iX0 = (int)m_akVertex[i][0];
        iY0 = (int)m_akVertex[i][1];
        for (int iDY = -1; iDY <= 1; iDY++)
        {
            for (int iDX = -1; iDX <= 1; iDX++)
            {
                SetPixel(iX0+iDX,iY0+iDY,kBlack);
            }
        }
    }

    WindowApplication2::OnDisplay();
}
//----------------------------------------------------------------------------

