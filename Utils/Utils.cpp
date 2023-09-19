////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      Utils.cpp
// Description:   contains implementation of common utils and quantities conversion 
//
// Created:       19.09.23
////////////////////////////////////////////////////////////////////////////////////////////
#include "Utils.h"


namespace MathLib
{
	

////////////////////////////////////////////////////////////////////////////////////////////
//                              UTILS IMPLEMENTATION
////////////////////////////////////////////////////////////////////////////////////////////


float Fast_Sin(float theta)
{
	// Function using the sin_look[] lookup table for searching a sinus value.
	// Handles negative angle values. For fractional values an interpolation is executed.
	//
	// As input parameter takes an angle in degrees

	// in some cases we can have an angle is above 360 degrees so we use fmodf()
	theta = fmodf(theta, 360);

	// make this angle to be positive :D
	if (theta < 0.0f) theta += 360.0f;

	// calculate integer and fractional part for interpolation
	int theta_int = (int)theta;
	float theta_frac = theta - theta_int;

	// pay attention to correct handling of 359 degrees angle
	// because we have a 360 degrees in the table
	return (sin_look[theta_int] +
		theta_frac*
		(sin_look[theta_int + 1] - sin_look[theta_int]));

} // end Fast_Sin

///////////////////////////////////////////////////////////////

float Fast_Cos(float theta)
{
	// Function using the cos_look[] lookup table for searching a cosinus value.
	// Handles negative angle values. For fractional values an interpolation is executed.
	//
	// As input parameter takes an angle in degrees

	// convert angle to 0-359
	theta = fmodf(theta, 360);

	// make angle positive
	theta += (theta < 0) ? 360.0f : 0.0f;

	// calculate integer and fractional part for interpolation
	int theta_int = (int)theta;
	float theta_frac = theta - theta_int;

	// now compute the value of cos(angle) using the lookup table
	// and interpolating the fractional part, note that if theta_int
	// is equat to 359 then theta_int+1 = 360, but this is fine since
	// the table was made with the entries 0-360 inclusive
	return (cos_look[theta_int] +
		theta_frac * (cos_look[theta_int + 1] - cos_look[theta_int]));

} // end Fast_Cos

///////////////////////////////////////////////////////////////

int Fast_Distance_2D(int x, int y)
{
	// this function computes the distance from (0;0) to (x;y) with 3.5% error

	// first compute the absolute value of x and y
	x = abs(x);
	y = abs(y);

	// compute the minimum of x,y
	int mn = MIN(x, y);

	//return the distance
	return (x + y - (mn >> 1) - (mn >> 2) + (mn >> 4));

} // end Fast_Distance_2D

///////////////////////////////////////////////////////////////

float Fast_Distance_3D(const float fx, const float fy, const float fz)
{
	// this function computes the distance from the origin to x,y,z

	int temp = 0;  // uses for swapping
	
	// make sure that input values are all posivite
	int x = static_cast<int>(fabs(fx) * 1024);
	int y = static_cast<int>(fabs(fy) * 1024);
	int z = static_cast<int>(fabs(fz) * 1024);

	// sort values
	if (y < x) SWAP(x, y, temp);
	if (z < y) SWAP(y, z, temp);
	if (y < x) SWAP(x, y, temp);

	int dist = (z + 11 * (y >> 5) + (x >> 2));

	// compute the distance with 8% error
	return static_cast<float>(dist >> 10);

} // end Fast_Distance_3D


}