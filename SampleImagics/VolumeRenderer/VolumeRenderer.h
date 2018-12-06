// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef VOLUMERENDERER_H
#define VOLUMERENDERER_H

#include "Wm4WindowApplication2.h"
#include "RayTrace.h"
using namespace Wm4;

class VolumeRenderer : public WindowApplication2
{
    WM4_DECLARE_INITIALIZE;

public:
    VolumeRenderer ();

    virtual bool OnPrecreate ();
    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    int m_iBound;
    RayTrace* m_pkRT;
    float m_fX0, m_fY0, m_fX1, m_fY1, m_fHBound, m_fGamma;
    bool m_bButtonDown;
};

WM4_REGISTER_INITIALIZE(VolumeRenderer);

#endif

