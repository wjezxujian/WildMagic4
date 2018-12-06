# Microsoft Developer Studio Project File - Name="LibGraphics_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=LibGraphics_VC60 - Win32 NoPCH
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LibGraphics_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibGraphics_VC60.mak" CFG="LibGraphics_VC60 - Win32 NoPCH"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibGraphics_VC60 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibGraphics_VC60 - Win32 Debug Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "LibGraphics_VC60 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibGraphics_VC60 - Win32 Release Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "LibGraphics_VC60 - Win32 NoPCH" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LibGraphics_VC60 - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Collision" /I "Controllers" /I "Curves" /I "Detail" /I "Effects" /I "ObjectSystem" /I "Rendering" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "Terrain" /I "..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4GraphicsPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\SDK\Library\Debug\Wm4Graphics60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Collision\*.h ..\SDK\Include	copy Collision\*.inl ..\SDK\Include	copy Controllers\*.h ..\SDK\Include	copy Controllers\*.inl ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Curves\*.inl ..\SDK\Include	copy Detail\*.h ..\SDK\Include	copy Detail\*.inl ..\SDK\Include	copy Effects\*.h ..\SDK\Include	copy Effects\*.inl ..\SDK\Include	copy ObjectSystem\*.h ..\SDK\Include	copy ObjectSystem\*.inl ..\SDK\Include	copy Rendering\*.h ..\SDK\Include	copy Rendering\*.inl ..\SDK\Include	copy SceneGraph\*.h ..\SDK\Include	copy SceneGraph\*.inl ..\SDK\Include	copy Shaders\*.h ..\SDK\Include	copy Shaders\*.inl ..\SDK\Include	copy SharedArrays\*.h ..\SDK\Include	copy SharedArrays\*.inl ..\SDK\Include	copy Sorting\*.h ..\SDK\Include	copy Sorting\*.inl ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy Surfaces\*.inl ..\SDK\Include	copy Terrain\*.h ..\SDK\Include	copy Terrain\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 Debug Memory"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Collision" /I "Controllers" /I "Curves" /I "Detail" /I "Effects" /I "ObjectSystem" /I "Rendering" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "Terrain" /I "..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /D "WM4_MEMORY_MANAGER" /Yu"Wm4GraphicsPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm3Graphics60d.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\DebugMemory\Wm4Graphics60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Collision\*.h ..\SDK\Include	copy Collision\*.inl ..\SDK\Include	copy Controllers\*.h ..\SDK\Include	copy Controllers\*.inl ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Curves\*.inl ..\SDK\Include	copy Detail\*.h ..\SDK\Include	copy Detail\*.inl ..\SDK\Include	copy Effects\*.h ..\SDK\Include	copy Effects\*.inl ..\SDK\Include	copy ObjectSystem\*.h ..\SDK\Include	copy ObjectSystem\*.inl ..\SDK\Include	copy Rendering\*.h ..\SDK\Include	copy Rendering\*.inl ..\SDK\Include	copy SceneGraph\*.h ..\SDK\Include	copy SceneGraph\*.inl ..\SDK\Include	copy Shaders\*.h ..\SDK\Include	copy Shaders\*.inl ..\SDK\Include	copy SharedArrays\*.h ..\SDK\Include	copy SharedArrays\*.inl ..\SDK\Include	copy Sorting\*.h ..\SDK\Include	copy Sorting\*.inl ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy Surfaces\*.inl ..\SDK\Include	copy Terrain\*.h ..\SDK\Include	copy Terrain\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "Collision" /I "Controllers" /I "Curves" /I "Detail" /I "Effects" /I "ObjectSystem" /I "Rendering" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "Terrain" /I "..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4GraphicsPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\SDK\Library\Release\Wm4Graphics60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Collision\*.h ..\SDK\Include	copy Collision\*.inl ..\SDK\Include	copy Controllers\*.h ..\SDK\Include	copy Controllers\*.inl ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Curves\*.inl ..\SDK\Include	copy Detail\*.h ..\SDK\Include	copy Detail\*.inl ..\SDK\Include	copy Effects\*.h ..\SDK\Include	copy Effects\*.inl ..\SDK\Include	copy ObjectSystem\*.h ..\SDK\Include	copy ObjectSystem\*.inl ..\SDK\Include	copy Rendering\*.h ..\SDK\Include	copy Rendering\*.inl ..\SDK\Include	copy SceneGraph\*.h ..\SDK\Include	copy SceneGraph\*.inl ..\SDK\Include	copy Shaders\*.h ..\SDK\Include	copy Shaders\*.inl ..\SDK\Include	copy SharedArrays\*.h ..\SDK\Include	copy SharedArrays\*.inl ..\SDK\Include	copy Sorting\*.h ..\SDK\Include	copy Sorting\*.inl ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy Surfaces\*.inl ..\SDK\Include	copy Terrain\*.h ..\SDK\Include	copy Terrain\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 Release Memory"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "Collision" /I "Controllers" /I "Curves" /I "Detail" /I "Effects" /I "ObjectSystem" /I "Rendering" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "Terrain" /I "..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /D "WM4_MEMORY_MANAGER" /Yu"Wm4GraphicsPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Release\Wm3Graphics60.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\ReleaseMemory\Wm4Graphics60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Collision\*.h ..\SDK\Include	copy Collision\*.inl ..\SDK\Include	copy Controllers\*.h ..\SDK\Include	copy Controllers\*.inl ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Curves\*.inl ..\SDK\Include	copy Detail\*.h ..\SDK\Include	copy Detail\*.inl ..\SDK\Include	copy Effects\*.h ..\SDK\Include	copy Effects\*.inl ..\SDK\Include	copy ObjectSystem\*.h ..\SDK\Include	copy ObjectSystem\*.inl ..\SDK\Include	copy Rendering\*.h ..\SDK\Include	copy Rendering\*.inl ..\SDK\Include	copy SceneGraph\*.h ..\SDK\Include	copy SceneGraph\*.inl ..\SDK\Include	copy Shaders\*.h ..\SDK\Include	copy Shaders\*.inl ..\SDK\Include	copy SharedArrays\*.h ..\SDK\Include	copy SharedArrays\*.inl ..\SDK\Include	copy Sorting\*.h ..\SDK\Include	copy Sorting\*.inl ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy Surfaces\*.inl ..\SDK\Include	copy Terrain\*.h ..\SDK\Include	copy Terrain\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 NoPCH"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "LibGraphics_VC60___Win32_NoPCH"
# PROP BASE Intermediate_Dir "LibGraphics_VC60___Win32_NoPCH"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoPCH\VC60"
# PROP Intermediate_Dir "NoPCH\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM3_USE_PRECOMPILED_HEADERS" /Yu"Wm3GraphicsPCH.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Collision" /I "Controllers" /I "Curves" /I "Detail" /I "Effects" /I "ObjectSystem" /I "Rendering" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "Terrain" /I "..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm3Graphics60d.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\NoPCH\Wm4Graphics60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Collision\*.h ..\SDK\Include	copy Collision\*.inl ..\SDK\Include	copy Controllers\*.h ..\SDK\Include	copy Controllers\*.inl ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Curves\*.inl ..\SDK\Include	copy Detail\*.h ..\SDK\Include	copy Detail\*.inl ..\SDK\Include	copy Effects\*.h ..\SDK\Include	copy Effects\*.inl ..\SDK\Include	copy ObjectSystem\*.h ..\SDK\Include	copy ObjectSystem\*.inl ..\SDK\Include	copy Rendering\*.h ..\SDK\Include	copy Rendering\*.inl ..\SDK\Include	copy SceneGraph\*.h ..\SDK\Include	copy SceneGraph\*.inl ..\SDK\Include	copy Shaders\*.h ..\SDK\Include	copy Shaders\*.inl ..\SDK\Include	copy SharedArrays\*.h ..\SDK\Include	copy SharedArrays\*.inl ..\SDK\Include	copy Sorting\*.h ..\SDK\Include	copy Sorting\*.inl ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy Surfaces\*.inl ..\SDK\Include	copy Terrain\*.h ..\SDK\Include	copy Terrain\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "LibGraphics_VC60 - Win32 Debug"
# Name "LibGraphics_VC60 - Win32 Debug Memory"
# Name "LibGraphics_VC60 - Win32 Release"
# Name "LibGraphics_VC60 - Win32 Release Memory"
# Name "LibGraphics_VC60 - Win32 NoPCH"
# Begin Group "Collision"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Collision\Wm4BoundingVolumeTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4BoundingVolumeTree.h
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4BoundingVolumeTree.inl
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4BoxBVTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4BoxBVTree.h
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4CollisionGroup.cpp
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4CollisionGroup.h
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4CollisionRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4CollisionRecord.h
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4CollisionRecord.inl
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4SphereBVTree.cpp
# End Source File
# Begin Source File

SOURCE=.\Collision\Wm4SphereBVTree.h
# End Source File
# End Group
# Begin Group "Controllers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Controllers\Wm4Controller.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4Controller.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4Controller.inl
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKController.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKController.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKGoal.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKGoal.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKGoal.inl
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKJoint.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4IKJoint.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4KeyframeController.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4KeyframeController.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4MorphController.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4MorphController.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4MorphController.inl
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4ParticleController.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4ParticleController.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4ParticleController.inl
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4PointController.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4PointController.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4PointController.inl
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4SkinController.cpp
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4SkinController.h
# End Source File
# Begin Source File

SOURCE=.\Controllers\Wm4SkinController.inl
# End Source File
# End Group
# Begin Group "Curves"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Curves\Wm4CurveMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CurveMesh.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CurveMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CurveSegment.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CurveSegment.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CurveSegment.inl
# End Source File
# End Group
# Begin Group "Detail"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Detail\Wm4BillboardNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4BillboardNode.h
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4BillboardNode.inl
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4ClodMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4ClodMesh.h
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4ClodMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4CollapseRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4CollapseRecord.h
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4CreateClodMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4CreateClodMesh.h
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4DlodNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4DlodNode.h
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4DlodNode.inl
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4SwitchNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4SwitchNode.h
# End Source File
# Begin Source File

SOURCE=.\Detail\Wm4SwitchNode.inl
# End Source File
# End Group
# Begin Group "Effects"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Effects\Wm4DefaultShaderEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4DefaultShaderEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4Effect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4Effect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4LightingEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4LightingEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4LightingEffect.inl
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4MaterialEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4MaterialEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4MaterialTextureEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4MaterialTextureEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4MultitextureEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4MultitextureEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4PlanarReflectionEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4PlanarReflectionEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4PlanarReflectionEffect.inl
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4PlanarShadowEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4PlanarShadowEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4PlanarShadowEffect.inl
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4ShaderEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4ShaderEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4TextureEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4TextureEffect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4VertexColor3Effect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4VertexColor3Effect.h
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4VertexColor4Effect.cpp
# End Source File
# Begin Source File

SOURCE=.\Effects\Wm4VertexColor4Effect.h
# End Source File
# End Group
# Begin Group "ObjectSystem"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ObjectSystem\Wm4ImageVersion.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4ImageVersion.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Main.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Main.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4MainMCR.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4NameIdMCR.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Object.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Object.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Object.inl
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Rtti.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Rtti.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Rtti.inl
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4RttiMCR.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4SmartPointer.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4SmartPointer.inl
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Stream.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Stream.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4Stream.inl
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4StreamMCR.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4StreamVersion.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4StreamVersion.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4StringTree.cpp
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4StringTree.h
# End Source File
# Begin Source File

SOURCE=.\ObjectSystem\Wm4StringTree.inl
# End Source File
# End Group
# Begin Group "Rendering"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Rendering\Wm4AlphaState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4AlphaState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Bindable.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Bindable.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Camera.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Camera.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Camera.inl
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4CullState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4CullState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4FrameBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4FrameBuffer.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4FrameBuffer.inl
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4GlobalState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4GlobalState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Image.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Image.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Image.inl
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Light.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Light.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4MaterialState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4MaterialState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4PolygonOffsetState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4PolygonOffsetState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Renderer.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Renderer.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Renderer.inl
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4StencilState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4StencilState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Texture.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Texture.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4Texture.inl
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4WireframeState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4WireframeState.h
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4ZBufferState.cpp
# End Source File
# Begin Source File

SOURCE=.\Rendering\Wm4ZBufferState.h
# End Source File
# End Group
# Begin Group "SceneGraph"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SceneGraph\Wm4Attributes.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Attributes.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Attributes.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4BoundingVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4BoundingVolume.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4BoxBV.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4BoxBV.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4BoxBV.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4CameraNode.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4CameraNode.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4CameraNode.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Culler.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Culler.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Culler.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Geometry.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Geometry.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Geometry.inl
# End Source File
# Begin Source File

SOURCE=.\Wm4Graphics.h
# End Source File
# Begin Source File

SOURCE=.\Wm4GraphicsLIB.h
# End Source File
# Begin Source File

SOURCE=.\Wm4GraphicsPCH.cpp

!IF  "$(CFG)" == "LibGraphics_VC60 - Win32 Debug"

# ADD CPP /Yc"Wm4GraphicsPCH.h"

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 Debug Memory"

# ADD CPP /Yc"Wm4GraphicsPCH.h"

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 Release"

# ADD CPP /Yc"Wm4GraphicsPCH.h"

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 Release Memory"

# ADD CPP /Yc"Wm4GraphicsPCH.h"

!ELSEIF  "$(CFG)" == "LibGraphics_VC60 - Win32 NoPCH"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Wm4GraphicsPCH.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4IndexBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4IndexBuffer.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4IndexBuffer.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4LightNode.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4LightNode.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4LightNode.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Node.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Node.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Node.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Particles.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Particles.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Particles.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Polyline.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Polyline.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Polyline.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Polypoint.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Polypoint.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Polypoint.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Spatial.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Spatial.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Spatial.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4SphereBV.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4SphereBV.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4SphereBV.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4StandardMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4StandardMesh.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Transformation.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Transformation.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4Transformation.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4TriMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4TriMesh.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4TriMesh.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VertexBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VertexBuffer.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VertexBuffer.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VisibleObject.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VisibleObject.inl
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VisibleSet.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VisibleSet.h
# End Source File
# Begin Source File

SOURCE=.\SceneGraph\Wm4VisibleSet.inl
# End Source File
# End Group
# Begin Group "Shaders"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Shaders\Wm4ImageCatalog.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4ImageCatalog.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4NumericalConstant.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4NumericalConstant.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4NumericalConstant.inl
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4PixelProgram.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4PixelProgram.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4PixelProgramCatalog.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4PixelProgramCatalog.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4PixelShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4PixelShader.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4Program.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4Program.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4Program.inl
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4RendererConstant.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4RendererConstant.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4RendererConstant.inl
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4SamplerInformation.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4SamplerInformation.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4SamplerInformation.inl
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4Shader.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4Shader.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4Shader.inl
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4UserConstant.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4UserConstant.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4UserConstant.inl
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4VertexProgram.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4VertexProgram.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4VertexProgramCatalog.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4VertexProgramCatalog.h
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4VertexShader.cpp
# End Source File
# Begin Source File

SOURCE=.\Shaders\Wm4VertexShader.h
# End Source File
# End Group
# Begin Group "SharedArrays"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\SharedArrays\Wm4ColorRGBAArray.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4ColorRGBAArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4ColorRGBArray.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4ColorRGBArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4DoubleArray.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4DoubleArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4FloatArray.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4FloatArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4IntArray.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4IntArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Matrix2Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Matrix2Array.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Matrix3Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Matrix3Array.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Matrix4Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Matrix4Array.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Plane3Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Plane3Array.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4QuaternionArray.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4QuaternionArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4TSharedArray.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4TSharedArray.inl
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Vector2Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Vector2Array.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Vector3Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Vector3Array.h
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Vector4Array.cpp
# End Source File
# Begin Source File

SOURCE=.\SharedArrays\Wm4Vector4Array.h
# End Source File
# End Group
# Begin Group "Sorting"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sorting\Wm4BspNode.cpp
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4BspNode.h
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4BspNode.inl
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4ConvexRegion.cpp
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4ConvexRegion.h
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4ConvexRegion.inl
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4ConvexRegionManager.cpp
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4ConvexRegionManager.h
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4CRMCuller.cpp
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4CRMCuller.h
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4Portal.cpp
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4Portal.h
# End Source File
# Begin Source File

SOURCE=.\Sorting\Wm4Portal.inl
# End Source File
# End Group
# Begin Group "Surfaces"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Surfaces\Wm4BoxSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4BoxSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4BoxSurface.inl
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4BSplineSurfacePatch.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4BSplineSurfacePatch.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4RectangleSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4RectangleSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4RectangleSurface.inl
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4RevolutionSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4RevolutionSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4RevolutionSurface.inl
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4SurfaceMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4SurfaceMesh.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4SurfaceMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4SurfacePatch.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4SurfacePatch.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4SurfacePatch.inl
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4TubeSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4TubeSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4TubeSurface.inl
# End Source File
# End Group
# Begin Group "Terrain"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrain.cpp
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrain.h
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrain.inl
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainBlock.h
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainBlock.inl
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainPage.h
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainPage.inl
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainVertex.cpp
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainVertex.h
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4ClodTerrainVertex.inl
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4Terrain.cpp
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4Terrain.h
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4Terrain.inl
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4TerrainPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4TerrainPage.h
# End Source File
# Begin Source File

SOURCE=.\Terrain\Wm4TerrainPage.inl
# End Source File
# End Group
# End Target
# End Project

