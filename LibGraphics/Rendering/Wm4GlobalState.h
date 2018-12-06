// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4GLOBALSTATE_H
#define WM4GLOBALSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM GlobalState : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // abstract base class
    virtual ~GlobalState ();

    // supported global states
    enum StateType
    {
        ALPHA,
        CULL,
        MATERIAL,
        POLYGONOFFSET,
        STENCIL,
        WIREFRAME,
        ZBUFFER,
        MAX_STATE_TYPE
    };

    virtual StateType GetStateType () const = 0;

    // default states
    static Pointer<GlobalState> Default[MAX_STATE_TYPE];

protected:
    GlobalState ();
};

WM4_REGISTER_STREAM(GlobalState);
typedef Pointer<GlobalState> GlobalStatePtr;

}

#endif
