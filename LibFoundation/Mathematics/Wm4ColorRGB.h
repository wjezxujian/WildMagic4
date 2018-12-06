// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4COLORRGB_H
#define WM4COLORRGB_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_FOUNDATION_ITEM ColorRGB
{
public:
    // Construction.  The components are intended to be in the interval [0,1].
    // For accessing of colors by array index, the map is 0 = red, 1 = green,
    // and 2 = blue.
    ColorRGB ();  // initial values (0,0,0)
    ColorRGB (float fR, float fG, float fB);
    ColorRGB (const float* afTuple);
    ColorRGB (const ColorRGB& rkC);

    // member access
    operator const float* () const;
    operator float* ();
    float operator[] (int i) const;
    float& operator[] (int i);
    float R () const;
    float& R ();
    float G () const;
    float& G ();
    float B () const;
    float& B ();

    // assignment
    ColorRGB& operator= (const ColorRGB& rkC);

    // comparison
    bool operator== (const ColorRGB& rkC) const;
    bool operator!= (const ColorRGB& rkC) const;
    bool operator<  (const ColorRGB& rkC) const;
    bool operator<= (const ColorRGB& rkC) const;
    bool operator>  (const ColorRGB& rkC) const;
    bool operator>= (const ColorRGB& rkC) const;

    // arithmetic operations
    ColorRGB operator+ (const ColorRGB& rkC) const;
    ColorRGB operator- (const ColorRGB& rkC) const;
    ColorRGB operator* (const ColorRGB& rkC) const;
    ColorRGB operator* (float fScalar) const;
    WM4_FOUNDATION_ITEM friend ColorRGB operator* (float fScalar,
        const ColorRGB& rkC);

    // arithmetic updates
    ColorRGB& operator+= (const ColorRGB& rkC);
    ColorRGB& operator-= (const ColorRGB& rkC);
    ColorRGB& operator*= (const ColorRGB& rkC);
    ColorRGB& operator*= (float fScalar);

    // Transform the color channels to [0,1].  Clamp sets negative values to
    // zero and values larger than one to one.  ScaleByMax assumes the color
    // channels are nonnegative, finds the maximum color channel, and divides
    // all channels by that value.
    void Clamp ();
    void ScaleByMax ();

    static const ColorRGB BLACK;    // = (0,0,0) 
    static const ColorRGB WHITE;    // = (1,1,1)
    static const ColorRGB INVALID;  // = (-1,-1,-1)

private:
    // support for comparisons
    int CompareArrays (const ColorRGB& rkC) const;

    float m_afTuple[3];
};

#include "Wm4ColorRGB.inl"

}

#endif
