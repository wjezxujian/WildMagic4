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
inline bool Transformation::IsIdentity () const
{
    return m_bIsIdentity;
}
//----------------------------------------------------------------------------
inline bool Transformation::IsRSMatrix () const
{
    return m_bIsRSMatrix;
}
//----------------------------------------------------------------------------
inline bool Transformation::IsUniformScale () const
{
    return m_bIsRSMatrix && m_bIsUniformScale;
}
//----------------------------------------------------------------------------
inline const Matrix3f& Transformation::GetRotate () const
{
    assert(m_bIsRSMatrix);
    return m_kMatrix;
}
//----------------------------------------------------------------------------
inline const Matrix3f& Transformation::GetMatrix () const
{
    return m_kMatrix;
}
//----------------------------------------------------------------------------
inline const Vector3f& Transformation::GetTranslate () const
{
    return m_kTranslate;
}
//----------------------------------------------------------------------------
inline const Vector3f& Transformation::GetScale () const
{
    assert(m_bIsRSMatrix);
    return m_kScale;
}
//----------------------------------------------------------------------------
inline float Transformation::GetUniformScale () const
{
    assert(m_bIsRSMatrix && m_bIsUniformScale);
    return m_kScale.X();
}
//----------------------------------------------------------------------------
