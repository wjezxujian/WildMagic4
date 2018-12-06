// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

// Bit hacks are available at
//     http://graphics.stanford.edu/~seander/bithacks.html

#ifndef WM4BITHACKS_H
#define WM4BITHACKS_H

namespace Wm4
{

bool IsPowerOfTwo (int iValue);
unsigned int Log2OfPowerOfTwo (unsigned int uiPowerOfTwo);

#include "Wm4BitHacks.inl"

}

#endif
