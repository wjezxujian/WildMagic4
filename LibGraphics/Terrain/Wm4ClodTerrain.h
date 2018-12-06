// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CLODTERRAIN_H
#define WM4CLODTERRAIN_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Node.h"
#include "Wm4ClodTerrainPage.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ClodTerrain : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    ClodTerrain (const char* acHeightName, const char* acImageName,
        const Attributes& rkAttr, Renderer* pkRenderer, float fUVBias,
        ColorRGBA* pkBorderColor);

    virtual ~ClodTerrain ();

    // member access
    int GetRowQuantity () const;
    int GetColQuantity () const;
    int GetSize () const;
    float GetMinElevation () const;
    float GetMaxElevation () const;
    float GetSpacing () const;
    void SetPixelTolerance (float fTolerance);
    float GetPixelTolerance () const;
    void SetRenderer (Renderer* pkRenderer);
    bool& CloseAssumption ();
    float& UVBias ();
    ColorRGBA& BorderColor ();

    // page management
    ClodTerrainPage* GetPage (int iRow, int iCol);
    ClodTerrainPage* GetCurrentPage (float fX, float fY) const;
    float GetHeight (float fX, float fY) const;

    // Allow a page to be replaced.  The code unstitches the old page, loads
    // the new page and stitches it, then returns the old page in case the
    // application wants to cache it for quick reuse.
    ClodTerrainPagePtr ReplacePage (int iRow, int iCol,
        const char* acHeightName, const char* acHeightSuffix,
        const char* acImageName, const char* acImageSuffix);

    ClodTerrainPagePtr ReplacePage (int iRow, int iCol,
        ClodTerrainPage* pkNewPage);

    void Simplify ();

protected:
    ClodTerrain ();

    void LoadHeader (const char* acHeightPrefix);
    void LoadPage (int iRow, int iCol, const char* acHeightName,
        const char* acHeightSuffix, const char* acImageName,
        const char* acImageSuffix);
    void StitchAll ();

    // Attributes for the vertex buffers of the pages.
    Attributes m_kAttr;

    // page information
    int m_iRows, m_iCols;
    int m_iSize;
    float m_fMinElevation, m_fMaxElevation, m_fSpacing;
    ClodTerrainPagePtr** m_aaspkPage;

    // simplification
    float m_fPixelTolerance;
    Renderer* m_pkRenderer;
    bool m_bCloseAssumption;

    // current page containing the camera
    int m_iCameraRow, m_iCameraCol;

    // texture parameters
    float m_fUVBias;
    ColorRGBA m_kBorderColor;
};

WM4_REGISTER_STREAM(ClodTerrain);
typedef Pointer<ClodTerrain> ClodTerrainPtr;
#include "Wm4ClodTerrain.inl"

}

#endif
