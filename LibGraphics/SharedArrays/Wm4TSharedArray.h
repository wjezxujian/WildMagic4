// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TSHAREDARRAY_H
#define WM4TSHAREDARRAY_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"

namespace Wm4
{

template <class T>
class TSharedArray : public Object
{
    WM4_DECLARE_TEMPLATE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_TEMPLATE_STREAM;

public:
    TSharedArray (int iQuantity = 0, T* atArray = 0);
    TSharedArray (const TSharedArray& rkShared);
    virtual ~TSharedArray ();

    TSharedArray& operator= (const TSharedArray& rkShared);

    int GetQuantity () const;
    T* GetData () const;
    operator const T* () const;
    operator T* ();
    const T& operator[] (int i) const;
    T& operator[] (int i);

    // This will not cause a reallocation of the array.  The idea is to
    // allow only some of the data to be considered valid.  The caller is
    // responsible for remembering the total quantity that was passed to the
    // constructor.
    void SetActiveQuantity (int iActiveQuantity);

protected:
    int m_iQuantity;
    T* m_atArray;
};

#include "Wm4TSharedArray.inl"

}

#endif
