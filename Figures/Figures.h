////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Figures.h
// Description:   contains definitions for geometric figures:
//                parametric lines, 3D planes, etc.
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../VectorAndPoint/VectorAndPoint.h" 
#include "../Matrix/Matrix.h"


namespace MathLib
{

	
////////////////////////////////////////////////////////////////////////////////////////////
// 
//                                PARAMETRIC LINES
//
////////////////////////////////////////////////////////////////////////////////////////////

// 2D parametric line
typedef struct PARAMLINE2D_TYPE
{
	PARAMLINE2D_TYPE()
	{
	}

	PARAMLINE2D_TYPE(const POINT2D & pInit, const POINT2D & pTerm) :
		p0(pInit), 
		p1(pTerm),
		v(pInit, pTerm)
	{
	}

	POINT2D p0;   // start point
	POINT2D p1;   // end point
	VECTOR2D v;   // direction vector: |v| = |p0 -> p1|
} PARAMLINE2D, *PARAMLINE2D_PTR;


// 3D parametric line
typedef struct PARAMLINE3D_TYPE
{
	PARAMLINE3D_TYPE() :
		p0(0, 0, 0), 
		p1(0, 0, 0), 
		v(0, 0, 0)
	{
	}

	PARAMLINE3D_TYPE(const POINT3D & pInit, const POINT3D & pTerm) :
		p0(pInit),
		p1(pTerm),
		v(pInit, pTerm)
	{
	}

	POINT3D p0;   // start point
	POINT3D p1;   // end point
	VECTOR3D v;   // direction vector: |v| = |p0 -> p1|
} PARAMLINE3D, *PARAMLINE3D_PTR;




////////////////////////////////////////////////////////////////////////////////////////////
//
//                                  3D PLANES
//
////////////////////////////////////////////////////////////////////////////////////////////

// 3D plane
typedef struct PLANE3D_TYPE
{
	PLANE3D_TYPE()
	{
	}

	PLANE3D_TYPE(const POINT3D & p, const VECTOR3D & normal) :
		p0(p),
		n(normal)
	{
	}

	POINT3D p0;   // point on the plane
	VECTOR3D n;   // normal vector (not necessary a unit vector)
} PLANE3D, *PLANE3D_PTR;






////////////////////////////////////////////////////////////////////////////////////////////
//                        
//                    FUNCTIONS FOR WORK WITH PARAMETRIC LINES
// 
////////////////////////////////////////////////////////////////////////////////////////////

void Init_Param_Line2D(const POINT2D* pInit, const POINT2D* pTerm, PARAMLINE2D* pLine);

void Compute_Param_Line2D(const PARAMLINE2D* pLine, const float t, POINT2D* pPoint);

int Intersect_Param_Lines2D(const PARAMLINE2D* pLine1,
	const PARAMLINE2D* pLine2,
	float* t1, float* t2);

int Intersect_Param_Lines2D(const PARAMLINE2D* line1, const PARAMLINE2D* line2, POINT2D* pt);

void Init_Param_Line3D(const POINT3D* pInit, const POINT3D* pTerm, PARAMLINE3D* pLine);

void Compute_Param_Line3D(const PARAMLINE3D* pLine, const float t, POINT3D* pt);





////////////////////////////////////////////////////////////////////////////////////////////
//                        
//                        FUNCTIONS FOR WORK WITH 3D PLANES
// 
////////////////////////////////////////////////////////////////////////////////////////////

void PLANE3D_Init(PLANE3D* pPlane,
	const POINT3D* p0,
	const VECTOR3D* pNormal,
	const int normalize);

float Compute_Point_In_Plane3D(const POINT3D* pt, const PLANE3D* plane);

int Intersect_Param_Line3D_Plane3D(const PARAMLINE3D* pLine,
	const PLANE3D* pPlane,
	float* t,
	POINT3D* pt);

} // end namespace MathLib