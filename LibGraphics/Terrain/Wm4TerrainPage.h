// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TERRAINPAGE_H
#define WM4TERRAINPAGE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM TerrainPage : public TriMesh
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // size = 2^p + 1, p <= 7 (size = 3, 5, 9, 17, 33, 65, 129)
    TerrainPage (const Attributes& rkAttr, int iSize,
        unsigned short* ausHeight, const Vector2f& rkOrigin,
        float fMinElevation, float fMaxElevation, float fSpacing,
        float fUVBias);

    virtual ~TerrainPage ();

    // height field access
    int GetSize () const;
    const unsigned short* GetHeights () const;
    const Vector2f& GetOrigin () const;
    float GetMinElevation () const;
    float GetMaxElevation () const;
    float GetSpacing () const;

    // Height field measurements.  If the location is not in the page, the
    // return value is INFINITY.
    float GetHeight (float fX, float fY) const;

    // Texture coordinates for the page may be obtained by querying VBuffer.
    // The bias is obtained by the following function.
    float& UVBias ();

protected:
    // streaming support
    TerrainPage ();
    void InitializeDerivedData ();

    // tessellation
    float GetX (int iX) const;
    float GetY (int iY) const;
    float GetHeight (int iIndex) const;
    float GetTextureCoordinate (int iIndex) const;

    // height field
    int m_iSize, m_iSizeM1;
    unsigned short* m_ausHeight;
    Vector2f m_kOrigin;
    float m_fMinElevation, m_fMaxElevation, m_fSpacing;
    float m_fInvSpacing, m_fTextureSpacing, m_fMultiplier;

    // bias for texture coordinates
    float m_fUVBias;
};

WM4_REGISTER_STREAM(TerrainPage);
typedef Pointer<TerrainPage> TerrainPagePtr;
#include "Wm4TerrainPage.inl"

}

#endif
