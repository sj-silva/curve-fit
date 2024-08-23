#pragma once
#include "Function.h"

namespace integral
{
	double Simpson(Function f, double a, double b, double precisao=1e-4);
};

