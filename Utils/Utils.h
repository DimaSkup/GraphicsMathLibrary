////////////////////////////////////////////////////////////////////
// Filename:      Utils.h
// Description:   contains definitions of common utils and quantities conversion 
//
// Created:       14.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "../MathConstant.h"


namespace MathLib
{

// lookup tables for calculating trigonometric functions
_declspec(selectany) float cos_look[361]{ 0.0f };
_declspec(selectany) float sin_look[361]{ 0.0f };

// definition of minimum or maximum of two values
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// values swapping
#define SWAP(a, b, t) {t = a; a = b; b = t;}

// some math macroses
#define DEG_TO_RAD(angle)      ((angle) * PI / 180.0f)
#define RAD_TO_ANGLE(radians)  ((radians) / PI * 180.0f)

#define RAND_RANGE(x, y) ((x) + (rand() % ((y) - (x) + 1)))


//////////////////////////////////
//    FUNCTIONS PROTOTYPES
//////////////////////////////////

// trigonometric functions
float Fast_Sin(float theta);
float Fast_Cos(float theta);


// functions for computing the distance from the origin to some 2D/3D point
int Fast_Distance_2D(const int x, const int y);
float Fast_Distance_3D(const float fx, const float fy, const float fz);




}
