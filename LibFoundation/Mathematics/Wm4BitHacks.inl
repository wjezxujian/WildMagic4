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
inline bool IsPowerOfTwo (unsigned int uiValue)
{
    return (uiValue > 0) && ((uiValue & (uiValue - 1)) == 0);
}
//----------------------------------------------------------------------------
inline unsigned int Log2OfPowerOfTwo (unsigned int uiPowerOfTwo)
{
    unsigned int uiLog2 = (uiPowerOfTwo & 0xAAAAAAAA) != 0;
    uiLog2 |= ((uiPowerOfTwo & 0xFFFF0000) != 0) << 4;
    uiLog2 |= ((uiPowerOfTwo & 0xFF00FF00) != 0) << 3;
    uiLog2 |= ((uiPowerOfTwo & 0xF0F0F0F0) != 0) << 2;
    uiLog2 |= ((uiPowerOfTwo & 0xCCCCCCCC) != 0) << 1;
    return uiLog2;
}
//----------------------------------------------------------------------------
