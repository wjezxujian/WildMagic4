// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BSPLINESURFACEPATCH_H
#define WM4BSPLINESURFACEPATCH_H

#include "Wm4GraphicsLIB.h"
#include "Wm4SurfacePatch.h"
#include "Wm4BSplineRectangle.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM BSplineSurfacePatch : public SurfacePatch
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.   The caller is responsible for deleting
    // the input arrays if they were dynamically allocated.  Internal copies
    // of the arrays are made, so to dynamically change control points or
    // knots you must use the 'SetControlPoint', 'GetControlPoint', and
    // 'Knot' member functions.

    // Spline types for curves are
    //   open uniform (OU)
    //   periodic uniform (PU)
    //   open nonuniform (ON)
    // For tensor product surfaces, you have to choose a type for each of two
    // dimensions, leading to nine possible spline types for surfaces.  The
    // constructors below represent these choices.

    // (OU,OU), (OU,PU), (PU,OU), or (PU,PU)
    BSplineSurfacePatch (int iNumUCtrlPoints, int iNumVCtrlPoints,
        Vector3f** aakCtrlPoint, int iUDegree, int iVDegree, bool bULoop,
        bool bVLoop, bool bUOpen, bool bVOpen);

    // (OU,ON) or (PU,ON)
    BSplineSurfacePatch (int iNumUCtrlPoints, int iNumVCtrlPoints,
        Vector3f** aakCtrlPoint, int iUDegree, int iVDegree, bool bULoop,
        bool bVLoop, bool bUOpen, float* afVKnot);

    // (ON,OU) or (ON,PU)
    BSplineSurfacePatch (int iNumUCtrlPoints, int iNumVCtrlPoints,
        Vector3f** aakCtrlPoint, int iUDegree, int iVDegree, bool bULoop,
        bool bVLoop, float* afUKnot, bool bVOpen);

    // (ON,ON)
    BSplineSurfacePatch (int iNumUCtrlPoints, int iNumVCtrlPoints,
        Vector3f** aakCtrlPoint, int iUDegree, int iVDegree, bool bULoop,
        bool bVLoop, float* afUKnot, float* afVKnot);

    virtual ~BSplineSurfacePatch ();

    // Position and derivatives up to second order.
    virtual Vector3f P (float fU, float fV) const;
    virtual Vector3f PU (float fU, float fV) const;
    virtual Vector3f PV (float fU, float fV) const;
    virtual Vector3f PUU (float fU, float fV) const;
    virtual Vector3f PUV (float fU, float fV) const;
    virtual Vector3f PVV (float fU, float fV) const;

protected:
    BSplineSurfacePatch ();

    // The class has four constructors, not counting the default one used
    // for streaming.  The correct constructor needs to be called on a stream
    // load operation, so this data member stores that information.  The
    // value is 1, 2, 3, or 4 and refers to the order of the four nondefault
    // constructors listed previously.
    int m_iConstructor;

    BSplineRectanglef* m_pkPatch;
};

WM4_REGISTER_STREAM(BSplineSurfacePatch);
typedef Pointer<SurfacePatch> BSplineSurfacePatchPtr;

}

#endif
