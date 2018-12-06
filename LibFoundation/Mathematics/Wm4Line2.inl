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
Line2<Real>::Line2 ()
{
    // uninitialized
}
//----------------------------------------------------------------------------
template <class Real>
Line2<Real>::Line2 (const Vector2<Real>& rkOrigin,
    const Vector2<Real>& rkDirection)
    :
    Origin(rkOrigin),
    Direction(rkDirection)
{
}
//----------------------------------------------------------------------------
