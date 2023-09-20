////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector2D.h
// Description:   contains definitions of 2D point and 2D vector types;
//                also has functional for work with these types;
//
// Created:       18.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cassert>

#include "../Utils/Utils.h"
#include "../Log/Log.h"

namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                         2D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////


// 2D vector or point, without w 
typedef struct VECTOR2D_TYPE
{
	union
	{
		float M[2];     // array for storing

		struct
		{
			float x;
			float y;
		}; // struct
	}; // union
} VECTOR2D, POINT2D, *VECTOR2D_PTR, *POINT2D_PTR;





////////////////////////////////////////////////////////////////////////////////////////////
//                 ZERO/INIT/COPY OPERATIONS FOR 2D VECTORS / 2D POINTS
////////////////////////////////////////////////////////////////////////////////////////////

// functions for work with vectors

// reset of vectors
inline void VECTOR2D_ZERO(VECTOR2D* pVec)
{
	pVec->x = pVec->y = 0.0f;
}

// vectors initialization with particular values
inline void VECTOR2D_INIT_XY(VECTOR2D* pVec,
	const float x,
	const float y)
{
	pVec->x = x;
	pVec->y = y;
}

// vectors initialization with the other vectors
inline void VECTOR2D_INIT(VECTOR2D* pVecDst, const VECTOR2D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
}

// copying of vectors
inline void VECTOR2D_COPY(VECTOR2D* pVecDst, const VECTOR2D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
}

// initialization of a destination point with a source point
inline void POINT2D_INIT(POINT2D* pDst, const POINT2D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
}

// copying data from a source point into a destination point
inline void POINT2D_COPY(POINT2D* pDst, const POINT2D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
}






////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH 2D VECTOR/POINT
////////////////////////////////////////////////////////////////////////////////////////////

void VECTOR2D_Add(const VECTOR2D* pVecA, const VECTOR2D* pVecB, VECTOR2D* pVecSum)
{
	// this function adds pVecA+pVecB and returns it in pVecSum
	pVecSum->x = pVecA->x + pVecB->x;
	pVecSum->y = pVecA->y + pVecB->y;

} // end VECTOR2D_Add

/////////////////////////////////////////////////////////////

VECTOR2D VECTOR2D_Add(const VECTOR2D* pVecA, const VECTOR2D* pVecB)
{
	// this function adds pVecA+pVecB and returns the result on 
	// the stack
	VECTOR2D vecSum{ 0.0f, 0.0f };

	vecSum.x = pVecA->x + pVecB->x;
	vecSum.y = pVecA->y + pVecB->y;

	return vecSum;

} // end VECTOR2D_Add

/////////////////////////////////////////////////////////////

void VECTOR2D_Sub(const VECTOR2D* pVecA, const VECTOR2D* pVecB, VECTOR2D* pVecDiff)
{
	// this function subtracts pVecA-pVecB and returns it in pVecDiff
	pVecDiff->x = pVecA->x - pVecB->x;
	pVecDiff->y = pVecA->y - pVecB->y;

} // end VECTOR2D_Sub

/////////////////////////////////////////////////////////////

VECTOR2D VECTOR2D_Sub(const VECTOR2D* pVecA, const VECTOR2D* pVecB)
{
	// this function subtracts pVecA-pVecB and returns the result on
	// the stack
	VECTOR2D vecDiff{ 0.0f, 0.0f };

	vecDiff.x = pVecA->x - pVecB->x;
	vecDiff.y = pVecA->y - pVecB->y;

	return vecDiff;

} // end VECTOR2D_Sub

/////////////////////////////////////////////////////////////

void VECTOR2D_Scale(const float k, VECTOR2D* pVecA)
{
	// this function scales a vector by the constant k,
	// in place, note that w is left unchanged
	pVecA->x *= k;
	pVecA->y *= k;

} // end VECTOR2D_Scale

/////////////////////////////////////////////////////////////

void VECTOR2D_Scale(const float k, const VECTOR2D* pVecA, VECTOR2D* pVecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled
	pVecScaled->x = pVecA->x * k;
	pVecScaled->y = pVecA->y * k;

} // end VECTOR2D_Scale

/////////////////////////////////////////////////////////////

float VECTOR2D_Dot(const VECTOR2D* pVecA, const VECTOR2D* pVecB)
{
	// calculates a dot product between two vectors and returns it on the stack. 
	return (pVecA->x * pVecB->x) + (pVecA->y * pVecB->y);

} // end VECTOR2D_Dot

/////////////////////////////////////////////////////////////

float VECTOR2D_Length(const VECTOR2D* pVec)
{
	// computes a length of the vector
	return sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y));

} // end VECTOR2D_Length

/////////////////////////////////////////////////////////////

float VECTOR2D_Length_Fast(const VECTOR2D* pVec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	return static_cast<float>(Fast_Distance_2D(
		static_cast<int>(pVec->x), 
		static_cast<int>(pVec->y)
	));

} // end VECTOR2D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR2D_Normalize(VECTOR2D* pVec)
{
	// normalizes the sent vector

	// compute a length of the vector
	float length = sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR2D_ZERO(pVec);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	pVec->x *= length_inv;
	pVec->y *= length_inv;

} // end VECTOR2D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR2D_Normalize(const VECTOR2D* pVa, VECTOR2D* pVecN)
{
	// normalizes the sent vector and returns the result in pVecN

	// compute a length of the vector
	float length = sqrtf((pVa->x * pVa->x) + (pVa->y * pVa->y));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR2D_ZERO(pVecN);
		return;
	}
		

	float length_inv = 1.0f / length;

	// normalize the vector
	pVecN->x *= length_inv;
	pVecN->y *= length_inv;

} // end VECTOR2D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR2D_Build(const VECTOR2D* pInit, const VECTOR2D* pTerm, VECTOR2D* pResult)
{
	// builds a vector init->term and stores the result into pResult;
	// you can pass into this function points as well as vectors

	pResult->x = pTerm->x - pInit->x;
	pResult->y = pTerm->y - pInit->y;

} // end VECTOR2D_Build

/////////////////////////////////////////////////////////////

float VECTOR2D_CosTh(const VECTOR2D* pVecA, const VECTOR2D* pVecB)
{
	// this function returns the cosine of the angle between two vectors.
	// Note, we could compute the actual angle many many times, in further calcs
	// we will want ultimately compute cos of the angle, so why not just leave it!
	assert(pVecA != nullptr);
	assert(pVecB != nullptr);

	return (VECTOR2D_Dot(pVecA, pVecB) / (VECTOR2D_Length(pVecA) * VECTOR2D_Length(pVecB)));

} // end VECTOR2D_CosTh

/////////////////////////////////////////////////////////////

void VECTOR2D_Print(const VECTOR2D* pVec, const char* name = "v")
{
	// this function prints out a VECTOR2D's data; used for the debugging purpose

	std::string vectorData;
	vectorData.reserve(35);  // we need about 35 characters to print 2D vector's data (in format: vector_name = [X, Y])

	// make a string with vector's data
	vectorData += { (std::string)name + " = [" };

	for (UINT i = 0; i < 2; i++)
	{
		vectorData += (std::to_string(pVec->M[i]) + ", ");
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR2D_Print


}; // end namespace MathLib