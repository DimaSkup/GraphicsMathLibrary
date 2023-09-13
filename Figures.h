////////////////////////////////////////////////////////////////////
// Filename:      Figures.h
// Description:   contains definitions for geometric figures:
//                parametric lines, 3D planes, etc.
//
// Create:        13.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "VectorAndPoint.h"



////////////////////////////////////////////////////////////////////
//
//                      PARAMETRIC LINES
//
////////////////////////////////////////////////////////////////////

// 2D parametric line
typedef struct PARAMLINE2D_TYPE
{
	POINT2D p0;   // start point
	POINT2D p1;   // end point
	VECTOR2D v;   // direction vector: |v| = |p0 -> p1|
} PARAMLINE2D, *PARAMLINE2D_PTR;


// 3D parametric line
typedef struct PARAMLINE3D_TYPE
{
	POINT3D p0;   // start point
	POINT3D p1;   // end point
	VECTOR3D v;   // direction vector: |v| = |p0 -> p1|
} PARAMLINE3D, *PARAMLINE3D_PTR;




////////////////////////////////////////////////////////////////////
//
//                          3D PLANES
//
////////////////////////////////////////////////////////////////////

// 3D plane
typedef struct PLANE3D_TYPE
{
	POINT3D p0;   // point on the plane
	VECTOR3D n;   // normal vector (not necessary a unit vector)
} PLANE3D, *PLANE3D_PTR;
