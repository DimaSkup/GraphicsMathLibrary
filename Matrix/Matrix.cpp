////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Matrix.cpp
// Description:   contains implementation of common functional for matrices
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Matrix.h"

namespace MathLib
{




////////////////////////////////////////////////////////////////////////////////////////////
//                       FUNCTIONS WORK WITH FOR 2X2 MATRICES
////////////////////////////////////////////////////////////////////////////////////////////


void Mat_Init_2X2(MATRIX2X2* pMat,
	const float m00, const float m01,
	const float m10, const float m11)
{
	// this function initializes the matrix pMat with float-point values

	assert(pMat != nullptr);

	pMat->M00 = m00;
	pMat->M01 = m01;
	pMat->M10 = m10;
	pMat->M11 = m11;

} // end Mat_Init_2X2

////////////////////////////////////////////////////////////

void Mat_Add_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMSum)
{
	// this function adds two 2x2 matrices together and stores the result in pMSum

	assert(pMA != nullptr);
	assert(pMB != nullptr);

	pMSum->M00 = pMA->M00 + pMB->M00;
	pMSum->M01 = pMA->M01 + pMB->M01;
	pMSum->M10 = pMA->M10 + pMB->M10;
	pMSum->M11 = pMA->M11 + pMB->M11;

} // end Mat_Add_2X2

////////////////////////////////////////////////////////////

void Mat_Mul_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMProd)
{
	// this function multiplies two 2x2 matrices together and stores the result in pMProd

	assert(pMA != nullptr);
	assert(pMB != nullptr);

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

	assert(pM != nullptr);
	assert(pMi != nullptr);

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

	assert(pM != nullptr);

	std::string strMatrixData{ " " };
	strMatrixData.reserve(45);  // we need at least 45 characters to print data of a 2x2 matrix 

	// make a string with data of the matrix
	strMatrixData += name;
	strMatrixData += " =\n";

	// go through rows
	for (unsigned int r = 0; r < 2; r++)
	{
		strMatrixData += "\t";   // before the row make a tabulation

		// go through columns
		for (unsigned int c = 0; c < 2; c++)
		{
			strMatrixData += std::to_string(pM->M[r][c]);
			strMatrixData += ' ';
		}

		strMatrixData += "\n";
	}

	Log::Debug(LOG_MACRO, strMatrixData);

} // Print_Mat_2X2

////////////////////////////////////////////////////////////

int Mat_Mul_1X2_3X2(const MATRIX1X2* pMatA, const MATRIX3X2* pMatB, MATRIX1X2* pMProd)
{
	// this function multiplies a 1x2 matrix by a 3x2 matrix and stores 
	// the result in the pMProd;
	//
	// this multiplication is using a dummy element for the 3rd element of the 1x22
	// to make the matrix multiply valid i.e. 1x3 X 3x2

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);

	for (int col = 0; col < 2; col++)
	{
		// calculate dot product from row of pMatA and column of pMatB
		float sum = 0;
		int i = 0;  // index

		for (i = 0; i < 2; i++)
		{
			// add results of multiplication
			sum += (pMatA->M[i] * pMatB->M[i][col]);
		}

		// the last element multiply by 1
		sum += pMatB->M[i][col];

		// insert resulting col element
		pMProd->M[col] = sum;

	} // end for col

	return 1;

} // end Mat_Mul_1X2_3X2

////////////////////////////////////////////////////////////

float Mat_Det_2X2(const MATRIX2X2* pMat)
{
	// this function computes and return the value of 2x2 matrix determinate

	assert(pMat != nullptr);

	return (pMat->M00 * pMat->M11) - (pMat->M01 * pMat->M10);
} // end Mat_Det_2X2






////////////////////////////////////////////////////////////////////////////////////////////
//                       FUNCTIONS WORK WITH FOR 3X3 MATRICES
////////////////////////////////////////////////////////////////////////////////////////////

void Mat_Add_3X3(const MATRIX3X3* pMatA, const MATRIX3X3* pMatB, MATRIX3X3* pMatSum)
{
	// this function adds matrices pMatA+pMatB and returns the result in pMatSum

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);

	pMatSum->M00 = pMatA->M00 + pMatB->M00;
	pMatSum->M01 = pMatA->M01 + pMatB->M01;
	pMatSum->M02 = pMatA->M02 + pMatB->M02;

	pMatSum->M10 = pMatA->M10 + pMatB->M10;
	pMatSum->M11 = pMatA->M11 + pMatB->M11;
	pMatSum->M12 = pMatA->M12 + pMatB->M12;

	pMatSum->M20 = pMatA->M20 + pMatB->M20;
	pMatSum->M21 = pMatA->M21 + pMatB->M21;
	pMatSum->M22 = pMatA->M22 + pMatB->M22;

} // end Mat_Add_3X3

////////////////////////////////////////////////////////////

void Mat_Mul_VECTOR3D_3X3(const VECTOR3D* pVec, const MATRIX3X3* pMat, VECTOR3D* pVecProd)
{
	// this function multiplies 1x3 vector by 3x3 matrix and returns 
	// the result in pVecProd
	
	assert(pVec != nullptr);
	assert(pMat != nullptr);
	assert(pVecProd != nullptr);

	float sum = 0;

	for (int col = 0; col < 3; col++)
	{
		sum = 0;   // at the beginning of each for col loop we have to reset the sum

		for (int row = 0; row < 3; row++)
		{
			sum += pVec->M[row] * pMat->M[col][row];
		} // for row

		// insert the resulting value
		pVecProd->M[col] = sum;

	} // for col

} // end Mat_Mul_VECTOR3D_3X3

////////////////////////////////////////////////////////////

} // end namespace MathLib