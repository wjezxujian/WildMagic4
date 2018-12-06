// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef EDGE2_H
#define EDGE2_H

class Edge2
{
public:
    Edge2 ();
    Edge2 (int j0, int j1);

    bool operator< (const Edge2& rkE) const;

    int i0, i1;
};

#endif
