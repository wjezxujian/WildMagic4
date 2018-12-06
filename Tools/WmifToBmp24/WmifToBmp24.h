// Geometric Tools
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM4) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic4License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WMIFTOBMP24_H
#define WMIFTOBMP24_H

#include "Wm4ConsoleApplication.h"
using namespace Wm4;

class WmifToBmp24 : public ConsoleApplication
{
    WM4_DECLARE_INITIALIZE;

public:
    virtual int Main (int iQuantity, char** apcArgument);

protected:
    void Usage ();
    void SaveRGBImage (std::ofstream& rkRGBStr, const Image* pkImage);
    void SaveRGBAImage (std::ofstream& rkRGBStr, std::ofstream& rkAStr,
        const Image* pkImage);
};

WM4_REGISTER_INITIALIZE(WmifToBmp24);

#endif
