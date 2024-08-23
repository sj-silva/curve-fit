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
	

	/**
 * @brief Generates a plot of the desired function and its polynomial approximation.
 *
 * This function creates a plot by loading a Gnuplot script that generates a figure in PNG format.
 * The degree of the polynomial used for the approximation is specified by the parameter `n`.
 * The resulting plot is saved as a PNG file named `result<n>.png`, where `<n>` is replaced with
 * the polynomial degree provided as an argument to the function.
 *
 * The plot covers the interval [-5, 5] and shows both the desired function and its polynomial
 * approximation of degree `n`. The purpose of this function is to visualize the approximation
 * quality of the polynomial for the given degree.
 *
 * @param n The degree of the polynomial used for approximation. This value determines the
 *           complexity of the polynomial and is reflected in the filename of the generated plot.
 */

	void CreateFigure(unsigned n);

}

