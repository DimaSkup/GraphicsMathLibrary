#include <iostream>

#include "VectorAndPoint/VectorAndPoint.h"
#include "Log/Log.h"

//using namespace ;

int main()
{
	Log log;
	MathLib::VECTOR4D vec{ 1.0f, 2.0f, 3.0f, 1.0f };

	
	Log::Print(__FUNCTION__, __LINE__, (std::string)"HELLO_STRING");
	//Log::Print(__FUNCTION__, __LINE__, "hello");

	return 0;
}