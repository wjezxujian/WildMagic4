// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
template <class Real>
Cylinder3<Real>::Cylinder3 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Cylinder3<Real>::Cylinder3 (const Segment3<Real>& rkSegment, Real fHeight,
    Real fRadius)
    :
    Segment(rkSegment)
{
    Height = fHeight;
    Radius = fRadius;
}
//----------------------------------------------------------------------------
