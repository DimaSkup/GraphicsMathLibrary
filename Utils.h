////////////////////////////////////////////////////////////////////
// Filename:      Utils.h
// Description:   contains definitions of common utils and quantities conversion 
//
// Created:       14.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "MathConstant.h"

// definition of minimum or maximum of two values
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// values swapping
#define SWAP(a, b, t) {t = a; a = b; b = t;}

// some math macroses
#define DEG_TO_RAD(angle)      ((angle) * PI / 180.0f)
#define RAD_TO_ANGLE(radians)  ((radians) / PI * 180.0f)

#define RAND_RANGE(x, y) ((x) + (rand() % ((y) - (x) + 1)))

