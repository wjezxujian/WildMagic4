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
inline const std::string& Shader::GetShaderName () const
{
    return m_kShaderName;
}
//----------------------------------------------------------------------------
inline int Shader::GetTextureQuantity () const
{
    return (int)m_kTextures.size();
}
//----------------------------------------------------------------------------
