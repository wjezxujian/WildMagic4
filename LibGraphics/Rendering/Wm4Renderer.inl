// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline Camera* Renderer::GetCamera () const
{
    return m_pkCamera;
}
//----------------------------------------------------------------------------
inline FrameBuffer::FormatType Renderer::GetFormatType () const
{
    return m_eFormat;
}
//----------------------------------------------------------------------------
inline FrameBuffer::DepthType Renderer::GetDepthType () const
{
    return m_eDepth;
}
//----------------------------------------------------------------------------
inline FrameBuffer::StencilType Renderer::GetStencilType () const
{
    return m_eStencil;
}
//----------------------------------------------------------------------------
inline FrameBuffer::BufferingType Renderer::GetBufferingType () const
{
    return m_eBuffering;
}
//----------------------------------------------------------------------------
inline FrameBuffer::MultisamplingType Renderer::GetMultisamplingType () const
{
    return m_eMultisampling;
}
//----------------------------------------------------------------------------
inline int Renderer::GetWidth () const
{
    return m_iWidth;
}
//----------------------------------------------------------------------------
inline int Renderer::GetHeight () const
{
    return m_iHeight;
}
//----------------------------------------------------------------------------
inline void Renderer::ToggleFullscreen ()
{
    m_bFullscreen = !m_bFullscreen;
}
//----------------------------------------------------------------------------
inline void Renderer::SetBackgroundColor (const ColorRGBA& rkColor)
{
    m_kBackgroundColor = rkColor;
}
//----------------------------------------------------------------------------
inline const ColorRGBA& Renderer::GetBackgroundColor () const
{
    return m_kBackgroundColor;
}
//----------------------------------------------------------------------------
inline bool Renderer::BeginScene ()
{
    // stub for derived classes
    return true;
}
//----------------------------------------------------------------------------
inline void Renderer::EndScene ()
{
    // stub for derived classes
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxLights () const
{
    return m_iMaxLights;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxColors () const
{
    return m_iMaxColors;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxTCoords () const
{
    return m_iMaxTCoords;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxVShaderImages () const
{
    return m_iMaxVShaderImages;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxPShaderImages () const
{
    return m_iMaxPShaderImages;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxStencilIndices () const
{
    return m_iMaxStencilIndices;
}
//----------------------------------------------------------------------------
inline int Renderer::GetMaxUserClipPlanes () const
{
    return m_iMaxUserClipPlanes;
}
//----------------------------------------------------------------------------
inline void Renderer::SetAlphaState (AlphaState* pkState)
{
    m_aspkState[GlobalState::ALPHA] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetCullState (CullState* pkState)
{
    m_aspkState[GlobalState::CULL] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetMaterialState (MaterialState* pkState)
{
    m_aspkState[GlobalState::MATERIAL] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetPolygonOffsetState (PolygonOffsetState* pkState)
{
    m_aspkState[GlobalState::POLYGONOFFSET] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetStencilState (StencilState* pkState)
{
    m_aspkState[GlobalState::STENCIL] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetWireframeState (WireframeState* pkState)
{
    m_aspkState[GlobalState::WIREFRAME] = pkState;
}
//----------------------------------------------------------------------------
inline void Renderer::SetZBufferState (ZBufferState* pkState)
{
    m_aspkState[GlobalState::ZBUFFER] = pkState;
}
//----------------------------------------------------------------------------
inline AlphaState* Renderer::GetAlphaState ()
{
    return StaticCast<AlphaState>(m_aspkState[GlobalState::ALPHA]);
}
//----------------------------------------------------------------------------
inline CullState* Renderer::GetCullState ()
{
    return StaticCast<CullState>(m_aspkState[GlobalState::CULL]);
}
//----------------------------------------------------------------------------
inline MaterialState* Renderer::GetMaterialState ()
{
    return StaticCast<MaterialState>(m_aspkState[GlobalState::MATERIAL]);
}
//----------------------------------------------------------------------------
inline PolygonOffsetState* Renderer::GetPolygonOffsetState ()
{
    return StaticCast<PolygonOffsetState>(
        m_aspkState[GlobalState::POLYGONOFFSET]);
}
//----------------------------------------------------------------------------
inline StencilState* Renderer::GetStencilState ()
{
    return StaticCast<StencilState>(m_aspkState[GlobalState::STENCIL]);
}
//----------------------------------------------------------------------------
inline WireframeState* Renderer::GetWireframeState ()
{
    return StaticCast<WireframeState>(m_aspkState[GlobalState::WIREFRAME]);
}
//----------------------------------------------------------------------------
inline ZBufferState* Renderer::GetZBufferState ()
{
    return StaticCast<ZBufferState>(m_aspkState[GlobalState::ZBUFFER]);
}
//----------------------------------------------------------------------------
inline void Renderer::SetReverseCullFace (bool bReverseCullFace)
{
    m_bReverseCullFace = bReverseCullFace;
}
//----------------------------------------------------------------------------
inline bool Renderer::GetReverseCullFace () const
{
    return m_bReverseCullFace;
}
//----------------------------------------------------------------------------
inline void Renderer::SetLight (int i, Light* pkLight)
{
    assert(0 <= i && i < m_iMaxLights);
    m_aspkLight[i] = (Object*)pkLight;
}
//----------------------------------------------------------------------------
inline Light* Renderer::GetLight (int i)
{
    assert(0 <= i && i < m_iMaxLights);
    return StaticCast<Light>(m_aspkLight[i]);
}
//----------------------------------------------------------------------------
inline void Renderer::SetProjector (Camera* pkProjector)
{
    m_pkProjector = pkProjector;
}
//----------------------------------------------------------------------------
inline Camera* Renderer::GetProjector ()
{
    return m_pkProjector;
}
//----------------------------------------------------------------------------
