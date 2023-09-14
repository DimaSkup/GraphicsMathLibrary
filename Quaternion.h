////////////////////////////////////////////////////////////////////
// Filename:      Quaternion.h
// Description:   contains a definition for quaternion structure
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "VectorAndPoint.h"

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
