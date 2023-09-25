#include <iostream>

#include "VectorAndPoint/VectorAndPoint.h"
#include "Matrix/Matrix.h"
#include "Log/Log.h"

using namespace MathLib;

int main()
{
	Log log;
	//MathLib::VECTOR2D vec2D{ 1.0f, 2.0f };
	//MathLib::VECTOR3D vec3D{ 1.0f, 2.0f, 3.0f };
	//MathLib::VECTOR4D vec4D{ 1.0f, 2.0f, 3.0f, 1.0f };

	MathLib::MATRIX3X3 m1{ 1,2,3, 4,5,6, 7,8,9 };
	MathLib::MATRIX3X3 m2;
	MAT_IDENTITY_3X3(&m2);
	MathLib::MATRIX3X3 mProd{ 0.0f, 0.0f, 0.0f, 0.0f };

	MathLib::Mat_Mul_3X3(&m1, &m2, &mProd);


	MathLib::Print_Mat_3X3(&mProd);

	return 0;
}