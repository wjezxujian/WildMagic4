// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4INDEXBUFFER_H
#define WM4INDEXBUFFER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4Bindable.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM IndexBuffer : public Object, public Bindable
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    IndexBuffer (int iIQuantity);
    IndexBuffer (const IndexBuffer* pkIBuffer);
    virtual ~IndexBuffer ();

    // Access to indices.
    int operator[] (int i) const;
    int& operator[] (int i);

    // Direct access to the index buffer data.  The quantity is the number of
    // int elements.  The number of bytes for the entire index buffer is
    // GetIndexQuantity()*sizeof(int).
    int GetIndexQuantity () const;
    int* GetData ();
    const int* GetData () const;

    // An application might want to vary the "active quantity" of indices.
    // Use this function to do so.  It does not change the data storage,
    // only the m_iQuantity member.  The caller is responsible for saving the
    // full quantity of indices and resetting this when finished with the
    // index buffer.  The caller also should not pass in a quantity that is
    // larger than the original full quantity.
    void SetIndexQuantity (int iIQuantity);

protected:
    // streaming support
    IndexBuffer ();

    int m_iIQuantity;
    int* m_aiIndex;
};

WM4_REGISTER_STREAM(IndexBuffer);
typedef Pointer<IndexBuffer> IndexBufferPtr;
#include "Wm4IndexBuffer.inl"

}

#endif
