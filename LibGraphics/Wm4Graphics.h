// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4GRAPHICSPCH_H
#define WM4GRAPHICSPCH_H

// collision
#include "Wm4BoundingVolumeTree.h"
#include "Wm4BoxBVTree.h"
#include "Wm4CollisionGroup.h"
#include "Wm4CollisionRecord.h"
#include "Wm4SphereBVTree.h"

// controllers
#include "Wm4Controller.h"
#include "Wm4IKController.h"
#include "Wm4IKGoal.h"
#include "Wm4IKJoint.h"
#include "Wm4KeyframeController.h"
#include "Wm4MorphController.h"
#include "Wm4ParticleController.h"
#include "Wm4PointController.h"
#include "Wm4SkinController.h"

// curves
#include "Wm4CurveMesh.h"
#include "Wm4CurveSegment.h"

// details
#include "Wm4BillboardNode.h"
#include "Wm4ClodMesh.h"
#include "Wm4CollapseRecord.h"
#include "Wm4CreateClodMesh.h"
#include "Wm4DlodNode.h"
#include "Wm4SwitchNode.h"

// effects
#include "Wm4DefaultShaderEffect.h"
#include "Wm4Effect.h"
#include "Wm4LightingEffect.h"
#include "Wm4MaterialEffect.h"
#include "Wm4MaterialTextureEffect.h"
#include "Wm4MultitextureEffect.h"
#include "Wm4PlanarReflectionEffect.h"
#include "Wm4PlanarShadowEffect.h"
#include "Wm4TextureEffect.h"
#include "Wm4VertexColor3Effect.h"
#include "Wm4VertexColor4Effect.h"

// object system
#include "Wm4ImageVersion.h"
#include "Wm4Main.h"
#include "Wm4Object.h"
#include "Wm4Rtti.h"
#include "Wm4SmartPointer.h"
#include "Wm4Stream.h"
#include "Wm4StreamVersion.h"
#include "Wm4StringTree.h"

// rendering
#include "Wm4AlphaState.h"
#include "Wm4Bindable.h"
#include "Wm4Camera.h"
#include "Wm4CullState.h"
#include "Wm4FrameBuffer.h"
#include "Wm4GlobalState.h"
#include "Wm4Image.h"
#include "Wm4Light.h"
#include "Wm4MaterialState.h"
#include "Wm4PolygonOffsetState.h"
#include "Wm4Renderer.h"
#include "Wm4StencilState.h"
#include "Wm4Texture.h"
#include "Wm4WireframeState.h"
#include "Wm4ZBufferState.h"

// scene graph
#include "Wm4BoundingVolume.h"
#include "Wm4BoxBV.h"
#include "Wm4CameraNode.h"
#include "Wm4Culler.h"
#include "Wm4Geometry.h"
#include "Wm4LightNode.h"
#include "Wm4Node.h"
#include "Wm4Particles.h"
#include "Wm4Polyline.h"
#include "Wm4Polypoint.h"
#include "Wm4Spatial.h"
#include "Wm4SphereBV.h"
#include "Wm4StandardMesh.h"
#include "Wm4Transformation.h"
#include "Wm4TriMesh.h"
#include "Wm4VisibleObject.h"
#include "Wm4VisibleSet.h"

// shaders
#include "Wm4Attributes.h"
#include "Wm4ImageCatalog.h"
#include "Wm4IndexBuffer.h"
#include "Wm4NumericalConstant.h"
#include "Wm4PixelProgram.h"
#include "Wm4PixelProgramCatalog.h"
#include "Wm4PixelShader.h"
#include "Wm4Program.h"
#include "Wm4RendererConstant.h"
#include "Wm4SamplerInformation.h"
#include "Wm4Shader.h"
#include "Wm4ShaderEffect.h"
#include "Wm4UserConstant.h"
#include "Wm4VertexBuffer.h"
#include "Wm4VertexProgram.h"
#include "Wm4VertexProgramCatalog.h"
#include "Wm4VertexShader.h"

// shared arrays
#include "Wm4ColorRGBAArray.h"
#include "Wm4ColorRGBArray.h"
#include "Wm4DoubleArray.h"
#include "Wm4FloatArray.h"
#include "Wm4IntArray.h"
#include "Wm4Matrix2Array.h"
#include "Wm4Matrix3Array.h"
#include "Wm4Matrix4Array.h"
#include "Wm4Plane3Array.h"
#include "Wm4QuaternionArray.h"
#include "Wm4TSharedArray.h"
#include "Wm4Vector2Array.h"
#include "Wm4Vector3Array.h"
#include "Wm4Vector4Array.h"

// sorting
#include "Wm4BspNode.h"
#include "Wm4ConvexRegion.h"
#include "Wm4ConvexRegionManager.h"
#include "Wm4CRMCuller.h"
#include "Wm4Portal.h"

// surfaces
#include "Wm4BoxSurface.h"
#include "Wm4BSplineSurfacePatch.h"
#include "Wm4RectangleSurface.h"
#include "Wm4RevolutionSurface.h"
#include "Wm4SurfaceMesh.h"
#include "Wm4SurfacePatch.h"
#include "Wm4TubeSurface.h"

// terrain
#include "Wm4ClodTerrain.h"
#include "Wm4ClodTerrainBlock.h"
#include "Wm4ClodTerrainPage.h"
#include "Wm4ClodTerrainVertex.h"
#include "Wm4Terrain.h"
#include "Wm4TerrainPage.h"

#endif
