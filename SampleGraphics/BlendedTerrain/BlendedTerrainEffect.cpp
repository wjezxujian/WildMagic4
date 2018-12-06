// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "BlendedTerrainEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,BlendedTerrainEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(BlendedTerrainEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(BlendedTerrainEffect,ShaderEffect);

//----------------------------------------------------------------------------
BlendedTerrainEffect::BlendedTerrainEffect (const char* acGrassName,
    const char* acStoneName, const char* acBlendName, const char* acCloudName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("BlendedTerrain");
    m_kPShader[0] = WM4_NEW PixelShader("BlendedTerrain");

    m_kPShader[0]->SetTextureQuantity(4);
    m_kPShader[0]->SetImageName(0,acGrassName);
    m_kPShader[0]->SetImageName(1,acStoneName);
    m_kPShader[0]->SetImageName(2,acBlendName);
    m_kPShader[0]->SetImageName(3,acCloudName);

    Texture* pkGrass = m_kPShader[0]->GetTexture(0);
    pkGrass->SetFilterType(Texture::LINEAR_LINEAR);
    pkGrass->SetWrapType(0,Texture::REPEAT);
    pkGrass->SetWrapType(1,Texture::REPEAT);

    Texture* pkStone = m_kPShader[0]->GetTexture(1);
    pkStone->SetFilterType(Texture::LINEAR_LINEAR);
    pkStone->SetWrapType(0,Texture::REPEAT);
    pkStone->SetWrapType(1,Texture::REPEAT);

    Texture* pkBlend = m_kPShader[0]->GetTexture(2);
    pkBlend->SetFilterType(Texture::LINEAR);
    pkBlend->SetWrapType(0,Texture::CLAMP_EDGE);

    Texture* pkCloud = m_kPShader[0]->GetTexture(3);
    pkCloud->SetFilterType(Texture::LINEAR_LINEAR);
    pkCloud->SetWrapType(0,Texture::REPEAT);
    pkCloud->SetWrapType(1,Texture::REPEAT);

    m_afFlowDirection[0] = 0.0f;
    m_afFlowDirection[1] = 0.0f;
    m_afPowerFactor[0] = 0.5f;
}
//----------------------------------------------------------------------------
BlendedTerrainEffect::BlendedTerrainEffect ()
{
}
//----------------------------------------------------------------------------
BlendedTerrainEffect::~BlendedTerrainEffect ()
{
}
//----------------------------------------------------------------------------
void BlendedTerrainEffect::OnLoadPrograms (int, Program* pkVProgram,
    Program* pkPProgram)
{
    pkVProgram->GetUC("FlowDirection")->SetDataSource(m_afFlowDirection);
    pkPProgram->GetUC("PowerFactor")->SetDataSource(m_afPowerFactor);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void BlendedTerrainEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_afFlowDirection[0]);
    rkStream.Read(m_afFlowDirection[1]);
    rkStream.Read(m_afPowerFactor[0]);

    WM4_END_DEBUG_STREAM_LOAD(BlendedTerrainEffect);
}
//----------------------------------------------------------------------------
void BlendedTerrainEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool BlendedTerrainEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void BlendedTerrainEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    rkStream.Write(m_afFlowDirection[0]);
    rkStream.Write(m_afFlowDirection[1]);
    rkStream.Write(m_afPowerFactor[0]);

    WM4_END_DEBUG_STREAM_SAVE(BlendedTerrainEffect);
}
//----------------------------------------------------------------------------
int BlendedTerrainEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        sizeof(m_afFlowDirection[0]) +
        sizeof(m_afFlowDirection[1]) +
        sizeof(m_afPowerFactor[0]);
}
//----------------------------------------------------------------------------
StringTree* BlendedTerrainEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    Vector2f kFlowDirection(m_afFlowDirection[0],m_afFlowDirection[1]);
    pkTree->Append(Format("flow direction =",kFlowDirection));
    pkTree->Append(Format("power factor =",m_afPowerFactor[0]));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
