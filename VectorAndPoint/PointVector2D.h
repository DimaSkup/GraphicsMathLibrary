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

	VECTOR2D_TYPE(const float dx, const float dy)
	{
		this->x = dx;
		this->y = dy;
	}

	// init a vector using references to two 2D points
	VECTOR2D_TYPE(const VECTOR2D_TYPE & pInit, const VECTOR2D_TYPE & pTerm)
	{
		this->x = pTerm.x - pInit.x;
		this->y = pTerm.y - pInit.y;
	}

	// init a point using another 2D point
	VECTOR2D_TYPE(const VECTOR2D_TYPE & pCopy)
	{
		this->x = pCopy.x;
		this->y = pCopy.y;
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
inline void VECTOR2D_ZERO(VECTOR2D & vec)
{
	vec.x = vec.y = 0.0f;
}

// vectors initialization with particular values
inline void VECTOR2D_INIT_XY(VECTOR2D & vec,
	const float x,
	const float y)
{
	vec.x = x;
	vec.y = y;
}

// vectors initialization with the other vectors
inline void VECTOR2D_INIT(VECTOR2D & vecDst, const VECTOR2D & vecSrc)
{
	vecDst.x = vecSrc.x;
	vecDst.y = vecSrc.y;
}

// copying of vectors
inline void VECTOR2D_COPY(VECTOR2D & vecDst, const VECTOR2D & vecSrc)
{
	vecDst.x = vecSrc.x;
	vecDst.y = vecSrc.y;
}


// points initialization with particular values
inline void POINT2D_INIT_XY(POINT2D & pDst,
	const float x,
	const float y)
{
	pDst.x = x;
	pDst.y = y;
}

// initialization of a destination point with a source point
inline void POINT2D_INIT(POINT2D & pDst, const POINT2D & pSrc)
{
	pDst.x = pSrc.x;
	pDst.y = pSrc.y;
}

// copying data from a source point into a destination point
inline void POINT2D_COPY(POINT2D & pDst, const POINT2D & pSrc)
{
	pDst.x = pSrc.x;
	pDst.y = pSrc.y;
}





////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH 2D VECTORS/POINTS
////////////////////////////////////////////////////////////////////////////////////////////
void VECTOR2D_Add(const VECTOR2D & vecA, const VECTOR2D & vecB, VECTOR2D & vecSum);
void VECTOR2D_Sub(const VECTOR2D & vecA, const VECTOR2D & vecB, VECTOR2D & vecDiff);

VECTOR2D VECTOR2D_Add(const VECTOR2D & vecA, const VECTOR2D & vecB);
VECTOR2D VECTOR2D_Sub(const VECTOR2D & vecA, const VECTOR2D & vecB);

void VECTOR2D_Scale(const float k, VECTOR2D & vecA);
void VECTOR2D_Scale(const float k, const VECTOR2D & vecA, VECTOR2D & vecScaled);

float VECTOR2D_Dot(const VECTOR2D & vecA, const VECTOR2D & vecB);
float VECTOR2D_Length(const VECTOR2D & vec);
float VECTOR2D_Length_Fast(const VECTOR2D & vec);

void VECTOR2D_Normalize(VECTOR2D & vec);
void VECTOR2D_Normalize(const VECTOR2D & vec, VECTOR2D & vecN);

void VECTOR2D_Build(const VECTOR2D & vInit, const VECTOR2D& vTerm, VECTOR2D & vResult);
float VECTOR2D_CosTh(const VECTOR2D & vecA, const VECTOR2D & vecB);
void VECTOR2D_Print(const VECTOR2D & vec, const char* name = "v");


} // end of MathLib namespace