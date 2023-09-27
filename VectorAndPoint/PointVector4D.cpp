////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector4D.cpp
// Description:   contains implementation of functional for work with 
//                4D points and 4D vectors;
//
// Created:       26.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "PointVector4D.h"

namespace MathLib
{


void VECTOR4D_Add(const VECTOR4D* pVecA, const VECTOR4D* pVecB, VECTOR4D* pVecSum)
{
	// this function adds pVecA+pVecB and returns it in the pVecSum
	pVecSum->x = pVecA->x + pVecB->x;
	pVecSum->y = pVecA->y + pVecB->y;
	pVecSum->z = pVecA->z + pVecB->z;
	pVecSum->w = pVecA->w + pVecB->w;

} // end VECTOR4D_Add

/////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Add(const VECTOR4D* pVecA, const VECTOR4D* pVecB)
{
	// this function adds pVecA+pVecB and returns the result on
	// the stack
	VECTOR4D vecSum;

	vecSum.x = pVecA->x + pVecB->x;
	vecSum.y = pVecA->y + pVecB->y;
	vecSum.z = pVecA->z + pVecB->z;
	vecSum.w = pVecA->w + pVecB->w;

	return vecSum;

} // end VECTOR4D_Add

/////////////////////////////////////////////////////////////

void VECTOR4D_Sub(const VECTOR4D* pVecA, const VECTOR4D* pVecB, VECTOR4D* pVecDiff)
{
	// this function subtracts pVecA-pVecB and returns the result in the pVecDiff
	pVecDiff->x = pVecA->x - pVecB->x;
	pVecDiff->y = pVecA->y - pVecB->y;
	pVecDiff->z = pVecA->z - pVecB->z;
	pVecDiff->w = pVecA->w - pVecB->w;

} // end VECTOR4D_Sub

/////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Sub(const VECTOR4D* pVecA, const VECTOR4D* pVecB)
{
	// this function subtracts pVecA-pVecB and returns the result on 
	// the stack
	VECTOR4D vecDiff;

	vecDiff.x = pVecA->x - pVecB->x;
	vecDiff.y = pVecA->y - pVecB->y;
	vecDiff.z = pVecA->z - pVecB->z;
	vecDiff.w = pVecA->w - pVecB->w;

	return vecDiff;
} // end VECTOR4D_Sub

/////////////////////////////////////////////////////////////

void VECTOR4D_Scale(const float k, VECTOR4D* pVecA)
{
	// this function scales a vector by the constant k,
	// in place, note that w is left unchanged
	pVecA->x *= k;
	pVecA->y *= k;
	pVecA->z *= k;
	pVecA->w = 1.0f;

} // end VECTOR4D_Scale

/////////////////////////////////////////////////////////////

void VECTOR4D_Scale(const float k, const VECTOR4D* pVecA, VECTOR4D* pVecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled
	pVecScaled->x = pVecA->x * k;
	pVecScaled->y = pVecA->y * k;
	pVecScaled->z = pVecA->z * k;
	pVecScaled->w = 1.0f;

} // end VECTOR4D_Scale

/////////////////////////////////////////////////////////////

float VECTOR4D_Dot(const VECTOR4D* pVecA, const VECTOR4D* pVecB)
{
	// computes the dot product between two vectors and returns it on the stack. 
	// For 4D vectors a w component isn't used;
	return (pVecA->x * pVecB->x) + (pVecA->y * pVecB->y) + (pVecA->z * pVecB->z);

} // end VECTOR4D_Dot

/////////////////////////////////////////////////////////////

void VECTOR4D_Cross(const VECTOR4D* pVecA, const VECTOR4D* pVecB, VECTOR4D* pVecN)
{
	// computes the cross product between pVecA and pVecB and returns the result in pVecN;
	// For 4D vectors a component w is not used
	pVecN->x = (pVecA->y * pVecB->z) - (pVecA->z * pVecB->y);
	pVecN->y = (pVecA->z * pVecB->x) - (pVecA->x * pVecB->z);
	pVecN->z = (pVecA->x * pVecB->y) - (pVecA->y * pVecB->x);
	pVecN->w = 1.0f;

} // end VECTOR4D_Cross

/////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Cross(const VECTOR4D* pVecA, const VECTOR4D* pVecB)
{
	// computes the cross product between pVecA and pVecB and returns the result 
	// on the stack;
	VECTOR4D vecN{ 0.0f, 0.0f, 0.0f, 1.0f };

	vecN.x = (pVecA->y * pVecB->z) - (pVecA->z * pVecB->y);
	vecN.y = (pVecA->z * pVecB->x) - (pVecA->x * pVecB->z);
	vecN.z = (pVecA->x * pVecB->y) - (pVecA->y * pVecB->x);
	// vecN.w = 1.0f;   // we don't set component w to 1.0f because we've already done it

	return vecN;

} // end VECTOR4D_Cross

/////////////////////////////////////////////////////////////

float VECTOR4D_Length(const VECTOR4D* pVec)
{
	// computes a length of the vector
	return sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y) + (pVec->z * pVec->z));

} // end VECTOR4D_Length

/////////////////////////////////////////////////////////////

float VECTOR4D_Length_Fast(const VECTOR4D* pVec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	return Fast_Distance_3D(pVec->x, pVec->y, pVec->z);

} // end VECTOR4D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR4D_Normalize(VECTOR4D* pVec)
{
	// normalizes the sent vector

	// compute a length of the vector
	float length = sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y) + (pVec->z * pVec->z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR4D_ZERO(pVec);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	pVec->x *= length_inv;
	pVec->y *= length_inv;
	pVec->z *= length_inv;
	pVec->w = 1.0f;

} // end VECTOR4D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR4D_Normalize(const VECTOR4D* pVa, VECTOR4D* pVecN)
{
	// normalizes the sent vector and returns the result in pVecN

	// compute a length of the vector
	float length = sqrtf((pVa->x * pVa->x) + (pVa->y * pVa->y) + (pVa->z * pVa->z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR4D_ZERO(pVecN);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	pVecN->x *= length_inv;
	pVecN->y *= length_inv;
	pVecN->z *= length_inv;
	pVecN->w = 1.0f;

} // end VECTOR4D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR4D_Build(const VECTOR4D* pInit, const VECTOR4D* pTerm, VECTOR4D* pResult)
{
	// builds a vector init->term and stores the result into pResult;
	// you can pass into this function points as well as vectors

	pResult->x = pTerm->x - pInit->x;
	pResult->y = pTerm->y - pInit->y;
	pResult->z = pTerm->z - pInit->z;
	pResult->w = 1.0f;

} // end VECTOR4D_Build

/////////////////////////////////////////////////////////////

float VECTOR4D_CosTh(const VECTOR4D* pVecA, const VECTOR4D* pVecB)
{
	// this function returns the cosine of the angle between two vectors.
	// Note, we could compute the actual angle many many times, in further calcs
	// we will want ultimately compute cos of the angle, so why not just leave it!
	assert(pVecA != nullptr);
	assert(pVecB != nullptr);

	return (VECTOR4D_Dot(pVecA, pVecB) / (VECTOR4D_Length(pVecA) * VECTOR4D_Length(pVecB)));

} // end VECTOR4D_CosTh

/////////////////////////////////////////////////////////////

void VECTOR4D_Print(const VECTOR4D* pVec, const char* name)
{
	// this function prints out a VECTOR4D's data; used for the debugging purpose

	assert(pVec != nullptr);
	assert((name != nullptr) && (name[0] != '\0'));

	// we need about 50 characters to print 4D vector's data (in format: vector_name = [X, Y, Z, W])
	std::string vectorData;
	vectorData.reserve(50);  

	// make a string with vector's data
	vectorData += name;
	vectorData += " = [";

	for (UINT i = 0; i < 4; i++)
	{
		vectorData += std::to_string(pVec->M[i]);
		vectorData += ", ";
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR4D_Print


} // end of MathLib namespace 