#include "curve_fit.h"
#include "Mat.h"
#include "integral.h"

namespace fit {
	
	namespace {
		
		//F(x)= f(x) * x^n
		double prod_tipo_1(Function f, unsigned n, double x) {
			return f(x) * pow(x, n);// f(x)*x^n
		}

		//G(x) = x^m * x^n
		double prod_tipo_2(int m, unsigned n, double x) {
			return (pow(x, m) * pow(x, n));
		}

	}
	
	std::vector<double> CreateCoefficients(Function f, int n, double xmin, double xmax)
	{
		n++;
		Mat A(n, n);
		Mat b(n, 1);
		unsigned rows = 0;
		unsigned cols = 0;
		
		//F(x)= f(x) * x^n
		auto F = std::bind(&prod_tipo_1, f, std::ref(rows), std::placeholders::_1);
		
		//G(x) = x^m * x^n
		auto G = std::bind(&prod_tipo_2, std::ref(rows), std::ref(cols), std::placeholders::_1);

		for (; rows < n; rows++) {
			b(rows, 0) = integral::Simpson(F,xmin,xmax);
			for (; cols < n; cols++) {
				A(rows, cols) = integral::Simpson(G, xmin, xmax);
			}
			cols = 0;
		}

		Mat M = Mat::merge(A, b);
		M = Mat::rref(M);
		unsigned last_col = M.cols() - 1;
		
		std::vector<double> result;
		for (unsigned i = 0; i < M.rows(); i++) {
			result.push_back(M(i, last_col));
		}
		

		return result;
	}
}