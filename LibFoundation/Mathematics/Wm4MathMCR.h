// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MATHMCR_H
#define WM4MATHMCR_H

//----------------------------------------------------------------------------

// Fast conversion from a IEEE 32-bit floating point number F in [0,1] to a
// a 32-bit integer I in [0,2^L-1].
//
//   fFloat = F
//   iLog = L
//   iInt = I

#define WM4_SCALED_FLOAT_TO_INT(fFloat,iLog,iInt)\
{ \
    int iShift = 150 - iLog - ((*(int*)(&fFloat) >> 23) & 0xFF); \
    if ( iShift < 24 ) \
    { \
        iInt = ((*(int*)(&fFloat) & 0x007FFFFF) | \
            0x00800000) >> iShift; \
        if ( iInt == (1 << iLog) ) \
        { \
            iInt--; \
        } \
    } \
    else \
    { \
        iInt = 0; \
    } \
}

//----------------------------------------------------------------------------

#endif
