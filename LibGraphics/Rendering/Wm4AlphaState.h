// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4ALPHASTATE_H
#define WM4ALPHASTATE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4GlobalState.h"
#include "Wm4ColorRGBA.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM AlphaState : public GlobalState
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;
    WM4_DECLARE_INITIALIZE;
    WM4_DECLARE_TERMINATE;

public:
    virtual StateType GetStateType () const { return ALPHA; }

    AlphaState ();
    virtual ~AlphaState ();

    enum SrcBlendMode
    {
        SBF_ZERO,
        SBF_ONE,
        SBF_DST_COLOR,
        SBF_ONE_MINUS_DST_COLOR,
        SBF_SRC_ALPHA,
        SBF_ONE_MINUS_SRC_ALPHA,
        SBF_DST_ALPHA,
        SBF_ONE_MINUS_DST_ALPHA,
        SBF_SRC_ALPHA_SATURATE,
        SBF_CONSTANT_COLOR,
        SBF_ONE_MINUS_CONSTANT_COLOR,
        SBF_CONSTANT_ALPHA,
        SBF_ONE_MINUS_CONSTANT_ALPHA,
        SBF_QUANTITY
    };

    enum DstBlendMode
    {
        DBF_ZERO,
        DBF_ONE,
        DBF_SRC_COLOR,
        DBF_ONE_MINUS_SRC_COLOR,
        DBF_SRC_ALPHA,
        DBF_ONE_MINUS_SRC_ALPHA,
        DBF_DST_ALPHA,
        DBF_ONE_MINUS_DST_ALPHA,
        DBF_CONSTANT_COLOR,
        DBF_ONE_MINUS_CONSTANT_COLOR,
        DBF_CONSTANT_ALPHA,
        DBF_ONE_MINUS_CONSTANT_ALPHA,
        DBF_QUANTITY
    };

    enum TestMode
    {
        TF_NEVER,
        TF_LESS,
        TF_EQUAL,
        TF_LEQUAL,
        TF_GREATER,
        TF_NOTEQUAL,
        TF_GEQUAL,
        TF_ALWAYS,
        TF_QUANTITY
    };

    bool BlendEnabled;      // default: false
    SrcBlendMode SrcBlend;  // default: SBF_SRC_ALPHA
    DstBlendMode DstBlend;  // default: DBF_ONE_MINUS_SRC_ALPHA
    bool TestEnabled;       // default: false;
    TestMode Test;          // default: TF_ALWAYS
    float Reference;        // default: 0, always in [0,1]

    // TO DO.  New member, needs to be streamed.
    ColorRGBA ConstantColor;   // default: (0,0,0,0)

private:
    static const char* ms_aacSrcBlend[SBF_QUANTITY];
    static const char* ms_aacDstBlend[DBF_QUANTITY];
    static const char* ms_aacTestMode[TF_QUANTITY];
};

WM4_REGISTER_STREAM(AlphaState);
WM4_REGISTER_INITIALIZE(AlphaState);
WM4_REGISTER_TERMINATE(AlphaState);
typedef Pointer<AlphaState> AlphaStatePtr;

}

#endif
