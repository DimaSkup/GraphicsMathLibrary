////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector3D.h
// Description:   contains definitions of 3D point and 3D vector types;
//                also has functional for work with these types;
//
// Created:       18.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cmath>
#include <cassert>

#include "../Utils/Utils.h"
#include "../Log/Log.h"

namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                         3D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////

// 3D vector or point, without w
typedef struct VECTOR3D_TYPE
{


	union
	{
		float M[3];     // array for storing

		struct
		{
			float x;
			float y;
			float z;
		}; // struct
	}; // union
} VECTOR3D, POINT3D, *VECTOR3D_PTR, *POINT3D_PTR;



////////////////////////////////////////////////////////////////////////////////////////////
//                  ZERO/INIT/COPY OPERATIONS FOR 3D VECTORS / 3D POINTS
////////////////////////////////////////////////////////////////////////////////////////////


inline void VECTOR3D_ZERO(VECTOR3D* pVec)
{
	pVec->x = pVec->y = pVec->z = 0.0f;
}

/////////////////////////////////////////////////////////////

inline void VECTOR3D_INIT_XYZ(VECTOR3D* pVec,
	const float x,
	const float y,
	const float z)
{
	pVec->x = x;
	pVec->y = y;
	pVec->z = z;
}

/////////////////////////////////////////////////////////////

inline void VECTOR3D_INIT(VECTOR3D* pVecDst, const VECTOR3D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
}

/////////////////////////////////////////////////////////////

inline void VECTOR3D_COPY(VECTOR3D* pVecDst, const VECTOR3D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
}

/////////////////////////////////////////////////////////////

inline void POINT3D_INIT(POINT3D* pDst, const POINT3D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
}

/////////////////////////////////////////////////////////////

inline void POINT3D_COPY(POINT3D* pDst, const POINT3D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
}




////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH VECTORS/POINTS
////////////////////////////////////////////////////////////////////////////////////////////

void VECTOR3D_Add(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecSum)
{
	// this function adds pVecA+pVecB and returns it in the pVecSum
	pVecSum->x = pVecA->x + pVecB->x;
	pVecSum->y = pVecA->y + pVecB->y;
	pVecSum->z = pVecA->z + pVecB->z;

} // end VECTOR3D_Add

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Add(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// this function adds pVecA+pVecB and returns the result on
	// the stack
	VECTOR3D vecSum;

	vecSum.x = pVecA->x + pVecB->x;
	vecSum.y = pVecA->y + pVecB->y;
	vecSum.z = pVecA->z + pVecB->z;

	return vecSum;

} // end VECTOR3D_Add

/////////////////////////////////////////////////////////////

void VECTOR3D_Sub(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecDiff)
{
	// this function subtracts pVecA-pVecB and returns the result in the pVecDiff
	pVecDiff->x = pVecA->x - pVecB->x;
	pVecDiff->y = pVecA->y - pVecB->y;
	pVecDiff->z = pVecA->z - pVecB->z;

} // end VECTOR3D_Sub

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Sub(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// this function subtracts pVecA-pVecB and returns the result on 
	// the stack
	VECTOR3D vecDiff;

	vecDiff.x = pVecA->x - pVecB->x;
	vecDiff.y = pVecA->y - pVecB->y;
	vecDiff.z = pVecA->z - pVecB->z;

	return vecDiff;
} // end VECTOR3D_Sub

/////////////////////////////////////////////////////////////

void VECTOR3D_Scale(const float k, VECTOR3D* pVecA)
{
	// this function scales a vector by the constant k,
	// in place, note that w is left unchanged
	pVecA->x *= k;
	pVecA->y *= k;
	pVecA->z *= k;

} // end VECTOR3D_Scale

/////////////////////////////////////////////////////////////

void VECTOR3D_Scale(const float k, const VECTOR3D* pVecA, VECTOR3D* pVecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled

	pVecScaled->x = pVecA->x * k;
	pVecScaled->y = pVecA->y * k;
	pVecScaled->z = pVecA->z * k;

} // end VECTOR3D_Scale

/////////////////////////////////////////////////////////////

float VECTOR3D_Dot(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// calculates a dot product between two vectors and returns it on the stack.
	return (pVecA->x * pVecB->x) + (pVecA->y * pVecB->y) + (pVecA->z * pVecB->z);

} // end VECTOR3D_Dot

/////////////////////////////////////////////////////////////

void VECTOR3D_Cross(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecN)
{
	// computes the cross product between pVecA and pVecB and returns the result in pVecN;
	pVecN->x = (pVecA->y * pVecB->z) - (pVecA->z * pVecB->y);
	pVecN->y = (pVecA->z * pVecB->x) - (pVecA->x * pVecB->z);
	pVecN->z = (pVecA->x * pVecB->y) - (pVecA->y * pVecB->x);

} // end VECTOR3D_Cross

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Cross(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// computes the cross product between pVecA and pVecB and returns the result 
	// on the stack;
	VECTOR3D vecN{ 0.0f, 0.0f, 0.0f };

	vecN.x = (pVecA->y * pVecB->z) - (pVecA->z * pVecB->y);
	vecN.y = (pVecA->z * pVecB->x) - (pVecA->x * pVecB->z);
	vecN.z = (pVecA->x * pVecB->y) - (pVecA->y * pVecB->x);

	return vecN;

} // end VECTOR3D_Cross

/////////////////////////////////////////////////////////////

float VECTOR3D_Length(const VECTOR3D* pVec)
{
	// computes a length of the vector
	return sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y) + (pVec->z * pVec->z));

} // end VECTOR3D_Length

/////////////////////////////////////////////////////////////

float VECTOR3D_Length_Fast(const VECTOR3D* pVec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	return Fast_Distance_3D(pVec->x, pVec->y, pVec->z);

} // end VECTOR3D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR3D_Normalize(VECTOR3D* pVec)
{
	// normalizes the sent vector

	// compute a length of the vector
	float length = sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y) + (pVec->z * pVec->z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR3D_ZERO(pVec);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	pVec->x *= length_inv;
	pVec->y *= length_inv;
	pVec->z *= length_inv;

} // end VECTOR3D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR3D_Normalize(const VECTOR3D* pVa, VECTOR3D* pVecN)
{
	// normalizes the sent vector and returns the result in pVecN

	// compute a length of the vector
	float length = sqrtf((pVa->x * pVa->x) + (pVa->y * pVa->y) + (pVa->z * pVa->z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR3D_ZERO(pVecN);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	pVecN->x *= length_inv;
	pVecN->y *= length_inv;
	pVecN->z *= length_inv;

} // end VECTOR3D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR3D_Build(const VECTOR3D* pInit, const VECTOR3D* pTerm, VECTOR3D* pResult)
{
	// builds a vector init->term and stores the result into pResult;
	// you can pass into this function points as well as vectors

	pResult->x = pTerm->x - pInit->x;
	pResult->y = pTerm->y - pInit->y;
	pResult->z = pTerm->z - pInit->z;

} // end VECTOR3D_Build

/////////////////////////////////////////////////////////////

float VECTOR3D_CosTh(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// this function returns the cosine of the angle between two vectors.
	// Note, we could compute the actual angle many many times, in further calcs
	// we will want ultimately compute cos of the angle, so why not just leave it!
	assert(pVecA != nullptr);
	assert(pVecB != nullptr);

	return (VECTOR3D_Dot(pVecA, pVecB) / (VECTOR3D_Length(pVecA) * VECTOR3D_Length(pVecB)));

} // end VECTOR3D_CosTh

/////////////////////////////////////////////////////////////

void VECTOR3D_Print(const VECTOR3D* pVec, const char* name = "v")
{
	// this function prints out a VECTOR3D's data; used for the debugging purpose

	std::string vectorData;
	vectorData.reserve(45);  // we need about 45 characters to print 3D vector's data (in format: vector_name = [X, Y, Z])

	// make a string with vector's data
	vectorData += { (std::string)name + " = [" };

	for (UINT i = 0; i < 3; i++)
	{
		vectorData += (std::to_string(pVec->M[i]) + ", ");
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR3D_Print


}; // end namespace MathLib