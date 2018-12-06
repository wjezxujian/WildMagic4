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
#include "Wm4VertexBuffer.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,VertexBuffer,Object);
WM4_IMPLEMENT_STREAM(VertexBuffer);
WM4_IMPLEMENT_DEFAULT_NAME_ID(VertexBuffer,Object);

//----------------------------------------------------------------------------
VertexBuffer::VertexBuffer (const Attributes& rkAttributes,
    int iVertexQuantity)
    :
    m_kAttributes(rkAttributes)
{
    assert(iVertexQuantity > 0);
    m_iVertexQuantity = iVertexQuantity;
    m_iVertexSize = m_kAttributes.GetChannelQuantity();
    m_iChannelQuantity = m_iVertexQuantity*m_iVertexSize;
    m_afChannel = WM4_NEW float[m_iChannelQuantity];
    memset(m_afChannel,0,m_iChannelQuantity*sizeof(float));
}
//----------------------------------------------------------------------------
VertexBuffer::VertexBuffer (const VertexBuffer* pkVBuffer)
{
    assert(pkVBuffer);
    m_kAttributes = pkVBuffer->m_kAttributes;
    m_iVertexQuantity = pkVBuffer->m_iVertexQuantity;
    m_iVertexSize = m_kAttributes.GetChannelQuantity();
    m_iChannelQuantity = m_iVertexQuantity*m_iVertexSize;
    m_afChannel = WM4_NEW float[m_iChannelQuantity];
    size_t uiSize = m_iChannelQuantity*sizeof(float);
    System::Memcpy(m_afChannel,uiSize,pkVBuffer->m_afChannel,uiSize);
}
//----------------------------------------------------------------------------
VertexBuffer::VertexBuffer ()
{
    m_iVertexQuantity = 0;
    m_iVertexSize = 0;
    m_iChannelQuantity = 0;
    m_afChannel = 0;
}
//----------------------------------------------------------------------------
VertexBuffer::~VertexBuffer ()
{
    // Inform all renderers using this vertex buffer that it is being
    // destroyed.  This allows the renderer to free up any associated
    // resources.
    Release();

    WM4_DELETE[] m_afChannel;
}
//----------------------------------------------------------------------------
float* VertexBuffer::PositionTuple (int i)
{
    if (m_kAttributes.HasPosition() && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetPOffset();
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
const float* VertexBuffer::PositionTuple (int i) const
{
    if (m_kAttributes.HasPosition() && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetPOffset();
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
float* VertexBuffer::NormalTuple (int i)
{
    if (m_kAttributes.HasNormal() && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetNOffset();
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
const float* VertexBuffer::NormalTuple (int i) const
{
    if (m_kAttributes.HasNormal() && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetNOffset();
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
float* VertexBuffer::ColorTuple (int iUnit, int i)
{
    if (m_kAttributes.HasColor(iUnit) && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetCOffset(iUnit);
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
const float* VertexBuffer::ColorTuple (int iUnit, int i) const
{
    if (m_kAttributes.HasColor(iUnit) && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetCOffset(iUnit);
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
float* VertexBuffer::TCoordTuple (int iUnit, int i)
{
    if (m_kAttributes.HasTCoord(iUnit) && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
const float* VertexBuffer::TCoordTuple (int iUnit, int i) const
{
    if (m_kAttributes.HasTCoord(iUnit) && 0 <= i && i < m_iVertexQuantity)
    {
        int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
        return m_afChannel + iIndex;
    }
    return 0;
}
//----------------------------------------------------------------------------
Vector3f& VertexBuffer::Position3 (int i)
{
    assert(m_kAttributes.GetPChannels() == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetPOffset();
    return *(Vector3f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector3f VertexBuffer::Position3 (int i) const
{
    assert(m_kAttributes.GetPChannels() == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetPOffset();
    return *(Vector3f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector3f& VertexBuffer::Normal3 (int i)
{
    assert(m_kAttributes.GetNChannels() == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetNOffset();
    return *(Vector3f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector3f VertexBuffer::Normal3 (int i) const
{
    assert(m_kAttributes.GetNChannels() == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetNOffset();
    return *(Vector3f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
ColorRGB& VertexBuffer::Color3 (int iUnit, int i)
{
    assert(m_kAttributes.GetCChannels(iUnit) == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetCOffset(iUnit);
    return *(ColorRGB*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
ColorRGB VertexBuffer::Color3 (int iUnit, int i) const
{
    assert(m_kAttributes.GetCChannels(iUnit) == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetCOffset(iUnit);
    return *(ColorRGB*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
ColorRGBA& VertexBuffer::Color4 (int iUnit, int i)
{
    assert(m_kAttributes.GetCChannels(iUnit) == 4);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetCOffset(iUnit);
    return *(ColorRGBA*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
ColorRGBA VertexBuffer::Color4 (int iUnit, int i) const
{
    assert(m_kAttributes.GetCChannels(iUnit) == 4);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetCOffset(iUnit);
    return *(ColorRGBA*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
float& VertexBuffer::TCoord1 (int iUnit, int i)
{
    assert(m_kAttributes.GetTChannels(iUnit) == 1);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
float VertexBuffer::TCoord1 (int iUnit, int i) const
{
    assert(m_kAttributes.GetTChannels(iUnit) == 1);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector2f& VertexBuffer::TCoord2 (int iUnit, int i)
{
    assert(m_kAttributes.GetTChannels(iUnit) == 2);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(Vector2f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector2f VertexBuffer::TCoord2 (int iUnit, int i) const
{
    assert(m_kAttributes.GetTChannels(iUnit) == 2);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(Vector2f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector3f& VertexBuffer::TCoord3 (int iUnit, int i)
{
    assert(m_kAttributes.GetTChannels(iUnit) == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(Vector3f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector3f VertexBuffer::TCoord3 (int iUnit, int i) const
{
    assert(m_kAttributes.GetTChannels(iUnit) == 3);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(Vector3f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector4f& VertexBuffer::TCoord4 (int iUnit, int i)
{
    assert(m_kAttributes.GetTChannels(iUnit) == 4);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(Vector4f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
Vector4f VertexBuffer::TCoord4 (int iUnit, int i) const
{
    assert(m_kAttributes.GetTChannels(iUnit) == 4);
    int iIndex = m_iVertexSize*i + m_kAttributes.GetTOffset(iUnit);
    return *(Vector4f*)(m_afChannel + iIndex);
}
//----------------------------------------------------------------------------
void VertexBuffer::BuildCompatibleArray (const Attributes& rkIAttr,
    bool bPackARGB, int& riChannels, float*& rafCompatible) const
{
    // The use of "unsigned int" is to allow storage of "float" channels and
    // of the ARGB-formatted colors, which are "unsigned int".  Typecasting
    // "float" pointers to "unsigned int" pointers and then dereferencing
    // them works as expected.  The alternative is to use a vector of "float"
    // and typecast "unsigned int" pointers to "float" pointers.  However,
    // dereferencing to a "float" to allow push_back has problems.  The
    // memory pattern for an "unsigned int" might correspond to an invalid
    // "float".  The floating-point unit actually makes adjustments to these
    // values, changing what it is you started with.
    std::vector<unsigned int> kCompatible;    
    const unsigned int* puiData;
    float fOne = 1.0f;
    unsigned int* puiOne = (unsigned int*)&fOne;
    int iUnit, iIChannels, iVBChannels;

    for (int i = 0, j; i < m_iVertexQuantity; i++)
    {
        if (rkIAttr.HasPosition())
        {
            iIChannels = rkIAttr.GetPChannels();
            iVBChannels = m_kAttributes.GetPChannels();
            puiData = (unsigned int*)PositionTuple(i);
            if (iVBChannels < iIChannels)
            {
                for (j = 0; j < iVBChannels; j++)
                {
                    kCompatible.push_back(*puiData++);
                }
                for (j = iVBChannels; j < iIChannels; j++)
                {
                    // Fill with 1 so that the w-component is compatible with
                    // a homogeneous point.
                    kCompatible.push_back(*puiOne);
                }
            }
            else
            {
                for (j = 0; j < iIChannels; j++)
                {
                    kCompatible.push_back(*puiData++);
                }
            }
        }

        if (rkIAttr.HasNormal())
        {
            iIChannels = rkIAttr.GetNChannels();
            iVBChannels = m_kAttributes.GetNChannels();
            puiData = (unsigned int*)NormalTuple(i);
            if (iVBChannels < iIChannels)
            {
                for (j = 0; j < iVBChannels; j++)
                {
                    kCompatible.push_back(*puiData++);
                }
                for (j = iVBChannels; j < iIChannels; j++)
                {
                    // Fill with 0 so that the w-component is compatible with
                    // a homogeneous vector.
                    kCompatible.push_back(0);
                }
            }
            else
            {
                for (j = 0; j < iIChannels; j++)
                {
                    kCompatible.push_back(*puiData++);
                }
            }
        }

        for (iUnit = 0; iUnit < (int)rkIAttr.GetMaxColors(); iUnit++)
        {
            if (rkIAttr.HasColor(iUnit))
            {
                unsigned int auiColor[4], uiPackColor, uiValue;
                float fValue;

                iIChannels = rkIAttr.GetCChannels(iUnit);
                iVBChannels = m_kAttributes.GetCChannels(iUnit);
                puiData = (unsigned int*)ColorTuple(iUnit,i);
                if (iVBChannels < iIChannels)
                {
                    for (j = 0; j < iVBChannels; j++)
                    {
                        kCompatible.push_back(*puiData++);
                    }
                    for (j = iVBChannels; j < iIChannels; j++)
                    {
                        // Fill with 1 so that the a-component is compatible
                        // with an opaque color.
                        kCompatible.push_back(*puiOne);
                    }
                    if (bPackARGB)
                    {
                        for (j = iIChannels; j < 4; j++)
                        {
                            // Fill with 1 so that the a-component is
                            // compatible with an opaque color.
                            kCompatible.push_back(*puiOne);
                        }

                        // Map from [0,1] to [0,255].
                        for (j = 3; j >= 0; j--)
                        {
                            uiValue = kCompatible.back();
                            fValue = *(float*)&uiValue;
                            auiColor[j] = (unsigned int)(255.0f*fValue);
                            kCompatible.pop_back();
                        }

                        uiPackColor =
                            (auiColor[2]      ) |  // blue
                            (auiColor[1] <<  8) |  // green
                            (auiColor[0] << 16) |  // red
                            (auiColor[3] << 24);   // alpha

                        kCompatible.push_back(uiPackColor);
                    }
                }
                else
                {
                    for (j = 0; j < iIChannels; j++)
                    {
                        kCompatible.push_back(*puiData++);
                    }
                    if (bPackARGB)
                    {
                        for (j = iIChannels; j < 4; j++)
                        {
                            // Fill with 1 so that the a-component is
                            // compatible with an opaque color.
                            kCompatible.push_back(*puiOne);
                        }

                        // Map from [0,1] to [0,255].
                        for (j = 3; j >= 0; j--)
                        {
                            uiValue = kCompatible.back();
                            fValue = *(float*)&uiValue;
                            auiColor[j] = (unsigned int)(255.0f*fValue);
                            kCompatible.pop_back();
                        }

                        uiPackColor =
                            (auiColor[2]      ) |  // blue
                            (auiColor[1] <<  8) |  // green
                            (auiColor[0] << 16) |  // red
                            (auiColor[3] << 24);   // alpha

                        kCompatible.push_back(uiPackColor);
                    }
                }
            }
        }

        for (iUnit = 0; iUnit < (int)rkIAttr.GetMaxTCoords(); iUnit++)
        {
            if (rkIAttr.HasTCoord(iUnit))
            {
                iIChannels = rkIAttr.GetTChannels(iUnit);
                iVBChannels = m_kAttributes.GetTChannels(iUnit);
                puiData = (unsigned int*)TCoordTuple(iUnit,i);
                if (iVBChannels < iIChannels)
                {
                    for (j = 0; j < iVBChannels; j++)
                    {
                        kCompatible.push_back(*puiData++);
                    }
                    for (j = iVBChannels; j < iIChannels; j++)
                    {
                        // Fill with 0 so that the components are compatible
                        // with a higher-dimensional image embedded in a
                        // lower-dimensional one.
                        kCompatible.push_back(0);
                    }
                }
                else
                {
                    for (j = 0; j < iIChannels; j++)
                    {
                        kCompatible.push_back(*puiData++);
                    }
                }
            }
        }
    }

    riChannels = (int)kCompatible.size();
    if (!rafCompatible)
    {
        rafCompatible = WM4_NEW float[riChannels];
    }
    size_t uiSize = riChannels*sizeof(float);
    System::Memcpy(rafCompatible,uiSize,&kCompatible.front(),uiSize);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// streaming
//----------------------------------------------------------------------------
void VertexBuffer::Load (Stream& rkStream, Stream::Link* pkLink)
{
    WM4_BEGIN_DEBUG_STREAM_LOAD;

    Object::Load(rkStream,pkLink);

    rkStream.Read(m_iVertexSize);
    rkStream.Read(m_iVertexQuantity);
    rkStream.Read(m_iChannelQuantity);
    m_afChannel = WM4_NEW float[m_iChannelQuantity];
    rkStream.Read(m_iChannelQuantity,m_afChannel);

    int iPChannels;
    rkStream.Read(iPChannels);
    m_kAttributes.SetPChannels(iPChannels);

    int iNChannels;
    rkStream.Read(iNChannels);
    m_kAttributes.SetNChannels(iNChannels);

    int iMaxColors;
    rkStream.Read(iMaxColors);
    int i;
    for (i = 0; i < iMaxColors; i++)
    {
        int iCChannels;
        rkStream.Read(iCChannels);
        m_kAttributes.SetCChannels(i,iCChannels);
    }

    int iMaxTCoords;
    rkStream.Read(iMaxTCoords);
    for (i = 0; i < iMaxTCoords; i++)
    {
        int iTChannels;
        rkStream.Read(iTChannels);
        m_kAttributes.SetTChannels(i,iTChannels);
    }

    WM4_END_DEBUG_STREAM_LOAD(VertexBuffer);
}
//----------------------------------------------------------------------------
void VertexBuffer::Link (Stream& rkStream, Stream::Link* pkLink)
{
    Object::Link(rkStream,pkLink);
}
//----------------------------------------------------------------------------
bool VertexBuffer::Register (Stream& rkStream) const
{
    return Object::Register(rkStream);
}
//----------------------------------------------------------------------------
void VertexBuffer::Save (Stream& rkStream) const
{
    WM4_BEGIN_DEBUG_STREAM_SAVE;

    Object::Save(rkStream);
    rkStream.Write(m_iVertexSize);
    rkStream.Write(m_iVertexQuantity);
    rkStream.Write(m_iChannelQuantity);
    rkStream.Write(m_iChannelQuantity,m_afChannel);

    rkStream.Write(m_kAttributes.GetPChannels());
    rkStream.Write(m_kAttributes.GetNChannels());
    rkStream.Write(m_kAttributes.GetMaxColors());
    int i;
    for (i = 0; i < m_kAttributes.GetMaxColors(); i++)
    {
        rkStream.Write(m_kAttributes.GetCChannels(i));
    }
    rkStream.Write(m_kAttributes.GetMaxTCoords());
    for (i = 0; i < m_kAttributes.GetMaxTCoords(); i++)
    {
        rkStream.Write(m_kAttributes.GetTChannels(i));
    }

    WM4_END_DEBUG_STREAM_SAVE(VertexBuffer);
}
//----------------------------------------------------------------------------
int VertexBuffer::GetDiskUsed (const StreamVersion& rkVersion) const
{
    return Object::GetDiskUsed(rkVersion) +
        sizeof(m_iVertexSize) +
        sizeof(m_iVertexQuantity) +
        sizeof(m_iChannelQuantity) +
        m_iChannelQuantity*sizeof(m_afChannel[0]) +
        4*sizeof(int) +
        sizeof(int)*m_kAttributes.GetMaxColors() +
        sizeof(int)*m_kAttributes.GetMaxTCoords();
}
//----------------------------------------------------------------------------
StringTree* VertexBuffer::SaveStrings (const char* acTitle)
{
    StringTree* pkTree = WM4_NEW StringTree;

    // strings
    pkTree->Append(Format(&TYPE,GetName().c_str()));
    pkTree->Append(Format("vertex quantity = ",m_iVertexQuantity));
    pkTree->Append(Format("vertex size = ",m_iVertexSize));

    pkTree->Append(Format("p channels =",m_kAttributes.GetPChannels()));
    pkTree->Append(Format("n channels =",m_kAttributes.GetNChannels()));

    pkTree->Append(Format("c units =",m_kAttributes.GetMaxColors()));
    const size_t uiSubtitleSize = 16;
    char acSubtitle[uiSubtitleSize];
    int i;
    for (i = 0; i < m_kAttributes.GetMaxColors(); i++)
    {
        System::Sprintf(acSubtitle,uiSubtitleSize,"c[%d] channels =",i);
        pkTree->Append(Format(acSubtitle,m_kAttributes.GetCChannels(i)));
    }

    pkTree->Append(Format("t units =",m_kAttributes.GetMaxTCoords()));
    for (i = 0; i < m_kAttributes.GetMaxTCoords(); i++)
    {
        System::Sprintf(acSubtitle,uiSubtitleSize,"t[%d] channels =",i);
        pkTree->Append(Format(acSubtitle,m_kAttributes.GetTChannels(i)));
    }

    // children
    pkTree->Append(Object::SaveStrings());
    pkTree->Append(Format(acTitle,m_iChannelQuantity,m_afChannel));

    return pkTree;
}
//----------------------------------------------------------------------------
