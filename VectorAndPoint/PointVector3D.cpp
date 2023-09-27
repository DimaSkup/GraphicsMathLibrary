////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector3D.cpp
// Description:   contains implementation of functional for work with 
//                3D points and 3D vectors;
//
// Created:       26.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "PointVector3D.h"


namespace MathLib
{


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
	assert(pVecA != nullptr);
	assert(pVecB != nullptr);
	assert(pVecDiff != nullptr);

	pVecDiff->x = pVecA->x - pVecB->x;
	pVecDiff->y = pVecA->y - pVecB->y;
	pVecDiff->z = pVecA->z - pVecB->z;

} // end VECTOR3D_Sub

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Sub(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// this function subtracts pVecA-pVecB and returns the result on 
	// the stack

	assert(pVecA != nullptr);
	assert(pVecB != nullptr);

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

	assert(pVecA != nullptr);

	pVecA->x *= k;
	pVecA->y *= k;
	pVecA->z *= k;

} // end VECTOR3D_Scale

/////////////////////////////////////////////////////////////

void VECTOR3D_Scale(const float k, const VECTOR3D* pVecA, VECTOR3D* pVecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled

	assert(pVecA != nullptr);
	assert(pVecScaled != nullptr);

	pVecScaled->x = pVecA->x * k;
	pVecScaled->y = pVecA->y * k;
	pVecScaled->z = pVecA->z * k;

} // end VECTOR3D_Scale

/////////////////////////////////////////////////////////////

float VECTOR3D_Dot(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// calculates a dot product between two vectors and returns it on the stack.
	assert((pVecA != nullptr) && (pVecB != nullptr));

	return (pVecA->x * pVecB->x) + (pVecA->y * pVecB->y) + (pVecA->z * pVecB->z);

} // end VECTOR3D_Dot

/////////////////////////////////////////////////////////////

void VECTOR3D_Cross(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecN)
{
	// computes the cross product between pVecA and pVecB and returns the result in pVecN;
	assert((pVecA != nullptr) && (pVecB != nullptr) && (pVecN != nullptr));

	pVecN->x = (pVecA->y * pVecB->z) - (pVecA->z * pVecB->y);
	pVecN->y = (pVecA->z * pVecB->x) - (pVecA->x * pVecB->z);
	pVecN->z = (pVecA->x * pVecB->y) - (pVecA->y * pVecB->x);

} // end VECTOR3D_Cross

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Cross(const VECTOR3D* pVecA, const VECTOR3D* pVecB)
{
	// computes the cross product between pVecA and pVecB and returns the result 
	// on the stack;
	assert(pVecA != nullptr);
	assert(pVecB != nullptr);

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

	assert(pVec != nullptr);

	return sqrtf((pVec->x * pVec->x) + (pVec->y * pVec->y) + (pVec->z * pVec->z));

} // end VECTOR3D_Length

/////////////////////////////////////////////////////////////

float VECTOR3D_Length_Fast(const VECTOR3D* pVec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	assert(pVec != nullptr);

	return Fast_Distance_3D(pVec->x, pVec->y, pVec->z);

} // end VECTOR3D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR3D_Normalize(VECTOR3D* pVec)
{
	// normalizes the sent vector

	assert(pVec != nullptr);

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

	assert(pVa != nullptr);
	assert(pVecN != nullptr);

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

	assert(pInit != nullptr);
	assert(pTerm != nullptr);
	assert(pResult != nullptr);

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

void VECTOR3D_Print(const VECTOR3D* pVec, const char* name)
{
	// this function prints out a VECTOR3D's data; used for the debugging purpose

	assert(pVec != nullptr);
	assert((name != nullptr) && (name[0] != '\0'));

	// we need about 45 characters to print 3D vector's data (in format: vector_name = [X, Y, Z])
	std::string vectorData;
	vectorData.reserve(45); 

	// make a string with vector's data
	vectorData += name;
	vectorData += " = [";

	for (UINT i = 0; i < 3; i++)
	{
		vectorData += std::to_string(pVec->M[i]);
		vectorData += ", ";
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR3D_Print


} // end of MathLib namespace