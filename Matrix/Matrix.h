////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Matrix.h
// Description:   contains definitions for matrices structures;
//                and also has functional for work with these matrices
//
// Created:       13.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <string>

#include "../MathConstant.h"
#include "../Log/Log.h"
#include "../VectorAndPoint/VectorAndPoint.h"

namespace MathLib
{
	
////////////////////////////////////////////////////////////////////////////////////////////
//                                DATA STRUCTURES
////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////

// Matrix 1x2
typedef struct MATRIX1X2_TYPE
{
	union
	{
		float M[2];  // array for storing data

		struct
		{
			float M00, M01;
		};
	};
} MATRIX1X2, *MATRIX1X2_PTR;




////////////////////////////////////////////////////////////////////////////////////////////
//                               IDENTITY MATRICES
////////////////////////////////////////////////////////////////////////////////////////////

// identity matrix 4x4
const MATRIX4X4 IMAT_4X4 =
{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};


// identity matrix 4x3
// (used under the assumption that the fourth 
// column is always equal to [0 0 0 1])
const MATRIX4X3 IMAT_4X3 =
{
	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
	0, 0, 0
};


// identity matrix 3x3
const MATRIX3X3 IMAT_3X3 =
{
	1, 0, 0,
	0, 1, 0,
	0, 0, 1
};


// identity matrix 2x2
const MATRIX2X2 IMAT_2X2 =
{
	1, 0,
	0, 1
};



////////////////////////////////////////////////////////////////////////////////////////////
//                           MACROSES / INLINE FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////

// reset of matrices
#define MATRIX_ZERO_2X2(m) { memset((void*)(m), 0, sizeof(MATRIX2X2)); }
#define MATRIX_ZERO_3X3(m) { memset((void*)(m), 0, sizeof(MATRIX3X3)); }
#define MATRIX_ZERO_4X4(m) { memset((void*)(m), 0, sizeof(MATRIX4X4)); }
#define MATRIX_ZERO_4X3(m) { memset((void*)(m), 0, sizeof(MATRIX4X3)); }

// macroses for initialization with identity matrices
#define MAT_IDENTITY_2X2(m) { memcpy((void*)(m), (void*)&IMAT_2X2, sizeof(MATRIX2X2)); }
#define MAT_IDENTITY_3X3(m) { memcpy((void*)(m), (void*)&IMAT_3X3, sizeof(MATRIX3X3)); }
#define MAT_IDENTITY_4X4(m) { memcpy((void*)(m), (void*)&IMAT_4X4, sizeof(MATRIX4X4)); }
#define MAT_IDENTITY_4X3(m) { memcpy((void*)(m), (void*)&IMAT_4X3, sizeof(MATRIX4X3)); }

// copying of matrices
#define MAT_COPY_2X2(pSrcMat, pDestMat) { memcpy((void*)pDestMat, (void*)pSrcMat, sizeof(MATRIX2X2)); }
#define MAT_COPY_3X3(pSrcMat, pDestMat) { memcpy((void*)pDestMat, (void*)pSrcMat, sizeof(MATRIX3X3)); }
#define MAT_COPY_4X4(pSrcMat, pDestMat) { memcpy((void*)pDestMat, (void*)pSrcMat, sizeof(MATRIX4X4)); }
#define MAT_COPY_4X3(pSrcMat, pDestMat) { memcpy((void*)pDestMat, (void*)pSrcMat, sizeof(MATRIX4X3)); }

///////////////////////////////////////////////////////////////

// transpose of matrices
inline void MAT_TRANSPOSE_3X3(MATRIX3X3* pMat)
{
	MATRIX3X3 mt;
	mt.M00 = pMat->M00;  mt.M01 = pMat->M10;  mt.M02 = pMat->M20;
	mt.M10 = pMat->M01;  mt.M11 = pMat->M11;  mt.M12 = pMat->M21;
	mt.M20 = pMat->M02;  mt.M21 = pMat->M12;  mt.M22 = pMat->M22;
	memcpy((void*)pMat, (void*)&mt, sizeof(MATRIX3X3));
}

///////////////////////////////////////////////////////////////

inline void MAT_TRANSPOSE_4X4(MATRIX4X4* pMat)
{
	MATRIX4X4 mt;
	mt.M00 = pMat->M00;  mt.M01 = pMat->M10;  
	mt.M02 = pMat->M20;  mt.M03 = pMat->M30;
	mt.M10 = pMat->M01;  mt.M11 = pMat->M11;
	mt.M12 = pMat->M21;  mt.M13 = pMat->M31;
	mt.M20 = pMat->M02;  mt.M21 = pMat->M12;
	mt.M22 = pMat->M22;  mt.M23 = pMat->M32;
	mt.M30 = pMat->M03;  mt.M31 = pMat->M13;
	mt.M32 = pMat->M22;  mt.M33 = pMat->M33;
	memcpy((void*)pMat, (void*)&mt, sizeof(MATRIX4X4));
}

///////////////////////////////////////////////////////////////

inline void MAT_TRANSPOSE_3X3(const MATRIX3X3* pMatSrc, MATRIX3X3* pMatDst)
{
	pMatDst->M00 = pMatSrc->M00;  pMatDst->M01 = pMatSrc->M10;  pMatDst->M02 = pMatSrc->M20;
	pMatDst->M10 = pMatSrc->M01;  pMatDst->M11 = pMatSrc->M11;  pMatDst->M12 = pMatSrc->M21;
	pMatDst->M20 = pMatSrc->M02;  pMatDst->M21 = pMatSrc->M12;  pMatDst->M22 = pMatSrc->M22;
}

///////////////////////////////////////////////////////////////

inline void MAT_TRANSPOSE_4X4(const MATRIX4X4* pMatSrc, MATRIX4X4* pMatDst)
{
	pMatDst->M00 = pMatSrc->M00;  pMatDst->M01 = pMatSrc->M10;
	pMatDst->M02 = pMatSrc->M20;  pMatDst->M03 = pMatSrc->M30;
	pMatDst->M10 = pMatSrc->M01;  pMatDst->M11 = pMatSrc->M11;
	pMatDst->M12 = pMatSrc->M21;  pMatDst->M13 = pMatSrc->M31;
	pMatDst->M20 = pMatSrc->M02;  pMatDst->M21 = pMatSrc->M12;
	pMatDst->M22 = pMatSrc->M22;  pMatDst->M23 = pMatSrc->M32;
	pMatDst->M30 = pMatSrc->M03;  pMatDst->M31 = pMatSrc->M13;
	pMatDst->M32 = pMatSrc->M22;  pMatDst->M33 = pMatSrc->M33;
}

///////////////////////////////////////////////////////////////

// copumn swapping
inline void MAT_COLUMN_SWAP_2X2(MATRIX2X2* pMat, const int c, const MATRIX1X2* pVec)
{
	pMat->M[0][c] = pVec->M[0];
	pMat->M[1][c] = pVec->M[1];
}

///////////////////////////////////////////////////////////////

inline void MAT_COLUMN_SWAP_3X3(MATRIX3X3* pMat, const int c, const MATRIX1X3* pVec)
{
	pMat->M[0][c] = pVec->M[0];
	pMat->M[1][c] = pVec->M[1];
	pMat->M[2][c] = pVec->M[2];
}

///////////////////////////////////////////////////////////////

inline void MAT_COLUMN_SWAP_4X4(MATRIX4X4* pMat, const int c, const MATRIX1X4* pVec)
{
	pMat->M[0][c] = pVec->M[0];
	pMat->M[1][c] = pVec->M[1];
	pMat->M[2][c] = pVec->M[2];
	pMat->M[3][c] = pVec->M[3];
}


///////////////////////////////////////////////////////////////

inline int Mat_Init_3X2(MATRIX3X2* pMat,
	const float m00, const float m01,
	const float m10, const float m11,
	const float m20, const float m21)
{
	// this function fills a 3x2 matrix with the sent data in row major form
	pMat->M00 = m00; pMat->M10 = m01;
	pMat->M10 = m10; pMat->M11 = m11;
	pMat->M20 = m20; pMat->M21 = m21;

	// return success
	return 1;

} // end Mat_Init_3X2





////////////////////////////////////////////////////////////////////////////////////////////
//                          COMMON FUNCTIONS PROTOTYPES
////////////////////////////////////////////////////////////////////////////////////////////

void Mat_Init_2X2(MATRIX2X2* pMat,    
	const float m00, const float m01,
	const float m10, const float m11);

void Mat_Add_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMSum);  // add matrices
void Mat_Mul_2X2(const MATRIX2X2* pMA, const MATRIX2X2* pMB, MATRIX2X2* pMProd); // mul matrices
int Mat_Inverse_2X2(const MATRIX2X2* pM, MATRIX2X2* pMi);                        // get inverse matrix
void Print_Mat_2X2(const MATRIX2X2* pM, const char* name = "M");
int Mat_Mul_1X2_3X2(const MATRIX1X2* pMatA, const MATRIX3X2* pMatB, MATRIX1X2* pMProd);
float Mat_Det_2X2(const MATRIX2X2* pMat);

///////////////////////////////////////////////////////////////

void Mat_Add_3X3(const MATRIX3X3* pMatA, const MATRIX3X3* pMatB, MATRIX3X3* pMatSum);
void Mat_Mul_VECTOR3D_3X3(const VECTOR3D* pVec, const MATRIX3X3* pMat, VECTOR3D* pVecProd);
void Mat_Mul_1X3_3X3(const MATRIX1X3* pMatA, const MATRIX3X3* pMatB, MATRIX1X3* pMProd);
int Mat_Mul_3X3(const MATRIX3X3* pMatA, const MATRIX3X3* pMatB, MATRIX3X3* pMProd);
void Print_Mat_3X3(const MATRIX3X3* pMat, const char* name = "M");


} // end namespace MathLib