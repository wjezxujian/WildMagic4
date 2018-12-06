// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef TYPES2_H
#define TYPES2_H

#include "Edge2.h"
#include "Wm4Vector2.h"
using namespace Wm4;

#include <map>
#include <vector>
using namespace std;

// vertices
typedef map<Vector2d,int> VMap;
typedef map<Vector2d,int>::iterator VIterator;
typedef map<Vector2d,int>::const_iterator VCIterator;
typedef vector<Vector2d> VArray;

// edges
typedef map<Edge2,int> EMap;
typedef map<Edge2,int>::iterator EIterator;
typedef map<Edge2,int>::const_iterator ECIterator;
typedef vector<Edge2> EArray;

#endif
