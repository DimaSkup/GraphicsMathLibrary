////////////////////////////////////////////////////////////////////
// Filename:      CoordinateSystem.h
// Description:   contains definitions of different coordinate systems
//
// Created:       13.09.23
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


// 3D spherical coordinates;
// point p(p, phi, theta) is defined by a distance and two angles (in radians):
//    p     - polar radius; distance from the coordinates beginning (pole) to the p point;
//    theta - latitude; it is an angle (in radians) between positive direction of
//            Z-axis and the line segment which goes from the pole to the p point;
//            is located in the interval [0, PI].
//    phi   - longitude; it is an angle (in radians) between projection onto the xy plane 
//            of a line segment which goes from the pole to the p point AND between positive
//            direction of X-axis;
//            (is analogue of a standard polar angle in the 2D polar coodrinates)
typedef struct SPHERICAL3D_TYPE
{
	float p = 0.0f;          // polar radius
	float theta = 0.0f;      // latitude
	float phi = 0.0f;        // longitude
} SPHERICAL3D, *SPHERICAL3D_PTR;