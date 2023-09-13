////////////////////////////////////////////////////////////////////
// Filename:      CoordinateSystem.h
// Description:   contains definitions for different coordinate systems
//
// Create:        13.09.23
////////////////////////////////////////////////////////////////////
#pragma once

// 2D polar coordinates;
//
// notation p(r, theta) means that the point is located at an angle of theta
// to the polar axis (which is usually X-axis) and in a counterclockwise(!) direction,
// at a distance r from the the pole
// 
typedef struct POLAR2D_TYPE
{
	float r = 0.0f;          // polar radius
	float theta = 0.0f;      // polar angle (in radians)
} POLAR2D, *POLAR2D_PTR;


// 3D cylindrical coordinates;
//
// this coordinate system is like 2D polar coordinates but we 
// also have Z-axis which means a height above XY-plane 
// (a negative Z means that a point is under XY-plane)
typedef struct CYLINDRICAL3D_TYPE
{
	float r = 0.0f;          // polar radius of a point
	float theta = 0.0f;      // polar angle of a point (in radians)
	float z = 0.0f;          // Z-coordinate of a point (height)
} CYLINDRICAL3D, *CYLINDRICAL3D_PTR;


