// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4POINTCONTROLLER_H
#define WM4POINTCONTROLLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Controller.h"
#include "Wm4Polypoint.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM PointController : public Controller
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    virtual ~PointController ();

    // The system motion, in local coordinates.  The velocity vectors should
    // be unit length.
    float SystemLinearSpeed;
    float SystemAngularSpeed;
    Vector3f SystemLinearAxis;
    Vector3f SystemAngularAxis;

    // Point motion, in the model space of the system.  The velocity vectors
    // should be unit length.  In applications where the points represent a
    // rigid body, you might choose the origin of the system to be the center
    // of mass of the points and the coordinate axes to correspond to the
    // principal directions of the inertia tensor.
    float* PointLinearSpeed ();
    float* PointAngularSpeed ();
    Vector3f* PointLinearAxis ();
    Vector3f* PointAngularAxis ();

    // animation update
    virtual bool Update (double dAppTime);

protected:
    // streaming support
    PointController ();

    // for deferred allocation of the point motion arrays
    void Reallocate (int iVertexQuantity);
    virtual void SetObject (Object* pkObject);

    // This class computes the new positions and orientations from the motion
    // parameters.  Derived classes should update the motion parameters and
    // then either call the base class update methods or provide its own
    // update methods for position and orientation.
    virtual void UpdateSystemMotion (float fCtrlTime);
    virtual void UpdatePointMotion (float fCtrlTime);

    // point motion (in model space of system)
    int m_iPQuantity;
    float* m_afPointLinearSpeed;
    float* m_afPointAngularSpeed;
    Vector3f* m_akPointLinearAxis;
    Vector3f* m_akPointAngularAxis;
};

WM4_REGISTER_STREAM(PointController);
typedef Pointer<PointController> PointControllerPtr;
#include "Wm4PointController.inl"

}

#endif
