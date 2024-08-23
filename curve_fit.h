#pragma once
#include"Function.h"
#include<vector>

namespace fit{
	std::vector<double> CreateCoefficients(Function f, int n, double a, double b);
}
