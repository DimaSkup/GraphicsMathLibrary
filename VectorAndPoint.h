////////////////////////////////////////////////////////////////////
// Filename:      VectorAndPoint.h
// Description:   contains definitions for 2D and 3D vectors and points
//
// Create:        13.09.23
////////////////////////////////////////////////////////////////////
#pragma once


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
			float w = 0.0f;
		}; // struct
	}; // union
} VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;



