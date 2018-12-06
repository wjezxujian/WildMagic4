// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SIMPLESEGMENT_H
#define SIMPLESEGMENT_H

#include "Wm4CurveSegment.h"

namespace Wm4
{

class SimpleSegment : public CurveSegment
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    SimpleSegment ();
    virtual ~SimpleSegment ();

    float Amplitude, Frequency, Height;

    // position and derivatives up to third order
    virtual Vector3f P (float fU) const;
    virtual Vector3f PU (float fU) const;
    virtual Vector3f PUU (float fU) const;
    virtual Vector3f PUUU (float fU) const;
};

WM4_REGISTER_STREAM(SimpleSegment);
typedef Pointer<SimpleSegment> SimpleSegmentPtr;

}

#endif
