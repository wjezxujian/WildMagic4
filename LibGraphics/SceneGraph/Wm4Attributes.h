// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4ATTRIBUTES_H
#define WM4ATTRIBUTES_H

#include "Wm4GraphicsLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Attributes
{
public:
    Attributes ();
    ~Attributes ();

    // Set the attributes you want.  The currently supported attributes are
    //    p  = position
    //         3 or 4 channels (xyz,xyzw)
    //    n  = normal vector
    //         3 or 4 channels (xyz,xyzw)
    //    ci = color
    //         1 to 4 channels (r,rg,rgb,rgba)
    //    ti = texture coordinate
    //         1 to 4 channels (s,st,str,strq)
    // The attrbitues are organized internally to have the ordering:
    // p, n, c0, c1, ..., t0, t1, ...

    void SetPChannels (int iPChannels);
    void SetNChannels (int iNChannels);
    void SetCChannels (int iUnit, int iCChannels);
    void SetTChannels (int iUnit, int iTChannels);

    // The number of 'float' channels used by all the attributes.
    int GetChannelQuantity () const;

    // Access to position information.
    int GetPOffset () const;
    int GetPChannels () const;
    bool HasPosition () const;

    // Access to normal information.
    int GetNOffset () const;
    int GetNChannels () const;
    bool HasNormal () const;

    // Access to color information.
    int GetMaxColors () const;
    int GetCOffset (int iUnit) const;
    int GetCChannels (int iUnit) const;
    bool HasColor (int iUnit) const;

    // Access to texture coordinate information.
    int GetMaxTCoords () const;
    int GetTOffset (int iUnit) const;
    int GetTChannels (int iUnit) const;
    bool HasTCoord (int iUnit) const;

    // Support for comparing vertex program outputs with pixel program inputs.
    bool Matches (const Attributes& rkAttr, bool bIncludeP, bool bIncludeN,
        bool bIncludeC, bool bIncludeT) const;

    // Support for comparing vertex buffer attributes with vertex program
    // input attributes.
    bool operator== (const Attributes& rkAttr) const;
    bool operator!= (const Attributes& rkAttr) const;

private:
    void UpdateOffsets ();

    // The number of 'float' channels used by all attributes.
    int m_iChannelQuantity;

    // positions
    int m_iPOffset;
    int m_iPChannels;

    // normals
    int m_iNOffset;
    int m_iNChannels;

    // colors
    std::vector<int> m_kCOffset;
    std::vector<int> m_kCChannels;

    // texture coordinates
    std::vector<int> m_kTOffset;
    std::vector<int> m_kTChannels;
};

#include "Wm4Attributes.inl"

}

#endif
