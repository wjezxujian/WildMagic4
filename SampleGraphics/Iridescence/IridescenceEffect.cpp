// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "IridescenceEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,IridescenceEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(IridescenceEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(IridescenceEffect,ShaderEffect);

//----------------------------------------------------------------------------
IridescenceEffect::IridescenceEffect (const char* acBaseName,
    const char* acGradName)
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Iridescence");
    m_kPShader[0] = WM4_NEW PixelShader("Iridescence");

    m_kPShader[0]->SetTextureQuantity(2);
    m_kPShader[0]->SetImageName(0,acBaseName);
    m_kPShader[0]->SetImageName(1,acGradName);

    Texture* pkBase = m_kPShader[0]->GetTexture(0);
    pkBase->SetFilterType(Texture::LINEAR);
    pkBase->SetWrapType(0,Texture::REPEAT);
    pkBase->SetWrapType(1,Texture::REPEAT);

    Texture* pkGrad = m_kPShader[0]->GetTexture(1);
    pkGrad->SetFilterType(Texture::LINEAR);
}
//----------------------------------------------------------------------------
IridescenceEffect::IridescenceEffect ()
{
}
//----------------------------------------------------------------------------
IridescenceEffect::~IridescenceEffect ()
{
}
//----------------------------------------------------------------------------
void IridescenceEffect::OnLoadPrograms (int, Program* pkVProgram, Program*)
{
    // vertex program processing
    pkVProgram->GetUC("InterpolateFactor")->SetDataSource(m_afInterpolate);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void IridescenceEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    rkStream.Read(m_afInterpolate[0]);

    WM4_END_DEBUG_STREAM_LOAD(IridescenceEffect);
}
//----------------------------------------------------------------------------
void IridescenceEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool IridescenceEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void IridescenceEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    rkStream.Write(m_afInterpolate[0]);

    WM4_END_DEBUG_STREAM_SAVE(IridescenceEffect);
}
//----------------------------------------------------------------------------
int IridescenceEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        sizeof(m_afInterpolate[0]);
}
//----------------------------------------------------------------------------
StringTree* IridescenceEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("interpolation factor =",m_afInterpolate[0]));

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
