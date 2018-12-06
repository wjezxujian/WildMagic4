// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4STENCILSTATE_H
#define WM4STENCILSTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM StencilState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return STENCIL; }

    StencilState ();
    virtual ~StencilState ();

    enum CompareFunction
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

    enum OperationType
    {
        OT_KEEP,
        OT_ZERO,
        OT_REPLACE,
        OT_INCREMENT,
        OT_DECREMENT,
        OT_INVERT,
        OT_QUANTITY
    };

    bool Enabled;             // default: false
    CompareFunction Compare;  // default: CF_NEVER
    unsigned int Reference;   // default: 0
    unsigned int Mask;        // default: ~0
    unsigned int WriteMask;   // default: ~0
    OperationType OnFail;     // default: OT_KEEP
    OperationType OnZFail;    // default: OT_KEEP
    OperationType OnZPass;    // default: OT_KEEP

private:
    static const char* ms_aacCompare[CF_QUANTITY];
    static const char* ms_aacOperation[OT_QUANTITY];
};

WM4_REGISTER_STREAM(StencilState);
WM4_REGISTER_INITIALIZE(StencilState);
WM4_REGISTER_TERMINATE(StencilState);
typedef Pointer<StencilState> StencilStatePtr;

}

#endif
