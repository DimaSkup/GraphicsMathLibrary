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


void Init_Param_Line2D(const POINT2D & pInit, const POINT2D & pTerm, PARAMLINE2D & pLine)
{
	// this function initializes 2D parametric line with two 2D points
	// and computes a vector between them;
	// note that the function computes v = pTerm - pInit, thus when t=0 the line
	// p = p0 + v*t = p0 and when t=1, p = p1, this way the segment is traces out
	// from p0 to p1 via 0 <= t <= 1

	// start point
	VECTOR2D_INIT(pLine.p0, pInit);
	
	// end point
	VECTOR2D_INIT(pLine.p1, pTerm);

	// now compute direction vector from p0->p1
	VECTOR2D_Build(pInit, pTerm, pLine.v);

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

void Init_Param_Line3D(const POINT3D & pInit, const POINT3D & pTerm, PARAMLINE3D & pLine)
{
	// this functions initializes 3D parametric line using two input points, 
	// computes a vector from pInit to pTerm, and returns the result in pLine

	POINT3D_INIT(pLine.p0, pInit);
	POINT3D_INIT(pLine.p1, pTerm);
	VECTOR3D_Build(pInit, pTerm, pLine.v);

} // end Init_Param_Line3D

///////////////////////////////////////////////////////////

void Compute_Point_On_Param_Line3D(const PARAMLINE3D & pL, const float t, POINT3D & pt)
{
	// this function computes a point on the parametric line according 
	// to the t parameter, and stores the result in the pt. When t=0 the
	// function returns the beginning point, when t=1 it returns the end point

	// p = p0 + v*t
	pt.x = pL.p0.x + pL.v.x * t;
	pt.y = pL.p0.y + pL.v.y * t;
	pt.z = pL.p0.z + pL.v.z * t;

} // Compute_Param_Line3D

///////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////////////////
//                        
//                        FUNCTIONS FOR WORK WITH 3D PLANES
// 
////////////////////////////////////////////////////////////////////////////////////////////

void PLANE3D_Init(PLANE3D & plane,
	const POINT3D & p0,
	const VECTOR3D & normal,
	const int normalize)
{
	// this function initializes a plane using a 3D point and a normal vector.
	// Additionally the function normalizes the normal vector if it is necessary;
	// for that set a normalize parameter to TRUE. Such normalization is needed 
	// during a work with some algorithms

	// copy the point and initialize the normal vector
	POINT3D_COPY(plane.p0, p0);
	VECTOR3D_INIT(plane.n, normal);

	// if normalize is TRUE then the normal is made into a unit vector
	if (normalize == TRUE)
	{
		VECTOR3D_Normalize(plane.n);
	}

} // end PLANE3D_Init

///////////////////////////////////////////////////////////

float Compute_Point_In_Plane3D(const POINT3D & pt, const PLANE3D & plane)
{
	// this function checks a point location relative to a plane

	// compute a DOT PRODUCT between a plane's normal vector and a vector plane.p0->pt
	return (plane.n.x * (pt.x - plane.p0.x)) +
		   (plane.n.y * (pt.y - plane.p0.y)) +
		   (plane.n.z * (pt.z - plane.p0.z));
} // end Compute_Point_In_Plane3D

///////////////////////////////////////////////////////////

int Intersect_Param_Line3D_Plane3D(const PARAMLINE3D & pLine,
	const PLANE3D & plane,
	float & t,
	POINT3D & pt)
{
	// this function defines where the input parametric line intersects the plane.
	// The function continues the line into both sides to infinity, but a segment
	// intersects the plane only when t is in a [0, 1] range.
	//
	// Returns:
	//  0 - no intersection,
	//  1 - segment and plane intersection
	//  2 - line and plane intersection
	//  3 - line coincide with a plane

	// check input params

	float plane_dot_line = VECTOR3D_Dot(pLine.v, plane.n);

	if (fabs(plane_dot_line) <= EPSILON_E5)
	{
		// the line is parallel to the plane. Does it coincide with this plane?
		if (fabs(Compute_Point_In_Plane3D(pLine.p0, plane)) <= EPSILON_E5)
			return PARAM_LINE_INTERSECT_EVERYWHERE;
		else
			return PARAM_LINE_NO_INTERSECT;
	} // if


	// first of all find a t parameter
	t = -(plane.n.x * pLine.p0.x +
		plane.n.y * pLine.p0.y +
		plane.n.z * pLine.p0.z -
		plane.n.x * plane.p0.x -
		plane.n.y * plane.p0.y -
		plane.n.z * plane.p0.z) / (plane_dot_line);

	// put the t parameter into the equation of the straight line, and find
	// coordinates of an intersection point (x, y, z)
	pt.x = pLine.p0.x + pLine.v.x * t;
	pt.y = pLine.p0.y + pLine.v.y * t;
	pt.z = pLine.p0.z + pLine.v.z * t;

	// checking if the t parameter is in a [0, 1] range
	if ((t >= 0) && (t <= 1))
		return PARAM_LINE_INTERSECT_IN_SEGMENT;
	else
		return PARAM_LINE_INTERSECT_OUT_SEGMENT;

} // end Intersect_Param_Line3D_Plane3D

///////////////////////////////////////////////////////////

float Distance_Point3D_To_Plane3D(const POINT3D & point,
	const PLANE3D & plane)
{
	// this function computes ONLY distance from a point to a plane
	//   Input:  pPoint = a 3D point anywhere in space
	//           pPlane = a plane with point p0 and normal n
	//  
	//   Return: the distance from pPoint to the plane pPlane


	// equation:  -n*(pPoint->p0 - pPlane->p0) / n^2
	// or another representation: (a*x0 + b*y0 + c*z0 + d) / sqrt(nx^2 + ny^2 + nz^2)
	return -VECTOR3D_Dot(plane.n, VECTOR3D_Sub(point, plane.p0) ) /
		sqrtf(VECTOR3D_Dot(plane.n, plane.n));

} // end Distance_Point3D_Plane3D

  ///////////////////////////////////////////////////////////

float Distance_Point3D_To_Plane3D(const POINT3D & point,
	const PLANE3D & plane,
	POINT3D & base)
{
	// this function computes BOTH distance and perp base from a point to a plane
	//   Input:  pPoint = a 3D point anywhere in space
	//           pPlane = a plane with point p0 and normal n
	//   Output: *pBase = base point on pPlane of perpendicular from pPoint
	//   Return: the distance from pPoint to the plane pPlane

	// equation:  -n*(pPoint->p0 - pPlane->p0) / n^2
	// or another representation: (a*x0 + b*y0 + c*z0 + d) / sqrt(nx^2 + ny^2 + nz^2)
	float sn = VECTOR3D_Dot(plane.n, VECTOR3D_Sub(point, plane.p0) );
	float sd = sqrtf(VECTOR3D_Dot(plane.n, plane.n));
	float sb = -sn / sd;

	// compute a base point
	base.x = point.x + plane.n.x * sb;
	base.y = point.y + plane.n.y * sb;
	base.z = point.z + plane.n.z * sb;

	VECTOR3D vecPointToBase(base, point);

	return VECTOR3D_Length(vecPointToBase);

} // end Distance_Point3D_Plane3D

///////////////////////////////////////////////////////////

float Distance_Point3D_To_Plane3D_Normalized(const POINT3D & point,
	const PLANE3D & plane,
	POINT3D & base)
{
	// this function computes a length of a perpendicular from
	// a 3D point to a 3D plane and returns it on the stack;
	//
	// NOTE: it is supposed that the plane's normal vector is normalized

	// equation:  -n*(pPoint->p0 - pPlane->p0)
	// or another representation: (a*x0 + b*y0 + c*z0 + d)
	float sb = -VECTOR3D_Dot(plane.n, VECTOR3D_Sub(point, plane.p0));

	// compute a base point
	base.x = point.x + plane.n.x * sb;
	base.y = point.y + plane.n.y * sb;
	base.z = point.z + plane.n.z * sb;

	VECTOR3D vecPointToBase(base, point);

	return VECTOR3D_Length(vecPointToBase);
}

} // end namespace MathLib