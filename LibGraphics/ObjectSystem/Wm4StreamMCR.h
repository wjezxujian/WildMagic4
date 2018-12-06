// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4STREAMMCR_H
#define WM4STREAMMCR_H

//----------------------------------------------------------------------------
#define WM4_DECLARE_STREAM \
public: \
    static bool RegisterFactory (); \
    static void InitializeFactory (); \
    static Object* Factory (Stream& rkStream); \
    virtual void Load (Stream& rkStream, Stream::Link* pkLink); \
    virtual void Link (Stream& rkStream, Stream::Link* pkLink); \
    virtual bool Register (Stream& rkStream) const; \
    virtual void Save (Stream& rkStream) const; \
    virtual int GetDiskUsed (const StreamVersion& rkVersion) const; \
    virtual StringTree* SaveStrings (const char* acTitle = 0); \
private: \
    static bool ms_bStreamRegistered
//----------------------------------------------------------------------------
#define WM4_DECLARE_TEMPLATE_STREAM \
public: \
    static bool RegisterFactory (); \
    static void InitializeFactory (); \
    static Object* Factory (Stream& rkStream); \
    virtual void Load (Stream& rkStream, Stream::Link* pkLink); \
    virtual void Link (Stream& rkStream, Stream::Link* pkLink); \
    virtual bool Register (Stream& rkStream) const; \
    virtual void Save (Stream& rkStream) const; \
    virtual int GetDiskUsed (const StreamVersion& rkVersion) const; \
    virtual StringTree* SaveStrings (const char* acTitle = 0); \
private: \
    WM4_GRAPHICS_ITEM static bool ms_bStreamRegistered
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_STREAM(classname) \
bool classname::ms_bStreamRegistered = false; \
\
bool classname::RegisterFactory () \
{ \
    if (!ms_bStreamRegistered) \
    { \
        Main::AddInitializer(classname::InitializeFactory); \
        ms_bStreamRegistered = true; \
    } \
    return ms_bStreamRegistered; \
} \
\
void classname::InitializeFactory () \
{ \
    if (!ms_pkFactory) \
    { \
        ms_pkFactory = WM4_NEW TStringHashTable<FactoryFunction>( \
            FACTORY_MAP_SIZE); \
    } \
    ms_pkFactory->Insert(TYPE.GetName(),(FactoryFunction)Factory); \
} \
\
Object* classname::Factory (Stream& rkStream) \
{ \
    classname* pkObject = WM4_NEW classname; \
    Stream::Link* pkLink = WM4_NEW Stream::Link(pkObject); \
    pkObject->Load(rkStream,pkLink); \
    return pkObject; \
}
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_ABSTRACT_STREAM(classname) \
bool classname::ms_bStreamRegistered = false; \
\
bool classname::RegisterFactory () \
{ \
    if (!ms_bStreamRegistered) \
    { \
        Main::AddInitializer(classname::InitializeFactory); \
        ms_bStreamRegistered = true; \
    } \
    return ms_bStreamRegistered; \
} \
\
void classname::InitializeFactory () \
{ \
    if (!ms_pkFactory) \
    { \
        ms_pkFactory = WM4_NEW TStringHashTable<FactoryFunction>( \
            FACTORY_MAP_SIZE); \
    } \
    ms_pkFactory->Insert(TYPE.GetName(),(FactoryFunction)Factory); \
} \
\
Object* classname::Factory (Stream&) \
{ \
    assert(false); \
    return 0; \
}
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_TEMPLATE_STREAM(classname) \
template <> \
bool classname::ms_bStreamRegistered = false;
//----------------------------------------------------------------------------
#define WM4_IMPLEMENT_DEFAULT_STREAM(classname,baseclassname) \
void classname::Load (Stream& rkStream, Stream::Link* pkLink) \
{ \
    WM4_BEGIN_DEBUG_STREAM_LOAD; \
    baseclassname::Load(rkStream,pkLink); \
    WM4_END_DEBUG_STREAM_LOAD(classname); \
} \
\
void classname::Link (Stream& rkStream, Stream::Link* pkLink) \
{ \
    baseclassname::Link(rkStream,pkLink); \
} \
\
bool classname::Register (Stream& rkStream) const \
{ \
    return baseclassname::Register(rkStream); \
} \
\
void classname::Save (Stream& rkStream) const \
{ \
    WM4_BEGIN_DEBUG_STREAM_SAVE; \
    baseclassname::Save(rkStream); \
    WM4_END_DEBUG_STREAM_SAVE(classname); \
} \
\
int classname::GetDiskUsed (const StreamVersion& rkVersion) const \
{ \
    return baseclassname::GetDiskUsed(rkVersion); \
} \
\
StringTree* classname::SaveStrings (const char*) \
{ \
    StringTree* pkTree = WM4_NEW StringTree; \
    pkTree->Append(Format(&TYPE,GetName().c_str())); \
    pkTree->Append(baseclassname::SaveStrings()); \
    return pkTree; \
} \
//----------------------------------------------------------------------------
#define WM4_REGISTER_STREAM(classname) \
static bool gs_bStreamRegistered_##classname = \
    classname::RegisterFactory ()
//----------------------------------------------------------------------------
#ifdef _DEBUG
#define WM4_BEGIN_DEBUG_STREAM_LOAD \
    int iBeginLoad_ = rkStream.GetBufferNext()
#else
#define WM4_BEGIN_DEBUG_STREAM_LOAD
#endif
//----------------------------------------------------------------------------
#ifdef _DEBUG
#define WM4_END_DEBUG_STREAM_LOAD(classname) \
    int iEndLoad_ = rkStream.GetBufferNext(); \
    int iUsedLoad_ = iEndLoad_ - iBeginLoad_ + GetType().GetDiskUsed(); \
    int iUsedReported_ = classname::GetDiskUsed(rkStream.GetVersion()); \
    assert(iUsedLoad_ == iUsedReported_)
#else
#define WM4_END_DEBUG_STREAM_LOAD(classname)
#endif
//----------------------------------------------------------------------------
#ifdef _DEBUG
#define WM4_BEGIN_DEBUG_STREAM_SAVE \
    int iBeginSave_ = rkStream.GetBufferNext()
#else
#define WM4_BEGIN_DEBUG_STREAM_SAVE
#endif
//----------------------------------------------------------------------------
#ifdef _DEBUG
#define WM4_END_DEBUG_STREAM_SAVE(classname) \
    int iEndSave_ = rkStream.GetBufferNext(); \
    int iUsedSave_ = iEndSave_ - iBeginSave_; \
    int iUsedReported_ = classname::GetDiskUsed( \
        StreamVersion(StreamVersion::MAJOR,StreamVersion::MINOR)); \
    assert(iUsedSave_ == iUsedReported_)
#else
#define WM4_END_DEBUG_STREAM_SAVE(classname)
#endif
//----------------------------------------------------------------------------

#endif
