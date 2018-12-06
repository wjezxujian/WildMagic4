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
template <typename Type>
SoftArray<Type>::SoftArray (int iMaxQuantity)
{
    assert(iMaxQuantity > 0);
    if (iMaxQuantity <= 0)
    {
        iMaxQuantity = 1;
    }

    m_iQuantity = 0;
    m_iMaxQuantity = iMaxQuantity;
    m_atData = WM4_NEW Type[m_iMaxQuantity];
}
//----------------------------------------------------------------------------
template <typename Type>
SoftArray<Type>::SoftArray (const SoftArray& rkObject)
{
    m_atData = 0;
    *this = rkObject;
}
//----------------------------------------------------------------------------
template <typename Type>
SoftArray<Type>::~SoftArray ()
{
    WM4_DELETE[] m_atData;
}
//----------------------------------------------------------------------------
template <typename Type>
SoftArray<Type>& SoftArray<Type>::operator= (const SoftArray& rkObject)
{
    m_iQuantity = rkObject.m_iQuantity;
    m_iMaxQuantity = rkObject.m_iMaxQuantity;

    WM4_DELETE[] m_atData;
    if (m_iMaxQuantity > 0)
    {
        const size_t uiSize = m_iMaxQuantity*sizeof(Type);
        m_atData = WM4_NEW Type[m_iMaxQuantity];
        System::Memcpy(m_atData,uiSize,rkObject.m_atData,uiSize);
    }
    else
    {
        m_atData = 0;
    }

    return *this;
}
//----------------------------------------------------------------------------
template <typename Type>
int SoftArray<Type>::GetQuantity () const
{
    return m_iQuantity;
}
//----------------------------------------------------------------------------
template <typename Type>
int SoftArray<Type>::GetMaxQuantity () const
{
    return m_iMaxQuantity;
}
//----------------------------------------------------------------------------
template <typename Type>
Type* SoftArray<Type>::GetData ()
{
    return m_atData;
}
//----------------------------------------------------------------------------
template <typename Type>
const Type* SoftArray<Type>::GetData () const
{
    return m_atData;
}
//----------------------------------------------------------------------------
template <typename Type>
void SoftArray<Type>::EnsureCapacity (int iRequestedMaxQuantity)
{
    if (iRequestedMaxQuantity > m_iMaxQuantity)
    {
        const size_t uiOldSize = m_iMaxQuantity*sizeof(Type);
        const size_t uiNewSize = iRequestedMaxQuantity*sizeof(Type);
        Type* atNewArray = WM4_NEW Type[iRequestedMaxQuantity];
        System::Memcpy(atNewArray,uiNewSize,m_atData,uiOldSize);
        WM4_DELETE[] m_atData;
        m_atData = atNewArray;
        m_iMaxQuantity = iRequestedMaxQuantity;
    }
}
//----------------------------------------------------------------------------
template <typename Type>
void SoftArray<Type>::Clear ()
{
    m_iQuantity = 0;
}
//----------------------------------------------------------------------------
template <typename Type>
void SoftArray<Type>::Append (Type tValue)
{
    int i = m_iQuantity++;
    assert(m_iQuantity <= m_iMaxQuantity);
    m_atData[i] = tValue;
}
//----------------------------------------------------------------------------
template <typename Type>
Type SoftArray<Type>::Get (int i) const
{
    assert(0 <= i && i < m_iMaxQuantity);
    return m_atData[i];
}
//----------------------------------------------------------------------------
