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


class Tests
{
public:
	void Test_Coordinate_System();
	void Test_Matrices();



private:
	// MATRIX functional testing
	void Test_Matrix_Init();
	void Test_Matrices_Print_Func();
	void Test_Matrices_Add_Func();
	void Test_Matrices_Multiplication_Func();


private:
	MathLib::MATRIX2X2 iMat2x2_;  // identity 2x2 matrix
	MathLib::MATRIX3X3 iMat3x3_;  // identity 3x3 matrix
	MathLib::MATRIX4X4 iMat4x4_;  // identity 4x4 matrix
	MathLib::MATRIX4X3 iMat4x3_;  // identity 4x3 matrix

	MathLib::MATRIX2X2 m2x2_;
	MathLib::MATRIX3X3 m3x3_;
	MathLib::MATRIX4X4 m4x4_;
	
};