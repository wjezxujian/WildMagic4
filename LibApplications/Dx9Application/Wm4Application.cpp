// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4ApplicationPCH.h"
#include "Wm4Application.h"
using namespace Wm4;

Application::EntryPoint Application::Run = 0;
Command* Application::TheCommand = 0;
Application* Application::TheApplication = 0;

//----------------------------------------------------------------------------
Application::Application ()
{
    memset(m_acExtraData,0,APP_EXTRA_DATA_QUANTITY*sizeof(char));
    m_bLaunchFileDialog = false;
}
//----------------------------------------------------------------------------
Application::~Application ()
{
}
//----------------------------------------------------------------------------
void Application::SetExtraData (int iIndex, int iSize, const void* pvData)
{
    if (0 <= iIndex && iIndex < APP_EXTRA_DATA_QUANTITY - iSize)
    {
        System::Memcpy(m_acExtraData,APP_EXTRA_DATA_QUANTITY,pvData,iSize);
    }
}
//----------------------------------------------------------------------------
void Application::GetExtraData (int iIndex, int iSize, void* pvData) const
{
    if (0 <= iIndex && iIndex < APP_EXTRA_DATA_QUANTITY - iSize)
    {
        System::Memcpy(pvData,APP_EXTRA_DATA_QUANTITY,m_acExtraData,iSize);
    }
}
//----------------------------------------------------------------------------
bool Application::LaunchFileDialog () const
{
    return m_bLaunchFileDialog;
}
//----------------------------------------------------------------------------
void Application::TestStreaming (Spatial* pkScene, int iXPos, int iYPos,
    int iXSize, int iYSize, const char* acFilename)
{
    Stream kOStream;
    kOStream.Insert(pkScene);
    kOStream.Save(acFilename);

    Stream kIStream;
    kIStream.Load(acFilename);
    SpatialPtr spkScene = StaticCast<Spatial>(kIStream.GetObjectAt(0));
    spkScene->SetName(acFilename);

    LaunchTreeControl(spkScene,iXPos,iYPos,iXSize,iYSize);
}
//----------------------------------------------------------------------------
int main (int iQuantity, char* apcArgument[])
{
    // Sorry!  If you want to use the path to the Wild Magic 4 folder for
    // the purposes of searching for data files, you will need to create the
    // WM4_PATH environment variable.  The sample Wild Magic applications
    // rely on System::WM4_PATH to find scene graph object files (.wmof),
    // image files (.wmif), and shader program files (.wmsp).
    System::Initialize();
    assert(System::WM4_PATH[0]);
    std::string kWm4Path(System::WM4_PATH);

    Main::Initialize();

    int iExitCode = 0;
    if (Application::Run)
    {
        // Always check the current working directory.
        System::InsertDirectory(".");

        // The path to scene graph files.
        std::string kDir;
        kDir = kWm4Path + std::string("/Data/Wmof");
        System::InsertDirectory(kDir.c_str());

        // The path to texture image files.
        kDir = kWm4Path + std::string("/Data/Wmif");
        System::InsertDirectory(kDir.c_str());

        // The path to shader program files.
        kDir = kWm4Path + std::string("/Data/Wmsp");
        System::InsertDirectory(kDir.c_str());

        // The path to other images.
        kDir = kWm4Path + std::string("/Data/Im");
        System::InsertDirectory(kDir.c_str());

        Application::TheCommand = WM4_NEW Command(iQuantity,apcArgument);
        iExitCode = Application::Run(iQuantity,apcArgument);
        WM4_DELETE Application::TheCommand;
        Application::TheCommand = 0;

        System::RemoveAllDirectories();
    }
    else
    {
        iExitCode = INT_MAX;
    }

    Main::Terminate();

    WM4_DELETE Application::TheApplication;
    Application::TheApplication = 0;

    System::Terminate();

#ifdef WM4_MEMORY_MANAGER
#ifdef _DEBUG
    Memory::GenerateReport("MemoryReportDebug.txt");
#else
    Memory::GenerateReport("MemoryReportRelease.txt");
#endif
#endif

    return iExitCode;
}
//----------------------------------------------------------------------------
