// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VERTEXBUFFER_H
#define WM4VERTEXBUFFER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4Attributes.h"
#include "Wm4Bindable.h"
#include "Wm4ColorRGB.h"
#include "Wm4ColorRGBA.h"
#include "Wm4Vector2.h"
#include "Wm4Vector3.h"
#include "Wm4Vector4.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM VertexBuffer : public Object, public Bindable
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    VertexBuffer (const Attributes& rkAttributes, int iVertexQuantity);
    VertexBuffer (const VertexBuffer* pkVBuffer);
    virtual ~VertexBuffer ();

    // The format of a single vertex in the buffer.
    const Attributes& GetAttributes () const;

    // The size of a single vertex in the buffer, measured as number of
    // 'float' values.  The number of bytes for a single vertex is
    // GetVertexSize()*sizeof(float).
    int GetVertexSize () const;

    // The number of vertices in the buffer.
    int GetVertexQuantity () const;

    // Access to positions.
    float* PositionTuple (int i);
    const float* PositionTuple (int i) const;

    // Access to normals.
    float* NormalTuple (int i);
    const float* NormalTuple (int i) const;

    // Access to colors.
    float* ColorTuple (int iUnit, int i);
    const float* ColorTuple (int iUnit, int i) const;

    // Access to texture coordinates.
    float* TCoordTuple (int iUnit, int i);
    const float* TCoordTuple (int iUnit, int i) const;

    // Direct access to the vertex buffer data.  The quantity is the number of
    // float elements.  The number of bytes for the entire vertex buffer is
    // GetChannelQuantity()*sizeof(float).
    int GetChannelQuantity () const;
    float* GetData ();
    const float* GetData () const;

    // Use these accessors for convenience.  No range checking is performed,
    // so you should be sure that the attribute exists and that the number of
    // channels is correct.
    Vector3f& Position3 (int i);
    Vector3f Position3 (int i) const;
    Vector3f& Normal3 (int i);
    Vector3f Normal3 (int i) const;
    ColorRGB& Color3 (int iUnit, int i);
    ColorRGB Color3 (int iUnit, int i) const;
    ColorRGBA& Color4 (int iUnit, int i);
    ColorRGBA Color4 (int iUnit, int i) const;
    float& TCoord1 (int iUnit, int i);
    float TCoord1 (int iUnit, int i) const;
    Vector2f& TCoord2 (int iUnit, int i);
    Vector2f TCoord2 (int iUnit, int i) const;
    Vector3f& TCoord3 (int iUnit, int i);
    Vector3f TCoord3 (int iUnit, int i) const;
    Vector4f& TCoord4 (int iUnit, int i);
    Vector4f TCoord4 (int iUnit, int i) const;

    // Support for building an array from the vertex buffer data, but
    // compatible with the vertex program inputs.  The output array,
    // rafCompatible, if null on input is dynamically allocated.  The caller
    // is responsible for deleting it.  You may pass in an already allocated
    // array as long as you are certain it has enough channels to store the
    // data.
    //
    // TO DO.  The bPackARGB flag exists for DirectX because of its need
    // to have ARGB (8-bit channels) rather than floats in [0,1] like OpenGL
    // prefers.  Set bPackARGB to 'true' for DirectX and to 'false' for the
    // OpenGL and software renderers.  If we need other formats later, this
    // parameter must be expanded to include the new possibilities.
    void BuildCompatibleArray (const Attributes& rkIAttr, bool bPackARGB,
        int& riChannels, float*& rafCompatible) const;

    // An application might want to vary the "active quantity" of vertices.
    // Use this function to do so.  It does not change the data storage,
    // only the m_iVertexQuantity member.  The caller is responsible for
    // saving the full quantity of vertices and resetting this when finished
    // with the vertex buffer.  The caller also should not pass in a quantity
    // that is larger than the original full quantity.
    void SetVertexQuantity (int iVQuantity);

private:
    // streaming support
    VertexBuffer ();

    // The format of a single vertex in the buffer.
    Attributes m_kAttributes;

    // The size of a single vertex in the buffer.
    int m_iVertexSize;

    // The number of vertices in the buffer.
    int m_iVertexQuantity;

    // The vertex buffer data.
    int m_iChannelQuantity;  // = m_iVertexQuantity*m_iVertexSize
    float* m_afChannel;
};

WM4_REGISTER_STREAM(VertexBuffer);
typedef Pointer<VertexBuffer> VertexBufferPtr;
#include "Wm4VertexBuffer.inl"

}

#endif
