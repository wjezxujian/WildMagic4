// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BillboardNodes.h"

WM4_WINDOW_APPLICATION(BillboardNodes);

//----------------------------------------------------------------------------
BillboardNodes::BillboardNodes ()
    :
    WindowApplication3("BillboardNodes",0,0,640,480,
        ColorRGBA(0.9f,0.9f,0.9f,1.0f))
{
}
//----------------------------------------------------------------------------
bool BillboardNodes::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // set camera
    m_spkCamera->SetFrustum(-0.055f,0.055f,-0.04125f,0.04125f,0.1f,100.0f);
    Vector3f kCLoc(0.0f,-1.0f,0.25f);
    Vector3f kCDir(0.0f,1.0f,0.0f);
    Vector3f kCUp(0.0f,0.0f,1.0f);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    CreateScene();

    // initial update of objects
    m_spkScene->UpdateGS();
    m_spkScene->UpdateRS();

    // initial culling of scene
    m_kCuller.SetCamera(m_spkCamera);
    m_kCuller.ComputeVisibleSet(m_spkScene);

    InitializeCameraMotion(0.001f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void BillboardNodes::OnTerminate ()
{
    m_spkScene = 0;
    m_spkBillboard0 = 0;
    m_spkBillboard1 = 0;
    m_spkWireframe = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void BillboardNodes::OnIdle ()
{
    MeasureTime();

    if (MoveCamera())
    {
        m_spkBillboard0->UpdateGS();
        m_spkBillboard1->UpdateGS();
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
bool BillboardNodes::OnKeyDown (unsigned char ucKey, int iX, int iY)
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
        TestStreaming(m_spkScene,128,128,640,480,"BillboardNodes.wmof");
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void BillboardNodes::CreateScene ()
{
    m_spkScene = WM4_NEW Node;
    m_spkWireframe = WM4_NEW WireframeState;
    m_spkScene->AttachGlobalState(m_spkWireframe);

    // Create the ground.  It covers a square with vertices (1,1,0), (1,-1,0),
    // (-1,1,0), and (-1,-1,0).  Multiply the texture coordinates by a factor
    // to enhance the wrap-around.
    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetTChannels(0,2);
    StandardMesh kSM(kAttr);
    TriMesh* pkGround = kSM.Rectangle(2,2,16.0f,16.0f);
    int i;
    for (i = 0; i < pkGround->VBuffer->GetVertexQuantity(); i++)
    {
        pkGround->VBuffer->TCoord2(0,i) *= 128.0f;
    }

    ShaderEffect* pkEffect = WM4_NEW TextureEffect("Horizontal");
    Texture* pkTexture = pkEffect->GetPTexture(0,0);
    pkTexture->SetFilterType(Texture::LINEAR_LINEAR);
    pkTexture->SetWrapType(0,Texture::REPEAT);
    pkTexture->SetWrapType(1,Texture::REPEAT);
    pkGround->AttachEffect(pkEffect);
    m_spkScene->AttachChild(pkGround);

    // Create a billboard node that causes a rectangle to always be facing
    // the camera.  This is the type of billboard for an avatar.
    m_spkBillboard0 = WM4_NEW BillboardNode(m_spkCamera);
    m_spkScene->AttachChild(m_spkBillboard0);

    // Create a rectangle mesh.  The mesh is in the xy-plane.  Do not apply
    // local transformations to the mesh.  Use the billboard node transforms
    // to control the mesh location and orientation.
    TriMesh* pkMesh = kSM.Rectangle(2,2,0.125f,0.25f);

    pkEffect = WM4_NEW TextureEffect("RedSky");
    pkMesh->AttachEffect(pkEffect);
    m_spkBillboard0->AttachChild(pkMesh);

    // The billboard rotation is about its model-space up-vector (0,1,0).  In
    // this application, world-space up is (0,0,1).  Locally rotate the
    // billboard so it's up-vector matches the world's.
    m_spkBillboard0->Local.SetTranslate(Vector3f(-0.25f,0.0f,0.25f));
    m_spkBillboard0->Local.SetRotate(Matrix3f().FromAxisAngle(
        Vector3f::UNIT_X,Mathf::HALF_PI));

    // Create a billboard node that causes an object to always be oriented
    // the same way relative to the camera.
    m_spkBillboard1 = WM4_NEW BillboardNode(m_spkCamera);
    m_spkScene->AttachChild(m_spkBillboard1);

    // Create a torus mesh.  Do not apply local transformations to the mesh.
    // Use the billboard node transforms to control the mesh location and
    // orientation.
    pkMesh = kSM.Torus(16,16,1.0f,0.25f);
    pkMesh->Local.SetUniformScale(0.1f);

    pkMesh->AttachEffect(pkEffect);
    m_spkBillboard1->AttachChild(pkMesh);

    // The billboard rotation is about its model-space up-vector (0,1,0).  In
    // this application, world-space up is (0,0,1).  Locally rotate the
    // billboard so it's up-vector matches the world's.
    m_spkBillboard1->Local.SetTranslate(Vector3f(0.25f,0.0f,0.25f));
    m_spkBillboard1->Local.SetRotate(Matrix3f().FromAxisAngle(
        Vector3f::UNIT_X,Mathf::HALF_PI));
}
//----------------------------------------------------------------------------
