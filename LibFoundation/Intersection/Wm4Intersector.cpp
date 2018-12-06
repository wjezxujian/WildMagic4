// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4FoundationPCH.h"
#include "Wm4Intersector.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real, class TVector>
Intersector<Real,TVector>::Intersector ()
{
    m_fContactTime = (Real)0.0;
    m_iIntersectionType = IT_EMPTY;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Intersector<Real,TVector>::~Intersector ()
{
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
Real Intersector<Real,TVector>::GetContactTime () const
{
    return m_fContactTime;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
int Intersector<Real,TVector>::GetIntersectionType () const
{
    return m_iIntersectionType;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
bool Intersector<Real,TVector>::Test ()
{
    // stub for derived class
    assert(false);
    return false;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
bool Intersector<Real,TVector>::Find ()
{
    // stub for derived class
    assert(false);
    return false;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
bool Intersector<Real,TVector>::Test (Real, const TVector&, const TVector&)
{
    // stub for derived class
    assert(false);
    return false;
}
//----------------------------------------------------------------------------
template <class Real, class TVector>
bool Intersector<Real,TVector>::Find (Real, const TVector&, const TVector&)
{
    // stub for derived class
    assert(false);
    return false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class Intersector<float,Vector2f>;

template WM4_FOUNDATION_ITEM
class Intersector<float,Vector3f>;

template WM4_FOUNDATION_ITEM
class Intersector<double,Vector2d>;

template WM4_FOUNDATION_ITEM
class Intersector<double,Vector3d>;
//----------------------------------------------------------------------------
}
