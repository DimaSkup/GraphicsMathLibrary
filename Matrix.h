////////////////////////////////////////////////////////////////////
// Filename:      Matrix.h
// Description:   contains definitions for matrices structures
//
// Create:        13.09.23
////////////////////////////////////////////////////////////////////
#pragma once


// Matrix 4x4
typedef struct MATRIX4X4_TYPE
{
	union
	{
		float M[4][4];  // array for storing data

		struct
		{
			float M00, M01, M02, M03;
			float M10, M11, M12, M13;
			float M20, M21, M22, M23;
			float M30, M31, M32, M33;
		}; 
	};
} MATRIX4X4, *MATRIX4X4_PTR;


// Matrix 4x3
typedef struct MATRIX4X3_TYPE
{
	union
	{
		float M[4][3];  // array for storing data

		struct
		{
			float M00, M01, M02;
			float M10, M11, M12;
			float M20, M21, M22;
			float M30, M31, M32;
		};
	};
} MATRIX4X3, *MATRIX4X3_PTR;


// Matrix 1x4
typedef struct MATRIX1X4_TYPE
{
	union
	{
		float M[4];     // array for storing data

		struct
		{
			float M00, M01, M02, M03;
		};
	};
} MATRIX1X4, *MATRIX1X4_PTR;


// Matrix 3x3
typedef struct MATRIX3X3_TYPE
{
	union
	{
		float M[3][3];  // array for storing data

		struct
		{
			float M00, M01, M02;
			float M10, M11, M12;
			float M20, M21, M22;
		};
	};
} MATRIX3X3, *MATRIX3X3_PTR;


// Matrix 1x3
typedef struct MATRIX1X3_TYPE
{
	union
	{
		float M[3];     // array for storing data

		struct
		{
			float M00, M01, M02;
		};
	};
} MATRIX1X3, *MATRIX1X3_PTR;


// Matrix 3x2
typedef struct MATRIX3X2_TYPE
{
	union
	{
		float M[3][2];  // array for storing data

		struct
		{
			float M00, M01;
			float M10, M11;
			float M20, M21;
		};
	};
} MATRIX3X2, *MATRIX3X2_PTR;


// Matrix 2x2
typedef struct MATRIX2X2_TYPE
{
	union
	{
		float M[2][2];  // array for storing data

		struct
		{
			float M00, M01;
			float M10, M11;
		};
	};
} MATRIX2X2, *MATRIX2X2_PTR;


// Matrix 1x2
typedef struct MATRIX1X2_TYPE
{
	union
	{
		float M[1][2];  // array for storing data

		struct
		{
			float M00, M01;
		};
	};
} MATRIX1X2, *MATRIX1X2_PTR;