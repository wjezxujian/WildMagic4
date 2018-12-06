// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4Main.h"
#include "Wm4Object.h"
#include "Wm4ImageCatalog.h"
#include "Wm4VertexProgramCatalog.h"
#include "Wm4PixelProgramCatalog.h"
using namespace Wm4;

Main::InitializerArray* Main::ms_pkInitializers = 0;
Main::TerminatorArray* Main::ms_pkTerminators = 0;
int Main::ms_iStartObjects = 0;
int Main::ms_iFinalObjects = 0;
ImageCatalog* Main::ms_pkImageCatalog = 0;
VertexProgramCatalog* Main::ms_pkVertexProgramCatalog = 0;
PixelProgramCatalog* Main::ms_pkPixelProgramCatalog = 0;

//----------------------------------------------------------------------------
void Main::AddInitializer (Initializer oInitialize)
{
    if (!ms_pkInitializers)
    {
        ms_pkInitializers = WM4_NEW InitializerArray;
    }

    ms_pkInitializers->push_back(oInitialize);
}
//----------------------------------------------------------------------------
void Main::Initialize ()
{
    bool bCountIsCorrect = true;

    // objects should not be created pre-main
    if (Object::InUse)
    {
        bCountIsCorrect = false;
        Object::PrintInUse("AppLog.txt",
            "Objects were created before pre-main initialization");
    }
    assert(bCountIsCorrect);

    ms_pkImageCatalog = WM4_NEW ImageCatalog("Main");
    ImageCatalog::SetActive(ms_pkImageCatalog);

    ms_pkVertexProgramCatalog = WM4_NEW VertexProgramCatalog("Main");
    VertexProgramCatalog::SetActive(ms_pkVertexProgramCatalog);

    ms_pkPixelProgramCatalog = WM4_NEW PixelProgramCatalog("Main");
    PixelProgramCatalog::SetActive(ms_pkPixelProgramCatalog);

    if (ms_pkInitializers)
    {
        for (int i = 0; i < (int)ms_pkInitializers->size(); i++)
        {
            (*ms_pkInitializers)[i]();
        }
    }

    WM4_DELETE ms_pkInitializers;
    ms_pkInitializers = 0;

    // number of objects created during initialization
    if (Object::InUse)
    {
        ms_iStartObjects = Object::InUse->GetQuantity();
    }
    else
    {
        ms_iStartObjects = 0;
    }
}
//----------------------------------------------------------------------------
void Main::AddTerminator (Terminator oTerminate)
{
    if (!ms_pkTerminators)
    {
        ms_pkTerminators = WM4_NEW TerminatorArray;
    }

    ms_pkTerminators->push_back(oTerminate);
}
//----------------------------------------------------------------------------
void Main::Terminate ()
{
    bool bCountIsCorrect = true;

    // all objects created during the application should be deleted by now
    if (Object::InUse)
    {
        ms_iFinalObjects = Object::InUse->GetQuantity();
    }
    else
    {
        ms_iFinalObjects = 0;
    }

    if (ms_iStartObjects != ms_iFinalObjects)
    {
        bCountIsCorrect = false;
        Object::PrintInUse("AppLog.txt",
            "Not all objects were deleted before post-main termination");
    }

    if (ms_pkTerminators)
    {
        for (int i = 0; i < (int)ms_pkTerminators->size(); i++)
        {
            (*ms_pkTerminators)[i]();
        }
    }

    WM4_DELETE ms_pkTerminators;
    ms_pkTerminators = 0;

    if (PixelProgramCatalog::GetActive() == ms_pkPixelProgramCatalog)
    {
        PixelProgramCatalog::SetActive(0);
    }
    WM4_DELETE ms_pkPixelProgramCatalog;

    if (VertexProgramCatalog::GetActive() == ms_pkVertexProgramCatalog)
    {
        VertexProgramCatalog::SetActive(0);
    }
    WM4_DELETE ms_pkVertexProgramCatalog;

    if (ImageCatalog::GetActive() == ms_pkImageCatalog)
    {
        ImageCatalog::SetActive(0);
    }
    WM4_DELETE ms_pkImageCatalog;

    if (bCountIsCorrect)
    {
        // objects should not be deleted post-main
        if (Object::InUse)
        {
            ms_iFinalObjects = Object::InUse->GetQuantity();
        }
        else
        {
            ms_iFinalObjects = 0;
        }

        if (ms_iFinalObjects != 0)
        {
            bCountIsCorrect = false;
            Object::PrintInUse("AppLog.txt",
                "Objects were deleted after post-main termination");
        }
    }

    assert(bCountIsCorrect);

    // Now that the object leak detection system has completed its tasks,
    // delete the hash table to free up memory so that the debug memory
    // system will not flag it as a leak.
    WM4_DELETE Object::InUse;
    Object::InUse = 0;
}
//----------------------------------------------------------------------------
