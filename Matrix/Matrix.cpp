////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Matrix.cpp
// Description:   contains implementation of common functional for matrices
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Matrix.h"

namespace MathLib
{

void Mat_Init_2X2(MATRIX2X2* pMat,
	const float m00, const float m01,
	const float m10, const float m11)
{
	// this function initializes the matrix pMat with float-point values
	pMat->M00 = m00;
	pMat->M01 = m01;
	pMat->M10 = m10;
	pMat->M11 = m11;

} // end Mat_Init_2X2

////////////////////////////////////////////////////////////

void Mat_Add_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMSum)
{
	// this function adds two 2x2 matrices together and stores the result in pMSum
	pMSum->M00 = pMA->M00 + pMB->M00;
	pMSum->M01 = pMA->M01 + pMB->M01;
	pMSum->M10 = pMA->M10 + pMB->M10;
	pMSum->M11 = pMA->M11 + pMB->M11;

} // end Mat_Add_2X2

////////////////////////////////////////////////////////////

void Mat_Mul_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMProd)
{
	// this function multiplies two 2x2 matrices together and stores the result in pMProd
	pMProd->M00 = (pMA->M00 * pMB->M00) + (pMA->M01 * pMB->M10);
	pMProd->M01 = (pMA->M00 * pMB->M01) + (pMA->M01 * pMB->M11);

	pMProd->M10 = (pMA->M10 * pMB->M00) + (pMA->M11 * pMB->M10);
	pMProd->M11 = (pMA->M10 * pMB->M01) + (pMA->M11 * pMB->M11);

} // end Mat_Mul_2X2

////////////////////////////////////////////////////////////

int Mat_Inverse_2X2(const MATRIX2X2* pM, MATRIX2X2* pMi)
{
	// this function computes the inverse of a 2x2 matrix
	// and stores the result in pMi

	// compute determinate
	float det = (pM->M00 * pM->M11) - (pM->M01 * pM->M10);

	// if determinate is 0 then inverse doesn't exists
	if (fabs(det) < EPSILON_E5)
	{
		MATRIX_ZERO_2X2(pMi);
		return 0; 
	}

	float det_inv = 1.0f / det;

	// fill in inverse by formula
	pMi->M00 =  pM->M11 * det_inv;
	pMi->M01 = -pM->M01 * det_inv;
	pMi->M10 = -pM->M10 * det_inv;
	pMi->M11 =  pM->M00 * det_inv;

	return 1;  // return success

} // end Mat_Inverse_2X2

////////////////////////////////////////////////////////////

void Print_Mat_2X2(const MATRIX2X2* pM, const char* name)
{
	// prints out a 2x2 matrix
	std::string matrixData{ " " };
	//vectorData.reserve(45);  // we need about 45 characters to print 3D vector's data (in format: vector_name = [X, Y, Z])

	matrixData += name;
	matrixData += " =\n";

	for (unsigned int r = 0; r < 2; r++)
	{
		for (unsigned int c = 0; c < 2; c++)
		{
			matrixData += std::to_string(pM->M[r][c]);
			matrixData += "\n";
		}
	}

	Log::Debug(LOG_MACRO, matrixData);
}

} // end namespace MathLib