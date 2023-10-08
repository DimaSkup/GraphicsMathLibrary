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
	// function returns a beginning point, when t=1 it returns the end point.

	pPoint->x = pLine->p0.x + (pLine->v.x * t);
	pPoint->y = pLine->p0.y + (pLine->v.y * t);

} // end Compute_Param_Line2D

///////////////////////////////////////////////////////////

int Intersect_Param_Lines2D(const PARAMLINE2D* pLine1,
	const PARAMLINE2D* pLine2,
	float* t1, float* t2)
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

	// step 1:


} // end Intersect_Param_Lines2D

} // end namespace MathLib