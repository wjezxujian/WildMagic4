// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4WINDOWAPPLICATION3_H
#define WM4WINDOWAPPLICATION3_H

#include "Wm4WindowApplication.h"

namespace Wm4
{

class WindowApplication3 : public WindowApplication
{
public:
    WindowApplication3 (const char* acWindowTitle, int iXPosition,
        int iYPosition, int iWidth, int iHeight,
        const ColorRGBA& rkBackgroundColor);

    virtual ~WindowApplication3 ();

    // event callbacks
    virtual bool OnInitialize ();
    virtual void OnTerminate ();
    virtual void OnDisplay ();
    virtual bool OnKeyDown (unsigned char ucKey, int iX, int iY);
    virtual bool OnSpecialKeyDown (int iKey, int iX, int iY);
    virtual bool OnSpecialKeyUp (int iKey, int iX, int iY);
    virtual bool OnMouseClick (int iButton, int iState, int iX, int iY,
        unsigned int uiModifiers);
    virtual bool OnMotion (int iButton, int iX, int iY,
        unsigned int uiModifiers);

protected:
    // camera motion
    void InitializeCameraMotion (float fTrnSpeed, float fRotSpeed,
        float fTrnSpeedFactor = 2.0f, float fRotSpeedFactor = 2.0f);
    virtual bool MoveCamera ();
    virtual void MoveForward ();
    virtual void MoveBackward ();
    virtual void MoveUp ();
    virtual void MoveDown ();
    virtual void TurnLeft ();
    virtual void TurnRight ();
    virtual void LookUp ();
    virtual void LookDown ();
    CameraPtr m_spkCamera;
    Vector3f m_akWorldAxis[3];
    float m_fTrnSpeed, m_fTrnSpeedFactor;
    float m_fRotSpeed, m_fRotSpeedFactor;
    bool m_bUArrowPressed;
    bool m_bDArrowPressed;
    bool m_bLArrowPressed;
    bool m_bRArrowPressed;
    bool m_bPgUpPressed;
    bool m_bPgDnPressed;
    bool m_bHomePressed;
    bool m_bEndPressed;
    bool m_bCameraMoveable;

    // object motion
    void InitializeObjectMotion (Spatial* pkMotionObject);
    bool MoveObject ();
    void RotateTrackBall (float fX0, float fY0, float fX1, float fY1);
    SpatialPtr m_spkMotionObject;
    int m_iDoRoll, m_iDoYaw, m_iDoPitch;
    float m_fXTrack0, m_fYTrack0, m_fXTrack1, m_fYTrack1;
    Matrix3f m_kSaveRotate;
    bool m_bUseTrackBall, m_bTrackBallDown;

    // performance measurements
    void ResetTime ();
    void MeasureTime ();
    void UpdateFrameCount ();
    void DrawFrameRate (int iX, int iY, const ColorRGBA& rkColor);
    double m_dLastTime, m_dAccumulatedTime, m_dFrameRate;
    int m_iFrameCount, m_iAccumulatedFrameCount, m_iTimer, m_iMaxTimer;
};

}

#endif
