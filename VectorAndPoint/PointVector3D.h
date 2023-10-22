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
	// default constructor
	VECTOR3D_TYPE()
	{
		x = y = z = 0;
	}

	// init a vector using separate float values
	VECTOR3D_TYPE(const float dx, 
				  const float dy, 
				  const float dz)
	{
		x = dx;
		y = dy;
		z = dz;
	}

	// init a vector using references of two 3D vectors/points
	VECTOR3D_TYPE(const VECTOR3D_TYPE & pInit, const VECTOR3D_TYPE & pTerm)
	{
		x = pTerm.x - pInit.x;
		y = pTerm.y - pInit.y;
		z = pTerm.z - pInit.z;
	}

	// copy constructor
	VECTOR3D_TYPE(const VECTOR3D_TYPE & pCopy)
	{
		x = pCopy.x;
		y = pCopy.y;
		z = pCopy.z;
	}


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


inline void VECTOR3D_ZERO(VECTOR3D & v)
{
	v.x = v.y = v.z = 0.0f;
}

/////////////////////////////////////////////////////////////

inline void VECTOR3D_INIT_XYZ(VECTOR3D & vec,
	const float x,
	const float y,
	const float z)
{
	vec.x = x;
	vec.y = y;
	vec.z = z;
}

/////////////////////////////////////////////////////////////

inline void VECTOR3D_INIT(VECTOR3D & vecDst, const VECTOR3D & vecSrc)
{
	vecDst.x = vecSrc.x;
	vecDst.y = vecSrc.y;
	vecDst.z = vecSrc.z;
}

/////////////////////////////////////////////////////////////

inline void VECTOR3D_COPY(VECTOR3D & vecDst, const VECTOR3D & vecSrc)
{
	vecDst.x = vecSrc.x;
	vecDst.y = vecSrc.y;
	vecDst.z = vecSrc.z;
}

/////////////////////////////////////////////////////////////

inline void POINT3D_INIT_XYZ(VECTOR3D & pPoint,
	const float x,
	const float y,
	const float z)
{
	pPoint.x = x;
	pPoint.y = y;
	pPoint.z = z;
}

/////////////////////////////////////////////////////////////

inline void POINT3D_INIT(POINT3D & pDst, const POINT3D & pSrc)
{
	pDst.x = pSrc.x;
	pDst.y = pSrc.y;
	pDst.z = pSrc.z;
}

/////////////////////////////////////////////////////////////

inline void POINT3D_COPY(POINT3D & pDst, const POINT3D & pSrc)
{
	pDst.x = pSrc.x;
	pDst.y = pSrc.y;
	pDst.z = pSrc.z;
}




////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH VECTORS/POINTS
////////////////////////////////////////////////////////////////////////////////////////////

void VECTOR3D_Add(const VECTOR3D & vecA, const VECTOR3D & vecB, VECTOR3D & pVecSum);
void VECTOR3D_Sub(const VECTOR3D & vecA, const VECTOR3D & vecB, VECTOR3D & pVecDiff);

VECTOR3D VECTOR3D_Add(const VECTOR3D & vecA, const VECTOR3D & vecB);
VECTOR3D VECTOR3D_Sub(const VECTOR3D & vecA, const VECTOR3D & vecB);

void VECTOR3D_Scale(const float k, VECTOR3D & vecA);
void VECTOR3D_Scale(const float k, const VECTOR3D & vecA, VECTOR3D & vecScaled);

float VECTOR3D_Dot(const VECTOR3D & vecA, const VECTOR3D & vecB);
void VECTOR3D_Cross(const VECTOR3D & vecA, const VECTOR3D & vecB, VECTOR3D & vecN);
VECTOR3D VECTOR3D_Cross(const VECTOR3D & vecA, const VECTOR3D & vecB);

float VECTOR3D_Length(const VECTOR3D & vec);
float VECTOR3D_Length_Fast(const VECTOR3D & vec);

void VECTOR3D_Normalize(VECTOR3D & vec);
void VECTOR3D_Normalize(const VECTOR3D & vec, VECTOR3D & pVecN);

void VECTOR3D_Build(const VECTOR3D & vInit, const VECTOR3D & vTerm, VECTOR3D & vecResult);
float VECTOR3D_CosTh(const VECTOR3D & vecA, const VECTOR3D & pVecB);
void VECTOR3D_Print(const VECTOR3D & vec, const char* name = "v");

}; // end namespace MathLib