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
	VECTOR3D_TYPE()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	VECTOR3D_TYPE(const float dx, const float dy, const float dz)
	{
		this->x = dx;
		this->y = dy;
		this->z = dz;
	}

	// init a vector using two 3D points
	VECTOR3D_TYPE(const VECTOR3D_TYPE & pInit, const VECTOR3D_TYPE & pTerm)
	{
		this->x = pTerm.x - pInit.x;
		this->y = pTerm.y - pInit.y;
		this->z = pTerm.z - pInit.z;
	}

	// init a point using another point
	VECTOR3D_TYPE(const VECTOR3D_TYPE & pCopy)
	{
		this->x = pCopy.x;
		this->y = pCopy.y;
		this->z = pCopy.z;
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

void VECTOR3D_Add(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecSum);
void VECTOR3D_Sub(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecDiff);

VECTOR3D VECTOR3D_Add(const VECTOR3D* pVecA, const VECTOR3D* pVecB);
VECTOR3D VECTOR3D_Sub(const VECTOR3D* pVecA, const VECTOR3D* pVecB);

void VECTOR3D_Scale(const float k, VECTOR3D* pVecA);
void VECTOR3D_Scale(const float k, const VECTOR3D* pVecA, VECTOR3D* pVecScaled);

float VECTOR3D_Dot(const VECTOR3D* pVecA, const VECTOR3D* pVecB);
void VECTOR3D_Cross(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecN);
VECTOR3D VECTOR3D_Cross(const VECTOR3D* pVecA, const VECTOR3D* pVecB);

float VECTOR3D_Length(const VECTOR3D* pVec);
float VECTOR3D_Length_Fast(const VECTOR3D* pVec);

void VECTOR3D_Normalize(VECTOR3D* pVec);
void VECTOR3D_Normalize(const VECTOR3D* pVa, VECTOR3D* pVecN);

void VECTOR3D_Build(const VECTOR3D* pInit, const VECTOR3D* pTerm, VECTOR3D* pResult);
float VECTOR3D_CosTh(const VECTOR3D* pVecA, const VECTOR3D* pVecB);
void VECTOR3D_Print(const VECTOR3D* pVec, const char* name = "v");

}; // end namespace MathLib