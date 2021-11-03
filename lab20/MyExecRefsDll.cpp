#include <iostream>
#include "MathFuncsDll.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	double d1, d2;
	cout << "Диагональ1 = ";
	cin >> d1;
	cout << "Диагональ2 = ";
	cin >> d2;
	cout << "Периметр = " <<
		MathFuncs::MyMathFuncs::Perimetr(d1, d2) << endl;
	cout << "Площадь = " <<
		MathFuncs::MyMathFuncs::Area(d1, d2) << endl;
}
