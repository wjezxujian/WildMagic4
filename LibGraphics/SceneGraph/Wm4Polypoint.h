// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4POLYPOINT_H
#define WM4POLYPOINT_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Geometry.h"
#include "Wm4IntArray.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Polypoint : public Geometry
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // construction and destruction
    Polypoint (VertexBuffer* pkVBuffer);
    virtual ~Polypoint ();

    // member access
    void SetActiveQuantity (int iActiveQuantity);
    int GetActiveQuantity () const;

protected:
    Polypoint ();

    // Allow application to specify fewer than the maximum number of vertices
    // to draw.
    int m_iActiveQuantity;
};

WM4_REGISTER_STREAM(Polypoint);
typedef Pointer<Polypoint> PolypointPtr;
#include "Wm4Polypoint.inl"

}

#endif
