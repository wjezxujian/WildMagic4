// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ExtractLevelCurves.h"
#include "ImageInterp2D.h"

WM4_CONSOLE_APPLICATION(ExtractLevelCurves);

// comment this out for LINEAR
#define USE_BILINEAR

ImageRGB82D* ExtractLevelCurves::ms_pkColor = 0;
unsigned int ExtractLevelCurves::ms_uiColor = 0;
float ExtractLevelCurves::ms_fMultiply = 1.0f/(float)MAGNIFY;

//----------------------------------------------------------------------------
void ExtractLevelCurves::DrawPixel (int iX, int iY)
{
    if (0 <= iX && iX < ms_pkColor->GetBound(0)
    &&  0 <= iY && iY < ms_pkColor->GetBound(1))
    {
        (*ms_pkColor)(iX,iY) = ms_uiColor;
    }
}
//----------------------------------------------------------------------------
bool ExtractLevelCurves::Extract ()
{
    ms_pkColor = WM4_NEW ImageRGB82D(MAGNIFY*SIZE,MAGNIFY*SIZE);

    // load image for level set extraction
    ImageInterp2D kImage(System::GetPath("../../Data/Im/","Head.im"));
    if (kImage.GetDimensions() == 0)
    {
        // cannot load the image
        return false;
    }

    // get the extremes
    int iMin = kImage[0], iMax = iMin;
    for (int i = 1; i < kImage.GetQuantity(); i++)
    {
        int iValue = kImage[i];
        if (iValue < iMin)
        {
            iMin = iValue;
        }
        else if (iValue > iMax)
        {
            iMax = iValue;
        }
    }
    int iRange = iMax - iMin;

    // Generate a color subimage to superimpose level sets.  Process the
    // subimage with upper left corner (100,100) and of size 32x32.
    for (int iY = 0; iY < SIZE; iY++)
    {
        for (int iX = 0; iX < SIZE; iX++)
        {
            for (int iDY = 0; iDY < MAGNIFY; iDY++)
            {
                float fY = YPOS + iY + ms_fMultiply*iDY;
                for (int iDX = 0; iDX < MAGNIFY; iDX++)
                {
                    float fX = XPOS + iX + ms_fMultiply*iDX;
#ifdef USE_BILINEAR
                    float fInterp = kImage.BilinearInterpolate(fX,fY);
#else
                    float fInterp = kImage.LinearInterpolate(fX,fY);
#endif
                    fInterp = (fInterp - iMin)/(float)iRange;
                    unsigned char ucGrey = (unsigned char)(255.0f*fInterp);
                    (*ms_pkColor)(MAGNIFY*iX+iDX,MAGNIFY*iY+iDY) =
                        GetColor24(ucGrey,ucGrey,ucGrey);
                }
            }
        }
    }

    // extract the level set
    int iVertexQuantity = 0;
    ImageInterp2D::Vertex* akVertex = 0;
    int iEdgeQuantity = 0;
    EdgeKey* akEdge = 0;
#ifdef USE_BILINEAR
    kImage.ExtractLevelSetBilinear(512,iVertexQuantity,akVertex,
        iEdgeQuantity,akEdge);
#else
    kImage.ExtractLevelSetLinear(512,iVertexQuantity,akVertex,
        iEdgeQuantity,akEdge);
#endif

    kImage.MakeUnique(iVertexQuantity,akVertex,iEdgeQuantity,akEdge);

    // draw the edges in the subimage
    ms_uiColor = GetColor24(0,255,0);
    float fX, fY;
    for (int iE = 0; iE < iEdgeQuantity; iE++)
    {
        const EdgeKey& rkEdge = akEdge[iE];

        const ImageInterp2D::Vertex& rkV0 = akVertex[rkEdge.V[0]];
        rkV0.GetPair(fX,fY);
        int iX0 = (int)((fX - XPOS)*MAGNIFY);
        int iY0 = (int)((fY - YPOS)*MAGNIFY);

        const ImageInterp2D::Vertex& rkV1 = akVertex[rkEdge.V[1]];
        rkV1.GetPair(fX,fY);
        int iX1 = (int)((fX - XPOS)*MAGNIFY);
        int iY1 = (int)((fY - YPOS)*MAGNIFY);

        Line2D(iX0,iY0,iX1,iY1,DrawPixel);
    }

    // draw the vertices in the subimage
    ms_uiColor = GetColor24(255,0,0);
    for (int iV = 0; iV < iVertexQuantity; iV++)
    {
        akVertex[iV].GetPair(fX,fY);
        int iX = (int)((fX - XPOS)*MAGNIFY);
        int iY = (int)((fY - YPOS)*MAGNIFY);
        DrawPixel(iX,iY);
    }

#ifdef USE_BILINEAR
    ms_pkColor->Save("BilinearZoom.im");
#else
    ms_pkColor->Save("LinearZoom.im");
#endif

    WM4_DELETE[] akVertex;
    WM4_DELETE[] akEdge;
    WM4_DELETE ms_pkColor;

    return true;
}
//----------------------------------------------------------------------------
int ExtractLevelCurves::Main (int, char**)
{
    return (Extract() ? 0 : -1);
}
//----------------------------------------------------------------------------

