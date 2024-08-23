#pragma once
#include<iostream>

class Mat
{
private:
	unsigned int _rows;
	unsigned int _cols;
	double* _dados = nullptr;


public:

	// -- Construtor e Destrutor
	Mat();
	Mat(unsigned m, unsigned n);
	Mat(unsigned m, unsigned n, double* p);
	~Mat();

	// -- Construtor Cópia
	Mat(const Mat& m);

	// -- Métodos --
	void show()const;
	inline unsigned rows() { return _rows; }
	inline unsigned cols() { return _cols; }

	// -- Operadores --
	double& operator()(unsigned i, unsigned j);
	double operator()(unsigned i, unsigned j)const;

	double& operator()(unsigned i);
	double operator()(unsigned i)const;

	Mat& operator=(const Mat& m);


	// -- Static Functions --
	static Mat eye(unsigned n);
	static Mat merge(const Mat& m, const Mat& n);
	static std::pair<Mat, Mat> split(const Mat& m, unsigned col);
	static Mat rref(const Mat& m);
	static Mat inversa(const Mat& m);



private:
	void permuta_linha(unsigned i, unsigned j);
	void div_row_by(unsigned r, double x);
	bool is_eye();

};

