#include "Mat.h"
#include<algorithm>
#include<iostream>

Mat::Mat()
{
	_rows = 0;
	_cols = 0;
}

Mat::Mat(unsigned m, unsigned n)
{
	_rows = m;
	_cols = n;
	unsigned dim = m * n;
	_dados = new double[dim];
	std::fill_n(_dados, dim, 0.0);
}

Mat::Mat(unsigned m, unsigned n, double* p)
{
	_rows = m;
	_cols = n;
	unsigned dim = m * n;
	_dados = new double[dim];
	memcpy(_dados, p, dim * sizeof(double));
}

Mat::~Mat()
{
	delete[] _dados;
}

Mat::Mat(const Mat& M)
{
	_rows = M._rows;
	_cols = M._cols;
	unsigned dim = _rows * _cols;
	_dados = new double[dim];
	memcpy(_dados, M._dados, dim * sizeof(double));
}

void Mat::show()const
{
	for (unsigned i = 0; i < _rows; i++) {
		for (unsigned j = 0; j < _cols; j++)
			std::cout << *(_dados + i * _cols + j) << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

double& Mat::operator()(unsigned i, unsigned j)
{
	return _dados[i * _cols + j];
}

double Mat::operator()(unsigned i, unsigned j) const
{
	return *(_dados + i * _cols + j);
}

double& Mat::operator()(unsigned i)
{
	return _dados[i * _cols];
}

double Mat::operator()(unsigned i) const
{
	return *(_dados + i * _cols);
}

Mat& Mat::operator=(const Mat& m)
{
	if (this != &m) {
		this->_rows = m._rows;
		_cols = m._cols;
		unsigned dim = _rows * _cols;
		_dados = new double[dim];
		memcpy(_dados, m._dados, dim * sizeof(double));
	}
	return *this;
}


void Mat::permuta_linha(unsigned i, unsigned j)
{

	double temp;
	for (unsigned k = 0; k < _cols; k++)
	{
		temp = this->operator()(i, k);
		this->operator()(i, k) = this->operator()(j, k);
		this->operator()(j, k) = temp;
	}
}

bool Mat::is_eye()
{
	if (_rows == _cols) {
		bool flag = true;
		for (unsigned i = 0; i < _rows; i++)
			for (unsigned j = 0; j < _cols; j++)
				if (i == j) {
					if (this->operator()(i, i) != 1.0)
						flag = false;
				}
				else {
					if (this->operator()(i, j) != 0.0)
						flag = false;
				}
		return flag;
	}
	else
		return false;
}

void Mat::div_row_by(unsigned r, double x)
{
	for (unsigned j = 0; j < _cols; j++)
		this->operator()(r, j) /= x;
}


Mat Mat::eye(unsigned n)
{
	Mat result(n, n);
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < n; j++)
			if (i == j) result(i, j) = 1.0;

	return result;
}

Mat Mat::merge(const Mat& m, const Mat& n)
{
	if (m._rows == n._rows) {
		unsigned colunas = m._cols + n._cols;
		unsigned linhas = m._rows;
		Mat result(linhas, colunas);

		for (unsigned i = 0; i < linhas; i++)
			for (unsigned j = 0; j < colunas; j++) {
				if (j < m._cols)
					result(i, j) = m(i, j);
				else
					result(i, j) = n(i, j - m._cols);
			}

		return result;
	}
	else
		return Mat();
}

std::pair<Mat, Mat> Mat::split(const Mat& m, unsigned col)
{
	std::pair<Mat, Mat> bloco;
	bloco.first = Mat(m._rows, col);
	bloco.second = Mat(m._rows, m._cols - col);
	for (unsigned i = 0; i < m._rows; i++)
		for (unsigned j = 0; j < m._cols; j++) {
			if (j < col)
				bloco.first(i, j) = m(i, j);
			else
				bloco.second(i, j - col) = m(i, j);
		}
	return bloco;
}

Mat Mat::rref(const Mat& m)
{
	Mat result(m);
	int lead = 0;
	int rowCount = m._rows;
	int columnCount = m._cols;

	for (int r = 0; r < rowCount; r++)
	{
		if (columnCount <= lead)
			break;
		int i = r;
		while (result(i, lead) == 0.0)
		{
			i++;
			if (i == rowCount)
			{
				i = r;
				lead++;
				if (lead == columnCount)
					return result;
			}
		}//while

		if (i != r)
			result.permuta_linha(i, r);

		double pivo = result(r, lead);
		result.div_row_by(r, pivo);

		for (unsigned k = 0; k < rowCount; k++)
		{
			if (k != r)
			{
				pivo = -result(k, lead);
				for (unsigned j = 0; j < columnCount; j++) {
					result(k, j) += pivo * result(r, j);
				}
			}
		}
		lead++;
	}//próximo r

	return result;
}

Mat Mat::inversa(const Mat& m)
{
	if (m._rows != m._cols) {
		std::cout << "ERRO::Matriz nao e quadrada!\n";
		m.show();
		abort();
	}
	else {
		Mat idMat = eye(m._rows);
		Mat M = merge(m, idMat);
		M = rref(M);
		std::pair<Mat, Mat> bloco = split(M, m._rows);
		if (bloco.first.is_eye()) {
			return bloco.second;
		}
		else {
			std::cerr << "ERRO::Matriz nao inversivel!!!\n";
			m.show();
			std::cout << "Forma Escada:";
			Mat reduzida = rref(m);
			reduzida.show();
			abort();
		}
	}
}



