// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RECTANGLESURFACE_H
#define WM4RECTANGLESURFACE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4ParametricSurface.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM RectangleSurface : public TriMesh
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.  The input surface must be rectangular,
    // not triangular.  RectangleSurface accepts responsibility for deleting
    // the input surface.  If bWantColors is 'true', the vertex colors are
    // allocated and set to black.  The application needs to assign colors as
    // needed.  If either of pkUVMin or pkUVMax is not null, both must be not
    // null.  In this case, texture coordinates are generated for the
    // surface.
    RectangleSurface (ParametricSurfacef* pkSurface, int iUSamples,
        int iVSamples, const Attributes& rkAttr, bool bDoubleSided,
        const Vector2f* pkTCoordMin, const Vector2f* pkTCoordMax);

    virtual ~RectangleSurface ();

    // member access
    ParametricSurfacef*& Surface ();
    const ParametricSurfacef* GetSurface () const;
    int GetUSamples () const;
    int GetVSamples () const;

    // If the surface is modified, for example if it is control point
    // based and the control points are modified, then you should call this
    // update function to recompute the rectangle surface geometry.
    void UpdateSurface ();

protected:
    RectangleSurface ();

    ParametricSurfacef* m_pkSurface;
    int m_iUSamples, m_iVSamples;
};

WM4_REGISTER_STREAM(RectangleSurface);
typedef Pointer<RectangleSurface> RectangleSurfacePtr;
#include "Wm4RectangleSurface.inl"

}

#endif
