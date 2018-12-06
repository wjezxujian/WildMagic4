// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
template <int ISIZE>
RVector2<ISIZE>::RVector2 ()
{
    // the vector is uninitialized
}
//----------------------------------------------------------------------------
template <int ISIZE>
RVector2<ISIZE>::RVector2 (const RVector2& rkV)
{
    m_akTuple[0] = rkV.m_akTuple[0];
    m_akTuple[1] = rkV.m_akTuple[1];
}
//----------------------------------------------------------------------------
#ifndef WM4_USING_VC70
template <int ISIZE>
RVector2<ISIZE>::RVector2 (const TRVector<2,ISIZE>& rkV)
{
    m_akTuple[0] = rkV[0];
    m_akTuple[1] = rkV[1];
}
#endif
//----------------------------------------------------------------------------
template <int ISIZE>
RVector2<ISIZE>::RVector2 (const TRational<ISIZE>& rkX,
    const TRational<ISIZE>& rkY)
{
    m_akTuple[0] = rkX;
    m_akTuple[1] = rkY;
}
//----------------------------------------------------------------------------
template <int ISIZE>
RVector2<ISIZE>& RVector2<ISIZE>::operator= (const RVector2& rkV)
{
    m_akTuple[0] = rkV.m_akTuple[0];
    m_akTuple[1] = rkV.m_akTuple[1];
    return *this;
}
//----------------------------------------------------------------------------
#ifndef WM4_USING_VC70
template <int ISIZE>
RVector2<ISIZE>& RVector2<ISIZE>::operator= (const TRVector<2,ISIZE>& rkV)
{
    m_akTuple[0] = rkV[0];
    m_akTuple[1] = rkV[1];
    return *this;
}
#endif
//----------------------------------------------------------------------------
template <int ISIZE>
TRational<ISIZE> RVector2<ISIZE>::X () const
{
    return m_akTuple[0];
}
//----------------------------------------------------------------------------
template <int ISIZE>
TRational<ISIZE>& RVector2<ISIZE>::X ()
{
    return m_akTuple[0];
}
//----------------------------------------------------------------------------
template <int ISIZE>
TRational<ISIZE> RVector2<ISIZE>::Y () const
{
    return m_akTuple[1];
}
//----------------------------------------------------------------------------
template <int ISIZE>
TRational<ISIZE>& RVector2<ISIZE>::Y ()
{
    return m_akTuple[1];
}
//----------------------------------------------------------------------------
template <int ISIZE>
TRational<ISIZE> RVector2<ISIZE>::Dot (const RVector2& rkV) const
{
    return m_akTuple[0]*rkV.m_akTuple[0] + m_akTuple[1]*rkV.m_akTuple[1];
}
//----------------------------------------------------------------------------
template <int ISIZE>
RVector2<ISIZE> RVector2<ISIZE>::Perp () const
{
    return RVector2<ISIZE>(m_akTuple[1],-m_akTuple[0]);
}
//----------------------------------------------------------------------------
template <int ISIZE>
TRational<ISIZE> RVector2<ISIZE>::DotPerp (const RVector2& rkV) const
{
    return m_akTuple[0]*rkV.m_akTuple[1] - m_akTuple[1]*rkV.m_akTuple[0];
}
//----------------------------------------------------------------------------
