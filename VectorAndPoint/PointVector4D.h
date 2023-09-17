////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector4D.h
// Description:   contains definitions of 4D point and 4D vector types;
//                also has functional for work with these types;
//
// Created:       18.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                         4D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////


// 4D homogeneous vector or point (with w) 
	typedef struct VECTOR4D_TYPE
	{
		VECTOR4D_TYPE()
		{
			x = y = z = 0.0f;
			w = 1.0f;
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

inline void VECTOR4D_ZERO(VECTOR4D* pVec)
{
	pVec->x = pVec->y = pVec->z = 0.0f;
	pVec->w = 1.0f;
}

/////////////////////////////////////////////////////////////

inline void VECTOR4D_INIT_XYZ(VECTOR4D* pVec,
	const float x,
	const float y,
	const float z)
{
	pVec->x = x;
	pVec->y = y;
	pVec->z = z;
	pVec->w = 1.0f;
}

/////////////////////////////////////////////////////////////

inline void VECTOR4D_INIT(VECTOR4D* pVecDst, const VECTOR4D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
	pVecDst->w = pVecSrc->w;
}

/////////////////////////////////////////////////////////////

inline void VECTOR4D_COPY(VECTOR4D* pVecDst, const VECTOR4D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
	pVecDst->w = pVecSrc->w;
}

/////////////////////////////////////////////////////////////

inline void POINT4D_INIT(POINT4D* pDst, const POINT4D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
	pDst->w = pSrc->w;
}

/////////////////////////////////////////////////////////////

inline void POINT4D_COPY(POINT4D* pDst, const POINT4D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
	pDst->w = pSrc->w;
}



////////////////////////////////////////////////////////////////////////////////////////////
//                       MATH OPERATIONS WITH VECTORS/POINTS
////////////////////////////////////////////////////////////////////////////////////////////

void VECTOR4D_Add(const VECTOR4D* pVecA, const VECTOR4D* pVecB, VECTOR4D* pVecSum)
{
	// this function adds pVecA+pVecB and returns it in the pVecSum
	pVecSum->x = pVecA->x + pVecB->x;
	pVecSum->y = pVecA->y + pVecB->y;
	pVecSum->z = pVecA->z + pVecB->z;
	pVecSum->w = pVecA->w + pVecB->w;

} // end VECTOR4D_Add

}; // end namespace MathLib