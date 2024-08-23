#pragma once
#include"Function.h"
#include<string>
#include<glm/glm.hpp>
#include<vector>

namespace plot
{
/**
 * @brief Generates data points for a given function over a specified interval.
 *
 * This function evaluates the given function `f` over the interval
 * [xmin, xmax] and generates `n` evenly spaced (x, y) coordinates. The results
 * are stored in a file specified by `filePath`.
 *
 * @param f: The function to be evaluated, defined over the interval [xmin, xmax].
 * @param xmin: The minimum value of the interval.
 * @param xmax: The maximum value of the interval.
 * @param filePath: The path to the file where the generated (x, y) data points will be stored.
 * @param n: The number of data points to generate (default is 201).
 */
	void CreateData(Function f, 
					double xmin, double xmax,
		            std::string filePath, 
					int n = 201);
	
	void CreateFigure(unsigned n);
}

