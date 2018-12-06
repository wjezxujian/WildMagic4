// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline int SoftRenderer::GetType () const
{
    return Renderer::SOFTWARE;
}
//----------------------------------------------------------------------------
inline const char* SoftRenderer::GetExtension () const
{
    return "sft";
}
//----------------------------------------------------------------------------
inline char SoftRenderer::GetCommentCharacter () const
{
    return '/';
}
//----------------------------------------------------------------------------
inline float* SoftRenderer::GetOutputVertex (int i)
{
    return &m_kOutputVertex.GetData()[m_iNumOutputChannels*i];
}
//----------------------------------------------------------------------------
