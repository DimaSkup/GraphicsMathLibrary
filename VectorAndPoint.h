////////////////////////////////////////////////////////////////////
// Filename:      VectorAndPoint.h
// Description:   contains definitions for 2D and 3D vectors and points;
//                also has basic functional to work with these quantities;
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////
#pragma once



//////////////////////////////////
//       DATA STRUCTURES
//////////////////////////////////


// 2D vector or point, without w 
typedef struct VECTOR2D_TYPE
{
	union
	{
		float M[2];     // array for storing

		struct
		{
			float x = 0.0f;
			float y = 0.0f;
		}; // struct
	}; // union
} VECTOR2D, POINT2D, *VECTOR2D_PTR, *POINT2D_PTR;


// 3D vector or point, without w
typedef struct VECTOR3D_TYPE
{
	union
	{
		float M[3];     // array for storing

		struct
		{
			float x = 0.0f;
			float y = 0.0f;
			float z = 0.0f;
		}; // struct
	}; // union
} VECTOR3D, POINT3D, *VECTOR3D_PTR, *POINT3D_PTR;


// 4D homogeneous vector or point (with w) 
typedef struct VECTOR4D_TYPE
{
	union
	{
		float M[4];     // array for storing

		struct
		{
			float x = 0.0f;
			float y = 0.0f;
			float z = 0.0f;
			float w = 1.0f;
		}; // struct
	}; // union
} VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;




//////////////////////////////////
//          OPERATIONS
//////////////////////////////////

// functions for work with vectors

// reset of vectors
inline void VECTOR2D_ZERO(VECTOR2D* pVec)
{
	pVec->x = pVec->y = 0.0f;
}

inline void VECTOR3D_ZERO(VECTOR3D* pVec)
{
	pVec->x = pVec->y = pVec->z = 0.0f;
}

inline void VECTOR4D_ZERO(VECTOR4D* pVec)
{
	pVec->x = pVec->y = pVec->z = 0.0f;
	pVec->w = 1.0f;
}


// vectors initialization with particular values
inline void VECTOR2D_INIT_XY(VECTOR2D* pVec, 
	const float x, 
	const float y)
{
	pVec->x = x;
	pVec->y = y;
}

inline void VECTOR3D_INIT_XYZ(VECTOR3D* pVec, 
	const float x,
	const float y, 
	const float z)
{
	pVec->x = x;
	pVec->y = y;
	pVec->z = z;
}

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


// vectors initialization with the other vectors
inline void VECTOR2D_INIT(VECTOR2D* pVecDst, const VECTOR2D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
}

inline void VECTOR3D_INIT(VECTOR3D* pVecDst, const VECTOR3D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
}

inline void VECTOR4D_INIT(VECTOR4D* pVecDst, const VECTOR4D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
	pVecDst->w = pVecSrc->w;
}


// copying of vectors
inline void VECTOR2D_COPY(VECTOR2D* pVecDst, const VECTOR2D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
}

inline void VECTOR3D_COPY(VECTOR3D* pVecDst, const VECTOR3D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
}

inline void VECTOR4D_COPY(VECTOR4D* pVecDst, const VECTOR4D* pVecSrc)
{
	pVecDst->x = pVecSrc->x;
	pVecDst->y = pVecSrc->y;
	pVecDst->z = pVecSrc->z;
	pVecDst->w = pVecSrc->w;
}


// initialization of points
inline void POINT2D_INIT(POINT2D* pDst, const POINT2D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
}

inline void POINT3D_INIT(POINT3D* pDst, const POINT3D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
}

inline void POINT4D_INIT(POINT4D* pDst, const POINT4D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
	pDst->w = pSrc->w;
}



// copying of points
inline void POINT2D_COPY(POINT2D* pDst, const POINT2D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
}

inline void POINT3D_COPY(POINT3D* pDst, const POINT3D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
}

inline void POINT4D_COPY(POINT4D* pDst, const POINT4D* pSrc)
{
	pDst->x = pSrc->x;
	pDst->y = pSrc->y;
	pDst->z = pSrc->z;
	pDst->w = pSrc->w;
}