#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector> 

#include"plot.h"
#include"curve_fit.h"

const unsigned DEGREE = 8;

std::vector<double> polyCoeff;

double g(double x) {
	return sin(2.0 * x) * cos(x / 2.0);
}

double polynomial(double x, unsigned degree) {

	double result = 0.0;
	for (int i = 0; i <=degree; i++) {
		result += polyCoeff[i] * pow(x, i);
	}

	return result;
}

int main() {

	 // Setting function path
	std::string basePath = "graphics/";
	std::string funcPath = basePath + "funcData.dat";
	
	// Creating file with function Data
	plot::CreateData(g, -5, 5, funcPath);
	
	// Creating Coefficients
	auto polinomio = std::bind(&polynomial, std::placeholders::_1, std::ref(DEGREE));
	polyCoeff = fit::CreateCoefficients(g, DEGREE, -5, 5);
	std::cout << "Coefficients of the polynomial with degree " << DEGREE<<std::endl<<std::endl;

	// Printig Polynomial Coefficients
	for (int i = 0; i < polyCoeff.size(); i++)
		std::cout <<"a"<<i<<" = "<< polyCoeff[i] << std::endl;

	// Setting polynimial path
	std::string polyPath = basePath + "polyData.dat";

	// Creating file with polynomial Data
	plot::CreateData(polinomio, -5, 5, polyPath);

	// Creating Result Image = graphics/result*.png
	plot::CreateFigure(DEGREE);	
	

	// Show Resul Image
	std::string imagePath = basePath+"/result" + std::to_string(DEGREE) + ".png";
	cv::Mat image = cv::imread(imagePath);
	std::string mainWindow = "Curve Fit - Canonical Base Approximation";
	cv::namedWindow(mainWindow, cv::WINDOW_AUTOSIZE);
	cv::imshow(mainWindow, image);

	// Ending
	cv::waitKey(0);
	cv::destroyWindow(mainWindow);

	
}

