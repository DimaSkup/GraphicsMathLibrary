////////////////////////////////////////////////////////////////////
// Filename:      MathConstant.h
// Description:   contains definitions of different math constants
//
// Created:       14.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "Matrix.h"


// fixed-point numbers in format 16.16 (16 - integer part; 16 - fractional part)
typedef int FIXP16;
typedef int* FIXP16_PTR;


// PI number and related stuff
#define PI       ((float)3.141592654f)
#define PI2      ((float)6.283185307f)
#define PI_DIV_2 ((float)1.570796327f)
#define PI_DIV_4 ((float)0.785398163f)
#define PI_INV   ((float)0.318309886f)  // 1 / PI


// constants which are related to fixed - point numbers
#define FIXP16_SHIFT 16
#define FIXP16_MAG   65536
#define FIXP16_DP_MASK 0x0000FFFF
#define FIXP16_WP_MASK 0xFFFF0000
#define FIXP16_ROUND_UP 0x00008000


// definition of small numbers
#define EPSILON_E4 (float)(1E-4)
#define EPSILON_E5 (float)(1E-5)
#define EPSILON_E6 (float)(1E-6)


// values which define line segments intersection
#define PARAM_LINE_NO_INTERSECT 0
#define PARAM_LINE_INTERSECT_IN_SEGMENT 1
#define PARAM_LINE_INTERSECT_OUT_SEGMENT 2
#define PARAM_LINE_INTERSECT_EVERYWHERE 3




//////////////////////////////////
//
//      IDENTITY MATRICES
//
//////////////////////////////////

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
