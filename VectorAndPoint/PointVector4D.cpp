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


void VECTOR4D_Add(const VECTOR4D & vecA, const VECTOR4D & vecB, VECTOR4D & vecSum)
{
	// this function adds pVecA+pVecB and returns it in the pVecSum
	vecSum.x = vecA.x + vecB.x;
	vecSum.y = vecA.y + vecB.y;
	vecSum.z = vecA.z + vecB.z;
	vecSum.w = vecA.w + vecB.w;

} // end VECTOR4D_Add

/////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Add(const VECTOR4D & vecA, const VECTOR4D & vecB)
{
	// this function adds pVecA+pVecB and returns the result on
	// the stack
	VECTOR4D vecSum;

	vecSum.x = vecA.x + vecB.x;
	vecSum.y = vecA.y + vecB.y;
	vecSum.z = vecA.z + vecB.z;
	vecSum.w = vecA.w + vecB.w;

	return vecSum;

} // end VECTOR4D_Add

/////////////////////////////////////////////////////////////

void VECTOR4D_Sub(const VECTOR4D & vecA, const VECTOR4D & vecB, VECTOR4D & vecDiff)
{
	// this function subtracts pVecA-pVecB and returns the result in the pVecDiff

	vecDiff.x = vecA.x - vecB.x;
	vecDiff.y = vecA.y - vecB.y;
	vecDiff.z = vecA.z - vecB.z;
	vecDiff.w = vecA.w - vecB.w;

} // end VECTOR4D_Sub

/////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Sub(const VECTOR4D & vecA, const VECTOR4D & vecB)
{
	// this function subtracts pVecA-pVecB and returns the result on 
	// the stack
	VECTOR4D vecDiff;

	vecDiff.x = vecA.x - vecB.x;
	vecDiff.y = vecA.y - vecB.y;
	vecDiff.z = vecA.z - vecB.z;
	vecDiff.w = vecA.w - vecB.w;

	return vecDiff;
} // end VECTOR4D_Sub

/////////////////////////////////////////////////////////////

void VECTOR4D_Scale(const float k, VECTOR4D & vecA)
{
	// this function scales a vector by the constant k,
	// in place, note that w is left unchanged
	vecA.x *= k;
	vecA.y *= k;
	vecA.z *= k;
	vecA.w = 1.0f;

} // end VECTOR4D_Scale

/////////////////////////////////////////////////////////////

void VECTOR4D_Scale(const float k, const VECTOR4D & vecA, VECTOR4D & vecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled

	vecScaled.x = vecA.x * k;
	vecScaled.y = vecA.y * k;
	vecScaled.z = vecA.z * k;
	vecScaled.w = 1.0f;
	
} // end VECTOR4D_Scale

/////////////////////////////////////////////////////////////

float VECTOR4D_Dot(const VECTOR4D & vecA, const VECTOR4D & vecB)
{
	// computes the dot product between two vectors and returns it on the stack. 
	// For 4D vectors a w component isn't used;
	return (vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z);

} // end VECTOR4D_Dot

/////////////////////////////////////////////////////////////

void VECTOR4D_Cross(const VECTOR4D & vecA, const VECTOR4D & vecB, VECTOR4D & vecN)
{
	// computes the cross product between pVecA and pVecB and returns the result in pVecN;
	// For 4D vectors a component w is not used
	vecN.x = (vecA.y * vecB.z) - (vecA.z * vecB.y);
	vecN.y = (vecA.z * vecB.x) - (vecA.x * vecB.z);
	vecN.z = (vecA.x * vecB.y) - (vecA.y * vecB.x);
	vecN.w = 1.0f;

} // end VECTOR4D_Cross

/////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Cross(const VECTOR4D & vecA, const VECTOR4D & vecB)
{
	// computes the cross product between pVecA and pVecB and returns the result 
	// on the stack;
	VECTOR4D vecN;

	vecN.x = (vecA.y * vecB.z) - (vecA.z * vecB.y);
	vecN.y = (vecA.z * vecB.x) - (vecA.x * vecB.z);
	vecN.z = (vecA.x * vecB.y) - (vecA.y * vecB.x);
	// vecN.w = 1.0f;   // we don't set component w to 1.0f because we've already done it

	return vecN;

} // end VECTOR4D_Cross

/////////////////////////////////////////////////////////////

float VECTOR4D_Length(const VECTOR4D & vec)
{
	// computes a length of the vector
	return sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

} // end VECTOR4D_Length

/////////////////////////////////////////////////////////////

float VECTOR4D_Length_Fast(const VECTOR4D & vec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	return Fast_Distance_3D(vec.x, vec.y, vec.z);

} // end VECTOR4D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR4D_Normalize(VECTOR4D & vec)
{
	// normalizes the sent vector

	// compute a length of the vector
	float length = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR4D_ZERO(vec);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	vec.x *= length_inv;
	vec.y *= length_inv;
	vec.z *= length_inv;
	vec.w = 1.0f;

} // end VECTOR4D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR4D_Normalize(const VECTOR4D & vec, VECTOR4D & vecN)
{
	// normalizes the sent vector and returns the result in pVecN

	// compute a length of the vector
	float length = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR4D_ZERO(vecN);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	vecN.x *= length_inv;
	vecN.y *= length_inv;
	vecN.z *= length_inv;
	vecN.w = 1.0f;

} // end VECTOR4D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR4D_Build(const VECTOR4D & vInit, const VECTOR4D & vTerm, VECTOR4D & vResult)
{
	// builds a vector init->term and stores the result into pResult;
	// you can pass into this function points as well as vectors

	vResult.x = vTerm.x - vInit.x;
	vResult.y = vTerm.y - vInit.y;
	vResult.z = vTerm.z - vInit.z;
	vResult.x = 1.0f;

} // end VECTOR4D_Build

/////////////////////////////////////////////////////////////

float VECTOR4D_CosTh(const VECTOR4D & vecA, const VECTOR4D & vecB)
{
	// this function returns the cosine of the angle between two vectors.
	// Note, we could compute the actual angle many many times, in further calcs
	// we will want ultimately compute cos of the angle, so why not just leave it!

	return (VECTOR4D_Dot(vecA, vecB) / (VECTOR4D_Length(vecA) * VECTOR4D_Length(vecB)));

} // end VECTOR4D_CosTh

/////////////////////////////////////////////////////////////

void VECTOR4D_Print(const VECTOR4D & vec, const char* name)
{
	// this function prints out a VECTOR4D's data; used for the debugging purpose

	assert((name != nullptr) && (name[0] != '\0'));

	// we need about 50 characters to print 4D vector's data (in format: vector_name = [X, Y, Z, W])
	std::string vectorData;
	vectorData.reserve(50);  

	// make a string with vector's data
	vectorData += name;
	vectorData += " = [";

	for (UINT i = 0; i < 4; i++)
	{
		vectorData += std::to_string(vec.M[i]);
		vectorData += ", ";
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR4D_Print


} // end of MathLib namespace 