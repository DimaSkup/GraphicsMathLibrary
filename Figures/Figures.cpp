////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Figures.cpp
// Description:   contains implementation of functions for geometric figures:
//                parametric lines, 3D planes, etc.
//
// Created:       07.10.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Figures.h"



namespace MathLib
{




////////////////////////////////////////////////////////////////////////////////////////////
//                        
//                    FUNCTIONS FOR WORK WITH PARAMETRIC LINES
// 
////////////////////////////////////////////////////////////////////////////////////////////


void Init_Param_Line2D(const POINT2D* pInit, const POINT2D* pTerm, PARAMLINE2D* pLine)
{
	// this function initializes 2D parametric line with two 2D points
	// and computes a vector between them;
	// note that the function computes v = pTerm - pInit, thus when t=0 the line
	// p = p0 + v*t = p0 and when t=1, p = p1, this way the segment is traces out
	// from p0 to p1 via 0 <= t <= 1

	// start point
	VECTOR2D_INIT(&(pLine->p0), pInit);
	
	// end point
	VECTOR2D_INIT(&(pLine->p1), pTerm);

	// now compute direction vector from p0->p1
	VECTOR2D_Build(pInit, pTerm, &(pLine->v));

} // end Init_Param_Line2D

///////////////////////////////////////////////////////////

void Compute_Param_Line2D(const PARAMLINE2D* pLine, const float t, POINT2D* pPoint)
{
	// this function computes a point on the parametric line according 
	// to the t parameter, and stores the result in the pPoint. When t=0 the
	// function returns the beginning point, when t=1 it returns the end point.

	pPoint->x = pLine->p0.x + (pLine->v.x * t);
	pPoint->y = pLine->p0.y + (pLine->v.y * t);

} // end Compute_Param_Line2D

///////////////////////////////////////////////////////////

int Intersect_Param_Lines2D(const PARAMLINE2D* line1,
	const PARAMLINE2D* line2,
	float* t1, float* t2)
{
	// this function calculates an intersection of two parametric lines and returns 
	// true if these lines have an intersection. If so the values t1 and t2 correspond to
	// the intersection point. These parameters can go out from the [0, 1] range, it means that
	// the lines have an intersection but not the segments.
	// Returned:
	//   0 - means that lines haven't an intersection;
	//   1 - segments have an intersection;
	//   2 - lines have an intersection, but not the segments;
	//   3 - lines coincide with each other;

	// check input params
	assert((line1 != nullptr) && (line2 != nullptr));
	assert((t1 != nullptr) && (t2 != nullptr));

	// STEP 1: check if the parametric lines are parallel or coincide with each other;
	float detL1L2 = (line1->v.x * line2->v.y - line1->v.y * line2->v.x);

	// if determinant is equal to zero we don't have an intersection or the lines are coincide;
	if (fabs(detL1L2) <= EPSILON_E5)
	{
		// if the ratio equality is true so the lines are coincide:
		if ((line1->v.x / (line1->p0.x - line2->p0.x)) == 
			(line1->v.y / (line1->p0.y - line2->p0.y)))
			return PARAM_LINE_INTERSECT_EVERYWHERE;
		else
			return PARAM_LINE_NO_INTERSECT;
	}
	

	// STEP 2: computation of t1 and t2 values
	float detL1L2_Inv = 1 / detL1L2;

	*t1 = (line1->v.x * (line1->p0.y - line2->p0.y) -
		line1->v.y * (line1->p0.x - line2->p0.x)) * detL1L2_Inv;

	*t2 = (line2->v.x * (line1->p0.y - line2->p0.y) -
		line2->v.y * (line1->p0.x - line2->p0.x)) * detL1L2_Inv;

	// check segment intersection
	if ((*t1 >= 0) && (*t1 <= 1) && (*t2 >= 0) && (*t2 <= 1))
		return PARAM_LINE_INTERSECT_IN_SEGMENT;
	else
		return PARAM_LINE_INTERSECT_OUT_SEGMENT;

} // end Intersect_Param_Lines2D

///////////////////////////////////////////////////////////

int Intersect_Param_Lines2D(const PARAMLINE2D* line1, const PARAMLINE2D* line2, POINT2D* pt)
{
	// this function calculates and intersection of two parametric lines and returns 
	// true if these lines have an intersection. If so the values t1 and t2 correspond to
	// the intersection point. These parameters can go out from the [0, 1] range, it means that
	// the lines have an intersection but not the segments.
	// Returned:
	//   0 - means that lines haven't an intersection;
	//   1 - segments have an intersection;
	//   2 - lines have an intersection, but not the segments;
	//   3 - lines coincide with each other;
	// Also records coordinates of the intersection point into pt variable

	// check input params
	assert((line1 != nullptr) && (line2 != nullptr));
	assert(pt != nullptr);

	float t1 = 0.0f;
	int result = Intersect_Param_Lines2D(line1, line2, &t1, &t1);

	pt->x = line1->p0.x + line1->v.x * t1;
	pt->y = line1->p0.y + line1->v.y * t1;

	return result;
} // end Intersect_Param_Lines2D

///////////////////////////////////////////////////////////

void Init_Param_Line3D(const POINT3D* pInit, const POINT3D* pTerm, PARAMLINE3D* pLine)
{
	// this functions initializes 3D parametric line using two input points, 
	// computes a vector from pInit to pTerm, and returns the result in pLine

	POINT3D_INIT(&(pLine->p0), pInit);
	POINT3D_INIT(&(pLine->p1), pTerm);
	VECTOR3D_Build(pInit, pTerm, &(pLine->v));

} // end Init_Param_Line3D

///////////////////////////////////////////////////////////

void Compute_Param_Line3D(const PARAMLINE3D* pL, const float t, POINT3D* pt)
{
	// this function computes a point on the parametric line according 
	// to the t parameter, and stores the result in the pt. When t=0 the
	// function returns the beginning point, when t=1 it returns the end point

	pt->x = pL->p0.x + pL->v.x * t;
	pt->y = pL->p0.y + pL->v.y * t;
	pt->z = pL->p0.z + pL->v.z * t;

} // Compute_Param_Line3D

} // end namespace MathLib