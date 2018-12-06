// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SphereMaps.h"
#include "SphereMapEffect.h"

WM4_WINDOW_APPLICATION(SphereMaps);

//----------------------------------------------------------------------------
SphereMaps::SphereMaps ()
    :
    WindowApplication3("SphereMaps",0,0,640,480,
        ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool SphereMaps::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    CreateScene();

    // center-and-fit scene in the view frustum
    m_spkScene->UpdateGS();
    m_spkScene->GetChild(0)->Local.SetTranslate(
        -m_spkScene->WorldBound->GetCenter());
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    Vector3f kCLoc = -3.0f*m_spkScene->WorldBound->GetRadius()*kCDir;
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    // initial culling of scene
    m_kCuller.SetCamera(m_spkCamera);
    m_kCuller.ComputeVisibleSet(m_spkScene);

    InitializeCameraMotion(0.1f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void SphereMaps::OnTerminate ()
{
    m_spkScene = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void SphereMaps::OnIdle ()
{
    MeasureTime();

    if (MoveCamera())
    {
        m_kCuller.ComputeVisibleSet(m_spkScene);
    }

    if (MoveObject())
    {
        m_spkScene->UpdateGS();
        m_kCuller.ComputeVisibleSet(m_spkScene);
    }

    m_pkRenderer->ClearBuffers();
    if (m_pkRenderer->BeginScene())
    {
        m_pkRenderer->DrawScene(m_kCuller.GetVisibleSet());
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::BLACK);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool SphereMaps::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'w':
    case 'W':
        m_spkWireframe->Enabled = !m_spkWireframe->Enabled;
        return true;
    case 's':
    case 'S':
        TestStreaming(m_spkScene,128,128,640,480,"SphereMaps.wmof");
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void SphereMaps::CreateScene ()
{
    m_spkScene = WM4_NEW Node;
    Node* pkTrnNode = WM4_NEW Node;
    m_spkScene->AttachChild(pkTrnNode);
    m_spkWireframe = WM4_NEW WireframeState;
    m_spkScene->AttachGlobalState(m_spkWireframe);

    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetNChannels(3);
    StandardMesh kSM(kAttr);
    TriMesh* pkMesh = kSM.Torus(64,64,1.0f,0.5f);
    pkTrnNode->AttachChild(pkMesh);
    pkMesh->AttachEffect(WM4_NEW SphereMapEffect("SphereMap"));
}
//----------------------------------------------------------------------------
