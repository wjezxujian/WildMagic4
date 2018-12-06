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
#include "Wm4Images.h"
using namespace Wm4;

// VC6 incorrectly complains that the template-class specialization for
// TImage<Eint>, TImage2D<Eint>, and TImage3D<Eint> are already instantiated.
#ifdef WM4_USING_VC6
#pragma warning(disable : 4660 )
#endif


//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
namespace Wm4
{
template class WM4_FOUNDATION_ITEM TImage<Echar>;
template class WM4_FOUNDATION_ITEM TImage<Euchar>;
template class WM4_FOUNDATION_ITEM TImage<Eshort>;
template class WM4_FOUNDATION_ITEM TImage<Eushort>;
template class WM4_FOUNDATION_ITEM TImage<Eint>;
template class WM4_FOUNDATION_ITEM TImage<Euint>;
template class WM4_FOUNDATION_ITEM TImage<Elong>;
template class WM4_FOUNDATION_ITEM TImage<Eulong>;
template class WM4_FOUNDATION_ITEM TImage<Efloat>;
template class WM4_FOUNDATION_ITEM TImage<Edouble>;
template class WM4_FOUNDATION_ITEM TImage<Ergb5>;
template class WM4_FOUNDATION_ITEM TImage<Ergb8>;

template class WM4_FOUNDATION_ITEM TImage2D<Echar>;
template class WM4_FOUNDATION_ITEM TImage2D<Euchar>;
template class WM4_FOUNDATION_ITEM TImage2D<Eshort>;
template class WM4_FOUNDATION_ITEM TImage2D<Eushort>;
template class WM4_FOUNDATION_ITEM TImage2D<Eint>;
template class WM4_FOUNDATION_ITEM TImage2D<Euint>;
template class WM4_FOUNDATION_ITEM TImage2D<Elong>;
template class WM4_FOUNDATION_ITEM TImage2D<Eulong>;
template class WM4_FOUNDATION_ITEM TImage2D<Efloat>;
template class WM4_FOUNDATION_ITEM TImage2D<Edouble>;
template class WM4_FOUNDATION_ITEM TImage2D<Ergb5>;
template class WM4_FOUNDATION_ITEM TImage2D<Ergb8>;

template class WM4_FOUNDATION_ITEM TImage3D<Echar>;
template class WM4_FOUNDATION_ITEM TImage3D<Euchar>;
template class WM4_FOUNDATION_ITEM TImage3D<Eshort>;
template class WM4_FOUNDATION_ITEM TImage3D<Eushort>;
template class WM4_FOUNDATION_ITEM TImage3D<Eint>;
template class WM4_FOUNDATION_ITEM TImage3D<Euint>;
template class WM4_FOUNDATION_ITEM TImage3D<Elong>;
template class WM4_FOUNDATION_ITEM TImage3D<Eulong>;
template class WM4_FOUNDATION_ITEM TImage3D<Efloat>;
template class WM4_FOUNDATION_ITEM TImage3D<Edouble>;
template class WM4_FOUNDATION_ITEM TImage3D<Ergb5>;
template class WM4_FOUNDATION_ITEM TImage3D<Ergb8>;
}
//----------------------------------------------------------------------------
