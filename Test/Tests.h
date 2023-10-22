/////////////////////////////////////////////////////////////////////
// Filename:      Tests.h
// Description:   contains functional for testing the math library
//
// Created:       17.09.23
/////////////////////////////////////////////////////////////////////
#pragma once

#include <cassert>
#include <iomanip>

#include "../Log/Log.h"
#include "../Matrix/Matrix.h"
#include "../Figures/Figures.h"


class Tests
{
public:
	void Test_Vectors_And_Points();
	void Test_Coordinate_Systems();
	void Test_Matrices();
	void Test_Figures();
	



private:
	// VECTORs/POINTs functional testing
	void Test_2D_Vectors_Points();
	void Test_3D_Vectors_Points();
	void Test_4D_Vectors_Points();

	void Test_2D_Vectors_Points_Init_And_Inline_Func();
	void Test_2D_Vectors_Math_Operations();

	// MATRICEs functional testing
	void Test_Matrix_Init();
	void Test_Matrices_Print_Func();
	void Test_Matrices_Add_Func();
	void Test_Matrices_Multiplication_Func();

	// PARAMETRIC LINES functional testing
	void Test_Parametric_Lines();
	void Test_Parametric_Lines_2D_Intersection();
	void Test_Parametric_Lines_3D();

	// 3D planes
	void Test_3D_Planes();
	void Test_3D_Point_Pos_Relative_To_3D_Plane();
	void Test_Intersection_Plane3D_PARAMLINE3D();
	void Test_Distance_From_Point3D_To_Plane3D();

private:
	MathLib::MATRIX2X2 iMat2x2_;  // identity 2x2 matrix
	MathLib::MATRIX3X3 iMat3x3_;  // identity 3x3 matrix
	MathLib::MATRIX4X4 iMat4x4_;  // identity 4x4 matrix
	MathLib::MATRIX4X3 iMat4x3_;  // identity 4x3 matrix

	MathLib::MATRIX2X2 m2x2_;
	MathLib::MATRIX3X3 m3x3_;
	MathLib::MATRIX4X4 m4x4_;
	
};