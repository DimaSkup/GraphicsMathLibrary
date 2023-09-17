////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector2D.h
// Description:   contains definitions of 2D point and 2D vector types;
//                also has functional for work with these types;
//
// Created:       18.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                         2D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////


// 2D vector or point, without w 
typedef struct VECTOR2D_TYPE
{
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
//                           ZERO/INIT/COPY OPERATIONS
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
//                       MATH OPERATIONS WITH 2D VECTOR/POINT
////////////////////////////////////////////////////////////////////////////////////////////

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

}; // end namespace MathLib