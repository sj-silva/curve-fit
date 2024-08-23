#include "plot.h"
#include<string>
#include<fstream>


namespace plot {
	
	namespace {
		
		void loadGnuplotScript(unsigned degree) {

			FILE* pipe = _popen("gnuplot", "w");
			
			std::string nome_arq = "graficos/result" + std::to_string(degree) + ".png";
			std::string destino = "set out '" + nome_arq + "' \n";

			fprintf(pipe, "reset session\n");
			fprintf(pipe, destino.c_str());
			fprintf(pipe, "load 'graficos/plotFuncScript.txt'\n");

			_pclose(pipe);
		}

	}

	void CreateData(Function f, 
					double xmin, double xmax, 
					std::string filePath, 
					int n)
	{
		std::ofstream arq;

		arq.open(filePath.c_str());

		double incr = (xmax - xmin) / (n - 1.0);
		for (double x = xmin; x <= xmax; x = x + incr) {
			double y = f(x);
			arq << x << " " << y << "\n";
		}

		arq.close();

	}

	
	void CreateFigure(unsigned n)
	{
		loadGnuplotScript(n);	
	}
}