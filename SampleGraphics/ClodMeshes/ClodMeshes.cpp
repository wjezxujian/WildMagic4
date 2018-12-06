// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "ClodMeshes.h"

WM4_WINDOW_APPLICATION(ClodMeshes);

//----------------------------------------------------------------------------
ClodMeshes::ClodMeshes ()
    :
    WindowApplication3("ClodMeshes",0,0,640,480,
        ColorRGBA(0.9f,0.9f,0.9f,1.0f))
{
}
//----------------------------------------------------------------------------
bool ClodMeshes::OnInitialize ()
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
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,10000.0f);
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

    InitializeCameraMotion(1.0f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void ClodMeshes::OnTerminate ()
{
    m_spkScene = 0;
    m_spkClod = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void ClodMeshes::OnIdle ()
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
        DrawTriangleQuantity(128,GetHeight()-8,ColorRGBA::BLACK);
        m_pkRenderer->EndScene();
    }
    m_pkRenderer->DisplayBackBuffer();

    UpdateFrameCount();
}
//----------------------------------------------------------------------------
bool ClodMeshes::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case '-':  // decrease triangle quantity
    case '_':
        if (m_spkClod->TargetRecord() < m_spkClod->GetRecordQuantity()-1)
        {
            m_spkClod->TargetRecord()++;
        }
        m_spkClod->UpdateGS();
        m_kCuller.ComputeVisibleSet(m_spkScene);
        return true;

    case '+':  // increase triangle quantity
    case '=':
        if (m_spkClod->TargetRecord() > 0)
        {
            m_spkClod->TargetRecord()--;
        }
        m_spkClod->UpdateGS();
        m_kCuller.ComputeVisibleSet(m_spkScene);
        return true;

    case 'c':  // toggle between half and full resolution
    case 'C':
        if (m_spkClod->TargetRecord() != 0)
        {
            m_spkClod->TargetRecord() = 0;
        }
        else
        {
            m_spkClod->TargetRecord() = 500;
        }
        m_spkClod->UpdateGS();
        m_kCuller.ComputeVisibleSet(m_spkScene);
        return true;

    case 'w':
    case 'W':
        m_spkWireframe->Enabled = !m_spkWireframe->Enabled;
        return true;

    case 's':
    case 'S':
        TestStreaming(m_spkScene,128,128,640,480,"ClodMeshes.wmof");
        return true;
     }

    return false;
}
//----------------------------------------------------------------------------
void ClodMeshes::CreateScene ()
{
    m_spkScene = WM4_NEW Node;
    Node* pkTrnNode = WM4_NEW Node;
    m_spkScene->AttachChild(pkTrnNode);
    m_spkWireframe = WM4_NEW WireframeState;
    m_spkScene->AttachGlobalState(m_spkWireframe);

    const char* acPath = System::GetPath("FacePN.wmof",System::SM_READ);
    Stream kIStream;
    kIStream.Load(acPath);
    TriMeshPtr spkMesh = StaticCast<TriMesh>(kIStream.GetObjectAt(0));

    int iCQuantity = 0;
    CollapseRecord* akCRecord = 0;
    CreateClodMesh kCCM(spkMesh->VBuffer,spkMesh->IBuffer,iCQuantity,
        akCRecord);

    m_spkClod = WM4_NEW ClodMesh(spkMesh->VBuffer,spkMesh->IBuffer,iCQuantity,
        akCRecord);

    m_spkClod->Local = spkMesh->Local;
    pkTrnNode->AttachChild(m_spkClod);

    // create a material
    MaterialState* pkMaterial = WM4_NEW MaterialState;
    pkMaterial->Emissive = ColorRGB(0.0f,0.0f,0.0f);
    pkMaterial->Ambient = ColorRGB(0.5f,0.5f,0.5f);
    pkMaterial->Diffuse = ColorRGB(0.99607f,0.83920f,0.67059f);
    pkMaterial->Specular = ColorRGB(0.8f,0.8f,0.8f);
    pkMaterial->Alpha = 1.0f;
    pkMaterial->Shininess = 0.0f;
    m_spkScene->AttachGlobalState(pkMaterial);

    // create a directional light
    Light* pkLight = WM4_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = ColorRGB(0.25f,0.25f,0.25f);
    pkLight->Diffuse = ColorRGB::WHITE;
    pkLight->Specular = ColorRGB::BLACK;
    pkLight->DVector = Vector3f::UNIT_Y;
    m_spkClod->AttachLight(pkLight);
}
//----------------------------------------------------------------------------
void ClodMeshes::DrawTriangleQuantity (int iX, int iY,
    const ColorRGBA& rkColor)
{
    if (m_spkClod && m_pkRenderer)
    {
        const size_t uiSize = 32;
        char acMessage[uiSize];
        System::Sprintf(acMessage,uiSize,"triangles: %d",
            m_spkClod->GetTriangleQuantity());
        m_pkRenderer->Draw(iX,iY,rkColor,acMessage);
    }
}
//----------------------------------------------------------------------------
void ClodMeshes::MoveForward ()
{
    WindowApplication3::MoveForward();

    Vector3f kDiff = m_spkScene->WorldBound->GetCenter()
        - m_spkCamera->GetLocation();
    float fDepth = kDiff.Dot(m_spkCamera->GetDVector());
    if (fDepth <= m_spkCamera->GetDMin())
    {
        m_spkClod->TargetRecord() = 0;
    }
    else if (fDepth >= m_spkCamera->GetDMax())
    {
        m_spkClod->TargetRecord() = m_spkClod->GetRecordQuantity() - 1;
    }
    else
    {
        // distance along camera direction controls triangle quantity
        float fN = m_spkCamera->GetDMin();
        float fF = m_spkCamera->GetDMax();
        float fRatio = (fDepth - fN)/(fF - fN);

        // allow nonlinear drop-off
        fRatio = Mathf::Pow(fRatio,0.5f);

        int iMaxIndex = m_spkClod->GetRecordQuantity() - 1;
        int iIndex = (int)(iMaxIndex*fRatio);
        m_spkClod->TargetRecord() = iIndex;
    }
}
//----------------------------------------------------------------------------
void ClodMeshes::MoveBackward ()
{
    WindowApplication3::MoveBackward();

    Vector3f kDiff = m_spkScene->WorldBound->GetCenter()
        - m_spkCamera->GetLocation();
    float fDepth = kDiff.Dot(m_spkCamera->GetDVector());
    if (fDepth <= m_spkCamera->GetDMin())
    {
        m_spkClod->TargetRecord() = 0;
    }
    else if (fDepth >= m_spkCamera->GetDMax())
    {
        m_spkClod->TargetRecord() = m_spkClod->GetRecordQuantity() - 1;
    }
    else
    {
        // distance along camera direction controls triangle quantity
        float fN = m_spkCamera->GetDMin();
        float fF = m_spkCamera->GetDMax();
        float fRatio = (fDepth - fN)/(fF - fN);

        // allow nonlinear drop-off
        fRatio = Mathf::Pow(fRatio,0.5f);

        int iMaxIndex = m_spkClod->GetRecordQuantity() - 1;
        int iIndex = (int)(iMaxIndex*fRatio);
        m_spkClod->TargetRecord() = iIndex;
    }
}
//----------------------------------------------------------------------------
