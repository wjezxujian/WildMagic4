// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4ZBUFFERSTATE_H
#define WM4ZBUFFERSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM ZBufferState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return ZBUFFER; }

    ZBufferState ();
    virtual ~ZBufferState ();

    enum CompareMode
    {
        CF_NEVER,
        CF_LESS,
        CF_EQUAL,
        CF_LEQUAL,
        CF_GREATER,
        CF_NOTEQUAL,
        CF_GEQUAL,
        CF_ALWAYS,
        CF_QUANTITY
    };

    bool Enabled;         // default: true
    bool Writable;        // default: true
    CompareMode Compare;  // default: CF_LEQUAL

private:
    static const char* ms_aacCompareMode[CF_QUANTITY];
};

WM4_REGISTER_STREAM(ZBufferState);
WM4_REGISTER_INITIALIZE(ZBufferState);
WM4_REGISTER_TERMINATE(ZBufferState);
typedef Pointer<ZBufferState> ZBufferStatePtr;

}

#endif
