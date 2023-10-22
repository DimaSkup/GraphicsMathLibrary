/////////////////////////////////////////////////////////////////////////////////////////////
// Filename:      TestsVectorAndPoint.cpp
// Description:   contains implementation of functional for testing a work with
//                2D, 3D, and 4D vectors and points
//
// Created:       22.10.23
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Tests.h"

#include <random>




////////////////////////////////////////////////////////////////////////////////////////////
//                                PUBLIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////


void Tests::Test_Vectors_And_Points()
{
	Log::Print("\n\n");
	Log::Print("-------------------- TEST: VECTORS/POINTS ----------------");

	Test_2D_Vectors_Points();
	Test_3D_Vectors_Points();
	Test_4D_Vectors_Points();


} // end Test_Vectors_And_Points

///////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////////////////
//                                PRIVATE FUNCTIONS
////////////////////////////////////////////////////////////////////////////////////////////


void Tests::Test_2D_Vectors_Points()
{
	// this function tests functional for work both with 2D vectors and points 

	Log::Print("-------------------- TEST: 2D VECTORS --------------------\n");

	Test_2D_Vectors_Points_Init_And_Inline_Func();
	Test_2D_Vectors_Math_Operations();



	Log::Print(LOG_MACRO, "test 2D points/vectors: SUCCESS");

	return;
} // end Test_2D_Vectors_Points

///////////////////////////////////////////////////////////

void Tests::Test_3D_Vectors_Points()
{

} // end Test_3D_Vectors_Points

  ///////////////////////////////////////////////////////////

void Tests::Test_4D_Vectors_Points()
{

}

///////////////////////////////////////////////////////////

void Tests::Test_2D_Vectors_Points_Init_And_Inline_Func()
{
	// this function tests initialization of 2D vectors and points,
	// and work with inline functions for these types as well;

	// test INITIALIZATION
	MathLib::VECTOR2D vec1;               // default constructor
	MathLib::VECTOR2D vec2(1.5, 2.5);     // init using separate values
	MathLib::VECTOR2D vec3(vec1, vec2);   // init using two 2D points/vectors
	MathLib::VECTOR2D vec4(vec2);         // init using another 2D vector/point

	// check if values were initialized properly
	assert((vec1.x == 0) && (vec1.y == 0));
	assert((vec2.x == 1.5) && (vec2.y == 2.5));
	assert((vec3.x == 1.5) && (vec3.y == 2.5));
	assert((vec4.x == 1.5) && (vec4.y == 2.5));

	//////////////////////////////////////////////////

	// test INLINE FUNCTIONS for work with 2D vectors
	MathLib::VECTOR2D_ZERO(vec1);
	MathLib::VECTOR2D_INIT_XY(vec2, 100, 100);
	MathLib::VECTOR2D_INIT(vec3, vec2);
	MathLib::VECTOR2D_COPY(vec4, vec3);

	assert((vec1.x == 0) && (vec1.y == 0));
	assert((vec2.x == 100) && (vec2.y == 100));
	assert((vec3.x == 100) && (vec3.y == 100));
	assert((vec4.x == 100) && (vec4.y == 100));

	//////////////////////////////////////////////////

	// test INLINE FUNCTIONS for work with 2D points;
	// NOTE THAT we'll use vectors as points;
	MathLib::POINT2D_ZERO(vec4);
	MathLib::POINT2D_INIT_XY(vec3, 100, 100);
	MathLib::POINT2D_INIT(vec2, vec3);
	MathLib::POINT2D_COPY(vec1, vec2);

	assert((vec4.x == 0) && (vec4.y == 0));
	assert((vec3.x == 100) && (vec3.y == 100));
	assert((vec2.x == 100) && (vec2.y == 100));
	assert((vec1.x == 100) && (vec1.y == 100));

	//////////////////////////////////////////////////

	Log::Print(LOG_MACRO, "test init and inline func: 2D points/vectors: SUCCESS");

	return;

} // end Test_2D_Vectors_Points_Init_And_Inline_Func

///////////////////////////////////////////////////////////

void Tests::Test_2D_Vectors_Math_Operations()
{
	// this function tests math operations with 2D vectors;

	MathLib::VECTOR2D vec1(1, 2);
	MathLib::VECTOR2D vec2(1, 2);

	///////////////////////////////////////////

	// operations of adding
	MathLib::VECTOR2D vecSum1;
	MathLib::VECTOR2D vecSum2;

	MathLib::VECTOR2D_Add(vec1, vec2, vecSum1);
	vecSum2 = MathLib::VECTOR2D_Add(vec1, vec2);

	// check the results
	assert((vecSum1.x == 2) && (vecSum1.y == 4));
	assert((vecSum2.x == 2) && (vecSum2.y == 4));

	///////////////////////////////////////////

	// operations of subtraction

	MathLib::VECTOR2D vecDiff1;
	MathLib::VECTOR2D vecDiff2;

	MathLib::VECTOR2D_Sub(vec1, vec2, vecDiff1);
	vecDiff2 = MathLib::VECTOR2D_Sub(vec1, vec2);

	// check the results
	assert((vecDiff1.x == 0) && (vecDiff1.y == 0));
	assert((vecDiff2.x == 0) && (vecDiff2.y == 0));

	///////////////////////////////////////////

	// operations of scaling
	MathLib::VECTOR2D vecToScale(1, 2);
	MathLib::VECTOR2D vecScaled1;

	MathLib::VECTOR2D_Scale(2, vecToScale, vecScaled1);
	MathLib::VECTOR2D_Scale(2, vecToScale);

	// check the results
	assert((vecScaled1.x == 2) && (vecScaled1.y == 4));
	assert((vecToScale.x == 2) && (vecToScale.y == 4));

	///////////////////////////////////////////
	
	// dot product
	MathLib::VECTOR2D vecX(1, 0);
	MathLib::VECTOR2D vecY(0, 1);
	MathLib::VECTOR2D vecPositiveDot(1, 1);
	MathLib::VECTOR2D vecNegativeDot(-1, -1);
	float dotProduct = -100;

	dotProduct = MathLib::VECTOR2D_Dot(vecX, vecY);
	assert(dotProduct == 0);  // vectors are perpendicular

	dotProduct = MathLib::VECTOR2D_Dot(vecX, vecPositiveDot);
	assert(dotProduct > 0);

	dotProduct = MathLib::VECTOR2D_Dot(vecX, vecNegativeDot);
	assert(dotProduct < 0);

	///////////////////////////////////////////

	// vector length (precise)
	MathLib::VECTOR2D vec_10_10(10, 10);
	float vecLength = -1;

	vecLength = MathLib::VECTOR2D_Length(vec_10_10);
	assert(vecLength == sqrtf(200));

	///////////////////////////////////////////

	// vector length (fast);
	// this computation is very fast but less precise; 
	// it can have in average 3.5% error in precision;

	float fastLength = MathLib::VECTOR2D_Length_Fast(vec_10_10);
	assert(fastLength == 13.0f);

	///////////////////////////////////////////

	// vector normalization
	MathLib::VECTOR2D_INIT_XY(vec1, 3, 4);
	MathLib::VECTOR2D_INIT_XY(vec2, 100, 100);

	MathLib::VECTOR2D_Normalize(vec1);
	MathLib::VECTOR2D_Normalize(vec2);

	// assert that vector's length is 1.0f after its normalization
	assert(MathLib::VECTOR2D_Length(vec1) == 1.0f);
	assert(MathLib::VECTOR2D_Length(vec2) == 1.0f);

	Log::Print(LOG_MACRO, "test math operations: 2D points/vectors: SUCCESS");

	return;

} // end Test_2D_Vectors_Points_Math_Operations
