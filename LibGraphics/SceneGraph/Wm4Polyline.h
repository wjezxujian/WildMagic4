// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4POLYLINE_H
#define WM4POLYLINE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Geometry.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Polyline : public Geometry
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // construction and destruction
    Polyline (VertexBuffer* pkVBuffer, bool bClosed, bool bContiguous);
    virtual ~Polyline ();

    // member access
    void SetActiveQuantity (int iActiveQuantity);
    int GetActiveQuantity () const;

    void SetClosed (bool bClosed);
    bool GetClosed () const;

    void SetContiguous (bool bContiguous);
    bool GetContiguous () const;

protected:
    Polyline ();
    void SetGeometryType ();

    // Allow application to specify fewer than the maximum number of vertices
    // to draw.
    int m_iActiveQuantity;

    // polyline is open or closed, contiguous or disjoint segments
    bool m_bClosed, m_bContiguous;
};

WM4_REGISTER_STREAM(Polyline);
typedef Pointer<Polyline> PolylinePtr;
#include "Wm4Polyline.inl"

}

#endif
