// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4CONTROLLER_H
#define WM4CONTROLLER_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM Controller : public Object
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // destruction (abstract base class)
    virtual ~Controller ();

    // the controlled object
    Object* GetObject () const;

    // animation update
    virtual bool Update (double dAppTime);

    // time management

    enum RepeatType
    {
        RT_CLAMP,
        RT_WRAP,
        RT_CYCLE,
        RT_QUANTITY
    };

    RepeatType Repeat;  // default = RT_CLAMP
    double MinTime;     // default = 0.0
    double MaxTime;     // default = 0.0
    double Phase;       // default = 0.0
    double Frequency;   // default = 1.0
    bool Active;        // default = true

protected:
    // construction (abstract base class)
    Controller ();

    // the controlled object
    friend class Object;
    virtual void SetObject (Object* pkObject);

    // Conversion from application time units to controller time units.
    // Derived classes may use this in their update routines.
    double GetControlTime (double dAppTime);

    // Regular pointer used for controlled object to avoid circular smart
    // pointers between controller and object.
    Object* m_pkObject;

    double m_dLastAppTime;

private:
    static const char* ms_aacRepeatType[RT_QUANTITY];
};

WM4_REGISTER_STREAM(Controller);
typedef Pointer<Controller> ControllerPtr;
#include "Wm4Controller.inl"

}

#endif
