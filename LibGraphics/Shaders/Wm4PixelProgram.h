// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4PIXELPROGRAM_H
#define WM4PIXELPROGRAM_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Program.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PixelProgram : public Program
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    static PixelProgram* Load (const std::string& rkProgramName,
        const std::string& rkRendererType, char cCommentPrefix);
    virtual ~PixelProgram ();

protected:
    PixelProgram ();
};

WM4_REGISTER_STREAM(PixelProgram);
typedef Pointer<PixelProgram> PixelProgramPtr;

}

#endif
