// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic4License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline IVector2::IVector2 ()
{
    // the vector is uninitialized
}
//----------------------------------------------------------------------------
inline IVector2::IVector2 (const IVector2& rkV)
{
    m_aiTuple[0] = rkV.m_aiTuple[0];
    m_aiTuple[1] = rkV.m_aiTuple[1];
}
//----------------------------------------------------------------------------
inline IVector2::IVector2 (const TIVector<2>& rkV)
{
    m_aiTuple[0] = rkV[0];
    m_aiTuple[1] = rkV[1];
}
//----------------------------------------------------------------------------
inline IVector2::IVector2 (const Integer64& riX, const Integer64& riY)
{
    m_aiTuple[0] = riX;
    m_aiTuple[1] = riY;
}
//----------------------------------------------------------------------------
inline IVector2& IVector2::operator= (const IVector2& rkV)
{
    m_aiTuple[0] = rkV.m_aiTuple[0];
    m_aiTuple[1] = rkV.m_aiTuple[1];
    return *this;
}
//----------------------------------------------------------------------------
inline IVector2& IVector2::operator= (const TIVector<2>& rkV)
{
    m_aiTuple[0] = rkV[0];
    m_aiTuple[1] = rkV[1];
    return *this;
}
//----------------------------------------------------------------------------
inline Integer64 IVector2::X () const
{
    return m_aiTuple[0];
}
//----------------------------------------------------------------------------
inline Integer64& IVector2::X ()
{
    return m_aiTuple[0];
}
//----------------------------------------------------------------------------
inline Integer64 IVector2::Y () const
{
    return m_aiTuple[1];
}
//----------------------------------------------------------------------------
inline Integer64& IVector2::Y ()
{
    return m_aiTuple[1];
}
//----------------------------------------------------------------------------
inline Integer64 IVector2::Dot (const IVector2& rkV) const
{
    return m_aiTuple[0]*rkV.m_aiTuple[0] + m_aiTuple[1]*rkV.m_aiTuple[1];
}
//----------------------------------------------------------------------------
inline IVector2 IVector2::Perp () const
{
    return IVector2(m_aiTuple[1],-m_aiTuple[0]);
}
//----------------------------------------------------------------------------
inline Integer64 IVector2::DotPerp (const IVector2& rkV) const
{
    return m_aiTuple[0]*rkV.m_aiTuple[1] - m_aiTuple[1]*rkV.m_aiTuple[0];
}
//----------------------------------------------------------------------------
