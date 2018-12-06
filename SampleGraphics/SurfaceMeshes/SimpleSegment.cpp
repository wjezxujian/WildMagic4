// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "SimpleSegment.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,SimpleSegment,CurveSegment);
WM4_IMPLEMENT_STREAM(SimpleSegment);
WM4_IMPLEMENT_DEFAULT_NAME_ID(SimpleSegment,CurveSegment);

//----------------------------------------------------------------------------
SimpleSegment::SimpleSegment ()
    :
    CurveSegment(0.0f,1.0f)
{
    Amplitude = 1.0f;
    Frequency = Mathf::TWO_PI;
    Height = 1.0f;
}
//----------------------------------------------------------------------------
SimpleSegment::~SimpleSegment ()
{
}
//----------------------------------------------------------------------------
Vector3f SimpleSegment::P (float fU) const
{
    // P(u) = (A*cos(F*u),A*sin(F*u),H*u)
    float fAngle = Frequency*fU;
    return Vector3f(Amplitude*Mathf::Cos(fAngle),Amplitude*Mathf::Sin(fAngle),
        Height*fU);
}
//----------------------------------------------------------------------------
Vector3f SimpleSegment::PU (float fU) const
{
    // P'(u) = (-A*F*sin(F*u),A*F*cos(F*u),H)
    float fAF = Amplitude*Frequency;
    float fAngle = Frequency*fU;
    return Vector3f(-fAF*Mathf::Sin(fAngle),fAF*Mathf::Cos(fAngle),Height);
}
//----------------------------------------------------------------------------
Vector3f SimpleSegment::PUU (float fU) const
{
    // P"(u) = (-A*F*F*cos(F*u),-A*F*F*sin(F*u),0)
    float fAFF = Amplitude*Frequency*Frequency;
    float fAngle = Frequency*fU;
    return Vector3f(-fAFF*Mathf::Cos(fAngle),-fAFF*Mathf::Sin(fAngle),0.0f);
}
//----------------------------------------------------------------------------
Vector3f SimpleSegment::PUUU (float fU) const
{
    // P"'(u) = (A*F*F*F*sin(F*u),-A*F*F*F*cos(F*u),0)
    float fAFFF = Amplitude*Frequency*Frequency*Frequency;
    float fAngle = Frequency*fU;
    return Vector3f(fAFFF*Mathf::Sin(fAngle),-fAFFF*Mathf::Cos(fAngle),0.0f);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void SimpleSegment::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    CurveSegment::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Amplitude);
    rkStream.Read(Frequency);
    rkStream.Read(Height);

    WM4_END_DEBUG_STREAM_LOAD(SimpleSegment);
}
//----------------------------------------------------------------------------
void SimpleSegment::Link (Stream& rkStream, Stream::Link* pkLink)
{
    CurveSegment::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool SimpleSegment::Register (Stream& rkStream) const
{
    return CurveSegment::Register(rkStream);
}
//----------------------------------------------------------------------------
void SimpleSegment::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    CurveSegment::Save(rkStream);

    // native data
    rkStream.Write(Amplitude);
    rkStream.Write(Frequency);
    rkStream.Write(Height);

    WM4_END_DEBUG_STREAM_SAVE(SimpleSegment);
}
//----------------------------------------------------------------------------
int SimpleSegment::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return CurveSegment::GetDiskUsed(rkVersion) +
        sizeof(Amplitude) +
        sizeof(Frequency) +
        sizeof(Height);
}
//----------------------------------------------------------------------------
StringTree* SimpleSegment::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("amplitude =",Amplitude));
    pkTree->Append(Format("frequency =",Frequency));
    pkTree->Append(Format("height =",Height));

    // children
    pkTree->Append(CurveSegment::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
