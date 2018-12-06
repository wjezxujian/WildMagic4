// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Charcoal.h"

WM4_WINDOW_APPLICATION(Charcoal);

//----------------------------------------------------------------------------
Charcoal::Charcoal ()
    :
    WindowApplication3("Charcoal",0,0,640,480,ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
    System::InsertDirectory("Data");

    m_bSmudge = true;
    m_bDisplayPaper = true;
    m_bDisplayLighting = true;
}
//----------------------------------------------------------------------------
bool Charcoal::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // set up camera
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,1000.0f);
    Vector3f kCLoc(80.0f,0.0f,23.0f);
    Vector3f kCDir(-1.0f,0.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // set up scene
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
void Charcoal::OnTerminate ()
{
    m_spkScene = 0;
    m_spkEffect = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void Charcoal::OnIdle ()
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
bool Charcoal::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'p':
    case 'P':
        m_bDisplayPaper = !m_bDisplayPaper;
        UpdateConstants();
        return true;
    case 'm':
    case 'M':
        m_bSmudge = !m_bSmudge;
        UpdateConstants();
        return true;
    case 'l':
    case 'L':
        m_bDisplayLighting = !m_bDisplayLighting;
        UpdateConstants();
        return true;
    case 's':
    case 'S':
        TestStreaming(m_spkScene,128,128,640,480,"Charcoal.wmof");
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void Charcoal::CreateScene ()
{
    Stream kStream;
    const char* acFilename = System::GetPath("SkinnedBipedPN.wmof",
        System::SM_READ);
    bool bLoaded = kStream.Load(acFilename);
    assert(bLoaded);
    (void)bLoaded;  // avoid warning in release build
    m_spkScene = (Node*)kStream.GetObjectAt(0);

    Light* pkLight0 = WM4_NEW Light(Light::LT_DIRECTIONAL);
    pkLight0->DVector = Vector3f(-1.0f,0.3f,-0.8f);
    pkLight0->DVector.Normalize();

    Light* pkLight1 = WM4_NEW Light(Light::LT_DIRECTIONAL);
    pkLight1->DVector = Vector3f(0.4f,-1.0f,-0.5f);
    pkLight1->DVector.Normalize();

    m_spkEffect = WM4_NEW CharcoalEffect("Paper",0.2f,3.5f,0.0f,0.0f,
        pkLight0,pkLight1);
    AttachShader(m_spkScene);
}
//----------------------------------------------------------------------------
void Charcoal::UpdateConstants ()
{
    if (m_bDisplayLighting)
    {
        if (m_bSmudge)
        {
            m_spkEffect->SetSmudgeFactor(0.5f);
        }
        else
        {
            m_spkEffect->SetSmudgeFactor(1.0f);
        }
    }
    else
    {
        m_spkEffect->SetSmudgeFactor(0.0f);
    }

    if (m_bDisplayPaper)
    {
        m_spkEffect->SetPaperFactor(0.0f);
    }
    else
    {
        m_spkEffect->SetPaperFactor(1.0f);
    }
}
//----------------------------------------------------------------------------
void Charcoal::AttachShader (Spatial* pkObject)
{
    Geometry* pkGeom = DynamicCast<Geometry>(pkObject);
    if (pkGeom)
    {
        // The model has vertex positions and normals.  It also needs a set
        // of randomly generated texture coordinates.
        Attributes kAttr;
        kAttr.SetPChannels(3);
        kAttr.SetNChannels(3);
        kAttr.SetTChannels(0,2);
        int iVQuantity = pkGeom->VBuffer->GetVertexQuantity();
        VertexBuffer* pkVBuffer = WM4_NEW VertexBuffer(kAttr,iVQuantity);
        for (int i = 0; i < iVQuantity; i++)
        {
            pkVBuffer->Position3(i) = pkGeom->VBuffer->Position3(i);
            pkVBuffer->Normal3(i) = pkGeom->VBuffer->Normal3(i);
            pkVBuffer->TCoord2(0,i) = Vector2f(Mathf::UnitRandom(),
                Mathf::UnitRandom());
        }
        pkGeom->VBuffer = pkVBuffer;
        pkGeom->AttachEffect(m_spkEffect);
        return;
    }

    Node* pkNode = DynamicCast<Node>(pkObject);
    assert(pkNode);
    for (int i = 0; i < pkNode->GetQuantity(); i++)
    {
        Spatial* pkChild = pkNode->GetChild(i);
        if (pkChild)
        {
            AttachShader(pkChild);
        }
    }
}
//----------------------------------------------------------------------------
