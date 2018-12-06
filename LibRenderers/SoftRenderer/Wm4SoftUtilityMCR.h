// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SOFTUTILITYMCR_H
#define WM4SOFTUTILITYMCR_H

// TO DO.  Reimplement to manipulate float interpreted as an integer.

#define WM4_FLOAT_TO_INT(fFloat)\
    (int)(fFloat)

#define WM4_FLOAT_TO_UINT(fFloat)\
    (unsigned int)(fFloat)

#define WM4_UNIT_FLOAT_TO_INT(fFloat,iMaxValue)\
    (int)(fFloat*(float)iMaxValue)

#define WM4_UNIT_FLOAT_TO_UINT(fFloat,uiMaxValue)\
    (unsigned int)(fFloat*(float)uiMaxValue)

#endif
