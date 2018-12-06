// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SkinningEffect.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,SkinningEffect,ShaderEffect);
WM4_IMPLEMENT_STREAM(SkinningEffect);
WM4_IMPLEMENT_DEFAULT_NAME_ID(SkinningEffect,ShaderEffect);

//----------------------------------------------------------------------------
SkinningEffect::SkinningEffect ()
    :
    ShaderEffect(1)
{
    m_kVShader[0] = WM4_NEW VertexShader("Skinning");
    m_kPShader[0] = WM4_NEW PixelShader("PassThrough3");

    for (int i = 0; i < 4; i++)
    {
        m_akMatrix[i] = Matrix4f::IDENTITY;
    }
}
//----------------------------------------------------------------------------
SkinningEffect::~SkinningEffect ()
{
}
//----------------------------------------------------------------------------
void SkinningEffect::OnLoadPrograms (int, Program* pkVProgram, Program*)
{
    pkVProgram->GetUC("SkinningMatrix0")->SetDataSource(
        (float*)m_akMatrix[0]);

    pkVProgram->GetUC("SkinningMatrix1")->SetDataSource(
        (float*)m_akMatrix[1]);

    pkVProgram->GetUC("SkinningMatrix2")->SetDataSource(
        (float*)m_akMatrix[2]);

    pkVProgram->GetUC("SkinningMatrix3")->SetDataSource(
        (float*)m_akMatrix[3]);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void SkinningEffect::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    ShaderEffect::Load(rkStream,pkLink);

    // native data
    for (int i = 0; i < 4; i++)
    {
        rkStream.Read(m_akMatrix[i]);
    }

    WM4_END_DEBUG_STREAM_LOAD(SkinningEffect);
}
//----------------------------------------------------------------------------
void SkinningEffect::Link (Stream& rkStream, Stream::Link* pkLink)
{
    ShaderEffect::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool SkinningEffect::Register (Stream& rkStream) const
{
    return ShaderEffect::Register(rkStream);
}
//----------------------------------------------------------------------------
void SkinningEffect::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    ShaderEffect::Save(rkStream);

    // native data
    for (int i = 0; i < 4; i++)
    {
        rkStream.Write(m_akMatrix[i]);
    }

    WM4_END_DEBUG_STREAM_SAVE(SkinningEffect);
}
//----------------------------------------------------------------------------
int SkinningEffect::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return ShaderEffect::GetDiskUsed(rkVersion) +
        4*sizeof(m_akMatrix[0]);
}
//----------------------------------------------------------------------------
StringTree* SkinningEffect::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));

    const size_t uiTitleSize = 16;
    char acTitle[uiTitleSize];
    for (int i = 0; i < 4; i++)
    {
        System::Sprintf(acTitle,uiTitleSize,"matrix[%d] =",i);
        pkTree->Append(Format(acTitle,m_akMatrix[i]));
    }

    // children
    pkTree->Append(ShaderEffect::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
