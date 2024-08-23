#include "integral.h"
namespace integral {
	
	namespace {
		double calcula_Simpson(Function f, double a, double b) {

			double h = (b - a);
			double c = (a + b) / 2.0;
			double result = h / 6.0 * (f(a) + f(b) + 4 * f(c));

			return result;
		}

	}
	double Simpson(Function f, double a, double b, double precisao)
	{
		double c = (a + b) / 2.0;

		//	std::cout << "Calculando S2[" << a << ", " << b << "] = S1[" << a << "," << c << "] + S1[" << c << ", " << b << "]\n";
		double S1 = calcula_Simpson(f, a, b);
		double S2 = calcula_Simpson(f, a, c) + calcula_Simpson(f, c, b);

		double fator = 15.0;

		if (fabs(S2 - S1) < fator * precisao)
		{
			double Erro2 = (S2 - S1) / fator;
			return S2 + Erro2;
		}

		double L = Simpson(f, a, c, precisao / 2.0);
		double R = Simpson(f, c, b, precisao / 2.0);
		return (L + R);
	}
}