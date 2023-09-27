////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Matrix.cpp
// Description:   contains implementation of common functional for matrices
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Matrix.h"

#include <iomanip>

namespace MathLib
{




////////////////////////////////////////////////////////////////////////////////////////////
//                   FUNCTIONS FOR WORK WITH FOR 2X2 MATRICES
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

///////////////////////////////////////////////////////////

void Mat_Add_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMSum)
{
	// this function adds two 2x2 matrices together and stores the result in pMSum

	assert(pMA != nullptr);
	assert(pMB != nullptr);
	assert(pMSum != nullptr);

	pMSum->M00 = pMA->M00 + pMB->M00;
	pMSum->M01 = pMA->M01 + pMB->M01;
	pMSum->M10 = pMA->M10 + pMB->M10;
	pMSum->M11 = pMA->M11 + pMB->M11;

} // end Mat_Add_2X2

///////////////////////////////////////////////////////////

void Mat_Mul_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMProd)
{
	// this function multiplies two 2x2 matrices together and stores the result in pMProd

	assert(pMA != nullptr);
	assert(pMB != nullptr);
	assert(pMProd != nullptr);

	pMProd->M00 = (pMA->M00 * pMB->M00) + (pMA->M01 * pMB->M10);
	pMProd->M01 = (pMA->M00 * pMB->M01) + (pMA->M01 * pMB->M11);

	pMProd->M10 = (pMA->M10 * pMB->M00) + (pMA->M11 * pMB->M10);
	pMProd->M11 = (pMA->M10 * pMB->M01) + (pMA->M11 * pMB->M11);

} // end Mat_Mul_2X2

///////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////

void Print_Mat_2X2(const MATRIX2X2* pM, const char* name)
{
	// this function prints out a 2x2 matrix

	assert(pM != nullptr);
	assert((name != nullptr) && (name[0] != '\0'));

	std::stringstream strMatrixData;

	// make a string with data of the matrix
	strMatrixData << name << " =\n";

	// setup some output stream params
	strMatrixData << std::left << std::setfill(' ');

	// go through rows
	for (unsigned int r = 0; r < 2; r++)
	{
		// before each row make a tabulation
		strMatrixData << "\t";

		// go through columns
		for (unsigned int c = 0; c < 2; c++)
		{
			strMatrixData << std::setw(13);
			strMatrixData << std::to_string(pM->M[r][c]) << ' ';
		}
		strMatrixData << "\n";
	}

	// print out the matrix
	Log::Debug(LOG_MACRO, strMatrixData.str());

} // Print_Mat_2X2

///////////////////////////////////////////////////////////

float Mat_Det_2X2(const MATRIX2X2* pMat)
{
	// this function computes and return the value of 2x2 matrix determinate

	assert(pMat != nullptr);

	return (pMat->M00 * pMat->M11) - (pMat->M01 * pMat->M10);
} // end Mat_Det_2X2






////////////////////////////////////////////////////////////////////////////////////////////
//                    FUNCTIONS FOR WORK WITH FOR 3X3 MATRICES
////////////////////////////////////////////////////////////////////////////////////////////

void Mat_Init_3X3(MATRIX3X3* pMat,
	const float m00, const float m01, const float m02,
	const float m10, const float m11, const float m12,
	const float m20, const float m21, const float m22)
{
	// this function initializes the matrix pMat with passed elements

	assert(pMat != nullptr);

	pMat->M00 = m00; pMat->M01 = m01; pMat->M02 = m02;
	pMat->M10 = m10; pMat->M11 = m11; pMat->M12 = m12;
	pMat->M20 = m20; pMat->M21 = m21; pMat->M22 = m22;

} // end Mat_Init_3X3


void Mat_Add_3X3(const MATRIX3X3* pMatA, const MATRIX3X3* pMatB, MATRIX3X3* pMatSum)
{
	// this function adds matrices pMatA+pMatB and returns the result in pMatSum

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMatSum != nullptr);

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

///////////////////////////////////////////////////////////

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
		// at the beginning of each for col loop we have to reset the sum
		sum = 0;   

		for (int row = 0; row < 3; row++)
		{
			sum += pVec->M[row] * pMat->M[row][col];
		}

		// insert the resulting value
		pVecProd->M[col] = sum;

	} // for col

} // end Mat_Mul_VECTOR3D_3X3

///////////////////////////////////////////////////////////

int Mat_Mul_3X3(const MATRIX3X3* pMatA, const MATRIX3X3* pMatB, MATRIX3X3* pMProd)
{
	// this function multiplies two 3x3 matrices together and returns 
	// the result in pMProd
	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMProd != nullptr);

	float sum = 0.0f;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// used to hold result
			sum = 0.0f;  

			for (int k = 0; k < 3; k++)
			{
				sum += pMatA->M[i][k] + pMatB->M[k][j];
			}

			// insert resulting value 
			pMProd->M[i][j] = sum;
			
		} // end for j
	} // end for i

	return 1;
}

///////////////////////////////////////////////////////////

void Print_Mat_3X3(const MATRIX3X3* pMat, const char* name)
{
	// this function prints out a 3x3 matrix

	assert(pMat != nullptr);
	assert((name != nullptr) && (name[0] != '\0'));

	std::stringstream strMatrixData;

	// make a string with data of the matrix
	strMatrixData << name << " =\n";

	// setup some output stream params
	strMatrixData << std::left << std::setfill(' ');

	// go through rows
	for (unsigned int r = 0; r < 3; r++)
	{
		// before each row make a tabulation
		strMatrixData << "\t";

		// go through columns
		for (unsigned int c = 0; c < 3; c++)
		{
			strMatrixData << std::setw(13);
			strMatrixData << std::to_string(pMat->M[r][c]) << ' ';
		}
		strMatrixData << "\n";
	}

	// print out the matrix
	Log::Debug(LOG_MACRO, strMatrixData.str());

} // end Print_Mat_3X3

///////////////////////////////////////////////////////////

float Mat_Det_3X3(const MATRIX3X3* pm)
{
	// this function calculates and returns a determinant of the matrix
	
	assert(pm != nullptr);

	return pm->M00 * ((pm->M11 * pm->M22) - (pm->M21 * pm->M12)) - 
		   pm->M01 * ((pm->M10 * pm->M22) - (pm->M20 * pm->M12)) +
		   pm->M02 * ((pm->M10 * pm->M21) - (pm->M20 * pm->M11));

} // end Mat_Det_3X3

///////////////////////////////////////////////////////////

int Mat_Inverse_3X3(const MATRIX3X3* pMat, MATRIX3X3* pMi)
{
	// this function computes the inverse of a 3x3 matrix;

	assert(pMat != nullptr);
	assert(pMi != nullptr);

	// compute the determinant to see if there is an inverse
	float det = Mat_Det_3X3(pMat);

	if (fabs(det) < EPSILON_E5)
	{
		return 0;
	}

	// compute inverse to save divides
	float det_inv = 1.0f / det;

	// compute inverse using m-1 = adjoint(m) / det(m)
	pMi->M00 =  det_inv * (pMat->M11*pMat->M22 - pMat->M12*pMat->M21);
	pMi->M01 = -det_inv * (pMat->M01*pMat->M22 - pMat->M02*pMat->M21);
	pMi->M02 =  det_inv * (pMat->M01*pMat->M12 - pMat->M02*pMat->M11);

	pMi->M10 = -det_inv * (pMat->M10*pMat->M22 - pMat->M12*pMat->M20);
	pMi->M11 =  det_inv * (pMat->M00*pMat->M22 - pMat->M02*pMat->M20);
	pMi->M12 = -det_inv * (pMat->M00*pMat->M12 - pMat->M02*pMat->M10);

	pMi->M20 =  det_inv * (pMat->M10*pMat->M21 - pMat->M11*pMat->M20);
	pMi->M21 = -det_inv * (pMat->M00*pMat->M21 - pMat->M01*pMat->M20);
	pMi->M22 =  det_inv * (pMat->M00*pMat->M11 - pMat->M01*pMat->M10);

	// return success
	return 1;

} // Mat_Inverse_3X3





////////////////////////////////////////////////////////////////////////////////////////////
//                     FUNCTIONS FOR WORK WITH FOR 3X3 MATRICES
////////////////////////////////////////////////////////////////////////////////////////////

void Mat_Init_4X4(MATRIX4X4* pMat,
	const float m00, const float m01, const float m02, const float m03,
	const float m10, const float m11, const float m12, const float m13,
	const float m20, const float m21, const float m22, const float m23,
	const float m30, const float m31, const float m32, const float m33)
{
	// this function initializes the matrix pMat with passed elements

	assert(pMat != nullptr);

	pMat->M00 = m00; pMat->M01 = m01; pMat->M02 = m02; pMat->M03 = m03;
	pMat->M10 = m10; pMat->M11 = m11; pMat->M12 = m12; pMat->M13 = m13;
	pMat->M20 = m20; pMat->M21 = m21; pMat->M22 = m22; pMat->M23 = m23;
	pMat->M30 = m30; pMat->M31 = m31; pMat->M32 = m32; pMat->M33 = m33;

} // end Mat_Init_4X4

///////////////////////////////////////////////////////////

void Print_Mat_4X4(const MATRIX4X4* pMat, const char* name)
{
	// this function prints out a 4x4 matrix

	assert(pMat != nullptr);
	assert((name != nullptr) && (name[0] != '\0'));

	std::stringstream strMatrixData;

	// make a string with data of the matrix
	strMatrixData << name << " =\n";

	// setup some output stream params
	strMatrixData << std::left << std::setfill(' ');

	// go through rows
	for (unsigned int r = 0; r < 4; r++)
	{
		// before each row make a tabulation
		strMatrixData << "\t";
		
		// go through columns
		for (unsigned int c = 0; c < 4; c++)
		{
			strMatrixData << std::setw(13);
			strMatrixData << std::to_string(pMat->M[r][c]) << ' ';
		}
		strMatrixData << "\n";
	}

	// print out the matrix
	Log::Debug(LOG_MACRO, strMatrixData.str());

} // end Print_Mat_4X4

///////////////////////////////////////////////////////////

void Mat_Add_4X4(const MATRIX4X4* pMatA, const MATRIX4X4* pMatB, MATRIX4X4* pMSum)
{
	// this function adds matrices pMatA+pMatB and returns the result in pMSum

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMSum != nullptr);

	pMSum->M00 = pMatA->M00 + pMatB->M00;
	pMSum->M01 = pMatA->M01 + pMatB->M01;
	pMSum->M02 = pMatA->M02 + pMatB->M02;
	pMSum->M03 = pMatA->M03 + pMatB->M03;

	pMSum->M10 = pMatA->M10 + pMatB->M10;
	pMSum->M11 = pMatA->M11 + pMatB->M11;
	pMSum->M12 = pMatA->M12 + pMatB->M12;
	pMSum->M13 = pMatA->M13 + pMatB->M13;

	pMSum->M20 = pMatA->M20 + pMatB->M20;
	pMSum->M21 = pMatA->M21 + pMatB->M21;
	pMSum->M22 = pMatA->M22 + pMatB->M22;
	pMSum->M23 = pMatA->M23 + pMatB->M23;

	pMSum->M30 = pMatA->M30 + pMatB->M30;
	pMSum->M31 = pMatA->M31 + pMatB->M31;
	pMSum->M32 = pMatA->M32 + pMatB->M32;
	pMSum->M33 = pMatA->M33 + pMatB->M33;

} // end Mat_Add_4X4

///////////////////////////////////////////////////////////

void Mat_Mul_4X4(const MATRIX4X4* pMatA, const MATRIX4X4* pMatB, MATRIX4X4* pMProd)
{
	// this function multiplies two matrices 4x4 together and return the result in pMProd;

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMProd != nullptr);

	float sum = 0.0f;   // for storing the result

	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			// for each element we reset the sum
			sum = 0.0f;

			for (unsigned int k = 0; k < 4; k++)
			{
				sum += pMatA->M[i][k] * pMatB->M[k][j];
			}

			pMProd->M[i][j] = sum;
		} // end for j
	} // end for i

} // end Mat_Mul_4X4









////////////////////////////////////////////////////////////////////////////////////////////////
//                      WORK WITH NON SQUARE DIMENSIONAL MATRICES
////////////////////////////////////////////////////////////////////////////////////////////////

int Mat_Mul_1X2_3X2(const MATRIX1X2* pMatA, const MATRIX3X2* pMatB, MATRIX1X2* pMProd)
{
	// this function multiplies a 1x2 matrix by a 3x2 matrix and stores 
	// the result in the pMProd;
	//
	// this multiplication is using a dummy element for the 3rd element of the 1x22
	// to make the matrix multiply valid i.e. 1x3 X 3x2

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMProd != nullptr);

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

///////////////////////////////////////////////////////////

void Mat_Mul_1X3_3X3(const MATRIX1X3* pMatA, const MATRIX3X3* pMatB, MATRIX1X3* pMProd)
{
	// this function multiplies 1x3 matrix (3D vector) by 3x3 matrix and
	// returns the result in pMProd;
	//
	// This function is similar to the Mat_Mul_VECTOR3D_3X3 function

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMProd != nullptr);

	float sum = 0.0f;

	for (int row = 0; row < 3; row++)
	{
		// at the beginning of each for row loop we have to reset the sum
		sum = 0.0f;

		for (int index = 0; index < 3; index++)
		{
			sum += pMatA->M[index] * pMatB->M[index][row];
		}

		// insert the resulting value
		pMProd->M[row] = sum;

	} // for row

} // end Mat_Mul_1X3_3X3

///////////////////////////////////////////////////////////

void Mat_Mul_1X4_4X4(const MATRIX1X4* pMatA, const MATRIX4X4* pMatB, MATRIX1X4* pMProd)
{
	// this function multiplies a 1x4 matrix by a 4x4 matrix.

	assert(pMatA != nullptr);
	assert(pMatB != nullptr);
	assert(pMProd != nullptr);

	float sum = 0.0f;  // for storing the result

	for (unsigned int col = 0; col < 4; col++)
	{
		// for each element we reset the sum
		sum = 0.0f;

		for (unsigned int row = 0; row < 4; row++)
		{
			sum += (pMatA->M[row] * pMatB->M[row][col]);
		}

		pMProd->M[col] = sum;
	} // for col

} // end Mat_Mul_1X4_4X4


} // end namespace MathLib