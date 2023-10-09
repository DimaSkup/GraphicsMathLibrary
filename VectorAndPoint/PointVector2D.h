////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector2D.h
// Description:   contains definitions of 2D point and 2D vector types;
//                also has functional for work with these types;
//
// Created:       18.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cassert>

#include "../Utils/Utils.h"
#include "../Log/Log.h"


namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                         2D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////


// 2D vector or point, without w 
typedef struct VECTOR2D_TYPE
{
	VECTOR2D_TYPE()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	VECTOR2D_TYPE(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	union
	{
		float M[2];     // array for storing

		struct
		{
			float x;
			float y;
		}; // struct
	}; // union
} VECTOR2D, POINT2D, *VECTOR2D_PTR, *POINT2D_PTR;





////////////////////////////////////////////////////////////////////////////////////////////
//                 ZERO/INIT/COPY OPERATIONS FOR 2D VECTORS / 2D POINTS
////////////////////////////////////////////////////////////////////////////////////////////

// functions for work with vectors

// reset of vectors
inline void VECTOR2D_ZERO(VECTOR2D* pVec)
{
	pVec->x = pVec->y = 0.0f;
}

// vectors initialization with particular values
inline void VECTOR2D_INIT_XY(VECTOR2D* pVec,
	const float x,
	const float y)
{
	pVec->x = x;
	pVec->y = y;
}

// vectors initialization with the other vectors
inline void VECTOR2D_INIT(VECTOR2D* pVecDst, const VECTOR2D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
}

// copying of vectors
inline void VECTOR2D_COPY(VECTOR2D* pVecDst, const VECTOR2D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
}


// points initialization with particular values
inline void POINT2D_INIT_XY(POINT2D* pDst,
	const float x,
	const float y)
{
	pDst->x = x;
	pDst->y = y;
}

// initialization of a destination point with a source point
inline void POINT2D_INIT(POINT2D* pDst, const POINT2D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
}

// copying data from a source point into a destination point
inline void POINT2D_COPY(POINT2D* pDst, const POINT2D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
}





////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH 2D VECTORS/POINTS
////////////////////////////////////////////////////////////////////////////////////////////
void VECTOR2D_Add(const VECTOR2D* pVecA, const VECTOR2D* pVecB, VECTOR2D* pVecSum);
VECTOR2D VECTOR2D_Add(const VECTOR2D* pVecA, const VECTOR2D* pVecB);
void VECTOR2D_Sub(const VECTOR2D* pVecA, const VECTOR2D* pVecB, VECTOR2D* pVecDiff);
VECTOR2D VECTOR2D_Sub(const VECTOR2D* pVecA, const VECTOR2D* pVecB);
void VECTOR2D_Scale(const float k, VECTOR2D* pVecA);
void VECTOR2D_Scale(const float k, const VECTOR2D* pVecA, VECTOR2D* pVecScaled);
float VECTOR2D_Dot(const VECTOR2D* pVecA, const VECTOR2D* pVecB);
float VECTOR2D_Length(const VECTOR2D* pVec);
float VECTOR2D_Length_Fast(const VECTOR2D* pVec);
void VECTOR2D_Normalize(VECTOR2D* pVec);
void VECTOR2D_Normalize(const VECTOR2D* pVa, VECTOR2D* pVecN);
void VECTOR2D_Build(const VECTOR2D* pInit, const VECTOR2D* pTerm, VECTOR2D* pResult);
float VECTOR2D_CosTh(const VECTOR2D* pVecA, const VECTOR2D* pVecB);
void VECTOR2D_Print(const VECTOR2D* pVec, const char* name = "v");


} // end of MathLib namespace