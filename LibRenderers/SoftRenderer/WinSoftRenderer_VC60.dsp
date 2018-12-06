# Microsoft Developer Studio Project File - Name="WinSoftRenderer_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=WinSoftRenderer_VC60 - Win32 NoPCH
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WinSoftRenderer_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WinSoftRenderer_VC60.mak" CFG="WinSoftRenderer_VC60 - Win32 NoPCH"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WinSoftRenderer_VC60 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "WinSoftRenderer_VC60 - Win32 Debug Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "WinSoftRenderer_VC60 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "WinSoftRenderer_VC60 - Win32 Release Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "WinSoftRenderer_VC60 - Win32 NoPCH" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\\" /I "Wmsp" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4SoftRendererPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\SDK\Library\Debug\Wm4WinSoftRenderer60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Debug Memory"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\\" /I "Wmsp" /I "..\..\SDK\Include" /D "_DEBUG" /D "WM4_MEMORY_MANAGER" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4SoftRendererPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\SDK\Library\DebugMemory\Wm4WinSoftRenderer60d.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\DebugMemory\Wm4WinSoftRenderer60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\\" /I "Wmsp" /I "..\..\SDK\Include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4SoftRendererPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\SDK\Library\Release\Wm4WinSoftRenderer60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Release Memory"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\\" /I "Wmsp" /I "..\..\SDK\Include" /D "NDEBUG" /D "WM4_MEMORY_MANAGER" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4SoftRendererPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\SDK\Library\ReleaseMemory\Wm4WinSoftRenderer60.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\ReleaseMemory\Wm4WinSoftRenderer60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 NoPCH"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "NoPCH\VC60"
# PROP BASE Intermediate_Dir "NoPCH\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoPCH\VC60"
# PROP Intermediate_Dir "NoPCH\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\\" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4SoftRendererPCH.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\\" /I "Wmsp" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\SDK\Library\Debug\Wm4WinSoftRenderer60d.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\NoPCH\Wm4WinSoftRenderer60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include	copy *.inl ..\..\SDK\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "WinSoftRenderer_VC60 - Win32 Debug"
# Name "WinSoftRenderer_VC60 - Win32 Debug Memory"
# Name "WinSoftRenderer_VC60 - Win32 Release"
# Name "WinSoftRenderer_VC60 - Win32 Release Memory"
# Name "WinSoftRenderer_VC60 - Win32 NoPCH"
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm"
# Begin Source File

SOURCE=.\Wm4SoftArray.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftFrameBuffer.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftRenderer.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftResources.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler1.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler2.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler3.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSamplerCube.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSamplerProj.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftShaderLibrary.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftShaderLibraryMCR.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftShaderUtility.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftUtilityMCR.h
# End Source File
# Begin Source File

SOURCE=.\Wm4WinSoftRenderer.h
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Wm4SoftClipper.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftDrawElements.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftEdgeBuffers.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftFrameBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftPixelShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftPolygonOffsetState.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftRenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftResourcesED.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftResourcesLR.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler1.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler2.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler3.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSamplerCube.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSamplerProj.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftShaderUtility.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftTransformation.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftVertexShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4WinSoftRenderer.cpp
# End Source File
# Begin Source File

SOURCE=.\WmspWrapper.cpp
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "inl"
# Begin Source File

SOURCE=.\Wm4SoftArray.inl
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftFrameBuffer.inl
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftRenderer.inl
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler2.inl
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSampler3.inl
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftSamplerProj.inl
# End Source File
# End Group
# Begin Group "Shader Files"

# PROP Default_Filter ""
# Begin Group "Pixel Programs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Wmsp\p_Default.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_MaterialTexture.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_PassThrough3.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_PassThrough4.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_T0s1d0T1s1d1.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_T0s1d0T1s2d0.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_T0s1d0T1s3d1.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\p_Texture.sft.wmsp
# End Source File
# End Group
# Begin Group "Vertex Programs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Wmsp\v_Default.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_L1a.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_L1d.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_L1p.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_L1s.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_Material.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_MaterialTexture.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_T0d2T1d2PassThrough.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_Texture.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_VertexColor3.sft.wmsp
# End Source File
# Begin Source File

SOURCE=.\Wmsp\v_VertexColor4.sft.wmsp
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\Wm4SoftRendererLIB.h
# End Source File
# Begin Source File

SOURCE=.\Wm4SoftRendererPCH.cpp

!IF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Debug"

# ADD CPP /Yc"Wm4SoftRendererPCH.h"

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Debug Memory"

# ADD CPP /Yc"Wm4SoftRendererPCH.h"

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Release"

# ADD CPP /Yc"Wm4SoftRendererPCH.h"

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 Release Memory"

# ADD CPP /Yc"Wm4SoftRendererPCH.h"

!ELSEIF  "$(CFG)" == "WinSoftRenderer_VC60 - Win32 NoPCH"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Wm4SoftRendererPCH.h
# End Source File
# End Target
# End Project

