// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Library (WM3) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic3License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BumpMaps.h"

WM4_WINDOW_APPLICATION(BumpMaps);

//----------------------------------------------------------------------------
BumpMaps::BumpMaps ()
    :
    WindowApplication3("BumpMaps",0,0,640,480,ColorRGBA(1.0f,1.0f,1.0f,1.0f))
{
    System::InsertDirectory("Data");
    m_bUseTorus = true;
    m_bUseBumpMap = true;
}
//----------------------------------------------------------------------------
bool BumpMaps::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    m_spkCamera->SetFrustum(-0.055f,0.055f,-0.04125f,0.04125f,0.1f,100.0f);
    Vector3f kCDir, kCLoc;
    if (m_bUseTorus)
    {
        kCDir = Vector3f(0.0f,0.0f,1.0f);
        kCLoc = Vector3f(0.0f,-0.25f,-3.0f);
    }
    else
    {
        kCDir = Vector3f(0.0f,0.0f,-1.0f);
        kCLoc = Vector3f(0.0f,0.0f,3.0f);
    }
    Vector3f kCUp(0.0f,1.0f,0.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    CreateScene();

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    UpdateBumpMap();

    // initial culling of scene
    m_kCuller.SetCamera(m_spkCamera);
    m_kCuller.ComputeVisibleSet(m_spkScene);

    InitializeCameraMotion(0.01f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void BumpMaps::OnTerminate ()
{
    m_spkScene = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void BumpMaps::OnIdle ()
{
    MeasureTime();

    if (MoveCamera())
    {
        m_kCuller.ComputeVisibleSet(m_spkScene);
    }

    if (MoveObject())
    {
        UpdateBumpMap();
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
bool BumpMaps::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'b':
    case 'B':
    {
        m_bUseBumpMap = !m_bUseBumpMap;
        TriMesh* pkMesh = StaticCast<TriMesh>(m_spkScene->GetChild(0));
        if (m_bUseTorus)
        {
            Transformation kLocal = pkMesh->Local;
            pkMesh = CreateTorus();
            pkMesh->Local = kLocal;
        }
        else
        {
            pkMesh = CreateSquare();
        }
        m_spkScene->SetChild(0,pkMesh);
        m_spkScene->UpdateGS();
        m_spkScene->UpdateRS();
        UpdateBumpMap();
        m_kCuller.ComputeVisibleSet(m_spkScene);
        return true;
    }
    case 's':
    case 'S':
        TestStreaming(m_spkScene,128,128,640,480,"BumpMaps.wmof");
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void BumpMaps::CreateScene ()
{
    m_spkScene = WM4_NEW Node;
    TriMesh* pkMesh;
    if (m_bUseTorus)
    {
        pkMesh = CreateTorus();
        pkMesh->Local.SetRotate(Matrix3f(Vector3f::UNIT_X,0.25f*Mathf::PI));
    }
    else
    {
        pkMesh = CreateSquare();
    }
    m_spkScene->AttachChild(pkMesh);
}
//----------------------------------------------------------------------------
TriMesh* BumpMaps::CreateTorus ()
{
    Attributes kAttr;
    kAttr.SetPChannels(3);
    if (m_bUseBumpMap)
    {
        kAttr.SetNChannels(3);
        kAttr.SetCChannels(0,3);
        kAttr.SetTChannels(0,2);
        kAttr.SetTChannels(1,2);
    }
    else
    {
        kAttr.SetTChannels(0,2);
    }

    StandardMesh kSM(kAttr);
    TriMesh* pkMesh = kSM.Torus(32,32,1.0f,0.4f);

    VertexBuffer* pkVB = pkMesh->VBuffer;
    int iVQuantity = pkVB->GetVertexQuantity();
    for (int i = 0; i < iVQuantity; i++)
    {
        pkVB->TCoord2(0,i) *= 4.0f;
        if (m_bUseBumpMap)
        {
            pkVB->TCoord2(1,i) *= 4.0f;
        }
    }

    if (m_bUseBumpMap)
    {
        SimpleBumpMapEffect* pkEffect = WM4_NEW SimpleBumpMapEffect("Bricks",
            "BricksNormal",Vector3f::UNIT_Z);
        pkEffect->ComputeLightVectors(pkMesh);

        Texture* pkBricks = pkEffect->GetPTexture(0,0);
        pkBricks->SetFilterType(Texture::LINEAR_LINEAR);
        pkBricks->SetWrapType(0,Texture::REPEAT);
        pkBricks->SetWrapType(1,Texture::REPEAT);

        Texture* pkNormals = pkEffect->GetPTexture(0,1);
        pkNormals->SetFilterType(Texture::LINEAR_LINEAR);
        pkNormals->SetWrapType(0,Texture::REPEAT);
        pkNormals->SetWrapType(1,Texture::REPEAT);

        pkMesh->AttachEffect(pkEffect);
    }
    else
    {
        TextureEffect* pkEffect = WM4_NEW TextureEffect("Bricks");

        Texture* pkBricks = pkEffect->GetPTexture(0,0);
        pkBricks->SetFilterType(Texture::LINEAR_LINEAR);
        pkBricks->SetWrapType(0,Texture::REPEAT);
        pkBricks->SetWrapType(1,Texture::REPEAT);

        pkMesh->AttachEffect(pkEffect);
    }


    return pkMesh;
}
//----------------------------------------------------------------------------
TriMesh* BumpMaps::CreateSquare ()
{
    Attributes kAttr;
    kAttr.SetPChannels(3);
    if (m_bUseBumpMap)
    {
        kAttr.SetNChannels(3);
        kAttr.SetCChannels(0,3);
        kAttr.SetTChannels(0,2);
        kAttr.SetTChannels(1,2);
    }
    else
    {
        kAttr.SetTChannels(0,2);
    }

    VertexBuffer* pkVBuffer = WM4_NEW VertexBuffer(kAttr,4);

    pkVBuffer->Position3(0) = Vector3f(-1.0f,-1.0f,0.0f);
    pkVBuffer->Position3(1) = Vector3f(+1.0f,-1.0f,0.0f);
    pkVBuffer->Position3(2) = Vector3f(+1.0f,+1.0f,0.0f);
    pkVBuffer->Position3(3) = Vector3f(-1.0f,+1.0f,0.0f);

    if (m_bUseBumpMap)
    {
        pkVBuffer->Normal3(0) = Vector3f::UNIT_Z;
        pkVBuffer->Normal3(1) = Vector3f::UNIT_Z;
        pkVBuffer->Normal3(2) = Vector3f::UNIT_Z;
        pkVBuffer->Normal3(3) = Vector3f::UNIT_Z;

        pkVBuffer->TCoord2(0,0) = Vector2f(0.0f,0.0f);
        pkVBuffer->TCoord2(0,1) = Vector2f(1.0f,0.0f);
        pkVBuffer->TCoord2(0,2) = Vector2f(1.0f,1.0f);
        pkVBuffer->TCoord2(0,3) = Vector2f(0.0f,1.0f);

        pkVBuffer->TCoord2(1,0) = Vector2f(0.0f,0.0f);
        pkVBuffer->TCoord2(1,1) = Vector2f(1.0f,0.0f);
        pkVBuffer->TCoord2(1,2) = Vector2f(1.0f,1.0f);
        pkVBuffer->TCoord2(1,3) = Vector2f(0.0f,1.0f);
    }
    else
    {
        pkVBuffer->TCoord2(0,0) = Vector2f(0.0f,0.0f);
        pkVBuffer->TCoord2(0,1) = Vector2f(1.0f,0.0f);
        pkVBuffer->TCoord2(0,2) = Vector2f(1.0f,1.0f);
        pkVBuffer->TCoord2(0,3) = Vector2f(0.0f,1.0f);
    }

    IndexBuffer* pkIBuffer = WM4_NEW IndexBuffer(6);
    int* aiIndex = pkIBuffer->GetData();
    aiIndex[0] = 0;  aiIndex[1] = 1;  aiIndex[2] = 2;
    aiIndex[3] = 0;  aiIndex[4] = 2;  aiIndex[5] = 3;

    TriMesh* pkMesh = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);

    if (m_bUseBumpMap)
    {
        Vector3f kLightDirection(-1.0f,-1.0f,-1.0f);
        kLightDirection.Normalize();
        SimpleBumpMapEffect* pkEffect = WM4_NEW SimpleBumpMapEffect("Bricks",
            "BricksNormal",kLightDirection);
        pkEffect->ComputeLightVectors(pkMesh);
        pkMesh->AttachEffect(pkEffect);
    }
    else
    {
        TextureEffect* pkEffect = WM4_NEW TextureEffect("Bricks");
        pkMesh->AttachEffect(pkEffect);
    }

    return pkMesh;
}
//----------------------------------------------------------------------------
void BumpMaps::UpdateBumpMap ()
{
    if (m_bUseBumpMap)
    {
        // The scene graph transformations have been updated, which means the
        // tangent-space light vectors need updating.
        TriMesh* pkMesh = StaticCast<TriMesh>(m_spkScene->GetChild(0));
        SimpleBumpMapEffect* pkEffect =
            (SimpleBumpMapEffect*)pkMesh->GetEffect(0);
        pkEffect->ComputeLightVectors(pkMesh);
        pkMesh->VBuffer->Release();
    }
}
//----------------------------------------------------------------------------
