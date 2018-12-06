# Microsoft Developer Studio Project File - Name="ConvexHull3D_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ConvexHull3D_VC60 - Win32 Sft Debug Memory
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ConvexHull3D_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ConvexHull3D_VC60.mak" CFG="ConvexHull3D_VC60 - Win32 Sft Debug Memory"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ConvexHull3D_VC60 - Win32 Dx9 Debug" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Dx9 Debug Memory" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Dx9 Release" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Dx9 Release Memory" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Wgl Debug" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Wgl Debug Memory" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Wgl Release" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Wgl Release Memory" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Sft Debug" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Sft Debug Memory" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Sft Release" (based on "Win32 (x86) Application")
!MESSAGE "ConvexHull3D_VC60 - Win32 Sft Release Memory" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Dx9 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug\VC60"
# PROP BASE Intermediate_Dir "Debug\VC60"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\VC60"
# PROP Intermediate_Dir "Debug\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4Dx9Renderer60d.lib Wm4Dx9Application60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60Dx9DebSta.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\Debug"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Dx9 Debug Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMemory\VC60"
# PROP BASE Intermediate_Dir "DebugMemory\VC60"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMemory\VC60"
# PROP Intermediate_Dir "DebugMemory\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4Dx9Renderer60d.lib Wm4Dx9Application60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60Dx9DebMem.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\DebugMemory"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Dx9 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release\VC60"
# PROP BASE Intermediate_Dir "Release\VC60"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\VC60"
# PROP Intermediate_Dir "Release\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4Dx9Renderer60.lib Wm4Dx9Application60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60Dx9RelSta.exe" /libpath:"..\..\SDK\Library\Release"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Dx9 Release Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMemory\VC60"
# PROP BASE Intermediate_Dir "ReleaseMemory\VC60"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMemory\VC60"
# PROP Intermediate_Dir "ReleaseMemory\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4Dx9Renderer60.lib Wm4Dx9Application60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60Dx9RelMem.exe" /libpath:"..\..\SDK\Library\ReleaseMemory"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Wgl Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug\VC60"
# PROP BASE Intermediate_Dir "Debug\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\VC60"
# PROP Intermediate_Dir "Debug\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4WglRenderer60d.lib Wm4WglApplication60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60WglDebSta.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\Debug"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Wgl Debug Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMemory\VC60"
# PROP BASE Intermediate_Dir "DebugMemory\VC60"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMemory\VC60"
# PROP Intermediate_Dir "DebugMemory\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4WglRenderer60d.lib Wm4WglApplication60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60WglDebMem.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\DebugMemory"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Wgl Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release\VC60"
# PROP BASE Intermediate_Dir "Release\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\VC60"
# PROP Intermediate_Dir "Release\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4WglRenderer60.lib Wm4WglApplication60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60WglRelSta.exe" /libpath:"..\..\SDK\Library\Release"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Wgl Release Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMemory\VC60"
# PROP BASE Intermediate_Dir "ReleaseMemory\VC60"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMemory\VC60"
# PROP Intermediate_Dir "ReleaseMemory\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4WglRenderer60.lib Wm4WglApplication60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60WglRelMem.exe" /libpath:"..\..\SDK\Library\ReleaseMemory"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Sft Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ConvexHull3D_VC60___Win32_Sft_Debug"
# PROP BASE Intermediate_Dir "ConvexHull3D_VC60___Win32_Sft_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\VC60"
# PROP Intermediate_Dir "Debug\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4Dx9Renderer60d.lib Wm4Dx9Application60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60Dx9DebSta.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\Debug"
# ADD LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4WinSoftRenderer60d.lib Wm4WinSoftApplication60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60SftDebSta.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\Debug"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Sft Debug Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "ConvexHull3D_VC60___Win32_Sft_Debug_Memory"
# PROP BASE Intermediate_Dir "ConvexHull3D_VC60___Win32_Sft_Debug_Memory"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMemory\VC60"
# PROP Intermediate_Dir "DebugMemory\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4Dx9Renderer60d.lib Wm4Dx9Application60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60Dx9DebMem.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\DebugMemory"
# ADD LINK32 Wm4Foundation60d.lib Wm4Graphics60d.lib Wm4Physics60d.lib Wm4WinSoftRenderer60d.lib Wm4WinSoftApplication60d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /debug /machine:I386 /out:"ConvexHull3D_VC60SftDebMem.exe" /pdbtype:sept /libpath:"..\..\SDK\Library\DebugMemory"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Sft Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ConvexHull3D_VC60___Win32_Sft_Release"
# PROP BASE Intermediate_Dir "ConvexHull3D_VC60___Win32_Sft_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\VC60"
# PROP Intermediate_Dir "Release\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4Dx9Renderer60.lib Wm4Dx9Application60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60Dx9RelSta.exe" /libpath:"..\..\SDK\Library\Release"
# ADD LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4WinSoftRenderer60.lib Wm4WinSoftApplication60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60SftRelSta.exe" /libpath:"..\..\SDK\Library\Release"

!ELSEIF  "$(CFG)" == "ConvexHull3D_VC60 - Win32 Sft Release Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ConvexHull3D_VC60___Win32_Sft_Release_Memory"
# PROP BASE Intermediate_Dir "ConvexHull3D_VC60___Win32_Sft_Release_Memory"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMemory\VC60"
# PROP Intermediate_Dir "ReleaseMemory\VC60"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "WM4_MEMORY_MANAGER" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4Dx9Renderer60.lib Wm4Dx9Application60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60Dx9RelMem.exe" /libpath:"..\..\SDK\Library\ReleaseMemory"
# ADD LINK32 Wm4Foundation60.lib Wm4Graphics60.lib Wm4Physics60.lib Wm4WinSoftRenderer60.lib Wm4WinSoftApplication60.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"mainCRTStartup" /subsystem:windows /machine:I386 /out:"ConvexHull3D_VC60SftRelMem.exe" /libpath:"..\..\SDK\Library\ReleaseMemory"

!ENDIF 

# Begin Target

# Name "ConvexHull3D_VC60 - Win32 Dx9 Debug"
# Name "ConvexHull3D_VC60 - Win32 Dx9 Debug Memory"
# Name "ConvexHull3D_VC60 - Win32 Dx9 Release"
# Name "ConvexHull3D_VC60 - Win32 Dx9 Release Memory"
# Name "ConvexHull3D_VC60 - Win32 Wgl Debug"
# Name "ConvexHull3D_VC60 - Win32 Wgl Debug Memory"
# Name "ConvexHull3D_VC60 - Win32 Wgl Release"
# Name "ConvexHull3D_VC60 - Win32 Wgl Release Memory"
# Name "ConvexHull3D_VC60 - Win32 Sft Debug"
# Name "ConvexHull3D_VC60 - Win32 Sft Debug Memory"
# Name "ConvexHull3D_VC60 - Win32 Sft Release"
# Name "ConvexHull3D_VC60 - Win32 Sft Release Memory"
# Begin Group "Header Files"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=.\ConvexHull3D.h
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c"
# Begin Source File

SOURCE=.\ConvexHull3D.cpp
# End Source File
# End Group
# Begin Group "Data Files"

# PROP Default_Filter "txt"
# Begin Source File

SOURCE=.\Data\data01.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data02.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data03.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data04.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data05.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data06.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data07.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data08.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data09.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data10.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data11.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data12.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data13.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data14.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data15.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data16.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data17.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data18.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data19.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data20.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data21.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data22.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data23.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data24.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data25.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data26.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data27.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data28.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data29.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data30.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data31.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data32.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data33.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data34.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data35.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data36.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data37.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data38.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data39.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data40.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data41.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data42.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data43.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data44.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data45.txt
# End Source File
# Begin Source File

SOURCE=.\Data\data46.txt
# End Source File
# End Group
# End Target
# End Project

