// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SortedCube.h"
#include "Wm4TriMesh.h"
#include "Wm4TextureEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,SortedCube,Node);
WM4_IMPLEMENT_STREAM(SortedCube);

//----------------------------------------------------------------------------
SortedCube::SortedCube (Camera* pkCamera,
    const std::string& rkXpImage, const std::string& rkXmImage,
    const std::string& rkYpImage, const std::string& rkYmImage,
    const std::string& rkZpImage, const std::string& rkZmImage)
    :
    m_spkCamera(pkCamera)
{
    m_iBackFacing = 0;

    // no culling (all faces drawn)
    CullState* pkCS = WM4_NEW CullState;
    pkCS->Enabled = false;
    AttachGlobalState(pkCS);

    // depth buffering writes, but no reads
    ZBufferState* pkZS = WM4_NEW ZBufferState;
    pkZS->Enabled = false;
    pkZS->Writable = true;
    AttachGlobalState(pkZS);

    // child nodes have textures with an alpha channel of 1/2
    AlphaState* pkAS = WM4_NEW AlphaState;
    pkAS->BlendEnabled = true;
    AttachGlobalState(pkAS);

    // All faces share the same vertex and index buffers.
    Attributes kAttr;
    kAttr.SetPChannels(3);
    kAttr.SetTChannels(0,2);
    VertexBuffer* pkVBuffer = WM4_NEW VertexBuffer(kAttr,4);
    pkVBuffer->Position3(0) = Vector3f(-1.0f,-1.0f,0.0f);
    pkVBuffer->Position3(1) = Vector3f( 1.0f,-1.0f,0.0f);
    pkVBuffer->Position3(2) = Vector3f( 1.0f, 1.0f,0.0f);
    pkVBuffer->Position3(3) = Vector3f(-1.0f, 1.0f,0.0f);
    pkVBuffer->TCoord2(0,0) = Vector2f(0.0f,0.0f);
    pkVBuffer->TCoord2(0,1) = Vector2f(1.0f,0.0f);
    pkVBuffer->TCoord2(0,2) = Vector2f(1.0f,1.0f);
    pkVBuffer->TCoord2(0,3) = Vector2f(0.0f,1.0f);

    IndexBuffer* pkIBuffer = WM4_NEW IndexBuffer(6);
    int* aiIndex = pkIBuffer->GetData();
    aiIndex[0] = 0;  aiIndex[1] = 1;  aiIndex[2] = 2;
    aiIndex[3] = 0;  aiIndex[4] = 2;  aiIndex[5] = 3;

    // The six TriMesh children of this object are initially stored in the
    // order: x=1 face, x=-1 face, y=1 face, y=-1 face, z=1 face, z=-1 face.

    // xp face (x = 1)
    m_aspkFace[0] = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);
    m_aspkFace[0]->AttachEffect(WM4_NEW TextureEffect(rkXpImage));
    m_aspkFace[0]->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_Y,
        Mathf::HALF_PI));
    m_aspkFace[0]->Local.SetTranslate(Vector3f::UNIT_X);
    AttachChild(m_aspkFace[0]);

    // xm face (x = -1)
    m_aspkFace[1] = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);
    m_aspkFace[1]->AttachEffect(WM4_NEW TextureEffect(rkXmImage));
    m_aspkFace[1]->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_Y,
        -Mathf::HALF_PI));
    m_aspkFace[1]->Local.SetTranslate(-Vector3f::UNIT_X);
    AttachChild(m_aspkFace[1]);

    // yp face (y = 1)
    m_aspkFace[2] = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);
    m_aspkFace[2]->AttachEffect(WM4_NEW TextureEffect(rkYpImage));
    m_aspkFace[2]->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_X,
        -Mathf::HALF_PI));
    m_aspkFace[2]->Local.SetTranslate(Vector3f::UNIT_Y);
    AttachChild(m_aspkFace[2]);

    // ym face (y = -1)
    m_aspkFace[3] = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);
    m_aspkFace[3]->AttachEffect(WM4_NEW TextureEffect(rkYmImage));
    m_aspkFace[3]->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_X,
        Mathf::HALF_PI));
    m_aspkFace[3]->Local.SetTranslate(-Vector3f::UNIT_Y);
    AttachChild(m_aspkFace[3]);

    // zp face (z = 1)
    m_aspkFace[4] = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);
    m_aspkFace[4]->AttachEffect(WM4_NEW TextureEffect(rkZpImage));
    m_aspkFace[4]->Local.SetTranslate(Vector3f::UNIT_Z);
    AttachChild(m_aspkFace[4]);

    // zm face (z = -1)
    m_aspkFace[5] = WM4_NEW TriMesh(pkVBuffer,pkIBuffer);
    m_aspkFace[5]->AttachEffect(WM4_NEW TextureEffect(rkZmImage));
    m_aspkFace[5]->Local.SetRotate(Matrix3f().FromAxisAngle(Vector3f::UNIT_Y,
        Mathf::PI));
    m_aspkFace[5]->Local.SetTranslate(-Vector3f::UNIT_Z);
    AttachChild(m_aspkFace[5]);
}
//----------------------------------------------------------------------------
SortedCube::SortedCube ()
{
}
//----------------------------------------------------------------------------
SortedCube::~SortedCube ()
{
}
//----------------------------------------------------------------------------
void SortedCube::SetCamera (Camera* pkCamera)
{
    m_spkCamera = pkCamera;
}
//----------------------------------------------------------------------------
void SortedCube::SortFaces ()
{
    // must have a camera for sorting
    if (!m_spkCamera)
    {
        return;
    }

    // Inverse transform the camera world view direction into the model space
    // of the cube.
    Vector3f kMDir = World.InvertVector(m_spkCamera->GetDVector());

    // test for back faces
    int iNewBackFacing = 0, iBackQuantity = 0;

    // test xp face
    if (kMDir.X() > 0.0f)
    {
        iNewBackFacing |=  1;
        iBackQuantity++;
    }

    // test xm face
    if (kMDir.X() < 0.0f)
    {
        iNewBackFacing |=  2;
        iBackQuantity++;
    }

    // test yp face
    if (kMDir.Y() > 0.0f)
    {
        iNewBackFacing |=  4;
        iBackQuantity++;
    }

    // test ym face
    if (kMDir.Y() < 0.0f)
    {
        iNewBackFacing |=  8;
        iBackQuantity++;
    }

    // test zp face
    if (kMDir.Z() > 0.0f)
    {
        iNewBackFacing |= 16;
        iBackQuantity++;
    }

    // test zm face
    if (kMDir.Z() < 0.0f)
    {
        iNewBackFacing |= 32;
        iBackQuantity++;
    }

    if (iNewBackFacing != m_iBackFacing)
    {
        // Resorting is needed.  Reassign the sorted children to the node
        // parent.  Back facing children go first, front facing second.
        m_iBackFacing = iNewBackFacing;

        // detach old children
        int i;
        for (i = 0; i < 6; i++)
        {
            SetChild(i,0);
        }

        // attach new children
        int iBStart = 0, iFStart = iBackQuantity, iMask;
        for (i = 0, iMask = 1; i < 6; i++, iMask <<= 1)
        {
            if (m_iBackFacing & iMask)
            {
                SetChild(iBStart++,m_aspkFace[i]);
            }
            else
            {
                SetChild(iFStart++,m_aspkFace[i]);
            }
        }
    }
}
//----------------------------------------------------------------------------
void SortedCube::GetVisibleSet (Culler& rkCuller, bool bNoCull)
{
    SortFaces();
    Node::GetVisibleSet(rkCuller,bNoCull);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// name and unique id
//----------------------------------------------------------------------------
Object* SortedCube::GetObjectByName (const std::string& rkName)
{
    Object* pkFound = Node::GetObjectByName(rkName);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkCamera)
    {
        pkFound = m_spkCamera->GetObjectByName(rkName);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------
void SortedCube::GetAllObjectsByName (const std::string& rkName,
    std::vector<Object*>& rkObjects)
{
    Node::GetAllObjectsByName(rkName,rkObjects);

    if (m_spkCamera)
    {
        m_spkCamera->GetAllObjectsByName(rkName,rkObjects);
    }
}
//----------------------------------------------------------------------------
Object* SortedCube::GetObjectByID (unsigned int uiID)
{
    Object* pkFound = Node::GetObjectByID(uiID);
    if (pkFound)
    {
        return pkFound;
    }

    if (m_spkCamera)
    {
        pkFound = m_spkCamera->GetObjectByID(uiID);
        if (pkFound)
        {
            return pkFound;
        }
    }

    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void SortedCube::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Node::Load(rkStream,pkLink);

    // link data
    Object* pkObject;
    rkStream.Read(pkObject);  // m_spkCamera
    pkLink->Add(pkObject);

    WM4_END_DEBUG_STREAM_LOAD(SortedCube);
}
//----------------------------------------------------------------------------
void SortedCube::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Node::Link(rkStream,pkLink);

    Object* pkLinkID = pkLink->GetLinkID();
    m_spkCamera = (Camera*)rkStream.GetFromMap(pkLinkID);
}
//----------------------------------------------------------------------------
bool SortedCube::Register (Stream& rkStream) const
{
    if (!Node::Register(rkStream))
    {
        return false;
    }

    if (m_spkCamera)
    {
        m_spkCamera->Register(rkStream);
    }

    return true;
}
//----------------------------------------------------------------------------
void SortedCube::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Node::Save(rkStream);

    // link data
    rkStream.Write(m_spkCamera);

    WM4_END_DEBUG_STREAM_SAVE(SortedCube);
}
//----------------------------------------------------------------------------
int SortedCube::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Node::GetDiskUsed(rkVersion) + sizeof(m_spkCamera);
}
//----------------------------------------------------------------------------
StringTree* SortedCube::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    // children
    pkTree->Append(Node::SaveStrings());

    if (m_spkCamera)
    {
        pkTree->Append(m_spkCamera->SaveStrings());
    }

    return pkTree;
}
//----------------------------------------------------------------------------
