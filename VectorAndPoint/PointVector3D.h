////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      PointVector3D.h
// Description:   contains definitions of 3D point and 3D vector types;
//                also has functional for work with these types;
//
// Created:       18.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


namespace MathLib
{

////////////////////////////////////////////////////////////////////////////////////////////
//                         3D VECTOR/POINT DATA STRUCTURE
////////////////////////////////////////////////////////////////////////////////////////////

// 3D vector or point, without w
typedef struct VECTOR3D_TYPE
{


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

void VECTOR3D_Add(const VECTOR3D* pVecA, const VECTOR3D* pVecB, VECTOR3D* pVecSum)
{
	// this function adds pVecA+pVecB and returns it in the pVecSum
	pVecSum->x = pVecA->x + pVecB->x;
	pVecSum->y = pVecA->y + pVecB->y;
	pVecSum->z = pVecA->z + pVecB->z;

} // end VECTOR3D_Add

/////////////////////////////////////////////////////////////


}; // end namespace MathLib