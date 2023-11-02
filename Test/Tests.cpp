/////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Tests.h
// Description:   contains implementation of functional for testing the math library
//
// Created:       17.09.23
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Tests.h"






////////////////////////////////////////////////////////////////////////////////////////////
//                                PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////

void Tests::Test_Coordinate_Systems()
{

} // end Test_Coordinate_System

///////////////////////////////////////////////////////////

void Tests::Test_Matrices()
{
	Log::Print("\n\n");
	Log::Print("-------------------- TEST: MATRICES --------------------\n");

	Test_Matrix_Init();                   // test of initialization 
	Test_Matrices_Print_Func();           // test print out of matrices different dimensions
	Test_Matrices_Add_Func();             // test of addition 
	Test_Matrices_Multiplication_Func();  // test of multiplication 

} // end Test_Matrices

///////////////////////////////////////////////////////////

void Tests::Test_Figures()
{
	Log::Print("\n\n");
	Log::Print("-------------------- TEST: FIGURES --------------------\n");

	Test_Parametric_Lines();

} // end Test_Figures

///////////////////////////////////////////////////////////

void Tests::Test_Quaternions()
{
	Log::Print("\n\n");
	Log::Print("-------------------- TEST: QUATERNIONS --------------------\n");

	/////////////////////////////////////////////

	// TEST 1: create a quaternion using a direction vector and a rotation angle

	// create a rotation vector which is representing the diagonal of the first octant
	MathLib::VECTOR3D v{ 1, 1, 1 };
	MathLib::QUAT qr;

	// normalize v
	MathLib::VECTOR3D_Normalize(v);

	float theta = DEG_TO_RAD(100);   // 100 degrees

	// creation of a rotation quaternion
	MathLib::VECTOR3D_Theta_To_QUAT(qr, v, theta);

	/////////////////////////////////////////////

	// TEST 2: create a quaternion using Euler's rotation angles

	MathLib::QUAT qzyx;

	// rotation angles 
	float theta_x = DEG_TO_RAD(20);
	float theta_y = DEG_TO_RAD(30);
	float theta_z = DEG_TO_RAD(45);

	// create a rotation quaternion
	MathLib::EulerZYX_To_QUAT(qzyx, theta_z, theta_y, theta_x);

	/////////////////////////////////////////////

	// TEST 3: transform a unit quaternion into a unit direction vector and 
	//         a rotation angle around it

	MathLib::QUAT q;       // suppose that this quaternion is a unit quaternion
	MathLib::VECTOR3D vec_dir; 
	theta = 0;

	// transform a quaternion into a vector and angle
	MathLib::QUAT_To_VECTOR3D_Theta(q, vec_dir, theta);

	/////////////////////////////////////////////

	// TEST 4: add two quaternions together

	const MathLib::QUAT q1{ 1, 2, 3, 4 };
	const MathLib::QUAT q2{ 5, 6, 7, 8 };
	MathLib::QUAT qsum;

	// computation of a sum of the quaternions
	MathLib::QUAT_Add(q1, q2, qsum);

	// check the result
	assert((qsum.w == 6) && (qsum.x == 8) && (qsum.y == 10) && (qsum.z == 12));

	/////////////////////////////////////////////

	// TEST 5: subtraction of quaternions

	MathLib::QUAT qdiff;

	// computation of a difference between two quaternions
	MathLib::QUAT_Sub(q1, q2, qdiff);

	// check the result
	assert((qdiff.w == -4) && (qdiff.x == -4) && (qdiff.y == -4) && (qdiff.z == -4));

	/////////////////////////////////////////////

	// TEST 6: computation of the conjugate of a quaternion

	MathLib::QUAT qconj;

	MathLib::QUAT_Conjugate(q1, qconj);

	// check the result
	assert((qconj.w == q1.w) && (qconj.x == -q1.x) && (qconj.y == -q1.y) && (qconj.z == -q1.z));

	/////////////////////////////////////////////

	// TEST 7: scaling of quaternion (case 1)

	MathLib::QUAT qs;  

	// scaling q1 with coefficient of 2
	MathLib::QUAT_Scale(q1, 2, qs);

	// check the result
	assert((qs.w == q1.w*2) && (qs.x == q1.x*2) && (qs.y == q1.y*2) && (qs.z == q1.z*2));

	/////////////////////////////////////////////

	// TEST 8: scaling of quaternion (case 2)

	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);

	// scaling q with coefficient of 2
	MathLib::QUAT_Scale(q, 2);

	// check the result
	assert((qs.w == 2) && (qs.x == 4) && (qs.y == 6) && (qs.z == 8));

	/////////////////////////////////////////////

	// TEST 9: get a norm (length) of quaternion

	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);    // its length == sqrt(30)

	// what is the length of q?
	float qnorm = MathLib::QUAT_Norm(q);

	// check the result
	assert(qnorm == sqrtf(30));

	/////////////////////////////////////////////

	// TEST 10: get a square of a norm (length) of quaternion

	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);    // its length == sqrt(30)

	// what is the square of length of q?
	float qnorm2 = MathLib::QUAT_Norm2(q);

	// check the result
	assert(qnorm2 == 30);

	/////////////////////////////////////////////

	// TEST 11: normalization of quaternion (case 1)

	MathLib::QUAT qn;   // normalized quaternion
	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);

	// normalization of q
	MathLib::QUAT_Normalize(q, qn);

	// check the result
	float len_q_inv = 1.0f / MathLib::QUAT_Norm(q);
	assert((qn.w == (q.w * len_q_inv)) &&
		   (qn.x == (q.x * len_q_inv)) &&
		   (qn.y == (q.y * len_q_inv)) &&
		   (qn.z == (q.z * len_q_inv)));

	/////////////////////////////////////////////

	// TEST 12: normalization of quaternion (case 2)

	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);

	// this will be used for checking the result
	MathLib::QUAT_Normalize(q, qn);  

	// normalization of q (with modification of q)
	MathLib::QUAT_Normalize(q);
	
	// check the result
	assert((qn.w == q.w) &&	(qn.x == q.x) && (qn.y == q.y) && (qn.z == q.z));

	/////////////////////////////////////////////

	// TEST 13: get the inverse of quaternion (case 1)

	MathLib::QUAT qi;                        // put here the data of inverse quaternion
	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);  // our quaternion
	MathLib::QUAT_Normalize(q);              // normalize it to be a unit quternion
	MathLib::QUAT_Conjugate(q, qconj);       // compute the conjugate of our quaternion
	
	// compute the inverse of the quaternion
	MathLib::QUAT_Unit_Inverse(q, qi);

	// check the result
	assert((qi.w == qconj.w) && (qi.x == qconj.x) && (qi.y == qconj.y) && (qi.z == qconj.z));

	/////////////////////////////////////////////

	// TEST 14: get the inverse of quaternion (case 2)

	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);  // our quaternion
	MathLib::QUAT_Normalize(q);              // normalize it to be a unit quternion
	MathLib::QUAT_Conjugate(q, qconj);       // compute the conjugate of our quaternion

	MathLib::QUAT_Unit_Inverse(q, qi);       // compute the inverse of the quaternion

	// check the result
	assert((qi.w == qconj.w) && (qi.x == qconj.x) && (qi.y == qconj.y) && (qi.z == qconj.z));

	/////////////////////////////////////////////

	// TEST 15: get the inverse of quaternion (case 3)

	MathLib::QUAT_INIT_WXYZ(q, 1, 2, 3, 4);  // our quaternion (not normalized)
	MathLib::QUAT_Inverse(q, qi);            // compute the inverse of the quaternion

	// check the result
	//assert(((q.w*qi.w) == 1) &&
	//	  ((q.x*qi.x) == 1) &&
	//	  ((q.y*qi.y) == 1) &&
	//	  ((q.z*qi.z) == 1));

	/////////////////////////////////////////////

	// TEST 16: multiplication of quaternions (q1*q2 and q2*q1)

	MathLib::QUAT qprod;

	// q1 * q2 = -60 + 12i + 30j + 24k
	MathLib::QUAT_Mul(q1, q2, qprod);
	assert((qprod.w == -60) && (qprod.x == 12) && (qprod.y == 30) && (qprod.z == 24));

	// q2 * q1 = -60 + 20i + 14j + 32k
	MathLib::QUAT_Mul(q2, q1, qprod);
	assert((qprod.w == -60) && (qprod.x == 20) && (qprod.y == 14) && (qprod.z == 32));

	Log::Print(LOG_MACRO, "SUCCESS");

} // end Test_Quaternions








////////////////////////////////////////////////////////////////////////////////////////////
//                                PRIVATE FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////

void Tests::Test_Matrix_Init()
{
	// this function tests initialization function for matrices



	//
	// initialize matrices with raw values
	//

	// init a matrix 2x2
	MathLib::Mat_Init_2X2(&m2x2_,
		1.0f, 2.0f,
		3.0f, 4.0f);

	// init a matrix 3x3
	MathLib::Mat_Init_3X3(&m3x3_,
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);

	// init a matrix 4x4
	MathLib::Mat_Init_4X4(&m4x4_,
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f);

	// check some values to be correct
	assert(m2x2_.M00 == 1.0f);
	assert(m3x3_.M11 == 5.0f);
	assert(m4x4_.M33 == 16.0f);

	/////////////////////////////////////////////

	// initialize indetity matrices
	MAT_IDENTITY_2X2(&iMat2x2_);
	MAT_IDENTITY_3X3(&iMat3x3_);
	MAT_IDENTITY_4X4(&iMat4x4_);
	MAT_IDENTITY_4X3(&iMat4x3_);

	// check some values to be correct
	assert(iMat2x2_.M00 == 1.0f);
	assert(iMat3x3_.M11 == 1.0f);
	assert(iMat4x4_.M22 == 1.0f);
	assert(iMat4x3_.M22 == 1.0f);
	assert(iMat4x3_.M32 == 0.0f);


	Log::Print(LOG_MACRO, "success");

} // end TestMatrixInit

///////////////////////////////////////////////////////////

void Tests::Test_Matrices_Print_Func()
{
	// this function tests printing functions for matrices

	Log::Print("\n");

	// test printing out for 2x2 matrices
	MathLib::Print_Mat_2X2(&m2x2_, "m2x2");

	// test printing out for 3x3 matrices
	MathLib::Print_Mat_3X3(&m3x3_, "m3x3");

	// test printing out for 4x4 matrices
	MathLib::Print_Mat_4X4(&m4x4_, "m4x4");

	/////////////////////////////////////////////

	// print out the identity matrices
	MathLib::Print_Mat_2X2(&iMat2x2_, "iMat2x2");
	MathLib::Print_Mat_3X3(&iMat3x3_, "iMat3x3");
	MathLib::Print_Mat_4X4(&iMat4x4_, "iMat4x4");
	
	// print out the 4x3 identity matrix
	std::stringstream strMatrixData;
	strMatrixData << "iMat4x3" << " =\n";

	// setup some output stream params
	strMatrixData << std::left << std::setfill(' ');

	for (unsigned int j = 0; j < 4; j++)
	{
		// before each row make a tabulation
		strMatrixData << "\t";

		
		for (unsigned int i = 0; i < 3; i++)
		{
			strMatrixData << std::setw(13);
			strMatrixData << std::to_string(iMat4x3_.M[i][j]) << ' ';
		}
		strMatrixData << "\n";
	}

	Log::Debug(LOG_MACRO, strMatrixData.str());

	/////////////////////////////////////////////

	Log::Print(LOG_MACRO, "success");

} // end TestMatricesPrintFunc

///////////////////////////////////////////////////////////

void Tests::Test_Matrices_Add_Func()
{
	// this function tests of functional for addition of matrices
	
	// temporal matrices for writing the result into it
	MathLib::MATRIX2X2 tempMat2x2;
	MathLib::MATRIX3X3 tempMat3x3;
	MathLib::MATRIX4X4 tempMat4x4;

	MathLib::Mat_Add_2X2(&m2x2_, &m2x2_, &tempMat2x2);
	MathLib::Mat_Add_3X3(&m3x3_, &m3x3_, &tempMat3x3);
	MathLib::Mat_Add_4X4(&m4x4_, &m4x4_, &tempMat4x4);

	// check the results; as we added matrix to itself we just check that each
	// element of the result must be a doubled value of the origin matrix element
	for (unsigned int col = 0; col < 2; col++)
	{
		for (unsigned int row = 0; row < 2; row++)
		{
			assert(tempMat2x2.M[col][row] == (m2x2_.M[col][row] * 2));
		}
	}

	for (unsigned int col = 0; col < 3; col++)
	{
		for (unsigned int row = 0; row < 3; row++)
		{
			assert(tempMat3x3.M[col][row] == (m3x3_.M[col][row] * 2));
		}
	}

	for (unsigned int col = 0; col < 4; col++)
	{
		for (unsigned int row = 0; row < 4; row++)
		{
			assert(tempMat4x4.M[col][row] == (m4x4_.M[col][row] * 2));
		}
	}
	

	Log::Print(LOG_MACRO, "success");

} // end TestMatricesAddFunc

///////////////////////////////////////////////////////////

void Tests::Test_Matrices_Multiplication_Func()
{
	// this function tests matrices multiplication 

	MathLib::MATRIX2X2 tempMat2x2;
	MathLib::MATRIX3X3 tempMat3x3;
	MathLib::MATRIX4X4 tempMat4x4;
	//MathLib::MATRIX4X3 tempMat4x3;

	// store some values from the matrices to compare with it later
	float elemM00_FromMat2X2 = m2x2_.M00;
	float elemM11_FromMat3X3 = m3x3_.M11;
	float elemM22_FromMat4X4 = m4x4_.M22;
	//float elemFromMat2X2 = m4x3_.M22;

	// just multiply our matrices by the identity matrices and check if they left the same;
	MathLib::Mat_Mul_2X2(&m2x2_, &iMat2x2_, &tempMat2x2);
	MathLib::Mat_Mul_3X3(&m3x3_, &iMat3x3_, &tempMat3x3);
	MathLib::Mat_Mul_4X4(&m4x4_, &iMat4x4_, &tempMat4x4);
	//MathLib::Mat_Mul_2X2(&m2x2_, &iMat2x2_, &tempMat2x2);

	assert(m2x2_.M00 == elemM00_FromMat2X2);
	assert(m3x3_.M11 == elemM11_FromMat3X3);
	assert(m4x4_.M22 == elemM22_FromMat4X4);

	/////////////////////////////////////////////

	//
	// multiplication using non square matrices
	//

	// multiplication v*m (3D point transfer)
	MathLib::MATRIX1X4 v = { 1.0f, 2.0f, 3.0f, 1.0f };             // origin point
	MathLib::MATRIX1X4 vt;                                         // transfered point
	MathLib::MATRIX4X4 m = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 1,2,3,1 }; // transfer matrix

	MathLib::Mat_Mul_1X4_4X4(&v, &m, &vt);


	Log::Print(LOG_MACRO, "success");

} // end Test_Matrices_Multiplication_Func

///////////////////////////////////////////////////////////

void Tests::Test_Parametric_Lines()
{
	try
	{
		Test_Parametric_Lines_2D_Intersection();
		Test_Parametric_Lines_3D();
		Test_3D_Planes();
	}
	catch (std::exception & e)
	{
		Log::Error(LOG_MACRO, e.what());
		return;
	}
	
} // end Test_Parametric_Lines

///////////////////////////////////////////////////////////

void Tests::Test_Parametric_Lines_2D_Intersection()
{
	// this function tests a computation of intersection between two 2D parametric lines;

	int result = -1;

	// CASE 1: the lines haven't an intersection
	MathLib::POINT2D pBegin1(0, 0);
	MathLib::POINT2D pEnd1(10, 10);
	MathLib::POINT2D pBegin2(0, 1);
	MathLib::POINT2D pEnd2(10, 11);
	MathLib::POINT2D pt_Intersection;


	// init param lines
	MathLib::PARAMLINE2D line1(pBegin1, pEnd1);
	MathLib::PARAMLINE2D line2(pBegin2, pEnd2);

	// compute an intersection
	result = MathLib::Intersect_Param_Lines2D(&line1, &line2, &pt_Intersection);

	// if we have no intersection
	if (result == PARAM_LINE_NO_INTERSECT)
	{
		Log::Print(LOG_MACRO, "2D param lines: no intersection:\t\t SUCCESS");
	}
	else
	{
		throw new std::exception("2D param lines: CASE 1: no intersection: INCORRECT RESULT");
	}

	/////////////////////////////////////////////////////////////

	// CASE 2: segments have an intersection
	MathLib::POINT2D_INIT_XY(pBegin1, 1, 1);
	MathLib::POINT2D_INIT_XY(pEnd1, 8, 5);
	MathLib::POINT2D_INIT_XY(pBegin2, 3, 6);
	MathLib::POINT2D_INIT_XY(pEnd2, 8, 3);

	MathLib::Init_Param_Line2D(pBegin1, pEnd1, line1);
	MathLib::Init_Param_Line2D(pBegin2, pEnd2, line2);

	// compute an intersection
	result = MathLib::Intersect_Param_Lines2D(&line1, &line2, &pt_Intersection);

	// if we have an intersection of segments
	if (result == PARAM_LINE_INTERSECT_IN_SEGMENT)
	{
		Log::Print(LOG_MACRO, "2D param lines: segment intersection:\t SUCCESS");
	}
	else
	{
		throw new std::exception("2D param lines: CASE 2: segment intersection: INCORRECT RESULT");
	}

	/////////////////////////////////////////////////////////////

	// CASE 3: lines have an intersection, but not the segments

	MathLib::POINT2D_INIT_XY(pBegin1, 1, 1);
	MathLib::POINT2D_INIT_XY(pEnd1, 8, 5);
	MathLib::POINT2D_INIT_XY(pBegin2, 3, 6);
	MathLib::POINT2D_INIT_XY(pEnd2, 8, 8);

	MathLib::Init_Param_Line2D(pBegin1, pEnd1, line1);
	MathLib::Init_Param_Line2D(pBegin2, pEnd2, line2);

	// compute an intersection
	result = MathLib::Intersect_Param_Lines2D(&line1, &line2, &pt_Intersection);

	// if we have an intersection of segments
	if (result == PARAM_LINE_INTERSECT_OUT_SEGMENT)
	{
		Log::Print(LOG_MACRO, "2D param lines: lines intersection:\t\t SUCCESS");
	}
	else
	{
		throw new std::exception("2D param lines: lines intersection: INCORRECT RESULT");
	}

	/////////////////////////////////////////////////////////////

	// CASE 4: lines coincide with each other

	MathLib::POINT2D_INIT_XY(pBegin1, 1, 1);
	MathLib::POINT2D_INIT_XY(pEnd1, 10, 10);
	MathLib::POINT2D_INIT_XY(pBegin2, 1, 1);
	MathLib::POINT2D_INIT_XY(pEnd2, 5, 5);

	MathLib::Init_Param_Line2D(pBegin1, pEnd1, line1);
	MathLib::Init_Param_Line2D(pBegin2, pEnd2, line2);

	// compute an intersection
	result = MathLib::Intersect_Param_Lines2D(&line1, &line2, &pt_Intersection);

	// if the parametric lines coincide with each other
	if (result == PARAM_LINE_INTERSECT_EVERYWHERE)
	{
		Log::Print(LOG_MACRO, "2D param lines: lines coincide:\t\t SUCCESS");
	}
	else
	{
		throw new std::exception("2D param lines: lines coincide: INCORRECT RESULT");
	}

} // end Test_Parametric_Lines_2D_Intersection

///////////////////////////////////////////////////////////

void Tests::Test_Parametric_Lines_3D()
{

} // end Test_Parametric_Lines_3D

///////////////////////////////////////////////////////////

void Tests::Test_3D_Planes()
{
	// this function calls different functions for testing of the functional
	// for work with 3D planes

	Test_3D_Point_Pos_Relative_To_3D_Plane();
	Test_Intersection_Plane3D_PARAMLINE3D();

	
} // end Test_3D_Planes

///////////////////////////////////////////////////////////

void Tests::Test_3D_Point_Pos_Relative_To_3D_Plane()
{
	//
	// computation of a point position relative to a plane:
	//
	// a. point is in the negative half-space
	// b. point is in the positive half-space
	// c. point in on the plane
	//

	MathLib::VECTOR3D vec_normal{ 1, 1, 1 };
	MathLib::POINT3D  point{ 0, 0, 0 };
	MathLib::PLANE3D  plane1(point, vec_normal);

	// using this value we will define a point positon relative to a plane
	float hs = 0.0f;

	// there is point which are located in the negative, positive half-space, and
	// a point which is right on the plane
	MathLib::POINT3D p_test_negative{ -50, -50, -50 };
	MathLib::POINT3D p_test_positive{ 50, 50, 50 };
	MathLib::POINT3D p_test_on_plane{ 0,  0,  0 };

	// test a location of the point 

	// negative half-space
	hs = MathLib::Compute_Point_In_Plane3D(p_test_negative, plane1);
	assert(hs < 0);

	// positive half-space
	hs = MathLib::Compute_Point_In_Plane3D(p_test_positive, plane1);
	assert(hs > 0);

	// the point is on the plane
	hs = MathLib::Compute_Point_In_Plane3D(p_test_on_plane, plane1);
	assert(fabs(hs) <= EPSILON_E5);

	Log::Print(LOG_MACRO, "3D planes: test a point pos relative to a plane:   SUCCESS");

} // Test_3D_Point_Pos_Relative_To_3D_Plane

///////////////////////////////////////////////////////////

void Tests::Test_Intersection_Plane3D_PARAMLINE3D()
{
	// this function tests 4 cases of intersection between a 3D plane and
	// a 3D parametric line:
	//   1 -- intersection in segment
	//   2 -- intersection out segment
	//   3 -- line coincides with plane
	//   4 -- no intersection



	//
	// TEST 1: an intersection of a parametric 3D line and a 3D plane
	//

	// creation of a parametric line from p1 to p2;
	// this line is parallel to z-axis
	MathLib::POINT3D p1{ 5, 5, -5 };
	MathLib::POINT3D p2{ 5, 5, 5 };
	MathLib::POINT3D pt;
	MathLib::PARAMLINE3D paramLine(p1, p2);

	// creation of a xy plane
	MathLib::VECTOR3D n{ 0, 0, 1 };
	MathLib::POINT3D p{ 0, 0, 0 };
	MathLib::PLANE3D plane2(p, n);

	float t = 0;

	// computation of an intersection point (must be (5,5,0))
	int intersection_type = MathLib::Intersect_Param_Line3D_Plane3D(paramLine, plane2, t, pt);
	assert(intersection_type == PARAM_LINE_INTERSECT_IN_SEGMENT);
	assert((pt.x == 5) && (pt.y == 5) && (pt.z == 0));

	Log::Print(LOG_MACRO, "3D planes: test intersection (in segment):   \tSUCCESS");



	///////////////////////////////////////////////////////////

	//
	// TEST 2: a paramteric 3D line intersects a 3D plane out of the segment
	//

	// reinitialize the parametric 3D line and the 3D plane;
	MathLib::POINT3D_INIT_XYZ(p1, 1, 1, 1);
	MathLib::Init_Param_Line3D(p1, p2, paramLine);

	// computation of an intersection point (must be (0, 0, 0))
	intersection_type = MathLib::Intersect_Param_Line3D_Plane3D(paramLine, plane2, t, pt);
	assert(intersection_type == PARAM_LINE_INTERSECT_OUT_SEGMENT);
	assert((pt.x == 0) && (pt.y == 0) && (pt.z == 0));

	Log::Print(LOG_MACRO, "3D planes: test intersection (out segment):  \tSUCCESS");



	///////////////////////////////////////////////////////////

	//
	// TEST 3: a paramteric 3D line intersects a 3D plane everywhere (coincides with it)
	//

	// reinitialize the parametric 3D line and the 3D plane;
	MathLib::POINT3D_INIT_XYZ(p1, 0, 0, 0);
	MathLib::POINT3D_INIT_XYZ(p2, 0, 10, 0);
	MathLib::Init_Param_Line3D(p1, p2, paramLine);

	// computation of an intersection point (must be (0, 0, 0))
	intersection_type = MathLib::Intersect_Param_Line3D_Plane3D(paramLine, plane2, t, pt);
	assert(intersection_type == PARAM_LINE_INTERSECT_EVERYWHERE);

	Log::Print(LOG_MACRO, "3D planes: test intersection (coincidence):  \tSUCCESS");


	///////////////////////////////////////////////////////////

	//
	// TEST 4: a paramteric 3D line hasn't an intersection with a 3D plane 
	//

	// reinitialize the parametric 3D line and the 3D plane;
	MathLib::POINT3D_INIT_XYZ(p1, 5, 5, 5);
	MathLib::POINT3D_INIT_XYZ(p2, 5, 10, 5);
	MathLib::Init_Param_Line3D(p1, p2, paramLine);

	// computation of an intersection point (must be (0, 0, 0))
	intersection_type = MathLib::Intersect_Param_Line3D_Plane3D(paramLine, plane2, t, pt);
	assert(intersection_type == PARAM_LINE_NO_INTERSECT);

	Log::Print(LOG_MACRO, "3D planes: test intersection (no intersection):\tSUCCESS");

	return;

} // Test_Intersection_Plane3D_PARAMLINE3D

///////////////////////////////////////////////////////////

void Tests::Test_Distance_From_Point3D_To_Plane3D()
{



} // Test_Distance_From_Point3D_To_Plane3D
