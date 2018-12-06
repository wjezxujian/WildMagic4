// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef CONVEXHULL3D_H
#define CONVEXHULL3D_H

#include "Wm4WindowApplication3.h"
using namespace Wm4;

class ConvexHull3D : public WindowApplication3
{
    WM4_DECLARE_INITIALIZE;

public:
    ConvexHull3D ();

    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnIdle ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);

protected:
    void CreateScene ();
    void LoadData ();
    void CreateHull ();
    void RegenerateHull ();
    TriMesh* CreateSphere (const Vector3f& rkCenter, ColorRGB kColor =
        ColorRGB::WHITE, float fRadius = 0.01f);

    // The input data files are in the Data subfolder.  The files are of the
    // format "dataXX.txt", where XX is in {01,02,...,46}.
    int m_iFileQuantity;  // = 46
    int m_iCurrentFile;  // = 1 initially

    // The input data sets with randomly generated vertex colors.
    int m_iVQuantity;
    Vector3f* m_akVertex;
    ColorRGB* m_akColor;

    // The query type for the hull construction and the hull itself.
    Query::Type m_eQueryType;
    ConvexHullf* m_pkHull;

    // A visual representation of the hull.
    NodePtr m_spkScene, m_spkHull, m_spkSphere;
    WireframeStatePtr m_spkWireframe;
    Culler m_kCuller;

    // For debugging purposes.  The line of code
    //    m_iLimitedQuantity = m_iVQuantity;
    // in LoadData(...) can be replaced by
    //    m_iLimitedQuantity = 3;
    // This allows a subset of the input data set to be used for hull
    // construction.  The '+' key increments m_iLimitedQuantity and causes
    // the hull to be computed; the '-' key decrements m_iLimitedQuantity and
    // causes the hull to be computed.  This is useful for query type REAL
    // when the hull appears to be incorrect.  You can increment
    // m_iLimitedQuantity while the hull appears to be correct, and trap the
    // case when it fails.  Subsequently, you can set a conditional breakpoint
    // to step into the hull construction to see where things are failing.
    // Assuming the hull construction algorithm is correct, the failure is a
    // result of numerical round-off error leading to topological problems
    // with the convex polyhedron mesh.
    int m_iLimitedQuantity;

    // Display of query type and of hull vertex/triangle information.
    enum { STRING_SIZE = 256 };
    char m_acHeader[STRING_SIZE], m_acFooter[STRING_SIZE];
};

WM4_REGISTER_INITIALIZE(ConvexHull3D);

#endif
