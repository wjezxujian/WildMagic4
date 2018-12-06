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
inline void SkinningEffect::SetMatrix (int i, const Matrix4f& rkMatrix)
{
    assert(0 <= i && i < 4);
    m_akMatrix[i] = rkMatrix;
}
//----------------------------------------------------------------------------
inline const Matrix4f& SkinningEffect::GetMatrix (int i) const
{
    assert(0 <= i && i < 4);
    return m_akMatrix[i];
}
//----------------------------------------------------------------------------
