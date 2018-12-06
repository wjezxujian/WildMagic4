// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SOFTARRAY_H
#define WM4SOFTARRAY_H

#include "Wm4SoftRendererLIB.h"
#include "Wm4System.h"

namespace Wm4
{

template <typename Type>
class SoftArray
{
public:
    SoftArray (int iMaxQuantity);
    SoftArray (const SoftArray& rkObject);
    ~SoftArray ();

    SoftArray& operator= (const SoftArray& rkObject);

    int GetQuantity () const;
    int GetMaxQuantity () const;
    Type* GetData ();
    const Type* GetData () const;

    void EnsureCapacity (int iRequestedMaxQuantity);
    void Clear ();
    void Append (Type tValue);
    Type Get (int i) const;

private:
    int m_iQuantity, m_iMaxQuantity;
    Type* m_atData;
};

#include "Wm4SoftArray.inl"

}

#endif
