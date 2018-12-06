// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RENDERTOTEXTURE_H
#define RENDERTOTEXTURE_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class RenderToTexture : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    RenderToTexture ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);

protected:
    void CreateScene ();
    Node* CreateModel ();

    NodePtr m_spkScene;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    CameraPtr m_spkScreenCamera;

    TriMeshPtr m_spkScenePolygon;
    ImagePtr m_spkSceneImage;
    Texture* m_pkSceneTarget;
    FrameBuffer* m_pkPBuffer;
};

WM4_REGISTER_INITIALIZE(RenderToTexture);

#endif
