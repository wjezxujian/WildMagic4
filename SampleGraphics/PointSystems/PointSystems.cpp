// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "PointSystems.h"
#include "RandomController.h"

WM4_WINDOW_APPLICATION(PointSystems);

//----------------------------------------------------------------------------
PointSystems::PointSystems ()
    :
    WindowApplication3("PointSystems",0,0,640,480,
        ColorRGBA(0.75f,0.75f,0.75f,1.0f))
{
}
//----------------------------------------------------------------------------
bool PointSystems::OnInitialize ()
{
    if ( !WindowApplication3::OnInitialize() )
        return false;

    CreateScene();

    // set up camera
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCLoc(4.0f,0.0f,0.0f);
    Vector3f kCDir(-1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    // initial culling of scene
    m_kCuller.SetCamera(m_spkCamera);
    m_kCuller.ComputeVisibleSet(m_spkScene);

    InitializeCameraMotion(0.01f,0.01f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void PointSystems::OnTerminate ()
{
    m_spkScene = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void PointSystems::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    MoveObject();
    m_spkScene->UpdateGS(System::GetTime());
    m_kCuller.ComputeVisibleSet(m_spkScene);

    m_pkRenderer->ClearBuffers();
    if ( m_pkRenderer->BeginScene() )
    {
        m_pkRenderer->DrawScene(m_kCuller.GetVisibleSet());
        DrawFrameRate(8,GetHeight()-8,ColorRGBA::WHITE);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool PointSystems::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 's':
    case 'S':
        TestStreaming(m_spkScene,128,128,640,480,"PointSystems.wmof");
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void PointSystems::CreateScene ()
{
    m_spkScene = WM4_NEW Node;

    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetCChannels(0,3);
    int iVQuantity = 1024;
    VertexBuffer* pkVBuffer = WM4_NEW VertexBuffer(kAttr,iVQuantity);
    for (int i = 0; i < iVQuantity; i++)
    {
        pkVBuffer->Position3(i) = Vector3f(Mathf::SymmetricRandom(),
            Mathf::SymmetricRandom(),Mathf::SymmetricRandom());
        pkVBuffer->Color3(0,i) = ColorRGB(Mathf::UnitRandom(),
            Mathf::UnitRandom(),Mathf::UnitRandom());
    }

    Polypoint* pkPoints = WM4_NEW Polypoint(pkVBuffer);
    pkPoints->AttachEffect(WM4_NEW VertexColor3Effect);
    pkPoints->AttachController(WM4_NEW RandomController);

    m_spkScene->AttachChild(pkPoints);
}
//----------------------------------------------------------------------------
