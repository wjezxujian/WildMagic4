// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SimplePendulumFriction.h"

WM4_WINDOW_APPLICATION(SimplePendulumFriction);

//#define SINGLE_STEP

//----------------------------------------------------------------------------
SimplePendulumFriction::SimplePendulumFriction ()
    :
    WindowApplication3("SimplePendulumFriction",0,0,640,480,
        ColorRGBA(0.819607f,0.909803f,0.713725f,1.0f))
{
    m_fLastIdle = 0.0f;
}
//----------------------------------------------------------------------------
bool SimplePendulumFriction::OnInitialize ()
{
    if (!WindowApplication3::OnInitialize())
    {
        return false;
    }

    // initialize the physics module

    // (c/m)^2 > 4*g/L (pendulum slows to a vertical stop, no oscillation)
    //m_kModule.CDivM = 4.0;
    //m_kModule.GDivL = 1.0;

    // (c/m)^2 < 4*g/L (pendulum oscillates, but slows down quickly)
    //m_kModule.CDivM = 1.0;
    //m_kModule.GDivL = 1.0;

    // (c/m)^2 < 4*g/L (pendulum oscillates, but slows down slowly)
    m_kModule.CDivM = 0.1;
    m_kModule.GDivL = 1.0;

    double dTime = 0.0;
    double dDeltaTime = 0.001;
    double dTheta = 0.75;
    double dThetaDot = 0.0;
    m_kModule.Initialize(dTime,dDeltaTime,dTheta,dThetaDot);

    // set up the scene graph
    m_spkScene = WM4_NEW Node;
    m_spkWireframe = WM4_NEW WireframeState;
    m_spkScene->AttachGlobalState(m_spkWireframe);
    ZBufferState* pkZS = WM4_NEW ZBufferState;
    pkZS->Enabled = false;
    m_spkScene->AttachGlobalState(pkZS);

    m_spkScene->AttachChild(CreateFloor());
    m_spkScene->AttachChild(CreatePendulum());

    // set up camera
    m_spkCamera->SetFrustum(-0.55f,0.55f,-0.4125f,0.4125f,1.0f,100.0f);
    float fAngle = 0.1f*Mathf::PI;
    float fCos = Mathf::Cos(fAngle), fSin = Mathf::Sin(fAngle);
    Vector3f kCLoc(23.0f,0.0f,8.0f);
    Vector3f kCDir(-fCos,0.0f,-fSin);
    Vector3f kCUp(-fSin,0.0f,fCos);
    Vector3f kCRight = kCDir.Cross(kCUp);
    m_spkCamera->SetFrame(kCLoc,kCDir,kCUp,kCRight);

    // initial update of objects
    m_spkScene->UpdateGS(0.0f);
    m_spkScene->UpdateRS();

    DoPhysical();

    // initial culling of scene
    m_kCuller.SetCamera(m_spkCamera);
    m_kCuller.ComputeVisibleSet(m_spkScene);

    InitializeCameraMotion(0.01f,0.001f);
    InitializeObjectMotion(m_spkScene);
    return true;
}
//----------------------------------------------------------------------------
void SimplePendulumFriction::OnTerminate ()
{
    m_spkScene = 0;
    m_spkWireframe = 0;
    m_spkPendulum = 0;
    WindowApplication3::OnTerminate();
}
//----------------------------------------------------------------------------
void SimplePendulumFriction::OnIdle ()
{
    MeasureTime();

    MoveCamera();
    if (MoveObject())
    {
        m_spkScene->UpdateGS(0.0f);
    }

#ifndef SINGLE_STEP
    DoPhysical();
#endif
    m_kCuller.ComputeVisibleSet(m_spkScene);

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
bool SimplePendulumFriction::OnKeyDown (unsigned char ucKey, int iX, int iY)
{
    if (WindowApplication3::OnKeyDown(ucKey,iX,iY))
    {
        return true;
    }

    switch (ucKey)
    {
    case 'w':  // toggle wireframe
    case 'W':
        m_spkWireframe->Enabled = !m_spkWireframe->Enabled;
        return true;

#ifdef SINGLE_STEP
    case 'g':
    case 'G':
        DoPhysical();
        return true;
#endif
    }

    return false;
}
//----------------------------------------------------------------------------
TriMesh* SimplePendulumFriction::CreateFloor ()
{
    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetTChannels(0,2);
    TriMesh* pkFloor = StandardMesh(kAttr).Rectangle(2,2,32.0f,32.0f);
    pkFloor->AttachEffect(WM4_NEW TextureEffect("Wood"));
    return pkFloor;
}
//----------------------------------------------------------------------------
Node* SimplePendulumFriction::CreatePendulum ()
{
    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetNChannels(3);
    StandardMesh kSM(kAttr);

    // pendulum rod
    TriMesh* pkRod = kSM.Cylinder(2,8,0.05f,12.0f,true);
    pkRod->Local.SetTranslate(Vector3f(0.0f,0.0f,10.0f));

    // The pendulum bulb.  Start with a sphere (to get the connectivity) and
    // then adjust the vertices to form a pair of joined cones.
    TriMesh* pkBulb = kSM.Sphere(16,32,2.0f);
    VertexBuffer* pkVB = pkBulb->VBuffer;
    int iVQuantity = pkVB->GetVertexQuantity();
    int i;
    for (i = 0; i < iVQuantity; i++)
    {
        pkVB->Position3(i).Z() += 2.0f;

        float fR = Mathf::Sqrt(
            pkVB->Position3(i).X()*pkVB->Position3(i).X() +
            pkVB->Position3(i).Y()*pkVB->Position3(i).Y());
        float fZ = pkVB->Position3(i).Z();

        if (fZ >= 2.0f)
        {
            fZ = 4.0f - fR;
        }
        else
        {
            fZ = fR;
        }

        pkVB->Position3(i).Z() = fZ;
    }

    // Translate the pendulum joint to the origin for the purposes of
    // rotation.
    for (i = 0; i < iVQuantity; i++)
    {
        pkVB->Position3(i).Z() -= 16.0f;
    }
    pkBulb->UpdateMS(true);

    pkVB = pkRod->VBuffer;
    iVQuantity = pkVB->GetVertexQuantity();
    for (i = 0; i < iVQuantity; i++)
    {
        pkVB->Position3(i).Z() -= 16.0f;
    }
    pkRod->UpdateMS(true);

    // group the objects into a single subtree
    m_spkPendulum = WM4_NEW Node;
    m_spkPendulum->AttachChild(pkRod);
    m_spkPendulum->AttachChild(pkBulb);

    // translate back to original model position
    m_spkPendulum->Local.SetTranslate(Vector3f(0.0f,0.0f,16.0f));

    // add a material for coloring purposes
    MaterialState* pkMS = WM4_NEW MaterialState;
    pkMS->Emissive = ColorRGB::BLACK;
    pkMS->Ambient = ColorRGB(0.1f,0.1f,0.1f);
    pkMS->Diffuse = ColorRGB(0.99607f,0.83920f,0.67059f);
    pkMS->Specular = ColorRGB::BLACK;
    pkMS->Shininess = 1.0f;
    pkMS->Alpha = 1.0f;
    m_spkPendulum->AttachGlobalState(pkMS);

    Light* pkLight = WM4_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = ColorRGB::WHITE;
    pkLight->Diffuse = ColorRGB::WHITE;
    pkLight->Specular = ColorRGB::BLACK;
    pkLight->SetDirection(Vector3f(-1.0f,-1.0f,0.0f),false);
    m_spkPendulum->AttachLight(pkLight);

    pkLight = WM4_NEW Light(Light::LT_DIRECTIONAL);
    pkLight->Ambient = ColorRGB::WHITE;
    pkLight->Diffuse = ColorRGB::WHITE;
    pkLight->Specular = ColorRGB::BLACK;
    pkLight->SetDirection(Vector3f(1.0f,-1.0f,0.0f),false);
    m_spkPendulum->AttachLight(pkLight);

    // depth buffering only for this part of the scene graph
    m_spkPendulum->AttachGlobalState(WM4_NEW ZBufferState);

    return m_spkPendulum;
}
//----------------------------------------------------------------------------
void SimplePendulumFriction::DoPhysical ()
{
    m_kModule.Update();

    // Update the pendulum mechanism.  The pendulum rod is attached at
    // (x,y,z) = (0,0,16).  The update here has the 16 hard-coded.
    m_spkPendulum->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_X,
        (float)m_kModule.GetTheta()));
    m_spkPendulum->UpdateGS(0.0f);
}
//----------------------------------------------------------------------------
