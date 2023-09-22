#include <iostream>

#include "VectorAndPoint/VectorAndPoint.h"
#include "Matrix/Matrix.h"
#include "Log/Log.h"

//using namespace ;

int main()
{
	Log log;
	MathLib::VECTOR2D vec2D{ 1.0f, 2.0f };
	MathLib::VECTOR3D vec3D{ 1.0f, 2.0f, 3.0f };
	MathLib::VECTOR4D vec4D{ 1.0f, 2.0f, 3.0f, 1.0f };

	MathLib::MATRIX2X2 m1{ 1.0f, 2.0f, 4.0f, 8.0f };
	MathLib::MATRIX2X2 m2{ 1.0f, 0.0f, 0.0f, 1.0f };
	MathLib::MATRIX2X2 mProd{ 0.0f, 0.0f, 0.0f, 0.0f };

	MathLib::Mat_Mul_2X2(&m1, &m2, &mProd);


	float det = MathLib::Mat_Det_2X2(&m1);
	Log::Debug(LOG_MACRO, "det = " + std::to_string(det));

	return 0;
}