// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MAIN_H
#define WM4MAIN_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"
#include "Wm4MainMCR.h"

namespace Wm4
{

class ImageCatalog;
class VertexProgramCatalog;
class PixelProgramCatalog;

class WM4_GRAPHICS_ITEM Main
{
public:
    typedef void (*Initializer)(void);
    typedef std::vector<Initializer> InitializerArray;
    static void AddInitializer (Initializer oInitialize);
    static void Initialize ();

    typedef void (*Terminator)(void);
    typedef std::vector<Terminator> TerminatorArray;
    static void AddTerminator (Terminator oTerminate);
    static void Terminate ();

private:
    static InitializerArray* ms_pkInitializers;
    static TerminatorArray* ms_pkTerminators;
    static int ms_iStartObjects;
    static int ms_iFinalObjects;

    static ImageCatalog* ms_pkImageCatalog;
    static VertexProgramCatalog* ms_pkVertexProgramCatalog;
    static PixelProgramCatalog* ms_pkPixelProgramCatalog;
};

}

#endif
