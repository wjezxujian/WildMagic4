// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef DRAWIMPLICITSURFACE_H
#define DRAWIMPLICITSURFACE_H

#include "Wm4WindowApplication2.h"
#include "RayTracer.h"
using namespace Wm4;

class DrawImplicitSurface : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    DrawImplicitSurface ();

    virtual bool OnInitialize ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnSpecialKeyDown (int iKey, int iX, int iY);

protected:
    RayTracer m_kRT;
    int m_iMaxSample;
    bool m_bBlur;
};

WM4_REGISTER_INITIALIZE(DrawImplicitSurface);

#endif

