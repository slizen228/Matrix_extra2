#include <stdio.h>
#include "Matrix.h"
#include <iostream>
#include "Column.h"
#include "String.h"
using namespace std;
Matrix::Matrix() {
	m_mas = nullptr;
	m_dim = 0;
}

Matrix::Matrix(int _n) {
	m_dim = _n;
	m_mas = new int* [_n];
	for (int i = 0; i < _n; i++) {
		m_mas[i] = new int[_n];
	}
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _n; j++) {
			if (i != j) {
				m_mas[i][j] = 0;
			}
			else {
				m_mas[i][j] = 1;
			}
		}
	}
}

Matrix::Matrix(int _n, int* _arr) {
	m_dim = _n;
	m_mas = new int* [_n];
	for (int i = 0; i < _n; i++) {
		m_mas[i] = new int[_n];
	}
	for (int i = 0; i < _n; i++) {
		for (int j = 0; j < _n; j++) {
			if (i != j) {
				m_mas[i][j] = 0;
			}
			else {
				m_mas[i][j] = _arr[i];
			}
		}
	}
}
//конструктор копирования
Matrix::Matrix(const Matrix& _matr) {
	m_dim = _matr.m_dim;
	m_mas = new int* [m_dim];
	for (int i = 0; i < m_dim; i++) {
		m_mas[i] = new int[m_dim];
	}
	for (int i = 0; i < m_dim; i++) {
		for (int j = 0; j < m_dim; j++) {
			m_mas[i][j] = _matr.m_mas[i][j];
		}
	}
}
//конструктор перемещения
Matrix::Matrix(Matrix& _matr) {
	m_dim = _matr.m_dim;
	m_mas = (_matr.m_mas);
	_matr.m_mas = nullptr;
}

Matrix::~Matrix() {
	if (m_mas != nullptr) {
		for (int i = 0; i < m_dim; i++) {
			delete[] m_mas[i];
		}
		delete[] m_mas;
	}
}
// метод заполнения матрицы с клавиатуры
void Matrix::Set(int _n) {
	if (m_mas) {
		for (int i = 0; i < m_dim; i++) {
			if (m_mas[i]) {
				delete[] m_mas[i];
			}
		}
		delete[] m_mas;
	}
	m_dim = _n;
	m_mas = new int* [m_dim];
	for (int i = 0; i < m_dim; i++) {
		m_mas[i] = new int[m_dim];
	}
	for (int i = 0; i < m_dim; i++) {
		for (int j = 0; j < m_dim; j++) {
			cin >> _n;
			m_mas[i][j] = _n;
		}
	}
}

Matrix& Matrix::operator= (const Matrix& _matr) {
	if(*this!=_matr){
		for (int i = 0; i < m_dim; i++) {
			delete[] m_mas[i];
		}
		delete[] m_mas;
		m_dim = _matr.m_dim;
		m_mas = new int* [m_dim];
		for (int i = 0; i < m_dim; i++) {
			m_mas[i] = new int[m_dim];
		}
		for (int i = 0; i < m_dim; i++) {
			for (int j = 0; j < m_dim; j++) {
				m_mas[i][j] = _matr.m_mas[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator= (Matrix&& _matr) {
	if(*this!=_matr){
		for (int i = 0; i < m_dim; i++) {
			delete[] m_mas[i];
		}
		delete[] m_mas;
		m_dim = _matr.m_dim;
		m_mas = _matr.m_mas;
		_matr.m_mas = nullptr;
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& _matr) const {
	if (m_dim == _matr.m_dim) {
		Matrix _newMatr(_matr);
		for (int i = 0; i < m_dim; i++) {
			for (int j = 0; j < m_dim; j++) {
				_newMatr.m_mas[i][j] += m_mas[i][j];
			}
		}
		return _newMatr;
	}
	else {
		cout << "+";
		cout << "dimensions are not equal";
		exit(0);
	}
}
//транспонирование
Matrix Matrix::operator++() const {
	Matrix _newMatr(*this);
	int _p;
	for (int i = 0; i < m_dim; i++) {
		for (int j = i; j < m_dim; j++) {
			_p = _newMatr.m_mas[i][j];
			_newMatr.m_mas[i][j] = _newMatr.m_mas[j][i];
			_newMatr.m_mas[j][i] = _p;
		}
	}
	return _newMatr;
}

Matrix Matrix::operator()(int _col, int _str) const {
	Matrix _newMatr(m_dim - 1);
	for (int i = 0; i < _str; i++) {
		for (int j = 0; j < _col; j++) {
			_newMatr.m_mas[i][j] = m_mas[i][j];
		}
	}
	for (int i = _str + 1; i < m_dim; i++) {
		for (int j = _col + 1; j < m_dim; j++) {
			_newMatr.m_mas[i - 1][i - 1] = m_mas[i][j];
		}
	}
	return _newMatr;
}

Matrix Matrix::operator-(const Matrix& _matr) const {
	if (m_dim == _matr.m_dim) {
		Matrix _newMatr(*this);
		for (int i = 0; i < m_dim; i++) {
			for (int j = 0; j < m_dim; j++) {
				_newMatr.m_mas[i][j] -= _matr.m_mas[i][j];
			}
		}
		return _newMatr;
	}
	else {
		cout << "-";
		cout << "dimensions are not equal";
		exit(0);
	}
}

Matrix Matrix::operator*(const Matrix& _matr) const {
	if (m_dim == _matr.m_dim) {
		int* _inputMas = new int[m_dim];
		for (int i = 0; i < m_dim; i++) {
			_inputMas[i] = 0;
		}
		Matrix _newMatr(m_dim, _inputMas);
		delete[] _inputMas;
		for (int i = 0; i < m_dim; i++) {
			for (int j = 0; j < m_dim; j++) {
				_newMatr.m_mas[i][j];
				for (int k = 0; k < m_dim; k++) {
					_newMatr.m_mas[i][j] += m_mas[i][k] * _matr.m_mas[k][j];
				}
			}
		}
		return _newMatr;
	}
	else {
		cout << "*";
		cout << "dimensions are not equal";
		exit(0);
	}
}

bool Matrix::operator!=(const Matrix& _matr) const {
	if (m_dim == _matr.m_dim) {
		for (int i = 0; i < m_dim; i++) {
			for (int j = 0; j < m_dim; j++) {
				if (m_mas[i][j] == _matr.m_mas[i][j]) {
					continue;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
	else {
		return true;
	}
}

bool Matrix::operator==(const Matrix& _matr) const {
	if (m_dim == _matr.m_dim) {
		for (int i = 0; i < m_dim; i++) {
			for (int j = 0; j < m_dim; j++) {
				if (m_mas[i][j] == _matr.m_mas[i][j]) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}
Column Matrix::operator()(int _n){
	Column _col(_n, *this);
	return _col;
}
String Matrix::operator[](int _n){
	String _str(_n, *this);
	return _str;
}