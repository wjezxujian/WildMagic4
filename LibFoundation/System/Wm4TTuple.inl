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
template <int DIMENSION, class TYPE>
TTuple<DIMENSION,TYPE>::TTuple ()
{
    // Uninitialized for native data.  Initialized for class data as long as
    // TYPE's default constructor initializes its own data.
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TTuple<DIMENSION,TYPE>::~TTuple ()
{
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TTuple<DIMENSION,TYPE>::TTuple (const TTuple& rkT)
{
    for (int i = 0; i < DIMENSION; i++)
    {
        m_atTuple[i] = rkT.m_atTuple[i];
    }
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TTuple<DIMENSION,TYPE>::operator const TYPE* () const
{
    return m_atTuple;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TTuple<DIMENSION,TYPE>::operator TYPE* ()
{
    return m_atTuple;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TYPE TTuple<DIMENSION,TYPE>::operator[] (int i) const
{
    assert(0 <= i && i < DIMENSION);
    return m_atTuple[i];
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TYPE& TTuple<DIMENSION,TYPE>::operator[] (int i)
{
    assert(0 <= i && i < DIMENSION);
    return m_atTuple[i];
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
TTuple<DIMENSION,TYPE>& TTuple<DIMENSION,TYPE>::operator= (const TTuple& rkT)
{
    for (int i = 0; i < DIMENSION; i++)
    {
        m_atTuple[i] = rkT.m_atTuple[i];
    }
    return *this;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
bool TTuple<DIMENSION,TYPE>::operator== (const TTuple& rkT) const
{
    const size_t uiSize = DIMENSION*sizeof(TYPE);
    return memcmp(m_atTuple,rkT.m_atTuple,uiSize) == 0;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
bool TTuple<DIMENSION,TYPE>::operator!= (const TTuple& rkT) const
{
    const size_t uiSize = DIMENSION*sizeof(TYPE);
    return memcmp(m_atTuple,rkT.m_atTuple,uiSize) != 0;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
bool TTuple<DIMENSION,TYPE>::operator< (const TTuple& rkT) const
{
    const size_t uiSize = DIMENSION*sizeof(TYPE);
    return memcmp(m_atTuple,rkT.m_atTuple,uiSize) < 0;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
bool TTuple<DIMENSION,TYPE>::operator<= (const TTuple& rkT) const
{
    const size_t uiSize = DIMENSION*sizeof(TYPE);
    return memcmp(m_atTuple,rkT.m_atTuple,uiSize) <= 0;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
bool TTuple<DIMENSION,TYPE>::operator> (const TTuple& rkT) const
{
    const size_t uiSize = DIMENSION*sizeof(TYPE);
    return memcmp(m_atTuple,rkT.m_atTuple,uiSize) > 0;
}
//----------------------------------------------------------------------------
template <int DIMENSION, class TYPE>
bool TTuple<DIMENSION,TYPE>::operator>= (const TTuple& rkT) const
{
    const size_t uiSize = DIMENSION*sizeof(TYPE);
    return memcmp(m_atTuple,rkT.m_atTuple,uiSize) >= 0;
}
//----------------------------------------------------------------------------
