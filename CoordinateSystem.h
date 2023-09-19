////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      CoordinateSystem.h
// Description:   contains definitions of different coordinate systems
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cmath>

#include "VectorAndPoint/VectorAndPoint.h"
#include "MathConstant.h"

namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                               DATA STRUCTURES
////////////////////////////////////////////////////////////////////////////////////////////

// 2D polar coordinates;
//
// notation p(r, theta) means that the point is located at an angle of theta
// to the polar axis (which is usually X-axis) and in a counterclockwise(!) direction,
// at a distance r from the the pole
// 
typedef struct POLAR2D_TYPE
{
	POLAR2D_TYPE(float radius, float thetaRad)
	{
		r = radius;
		theta = thetaRad;
	}

	float r;          // polar radius
	float theta;      // polar angle (in radians)
} POLAR2D, *POLAR2D_PTR;


// 3D cylindrical coordinates;
//
// this coordinate system is like 2D polar coordinates but we 
// also have Z-axis which means a height above XY-plane 
// (a negative Z means that a point is under XY-plane)
typedef struct CYLINDRICAL3D_TYPE
{
	float r;          // polar radius of a point
	float theta;      // polar angle of a point (in radians)
	float z;          // Z-coordinate of a point (height)
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





////////////////////////////////////////////////////////////////////////////////////////////
//                  FUNCTIONS TO WORK WITH COODRINATE SYSTEMS
////////////////////////////////////////////////////////////////////////////////////////////

void POLAR2D_To_POINT2D(const POLAR2D* pPolar, POINT2D* pRect)
{
	// convert 2D polar coordinates to decart (rectangular) coordinates
	pRect->x = pPolar->r * cosf(pPolar->theta);
	pRect->y = pPolar->r * sinf(pPolar->theta);

} // end POLAR2D_TO_POINT2D

/////////////////////////////////////////////////////////////

void POLAR2D_To_RectXY(const POLAR2D* pPolar, 
	float* x, 
	float* y)
{
	// convert polar to decart (rectangular) coordinates
	*x = pPolar->r * cosf(pPolar->theta);
	*y = pPolar->r * sinf(pPolar->theta);

} // end POLAR2D_To_RectXY

/////////////////////////////////////////////////////////////


void POINT2D_To_POLAR2D(const POINT2D* pRect, POLAR2D* pPolar)
{
	// convert rectangular (decart) coordinates to polar
	pPolar->r = sqrtf((pRect->x * pRect->x) + (pRect->y * pRect->y));
	pPolar->theta = atanf(pRect->y / pRect->x);

} // end POINT2D_To_POLAR2D

void POINT2D_To_PolarRTh(const POINT2D* pRect, 
	float* r, 
	float* theta)
{
	// convert rectangular (decart) coordinates to polar
	*r = sqrtf((pRect->x * pRect->x) + (pRect->y * pRect->y));
	*theta = atanf(pRect->y / pRect->x);

} // end POINT2D_To_PolarRTh

/////////////////////////////////////////////////////////////

void CYLINDRICAL3D_To_POINT3D(const CYLINDRICAL3D* pCyl, POINT3D* pRect)
{
	// convertation of cylindrical coordinates into rectangle (decart) coordinates
	pRect->x = pCyl->r * cosf(pCyl->theta);
	pRect->y = pCyl->r * sinf(pCyl->theta);
	pRect->z = pCyl->z;

} // end CYLINDRICAL_To_POINT3D

/////////////////////////////////////////////////////////////

void CYLINDRICAL3D_To_RectXYZ(const CYLINDRICAL3D* pCyl, 
	float* x, 
	float* y, 
	float* z)
{
	// convertation of cylindrical coordinates into rectangle (decart) coordinates
	*x = pCyl->r * cosf(pCyl->theta);
	*y = pCyl->r * sinf(pCyl->theta);
	*z = pCyl->z;
} // end CYLINDRICAL3D_To_RectXYZ

/////////////////////////////////////////////////////////////

void POINT3D_To_CylindricalRThZ(const POINT3D* pRect, 
	float* r, 
	float* theta, 
	float* z)
{
	// convert rectangular to cylindrical
	*r     = sqrtf((pRect->x * pRect->x) + (pRect->y * pRect->y));
	*theta = atanf(pRect->y / pRect->x);
	*z     = pRect->z;

} // end POINT3D_To_CylindricalRThZ

/////////////////////////////////////////////////////////////

void SPHERICAL3D_To_POINT3D(const SPHERICAL3D* pSph, POINT3D* pRect)
{
	// convert spherical coordinates to rectanglular (decart);

	// pre-compute r to simplify computation of x,y
	float r = pSph->p * sinf(pSph->phi);
	pRect->x = r * cosf(pSph->theta);
	pRect->y = r * sinf(pSph->theta);
	pRect->z = pSph->p * cosf(pSph->phi);

} // end SPHRERICAL3D_To_POINT3D

/////////////////////////////////////////////////////////////

void SPHERICAL3D_To_RectXYZ(const SPHERICAL3D* pSph, 
	float* x,
	float* y, 
	float* z)
{
	// convert spherical coordinates to rectangular

	// pre-compute r to simplify computation of x,y
	float r = pSph->p * sinf(pSph->phi);

	*x = r * cosf(pSph->theta);
	*y = r * sinf(pSph->theta);
	*z = pSph->p * cosf(pSph->phi);

} // end SPHERICAL3D_To_RectXYZ

/////////////////////////////////////////////////////////////

void POINT3D_To_SPHERICAL3D(const POINT3D* pRect, SPHERICAL3D* pSph)
{
	// convert rectangular coordinates to spherical

	// pre-computer r to simplify computation
	float r = sqrtf((pRect->x * pRect->x) + (pRect->y * pRect->y));

	pSph->p     = sqrtf((r * r) + (pRect->z * pRect->z));
	pSph->phi   = atanf(r / pRect->z);
	pSph->theta = atanf(pRect->y / pRect->x);

} // end POINT3D_To_SPHERICAL3D

/////////////////////////////////////////////////////////////

void POINT3D_To_SphericalRThPh(const POINT3D* pRect, 
	float* p, 
	float* theta, 
	float* phi)
{
	// convert rectangular coordinates to spherical

	// pre-computer r to simplify computation
	float r = sqrtf((pRect->x * pRect->x) + (pRect->y * pRect->y));

	*p     = sqrtf((r * r) + (pRect->z * pRect->z));
	*phi   = atanf(r / pRect->z);
	*theta = atanf(pRect->y / pRect->x);

} // end POINT3D_To_SphericalRThPh

} // end namespace MathLib
