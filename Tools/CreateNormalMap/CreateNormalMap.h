// Geometric Tools
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM4) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic4License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CREATENORMALMAP_H
#define CREATENORMALMAP_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class CreateNormalMap : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void Usage ();

    int GetImage (const char* acBMPName, int& riWidth, int& riHeight,
        unsigned char*& raucData);

    void SaveImage (const char* acBMPName, int iWidth, int iHeight,
        unsigned char* aucData);

    unsigned char* GenerateNormals (int iXMax, int iYMax,
        float* afHeight, float fXScale, float fYScale);
};

WM4_REGISTER_INITIALIZE(CreateNormalMap);

#endif
