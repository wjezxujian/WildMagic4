# Microsoft Developer Studio Project File - Name="WglApplication_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=WglApplication_VC60 - Win32 NoPCH
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WglApplication_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WglApplication_VC60.mak" CFG="WglApplication_VC60 - Win32 NoPCH"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WglApplication_VC60 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "WglApplication_VC60 - Win32 Debug Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "WglApplication_VC60 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "WglApplication_VC60 - Win32 Release Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "WglApplication_VC60 - Win32 NoPCH" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WglApplication_VC60 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug\VC60"
# PROP BASE Intermediate_Dir "Debug\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\VC60"
# PROP Intermediate_Dir "Debug\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "TreeControl" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4ApplicationPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\SDK\Library\Debug\Wm4WglApplication60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 Debug Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMemory\VC60"
# PROP BASE Intermediate_Dir "DebugMemory\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMemory\VC60"
# PROP Intermediate_Dir "DebugMemory\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "TreeControl" /I "..\..\SDK\Include" /D "_DEBUG" /D "WM4_MEMORY_MANAGER" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4ApplicationPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm4WglApplication60d.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\DebugMemory\Wm4WglApplication60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release\VC60"
# PROP BASE Intermediate_Dir "Release\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\VC60"
# PROP Intermediate_Dir "Release\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "TreeControl" /I "..\..\SDK\Include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4ApplicationPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\SDK\Library\Release\Wm4WglApplication60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 Release Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMemory\VC60"
# PROP BASE Intermediate_Dir "ReleaseMemory\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMemory\VC60"
# PROP Intermediate_Dir "ReleaseMemory\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "TreeControl" /I "..\..\SDK\Include" /D "NDEBUG" /D "WM4_MEMORY_MANAGER" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4ApplicationPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Release\Wm4WglApplication60.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\ReleaseMemory\Wm4WglApplication60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 NoPCH"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WglApplication_VC60___Win32_NoPCH"
# PROP BASE Intermediate_Dir "WglApplication_VC60___Win32_NoPCH"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoPCH\VC60"
# PROP Intermediate_Dir "NoPCH\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\\" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4ApplicationPCH.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "TreeControl" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\SDK\Library\Debug\Wm4WglApplication60d.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\NoPCH\Wm4WglApplication60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "WglApplication_VC60 - Win32 Debug"
# Name "WglApplication_VC60 - Win32 Debug Memory"
# Name "WglApplication_VC60 - Win32 Release"
# Name "WglApplication_VC60 - Win32 Release Memory"
# Name "WglApplication_VC60 - Win32 NoPCH"
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm"
# Begin Source File

SOURCE=.\Wm4Application.h
# End Source File
# Begin Source File

SOURCE=.\Wm4ApplicationMCR.h
# End Source File
# Begin Source File

SOURCE=.\Wm4ConsoleApplication.h
# End Source File
# Begin Source File

SOURCE=.\Wm4WindowApplication.h
# End Source File
# Begin Source File

SOURCE=.\Wm4WindowApplication2.h
# End Source File
# Begin Source File

SOURCE=.\Wm4WindowApplication3.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "inl"
# Begin Source File

SOURCE=.\Wm4WindowApplication.inl
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Wm4Application.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4ConsoleApplication.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4WglApplication.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4WindowApplication.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4WindowApplication2.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4WindowApplication3.cpp
# End Source File
# End Group
# Begin Group "Tree Control Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\TreeControl\TreeControl.cpp
# End Source File
# Begin Source File

SOURCE=.\TreeControl\TreeControl.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Wm4ApplicationPCH.h
# End Source File
# Begin Source File

SOURCE=.\Wm4WglApplicationPCH.cpp

!IF  "$(CFG)" == "WglApplication_VC60 - Win32 Debug"

# ADD CPP /Yc"Wm4ApplicationPCH.h"

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 Debug Memory"

# ADD CPP /Yc"Wm4ApplicationPCH.h"

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 Release"

# ADD CPP /Yc"Wm4ApplicationPCH.h"

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 Release Memory"

# ADD CPP /Yc"Wm4ApplicationPCH.h"

!ELSEIF  "$(CFG)" == "WglApplication_VC60 - Win32 NoPCH"

# ADD BASE CPP /Yc"Wm4ApplicationPCH.h"
# SUBTRACT CPP /YX /Yc

!ENDIF 

# End Source File
# End Target
# End Project

