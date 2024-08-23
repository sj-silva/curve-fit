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

	std::string basePath = "graphics/";
	std::string funcPath = basePath + "funcData.dat";
	std::string polyPath = basePath + "polyData.dat";
	plot::CreateData(g, -5, 5, funcPath);
	
	
	auto polinomio = std::bind(&polynomial, std::placeholders::_1, std::ref(DEGREE));
	polyCoeff = fit::CreateCoefficients(g, DEGREE, -5, 5);
	std::cout << "Coefficients of the polynomial with degree " << DEGREE<<std::endl<<std::endl;

	for (int i = 0; i < polyCoeff.size(); i++)
		std::cout <<"a"<<i<<" = "<< polyCoeff[i] << std::endl;

	plot::CreateData(polinomio, -5, 5, polyPath);
	plot::CreateFigure(DEGREE);	
	/*
	cv::Size frame_size(640, 480);
	int frames_per_second = 4;
	cv::VideoWriter video("video/curve_animation.mp4", cv::VideoWriter::fourcc('D', 'I', 'V', 'X'),
		frames_per_second, frame_size, true);

	for (unsigned n = 1; n <= DEGREE; n=n+2) {
		std::string graphicImage = basePath+"result" + std::to_string(n) + ".png";
		cv::Mat frame = cv::imread(graphicImage);
		video.write(frame);
		cv::waitKey(25);
	}

	video.release();

	*/
	std::string imagePath = basePath+"/result" + std::to_string(DEGREE) + ".png";
	cv::Mat image = cv::imread(imagePath);

	std::string mainWindow = "Curve Fit - Canonical Base Approximation";
	cv::namedWindow(mainWindow, cv::WINDOW_AUTOSIZE);
	cv::imshow(mainWindow, image);

	cv::waitKey(0);
	cv::destroyWindow(mainWindow);

	
}

