#include "MathFuncsDll.h"
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
namespace MathFuncs
{
	double MyMathFuncs::Perimetr(double d1, double d2)
	{
		return 4 * sqrt(pow((d1 / 2), 2) + pow((d2 / 2), 2));
	}
	double MyMathFuncs::Area(double d1, double d2)
	{
		return (1 / 2.) * (d1 * d2);
	}

}