////////////////////////////////////////////////////////////////////
// Filename:      Quaternion.h
// Description:   contains a definition for quaternion structure;
//                and also has functional for work with quaternions;
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "VectorAndPoint.h"


//////////////////////////////////
//       DATA STRUCTURES
//////////////////////////////////

typedef struct QUAT_TYPE
{
	union
	{
		float M[4];          // array for storing data (q = q0 + q1*i + q2*j + q3*k)

		struct               // q = q0 + qv
		{
			float q0;        // real part
			VECTOR4D qv;     // imaginary part (vector representation)
		};

		struct               // q = q0 + <q1, q2, q1>
		{
			float w = 0.0f;  // real part
			float x = 0.0f;  // imaginary part 
			float y = 0.0f;  // imaginary part 
			float z = 0.0f;  // imaginary part 
		};
	}; // union
} QUAT, *QUAT_PTR;




//////////////////////////////////
//          OPERATIONS
//////////////////////////////////

// functions for work with quaternions
inline void QUAT_ZERO(QUAT* pQuat)
{
	pQuat->x = pQuat->y = pQuat->z = pQuat->w = 0.0f;
}

inline void QUAT_INIT_WXYZ(QUAT* pQuat,
	const float w,
	const float x,
	const float y,
	const float z)
{
	pQuat->w = w;
	pQuat->x = x;
	pQuat->y = y;
	pQuat->z = z;
}

inline void QUAT_INIT_VECTOR3D(QUAT* pQuat, const VECTOR3D* pVec)
{
	pQuat->w = 0.0f;
	pQuat->x = pVec->x;
	pQuat->y = pVec->y;
	pQuat->z = pVec->z;
}

inline void QUAT_INIT(QUAT* pQuatDst, const QUAT* pQuatSrc)
{
	pQuatDst->w = pQuatSrc->w;
	pQuatDst->x = pQuatSrc->x;
	pQuatDst->y = pQuatSrc->y;
	pQuatDst->z = pQuatSrc->z;
}

inline void QUAT_COPY(QUAT* pQuatDst, const QUAT* pQuatSrc)
{
	pQuatDst->w = pQuatSrc->w;
	pQuatDst->x = pQuatSrc->x;
	pQuatDst->y = pQuatSrc->y;
	pQuatDst->z = pQuatSrc->z;
}
