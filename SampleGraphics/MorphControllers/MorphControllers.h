// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef MORPHCONTROLLERS_H
#define MORPHCONTROLLERS_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class MorphControllers : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    MorphControllers ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void LoadTargets ();
    void CreateFace ();
    void CreateController ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    TriMeshPtr m_spkFace;
    Culler m_kCuller;

    // shared data
    IndexBufferPtr m_spkIBuffer;
    MaterialStatePtr m_spkMaterial;
    LightPtr m_spkLight;

    enum
    {
        TARGET_QUANTITY = 5,
        KEY_QUANTITY = 6
    };
    TriMeshPtr m_aspkTarget[TARGET_QUANTITY];

    // animation time
    double m_dBaseTime, m_dCurrTime;

    // picking
    enum { PICK_MESSAGE_SIZE = 128 };
    int m_iXPick, m_iYPick;
    char m_acPickMessage[PICK_MESSAGE_SIZE];
    bool m_bPickPending;
};

WM4_REGISTER_INITIALIZE(MorphControllers);

#endif
