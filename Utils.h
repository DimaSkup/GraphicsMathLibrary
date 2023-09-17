////////////////////////////////////////////////////////////////////
// Filename:      Utils.h
// Description:   contains definitions of common utils and quantities conversion 
//
// Created:       14.09.23
////////////////////////////////////////////////////////////////////
#pragma once

#include "MathConstant.h"

// lookup tables for calculating trigonometric functions
extern float cos_look[361]{ 0.0f };
extern float sin_look[361]{ 0.0f };

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





//////////////////////////////////
//    FUNCTIONS IMPLEMENTATION
//////////////////////////////////


// Function using the sin_look[] lookup table for searching a sinus value.
// Handles negative angle values. For fractional values an interpolation is executed.
//
// As input parameter takes an angle in degrees
float Fast_Sin(float theta)  
{
	// in some cases we can have an angle is above 360 degrees so we use fmodf()
	theta = fmodf(theta, 360);

	// make this angle to be positive :D
	if (theta < 0.0f) theta += 360.0f;

	// calculate integer and fractional part for interpolation
	int theta_int    = (int)theta;
	float theta_frac = theta - theta_int;

	// pay attention to correct handling of 359 degrees angle
	// because we have a 360 degrees in the table
	return (sin_look[theta_int] + 
		theta_frac*
		(sin_look[theta_int + 1] - sin_look[theta_int]));

} // end Fast_Sin

////////////////////////////////////////////////////////////////////

// Function using the cos_look[] lookup table for searching a cosinus value.
// Handles negative angle values. For fractional values an interpolation is executed.
//
// As input parameter takes an angle in degrees
float Fast_Cos(float theta)
{
	// convert angle to 0-359
	theta = fmodf(theta, 360);

	// make angle positive
	theta += (theta < 0) ? 360.0f : 0.0f;

	// calculate integer and fractional part for interpolation
	int theta_int    = (int)theta;
	float theta_frac = theta - theta_int;

	// now compute the value of cos(angle) using the lookup table
	// and interpolating the fractional part, note that if theta_int
	// is equat to 359 then theta_int+1 = 360, but this is fine since
	// the table was made with the entries 0-360 inclusive
	return (cos_look[theta_int] +
		theta_frac * (cos_look[theta_int + 1] - cos_look[theta_int]));

} // end Fast_Cos

////////////////////////////////////////////////////////////////////




