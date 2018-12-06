// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Fresnel.h"

WM4_WINDOW_APPLICATION(Fresnel);

//----------------------------------------------------------------------------
Fresnel::Fresnel ()
    :
    WindowApplication3("Fresnel",0,0,640,480,ColorRGBA(0.5f,0.0f,1.0f,1.0f))
{
}
//----------------------------------------------------------------------------
bool Fresnel::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    CreateScene();

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
void Fresnel::OnTerminate ()
{
    m_spkScene = 0;
    m_spkMesh = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void Fresnel::OnIdle ()
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
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool Fresnel::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
        TestStreaming(m_spkScene,128,128,640,480,"Fresnel.wmof");
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void Fresnel::CreateScene ()
{
    float fDMin = 1.0f;
    float fDMax = 1000.0f;
    float fRMax = 0.55f*fDMin;
    float fRMin = -fRMax;
    float fUMax = 0.4125f*fDMin;
    float fUMin = -fUMax;
    m_spkCamera->SetFrustum(fRMin,fRMax,fUMin,fUMax,fDMin,fDMax);
    Vector3f kCLoc(0.0f,-200.0f,0.0f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    m_spkScene = WM4_NEW Node;
    m_spkWireframe = WM4_NEW WireframeState;
    m_spkScene->AttachGlobalState(m_spkWireframe);

    Stream kStream;
    const char* acPath = System::GetPath("FacePN.wmof",System::SM_READ);
    bool bLoaded = kStream.Load(acPath);
    assert(bLoaded);
    m_spkMesh = DynamicCast<TriMesh>(kStream.GetObjectAt(0));
    assert(m_spkMesh);
    m_spkScene->AttachChild(m_spkMesh);

    FresnelEffect* pkEffect = WM4_NEW FresnelEffect;
    m_spkMesh->AttachEffect(pkEffect);
}
//----------------------------------------------------------------------------
