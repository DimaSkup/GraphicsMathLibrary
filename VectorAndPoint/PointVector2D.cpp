////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector2D.cpp
// Description:   contains implementation of functional for work with 
//                2D points and 2D vectors;
//
// Created:       25.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "PointVector2D.h"


namespace MathLib
{


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

void VECTOR2D_Print(const VECTOR2D* pVec, const char* name)
{
	// this function prints out a VECTOR2D's data; used for the debugging purpose

	assert(pVec != nullptr);
	assert((name != nullptr) && (name[0] != '\0'));

	// we need about 35 characters to print 2D vector's data (in format: vector_name = [X, Y])
	std::string vectorData;
	vectorData.reserve(35);  

	// make a string with vector's data
	vectorData += name;
	vectorData += " = [";

	for (UINT i = 0; i < 2; i++)
	{
		vectorData += std::to_string(pVec->M[i]);
		vectorData += ", ";
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR2D_Print


}; // end namespace MathLib