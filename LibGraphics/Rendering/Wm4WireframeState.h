// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4WIREFRAMESTATE_H
#define WM4WIREFRAMESTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM WireframeState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return WIREFRAME; }

    WireframeState ();
    virtual ~WireframeState ();

    bool Enabled;  // default: false
};

WM4_REGISTER_STREAM(WireframeState);
WM4_REGISTER_INITIALIZE(WireframeState);
WM4_REGISTER_TERMINATE(WireframeState);
typedef Pointer<WireframeState> WireframeStatePtr;

}

#endif
