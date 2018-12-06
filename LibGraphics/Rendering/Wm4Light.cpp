// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4Light.h"
#include "Wm4Matrix3.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,Light,Object);
WM4_IMPLEMENT_STREAM(Light);
WM4_IMPLEMENT_DEFAULT_NAME_ID(Light,Object);

//----------------------------------------------------------------------------
Light::Light (LightType eType)
    :
    Type(eType),
    Ambient(0.0f,0.0f,0.0f),
    Diffuse(0.0f,0.0f,0.0f),
    Specular(0.0f,0.0f,0.0f),
    Position(0.0f,0.0f,0.0f),
    DVector(0.0f,0.0f,-1.0f),
    UVector(0.0f,1.0f,0.0f),
    RVector(1.0f,0.0f,0.0f)
{
    Constant = 1.0f;
    Linear = 0.0f;
    Quadratic = 0.0f;
    Intensity = 1.0f;
    Angle = Mathf::PI;
    CosAngle = -1.0f;
    SinAngle = 0.0f;
    Exponent = 1.0f;
}
//----------------------------------------------------------------------------
Light::~Light ()
{
}
//----------------------------------------------------------------------------
void Light::SetAngle (float fAngle)
{
    assert(0.0f < fAngle && fAngle <= Mathf::PI);
    Angle = fAngle;
    CosAngle = Mathf::Cos(fAngle);
    SinAngle = Mathf::Sin(fAngle);
}
//----------------------------------------------------------------------------
void Light::SetDirection (const Vector3f& rkDirection, bool bUnitLength)
{
    DVector = rkDirection;
    Vector3f::GenerateOrthonormalBasis(UVector,RVector,DVector,bUnitLength);
}
//----------------------------------------------------------------------------
bool Light::IsValidFrame () const
{
    float fTest = DVector.Dot(UVector);
    if (Mathf::FAbs(fTest) > Mathf::ZERO_TOLERANCE)
    {
        return false;
    }

    fTest = DVector.Dot(RVector);
    if (Mathf::FAbs(fTest) > Mathf::ZERO_TOLERANCE)
    {
        return false;
    }

    fTest = UVector.Dot(RVector);
    if (Mathf::FAbs(fTest) > Mathf::ZERO_TOLERANCE)
    {
        return false;
    }

    fTest = DVector.Dot(UVector.Cross(RVector));
    return Mathf::FAbs(1.0f - fTest) <= Mathf::ZERO_TOLERANCE;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void Light::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    // native data
    rkStream.Read(Position);
    rkStream.Read(DVector);
    rkStream.Read(UVector);
    rkStream.Read(RVector);
    rkStream.Read(Ambient);
    rkStream.Read(Diffuse);
    rkStream.Read(Specular);
    rkStream.Read(Intensity);
    rkStream.Read(Constant);
    rkStream.Read(Linear);
    rkStream.Read(Quadratic);
    rkStream.Read(Angle);
    rkStream.Read(CosAngle);
    rkStream.Read(SinAngle);
    rkStream.Read(Exponent);

    WM4_END_DEBUG_STREAM_LOAD(Light);
}
//----------------------------------------------------------------------------
void Light::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool Light::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void Light::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);

    // native data
    rkStream.Write(Position);
    rkStream.Write(DVector);
    rkStream.Write(UVector);
    rkStream.Write(RVector);
    rkStream.Write(Ambient);
    rkStream.Write(Diffuse);
    rkStream.Write(Specular);
    rkStream.Write(Intensity);
    rkStream.Write(Constant);
    rkStream.Write(Linear);
    rkStream.Write(Quadratic);
    rkStream.Write(Angle);
    rkStream.Write(CosAngle);
    rkStream.Write(SinAngle);
    rkStream.Write(Exponent);

    WM4_END_DEBUG_STREAM_SAVE(Light);
}
//----------------------------------------------------------------------------
int Light::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Object::GetDiskUsed(rkVersion) +
        sizeof(Position) +
        sizeof(DVector) +
        sizeof(UVector) +
        sizeof(RVector) +
        sizeof(Ambient) +
        sizeof(Diffuse) +
        sizeof(Specular) +
        sizeof(Intensity) +
        sizeof(Constant) +
        sizeof(Linear) +
        sizeof(Quadratic) +
        sizeof(Angle) +
        sizeof(CosAngle) +
        sizeof(SinAngle) +
        sizeof(Exponent);
}
//----------------------------------------------------------------------------
StringTree* Light::SaveStrings (const char*)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("position =",Position));
    pkTree->Append(Format("d vector =",DVector));
    pkTree->Append(Format("u vector =",UVector));
    pkTree->Append(Format("r vector =",RVector));
    pkTree->Append(Format("ambient =",Ambient));
    pkTree->Append(Format("diffuse =",Diffuse));
    pkTree->Append(Format("specular =",Specular));
    pkTree->Append(Format("intensity =",Intensity));
    pkTree->Append(Format("attn constant =",Constant));
    pkTree->Append(Format("attn linear =",Linear));
    pkTree->Append(Format("attn quadratic =",Quadratic));
    pkTree->Append(Format("angle =",Angle));
    pkTree->Append(Format("exponent =",Exponent));

    // children
    pkTree->Append(Object::SaveStrings());

    return pkTree;
}
//----------------------------------------------------------------------------
