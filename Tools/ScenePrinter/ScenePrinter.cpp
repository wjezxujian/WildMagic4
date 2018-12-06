// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ScenePrinter.h"

WM4_CONSOLE_APPLICATION(ScenePrinter);

//----------------------------------------------------------------------------
void ScenePrinter::Usage ()
{
    std::cout << std::endl;
    std::cout << "To print a scene graph in ASCII format, use" << std::endl;
    std::cout << "    ScenePrinter myfile.wmof myfile.txt" << std::endl;
}
//----------------------------------------------------------------------------
int ScenePrinter::Main (int iQuantity, char** aacArgument)
{
    if (iQuantity != 3)
    {
        Usage();
        return -1;
    }

    // get files
    const char* acInFile = aacArgument[1];
    const char* acOutFile = aacArgument[2];

    Stream* pkStream = new Stream;
    bool bLoaded = pkStream->Load(acInFile);
    if (!bLoaded)
    {
       return -2;
    }

    for (int i = 0; i < pkStream->GetObjectCount(); i++)
    {
        Spatial* pkSpatial = DynamicCast<Spatial>(pkStream->GetObjectAt(i));
        if (pkSpatial)
        {
            pkSpatial->UpdateGS();
            pkSpatial->UpdateRS();
        }
    }

    bool bSaved = pkStream->SaveText(acOutFile);
    if (!bSaved)
    {
        delete pkStream;
        return -3;
    }

    delete pkStream;
    return 0;
}
//----------------------------------------------------------------------------

