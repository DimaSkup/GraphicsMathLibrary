#include <iostream>

#include "VectorAndPoint/VectorAndPoint.h"
#include "Matrix/Matrix.h"
#include "Log/Log.h"
#include "Figures/Figures.h"
#include "Test/Tests.h"

using namespace MathLib;

int main()
{
	Log log;
	Tests test;

	test.Test_Vectors_And_Points();
	test.Test_Matrices();
	test.Test_Figures();
	


	return 0;
}