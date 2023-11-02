////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Quaternion.h
// Description:   contains a definition for quaternion structure;
//                and also has functional for work with quaternions;
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../VectorAndPoint/VectorAndPoint.h"


namespace MathLib
{


////////////////////////////////////////////////////////////////////////////////////////////
//                                 DATA STRUCTURES
////////////////////////////////////////////////////////////////////////////////////////////

typedef struct QUAT_TYPE
{
	QUAT_TYPE() :
		w(0), x(0), y(0), z(0) {}

	QUAT_TYPE(const float qw, const float qx, const float qy, const float qz) :
		w(qw), x(qx), y(qy), z(qz) {}

	union
	{
		float M[4];          // array for storing data (q = q0 + q1*i + q2*j + q3*k)

		struct               // q = q0 + qv
		{
			float q0;        // real part
			VECTOR3D qv;     // imaginary part (vector representation)
		};

		struct               // q = q0 + <q1, q2, q1>
		{
			float w;  // real part
			float x;  // imaginary part 
			float y;  // imaginary part 
			float z;  // imaginary part 
		};
	}; // union
} QUAT, *QUAT_PTR;




////////////////////////////////////////////////////////////////////////////////////////////
//                               INLINE OPERATIONS
////////////////////////////////////////////////////////////////////////////////////////////

// functions for work with quaternions
inline void QUAT_ZERO(QUAT & q)
{
	q.w = q.x = q.y = q.z = 0.0f;
}

inline void QUAT_INIT_WXYZ(QUAT & q,
	const float w,
	const float x,
	const float y,
	const float z)
{
	q.w = w;
	q.x = x;
	q.y = y;
	q.z = z;
}

inline void QUAT_INIT_VECTOR3D(QUAT & q, const VECTOR3D & v)
{
	q.w = 0.0f;
	q.x = v.x;
	q.y = v.y;
	q.z = v.z;
}

inline void QUAT_INIT(QUAT & qDst, const QUAT & qSrc)
{
	qDst.w = qSrc.w;
	qDst.x = qSrc.x;
	qDst.y = qSrc.y;
	qDst.z = qSrc.z;
}

inline void QUAT_COPY(QUAT & qDst, const QUAT & qSrc)
{
	qDst.w = qSrc.w;
	qDst.x = qSrc.x;
	qDst.y = qSrc.y;
	qDst.z = qSrc.z;
}



////////////////////////////////////////////////////////////////////////////////////////////
//                            FUNCTIONS PROTOTYPES
////////////////////////////////////////////////////////////////////////////////////////////
void VECTOR3D_Theta_To_QUAT(QUAT & q, const VECTOR3D & v, const float theta);

void EulerZYX_To_QUAT(QUAT & q,
	const float theta_z,
	const float theta_y,
	const float theta_x);

void QUAT_To_VECTOR3D_Theta(const QUAT & q, VECTOR3D & v, float & theta);

void QUAT_Add(const QUAT & q1, const QUAT & q2, QUAT & qsum);
void QUAT_Sub(const QUAT & q1, const QUAT & q2, QUAT & qdiff);

void QUAT_Conjugate(const QUAT & q, QUAT & qconj);
void QUAT_Scale(const QUAT & q, const float scale, QUAT & qs);
void QUAT_Scale(QUAT & q, const float scale);

float QUAT_Norm(const QUAT & q);
float QUAT_Norm2(const QUAT & q);

void QUAT_Normalize(const QUAT & q, QUAT & qn);
void QUAT_Normalize(QUAT & q);

void QUAT_Unit_Inverse(const QUAT & q, QUAT & qi);
void QUAT_Unit_Inverse(QUAT & q);
void QUAT_Inverse(const QUAT & q, QUAT & qi);

void QUAT_Mul(const QUAT & q1, const QUAT & q2, QUAT & qprod);

} // end namespace MathLib