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


void VECTOR3D_Add(const VECTOR3D & vecA, const VECTOR3D & vecB, VECTOR3D & vecSum)
{
	// this function adds pVecA+pVecB and returns it in the pVecSum
	vecSum.x = vecA.x + vecB.x;
	vecSum.y = vecA.y + vecB.y;
	vecSum.z = vecA.z + vecB.z;

} // end VECTOR3D_Add

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Add(const VECTOR3D & vecA, const VECTOR3D & vecB)
{
	// this function adds pVecA+pVecB and returns the result on
	// the stack
	VECTOR3D vecSum;

	vecSum.x = vecA.x + vecB.x;
	vecSum.y = vecA.y + vecB.y;
	vecSum.z = vecA.z + vecB.z;

	return vecSum;

} // end VECTOR3D_Add

/////////////////////////////////////////////////////////////

void VECTOR3D_Sub(const VECTOR3D & vecA, const VECTOR3D & vecB, VECTOR3D & vecDiff)
{
	// this function subtracts pVecA-pVecB and returns the result in the pVecDiff

	vecDiff.x = vecA.x - vecB.x;
	vecDiff.y = vecA.y - vecB.y;
	vecDiff.z = vecA.z - vecB.z;

} // end VECTOR3D_Sub

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Sub(const VECTOR3D & vecA, const VECTOR3D & vecB)
{
	// this function subtracts pVecA-pVecB and returns the result on 
	// the stack

	VECTOR3D vecDiff;

	vecDiff.x = vecA.x - vecB.x;
	vecDiff.y = vecA.y - vecB.y;
	vecDiff.z = vecA.z - vecB.z;

	return vecDiff;

} // end VECTOR3D_Sub

/////////////////////////////////////////////////////////////

void VECTOR3D_Scale(const float k, VECTOR3D & vecA)
{
	// this function scales a vector by the constant k,
	// in place, note that w is left unchanged

	vecA.x *= k;
	vecA.y *= k;
	vecA.z *= k;

} // end VECTOR3D_Scale

/////////////////////////////////////////////////////////////

void VECTOR3D_Scale(const float k, const VECTOR3D & vecA, VECTOR3D & vecScaled)
{
	// this function scales a vector by the constant k
	// and returns the result in the pVecScaled

	vecScaled.x = vecA.x * k;
	vecScaled.y = vecA.y * k;
	vecScaled.z = vecA.z * k;

} // end VECTOR3D_Scale

/////////////////////////////////////////////////////////////

float VECTOR3D_Dot(const VECTOR3D & vecA, const VECTOR3D & vecB)
{
	// calculates a dot product between two vectors and returns it on the stack.

	return (vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z);

} // end VECTOR3D_Dot

/////////////////////////////////////////////////////////////

void VECTOR3D_Cross(const VECTOR3D & vecA, const VECTOR3D & vecB, VECTOR3D & vecN)
{
	// computes the cross product between pVecA and pVecB and returns the result in pVecN;

	vecN.x = (vecA.y * vecB.z) - (vecA.z * vecB.y);
	vecN.y = (vecA.z * vecB.x) - (vecA.x * vecB.z);
	vecN.z = (vecA.x * vecB.y) - (vecA.y * vecB.x);

} // end VECTOR3D_Cross

/////////////////////////////////////////////////////////////

VECTOR3D VECTOR3D_Cross(const VECTOR3D & vecA, const VECTOR3D & vecB)
{
	// computes the cross product between pVecA and pVecB and returns the result 
	// on the stack;

	VECTOR3D vecN{ 0.0f, 0.0f, 0.0f };

	vecN.x = (vecA.y * vecB.z) - (vecA.z * vecB.y);
	vecN.y = (vecA.z * vecB.x) - (vecA.x * vecB.z);
	vecN.z = (vecA.x * vecB.y) - (vecA.y * vecB.x);

	return vecN;

} // end VECTOR3D_Cross

/////////////////////////////////////////////////////////////

float VECTOR3D_Length(const VECTOR3D & vec)
{
	// computes a length of the vector

	return sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

} // end VECTOR3D_Length

/////////////////////////////////////////////////////////////

float VECTOR3D_Length_Fast(const VECTOR3D & vec)
{
	// computes the magnitute of a vector using an approximation;
	// very fast

	return Fast_Distance_3D(vec.x, vec.y, vec.z);

} // end VECTOR3D_Length_Fast

/////////////////////////////////////////////////////////////

void VECTOR3D_Normalize(VECTOR3D & v)
{
	// this function normalizes the sent vector

	// compute a length of the vector
	float length = sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR3D_ZERO(v);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	v.x *= length_inv;
	v.y *= length_inv;
	v.z *= length_inv;

} // end VECTOR3D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR3D_Normalize(const VECTOR3D & vec, VECTOR3D & vecN)
{
	// normalizes the sent vector and returns the result in pVecN

	// compute a length of the vector
	float length = sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));

	// test for zero length vector; 
	// if found return a zero vector
	if (length < EPSILON_E5)
	{
		VECTOR3D_ZERO(vecN);
		return;
	}

	float length_inv = 1.0f / length;

	// normalize the vector
	vecN.x *= length_inv;
	vecN.y *= length_inv;
	vecN.z *= length_inv;

} // end VECTOR3D_Normalize

/////////////////////////////////////////////////////////////

void VECTOR3D_Build(const VECTOR3D & vInit, const VECTOR3D & vTerm, VECTOR3D & vecResult)
{
	// builds a vector init->term and stores the result into pResult;
	// you can pass into this function points as well as vectors

	vecResult.x = vTerm.x - vInit.x;
	vecResult.y = vTerm.y - vInit.y;
	vecResult.z = vTerm.z - vInit.z;

} // end VECTOR3D_Build

/////////////////////////////////////////////////////////////

float VECTOR3D_CosTh(const VECTOR3D & vecA, const VECTOR3D & vecB)
{
	// this function returns the cosine of the angle between two vectors.
	// Note, we could compute the actual angle many many times, in further calcs
	// we will want ultimately compute cos of the angle, so why not just leave it!

	return (VECTOR3D_Dot(vecA, vecB) / (VECTOR3D_Length(vecA) * VECTOR3D_Length(vecB)));

} // end VECTOR3D_CosTh

/////////////////////////////////////////////////////////////

void VECTOR3D_Print(const VECTOR3D & vec, const char* name)
{
	// this function prints out a VECTOR3D's data; used for the debugging purpose

	assert((name != nullptr) && (name[0] != '\0'));

	// we need about 45 characters to print 3D vector's data (in format: vector_name = [X, Y, Z])
	std::string vectorData;
	vectorData.reserve(45); 

	// make a string with vector's data
	vectorData += name;
	vectorData += " = [";

	for (UINT i = 0; i < 3; i++)
	{
		vectorData += std::to_string(vec.M[i]);
		vectorData += ", ";
	}
	vectorData += "]\n";

	Log::Debug(LOG_MACRO, vectorData);

} // end VECTOR3D_Print


} // end of MathLib namespace