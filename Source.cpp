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

	MathLib::MATRIX2X2 mat2x2{ 1.0f, 2.0f, 3.0f, 4.0f };

	VECTOR2D_Print(&vec2D, "vec2D");
	VECTOR3D_Print(&vec3D, "vec3D");
	VECTOR4D_Print(&vec4D, "vec4D");
	Log::Debug(LOG_MACRO, "keke");
	
	Log::Print(LOG_MACRO, (std::string)"PRINT");
	Log::Print(LOG_MACRO, "char PRINT");

	Log::Debug(LOG_MACRO, (std::string)"DEBUG");
	Log::Debug(LOG_MACRO, "char DEBUG");

	Log::Error(LOG_MACRO, (std::string)"ERROR");
	Log::Error(LOG_MACRO, "char ERROR");


	MathLib::Print_Mat_2X2(&mat2x2);

	return 0;
}