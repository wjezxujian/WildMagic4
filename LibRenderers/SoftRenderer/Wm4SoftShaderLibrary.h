// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4SOFTSHADERLIBRARY_H
#define WM4SOFTSHADERLIBRARY_H

#include "Wm4SoftShaderLibraryMCR.h"

// vertex programs
WM4_REGISTER_VPROGRAM(Default);
WM4_REGISTER_VPROGRAM(L1a);
WM4_REGISTER_VPROGRAM(L1d);
WM4_REGISTER_VPROGRAM(L1p);
WM4_REGISTER_VPROGRAM(L1s);
WM4_REGISTER_VPROGRAM(Material);
WM4_REGISTER_VPROGRAM(MaterialTexture);
WM4_REGISTER_VPROGRAM(Texture);
WM4_REGISTER_VPROGRAM(T0d2T1d2PassThrough);
WM4_REGISTER_VPROGRAM(VertexColor3);
WM4_REGISTER_VPROGRAM(VertexColor4);

// pixel programs
WM4_REGISTER_PPROGRAM(Default);
WM4_REGISTER_PPROGRAM(MaterialTexture);
WM4_REGISTER_PPROGRAM(PassThrough3);
WM4_REGISTER_PPROGRAM(PassThrough4);
WM4_REGISTER_PPROGRAM(Texture);
WM4_REGISTER_PPROGRAM(T0s1d0T1s1d1);
WM4_REGISTER_PPROGRAM(T0s1d0T1s2d0);
WM4_REGISTER_PPROGRAM(T0s1d0T1s3d1);

#endif
