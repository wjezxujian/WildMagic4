// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TERRAIN_H
#define WM4TERRAIN_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Node.h"
#include "Wm4TerrainPage.h"

namespace Wm4
{

class Camera;

class WM4_GRAPHICS_ITEM Terrain : public Node
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    Terrain (const char* acHeightName, const char* acImageName,
        const Attributes& rkAttr, Camera* pkCamera, float fUVBias,
        ColorRGBA* pkBorderColor);

    virtual ~Terrain ();

    // member access
    int GetRowQuantity () const;
    int GetColQuantity () const;
    int GetSize () const;
    float GetMinElevation () const;
    float GetMaxElevation () const;
    float GetSpacing () const;
    float& UVBias ();
    ColorRGBA& BorderColor ();
    void SetCamera (Camera* pkCamera);

    // page management
    TerrainPage* GetPage (int iRow, int iCol);
    TerrainPage* GetCurrentPage (float fX, float fY) const;
    float GetHeight (float fX, float fY) const;

    // Allow a page to be replaced.  The code unstitches the old page, loads
    // the new page and stitches it, then returns the old page in case the
    // application wants to cache it for quick reuse.
    TerrainPagePtr ReplacePage (int iRow, int iCol, const char* acHeightName,
        const char* acHeightSuffix, const char* acImageName,
        const char* acImageSuffix);

    TerrainPagePtr ReplacePage (int iRow, int iCol, TerrainPage* pkNewPage);

    // update of active set of terrain pages
    void OnCameraMotion ();

protected:
    // streaming support
    Terrain ();

    void LoadHeader (const char* acHeightName);
    void LoadPage (int iRow, int iCol, const char* acHeightName,
        const char* acHeightSuffix, const char* acImageName,
        const char* acImageSuffix);

    // Attributes for the vertex buffers of the pages.
    Attributes m_kAttr;

    // page information
    int m_iRows, m_iCols;
    int m_iSize;
    float m_fMinElevation, m_fMaxElevation, m_fSpacing;
    TerrainPagePtr** m_aaspkPage;

    // current page containing the camera
    int m_iCameraRow, m_iCameraCol;
    Pointer<Camera> m_spkCamera;

    // texture parameters
    float m_fUVBias;
    ColorRGBA m_kBorderColor;
};

WM4_REGISTER_STREAM(Terrain);
typedef Pointer<Terrain> TerrainPtr;
#include "Wm4Terrain.inl"

}

#endif
