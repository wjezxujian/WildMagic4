// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef EXTRACTLEVELCUBES_H
#define EXTRACTLEVELCUBES_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ExtractLevelCubes : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ExtractLevelCubes ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    bool CreateModel ();

    NodePtr m_spkScene, m_spkTrnNode;
    TriMeshPtr m_spkModel;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(ExtractLevelCubes);

#endif

