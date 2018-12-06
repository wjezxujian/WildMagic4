// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef VOLUMEFOG_H
#define VOLUMEFOG_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class VolumeFog : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    VolumeFog ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    void UpdateFog ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkHeightField;
    CameraPtr m_spkScreenCamera;
    TriMeshPtr m_spkBackPoly;
    ImagePtr m_spkHeightImage;
    Culler m_kCuller;
};

WM4_REGISTER_INITIALIZE(VolumeFog);

#endif
