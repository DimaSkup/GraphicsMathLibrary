////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector4D.h
// Description:   contains definitions of 4D point and 4D vector types;
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
//                         4D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////


// 4D homogeneous vector or point (with w) 
typedef struct VECTOR4D_TYPE
{
	// default constructor
	VECTOR4D_TYPE()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	// init a vector using separate float values
	VECTOR4D_TYPE(const float vx, 
				  const float vy, 
				  const float vz, 
				  const float vw)
	{
		x = vx;
		y = vy;
		z = vz;
		w = vw;
	}

	// init a vector using references of two 4D vectors/points
	VECTOR4D_TYPE(const VECTOR4D_TYPE & vInit, const VECTOR4D_TYPE & vTerm)
	{
		x = vTerm.x - vInit.x;
		y = vTerm.y - vInit.y;
		z = vTerm.z - vInit.z;
		w = vTerm.w - vInit.w;
	}

	// copy constructor
	VECTOR4D_TYPE(const VECTOR4D_TYPE & copy)
	{
		x = copy.x;
		y = copy.y;
		z = copy.z;
		w = copy.w;
	}

	union
	{
		float M[4];     // array for storing

		struct
		{
			float x;
			float y;
			float z;
			float w;
		}; // struct
	}; // union

} VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;


////////////////////////////////////////////////////////////////////////////////////////////
//                  ZERO/INIT/COPY OPERATIONS FOR 4D VECTORS / 4D POINTS
////////////////////////////////////////////////////////////////////////////////////////////

// functions for work with 4D vectors

inline void VECTOR4D_ZERO(VECTOR4D & v)
{
	v.x = v.y = v.z = 0.0f;
	v.w = 1.0f;
}

/////////////////////////////////////////////////////////////

inline void VECTOR4D_INIT_XYZ(VECTOR4D & vec,
	const float x,
	const float y,
	const float z)
{
	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = 1.0f;
}

/////////////////////////////////////////////////////////////

inline void VECTOR4D_INIT(VECTOR4D & vecDst, const VECTOR4D & vecSrc)
{
	vecDst.x = vecSrc.x;
	vecDst.y = vecSrc.y;
	vecDst.z = vecSrc.z;
	vecDst.w = vecSrc.w;
}

/////////////////////////////////////////////////////////////

inline void VECTOR4D_COPY(VECTOR4D & vecDst, const VECTOR4D & vecSrc)
{
	vecDst.x = vecSrc.x;
	vecDst.y = vecSrc.y;
	vecDst.z = vecSrc.z;
	vecDst.w = vecSrc.w;
}

/////////////////////////////////////////////////////////////

inline void POINT4D_INIT(POINT4D & pDst, const POINT4D & pSrc)
{
	pDst.x = pSrc.x;
	pDst.y = pSrc.y;
	pDst.z = pSrc.z;
	pDst.w = pSrc.w;
}

/////////////////////////////////////////////////////////////

inline void POINT4D_COPY(POINT4D & pDst, const POINT4D & pSrc)
{
	pDst.x = pSrc.x;
	pDst.y = pSrc.y;
	pDst.z = pSrc.z;
	pDst.w = pSrc.w;
}



////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH VECTORS/POINTS
////////////////////////////////////////////////////////////////////////////////////////////

VECTOR4D VECTOR4D_Sub(const VECTOR4D & vecA, const VECTOR4D & vecB);
VECTOR4D VECTOR4D_Add(const VECTOR4D & vecA, const VECTOR4D & vecB);

void VECTOR4D_Add(const VECTOR4D & vecA, const VECTOR4D & vecB, VECTOR4D & vecSum);
void VECTOR4D_Sub(const VECTOR4D & vecA, const VECTOR4D & vecB, VECTOR4D & vecDiff);

void VECTOR4D_Scale(const float k, VECTOR4D & vecA);
void VECTOR4D_Scale(const float k, const VECTOR4D & vecA, VECTOR4D & vecScaled);

float VECTOR4D_Dot(const VECTOR4D & vecA, const VECTOR4D & vecB);
void VECTOR4D_Cross(const VECTOR4D & vecA, const VECTOR4D & vecB, VECTOR4D & vecN);
VECTOR4D VECTOR4D_Cross(const VECTOR4D & vecA, const VECTOR4D & vecB);

float VECTOR4D_Length(const VECTOR4D & vec);
float VECTOR4D_Length_Fast(const VECTOR4D & vec);

void VECTOR4D_Normalize(VECTOR4D & vec);
void VECTOR4D_Normalize(const VECTOR4D & vec, VECTOR4D & vecN);

void VECTOR4D_Build(const VECTOR4D & vInit, const VECTOR4D & vTerm, VECTOR4D & vResult);
float VECTOR4D_CosTh(const VECTOR4D & vecA, const VECTOR4D & vecB);
void VECTOR4D_Print(const VECTOR4D & vec, const char* name = "v");


}; // end namespace MathLib