// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TSET_H
#define WM4TSET_H

#include "Wm4FoundationLIB.h"
#include "Wm4Memory.h"

// This template class is for unordered sets of objects.  The intent is that
// the sets are not too large.  If you do not plan on searching the set and
// you know that the elements to be added are unique, then the size of the
// set is irrelevant since a member function is provided that inserts an
// element without checking to see if one already exists.
//
// The class T is either native data or is class data that has the following
// member functions:
//   T::T ()
//   T::T (const T&);
//   T& T::operator= (const T&)

namespace Wm4
{

template <class T>
class TSmallUnorderedSet
{
public:
    // construction and destruction
    TSmallUnorderedSet ();
    TSmallUnorderedSet (int iMaxQuantity, int iGrowBy);
    TSmallUnorderedSet (const TSmallUnorderedSet& rkSet);
    ~TSmallUnorderedSet ();

    // assignment
    TSmallUnorderedSet& operator= (const TSmallUnorderedSet& rkSet);

    // member access
    int GetMaxQuantity () const;
    int GetGrowBy () const;
    int GetQuantity () const;
    T* GetElements ();
    const T* GetElements () const;
    T& operator[] (int i);
    const T& operator[] (int i) const;

    // insertion, removal, searching
    bool Insert (const T& rkElement);
    void InsertNoCheck (const T& rkElement);
    bool Remove (const T& rkElement);
    bool Exists (const T& rkElement);

    // make empty set, keep quantity and growth parameters
    void Clear ();

    // make empty set, reallocate using new quantity and growth parameters
    void Clear (int iMaxQuantity, int iGrowBy);

private:
    int m_iQuantity, m_iMaxQuantity, m_iGrowBy;
    T* m_atElement;
};

#include "Wm4TSmallUnorderedSet.inl"

}

#endif
