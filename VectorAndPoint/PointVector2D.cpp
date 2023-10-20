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


void VECTOR2D_Add(const VECTOR2D & vecA, const VECTOR2D & vecB, VECTOR2D & vecSum)
{
	// this function adds pVecA+pVecB and returns it in pVecSum
	vecSum.x = vecA.x + vecB.x;
	vecSum.y = vecA.y + vecB.y;

} // end VECTOR2D_Add

/////////////////////////////////////////////////////////////

VECTOR2D VECTOR2D_Add(const VECTOR2D & vecA, const VECTOR2D & vecB)
{
	// this function adds pVecA+pVecB and returns the result on 
	// the stack
	VECTOR2D vecSum{ 0.0f, 0.0f };

	vecSum.x = vecA.x + vecB.x;
	vecSum.y = vecA.y + vecB.y;

	return vecSum;

} // end VECTOR2D_Add

/////////////////////////////////////////////////////////////

void VECTOR2D_Sub(const VECTOR2D & vecA, const VECTOR2D & vecB, VECTOR2D & vecDiff)
{
	// this function subtracts pVecA-pVecB and returns it in pVecDiff
	vecDiff.x = vecA.x - vecB.x;
	vecDiff.y = vecA.y - vecB.y;

} // end VECTOR2D_Sub

/////////////////////////////////////////////////////////////

VECTOR2D VECTOR2D_Sub(const VECTOR2D & vecA, const VECTOR2D & vecB)
{
	// this function subtracts pVecA-pVecB and returns the result on
	// the stack
	VECTOR2D vecDiff{ 0.0f, 0.0f };

	vecDiff.x = vecA.x - vecB.x;
	vecDiff.y = vecA.y - vecB.y;

	return vecDiff;

} // end VECTOR2D_Sub

/////////////////////////////////////////////////////////////

void VECTOR2D_Scale(const float k, VECTOR2D & vecA)
{
	// this function scales a vector by the constant k,
	// in place, note that w is left unchanged
	vecA.x *= k;
	vecA.y *= k;

} // end VECTOR2D_Scale

/////////////////////////////////////////////////////////////

void VECTOR2D_Scale(const float k, const VECTOR2D & vecA, VECTOR2D & vecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled
	vecScaled.x = vecA.x * k;
	vecScaled.y = vecA.y * k;

} // end VECTOR2D_Scale

/////////////////////////////////////////////////////////////

float VECTOR2D_Dot(const VECTOR2D & vecA, const VECTOR2D & vecB)
{
	// calculates a dot product between two vectors and returns it on the stack. 
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);

} // end VECTOR2D_Dot

/////////////////////////////////////////////////////////////

float VECTOR2D_Length(const VECTOR2D & vec)
{
	// computes a length of the vector
	return sqrtf((vec.x * vec.x) + (vec.y * vec.y));

} // end VECTOR2D_Length

/////////////////////////////////////////////////////////////

float VECTOR2D_Length_Fast(const VECTOR2D & vec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	return static_cast<float>(Fast_Distance_2D(
		static_cast<int>(vec.x),
		static_cast<int>(vec.y)
	));

} // end VECTOR2D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR2D_Normalize(VECTOR2D & vec)
{
	// normalizes the sent vector

	// compute a length of the vector
	float length = sqrtf((vec.x * vec.x) + (vec.y * vec.y));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR2D_ZERO(vec);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	vec.x *= length_inv;
	vec.y *= length_inv;

} // end VECTOR2D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR2D_Normalize(const VECTOR2D & vec, VECTOR2D & vecN)
{
	// normalizes the sent vector and returns the result in pVecN

	// compute a length of the vector
	float length = sqrtf((vec.x * vec.x) + (vec.y * vec.y));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR2D_ZERO(vecN);
		return;
	}


	float length_inv = 1.0f / length;

	// normalize the vector
	vecN.x *= length_inv;
	vecN.y *= length_inv;

} // end VECTOR2D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR2D_Build(const VECTOR2D & vInit, const VECTOR2D & vTerm, VECTOR2D & vResult)
{
	// builds a vector init->term and stores the result into pResult;
	// you can pass into this function points as well as vectors

	vResult.x = vTerm.x - vInit.x;
	vResult.y = vTerm.y - vInit.y;

} // end VECTOR2D_Build

/////////////////////////////////////////////////////////////

float VECTOR2D_CosTh(const VECTOR2D & vecA, const VECTOR2D & vecB)
{
	// this function returns the cosine of the angle between two vectors.
	// Note, we could compute the actual angle many many times, in further calcs
	// we will want ultimately compute cos of the angle, so why not just leave it!

	return (VECTOR2D_Dot(vecA, vecB) / (VECTOR2D_Length(vecA) * VECTOR2D_Length(vecB)));

} // end VECTOR2D_CosTh

/////////////////////////////////////////////////////////////

void VECTOR2D_Print(const VECTOR2D & vec, const char* name)
{
	// this function prints out a VECTOR2D's data; used for the debugging purpose

	assert((name != nullptr) && (name[0] != '\0'));

	// we need about 35 characters to print 2D vector's data (in format: vector_name = [X, Y])
	std::string vectorData;
	vectorData.reserve(35);  

	// make a string with vector's data
	vectorData += name;
	vectorData += " = [";

	for (UINT i = 0; i < 2; i++)
	{
		vectorData += std::to_string(vec.M[i]);
		vectorData += ", ";
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR2D_Print


}; // end namespace MathLib