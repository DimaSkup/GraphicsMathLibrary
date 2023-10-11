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


void Tests::Test_Coordinate_System()
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
	MathLib::POINT2D_INIT_XY(&pBegin1, 1, 1);
	MathLib::POINT2D_INIT_XY(&pEnd1, 8, 5);
	MathLib::POINT2D_INIT_XY(&pBegin2, 3, 6);
	MathLib::POINT2D_INIT_XY(&pEnd2, 8, 3);

	MathLib::Init_Param_Line2D(&pBegin1, &pEnd1, &line1);
	MathLib::Init_Param_Line2D(&pBegin2, &pEnd2, &line2);

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

	MathLib::POINT2D_INIT_XY(&pBegin1, 1, 1);
	MathLib::POINT2D_INIT_XY(&pEnd1, 8, 5);
	MathLib::POINT2D_INIT_XY(&pBegin2, 3, 6);
	MathLib::POINT2D_INIT_XY(&pEnd2, 8, 8);

	MathLib::Init_Param_Line2D(&pBegin1, &pEnd1, &line1);
	MathLib::Init_Param_Line2D(&pBegin2, &pEnd2, &line2);

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

	MathLib::POINT2D_INIT_XY(&pBegin1, 1, 1);
	MathLib::POINT2D_INIT_XY(&pEnd1, 10, 10);
	MathLib::POINT2D_INIT_XY(&pBegin2, 1, 1);
	MathLib::POINT2D_INIT_XY(&pEnd2, 5, 5);

	MathLib::Init_Param_Line2D(&pBegin1, &pEnd1, &line1);
	MathLib::Init_Param_Line2D(&pBegin2, &pEnd2, &line2);

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
	//
	// TEST 1: definition of a point position relative to a plane
	//

	MathLib::VECTOR3D vec_normal{ 1, 1, 1 };
	MathLib::POINT3D  point{ 0, 0, 0 };
	MathLib::PLANE3D  plane1(point, vec_normal);

	// using this value we will define a point positon relative to a plane
	float hs = 0.0f;

	// there is point which are located in the negative, positive half-space, and
	// a point which is right on the plane
	MathLib::POINT3D p_test_negative{ -50, -50, -50 };
	MathLib::POINT3D p_test_positive{  50, 50, 50 };
	MathLib::POINT3D p_test_on_plane{  0,  0,  0  };

	// test a location of the point 
	hs = MathLib::Compute_Point_In_Plane3D(&p_test_negative, &plane1);
	assert(hs < 0);

	hs = MathLib::Compute_Point_In_Plane3D(&p_test_positive, &plane1);
	assert(hs > 0);

	hs = MathLib::Compute_Point_In_Plane3D(&p_test_on_plane, &plane1);
	assert(fabs(hs) <= EPSILON_E5);

	Log::Print(LOG_MACRO, "3D planes: test a point pos relative to a plane: SUCCESS");


	///////////////////////////////////////////////////////////

	//
	// TEST 2: an intersection of a parametric 3D line and a 3D plane
	//

	// creation of a parametric line from p1 to p2;
	// this line is parallel to z-axis
	MathLib::POINT3D p1{ 5, 5, -5 };
	MathLib::POINT3D p2{ 5, 5, 5 };
	MathLib::POINT3D pt;
	MathLib::PARAMLINE3D pl(p1, p2);  

	// creation of a xy plane
	MathLib::VECTOR3D n{ 0, 0, 1 };
	MathLib::POINT3D p{ 0, 0, 0 };
	MathLib::PLANE3D plane2(p, n);

	float t = 0;

	// computation of an intersection point (must be (5,5,0))
	int intersection_type = MathLib::Intersect_Param_Line3D_Plane3D(&pl, &plane2, &t, &pt);
	assert(intersection_type == PARAM_LINE_INTERSECT_IN_SEGMENT);
	assert((pt.x == 5) && (pt.y == 5) && (pt.z == 0));

	Log::Print(LOG_MACRO, "3D planes: test intersection of line and plane:  SUCCESS");

	

} // end Test_3D_Planes
