// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef SEGMENTEDGE_H
#define SEGMENTEDGE_H

#include "RPoint2.h"

class Polysolid2;

class SegmentEdge
{
public:
    SegmentEdge ();
    ~SegmentEdge ();

    bool HasEdges () const;
    void AddEdge (const RPoint2& rkPosition0, const RPoint2& rkPosition1);

    // for union, intersection
    void MergeAppend (SegmentEdge& rkTEdge);
    void MergeUnique (SegmentEdge& rkTEdge);
    void MergeEqual  (SegmentEdge& rkTEdge);

    // for difference, exclusive or
    void MergeAppendReverse (SegmentEdge& rkTEdge);
    void MergeUniqueReverse (SegmentEdge& rkTEdge);

    void ConvertToPolySolid (Polysolid2& rkPoly);

protected:
    class TaggedEdge
    {
    public:
        RPoint2 Position[2];
        TaggedEdge* Next;
    };

    TaggedEdge* m_pkFirst;
};

#endif
