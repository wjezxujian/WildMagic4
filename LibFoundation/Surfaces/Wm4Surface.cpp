// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4FoundationPCH.h"
#include "Wm4Surface.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
Surface<Real>::Surface ()
{
}
//----------------------------------------------------------------------------
template <class Real>
Surface<Real>::~Surface ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class Surface<float>;

template WM4_FOUNDATION_ITEM
class Surface<double>;
//----------------------------------------------------------------------------
}
