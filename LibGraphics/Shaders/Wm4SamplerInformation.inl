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
inline const std::string& SamplerInformation::GetName () const
{
    return m_kName;
}
//----------------------------------------------------------------------------
inline SamplerInformation::Type SamplerInformation::GetType () const
{
    return m_eType;
}
//----------------------------------------------------------------------------
inline int SamplerInformation::GetTextureUnit () const
{
    return m_iTextureUnit;
}
//----------------------------------------------------------------------------
inline int SamplerInformation::GetDimension () const
{
    return m_iDimension;
}
//----------------------------------------------------------------------------
