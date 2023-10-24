#pragma once
#include <stdio.h>
#include <iostream>
//#include "Column.h"
//#include "String.h"
using namespace std;
class Column;
class String;
class Matrix {
public:
	int m_dim;
	int** m_mas;
	Column* m_colums;
public:
	Matrix();
	Matrix(int);
	Matrix(int, int*);
	Matrix(const Matrix&);
	Matrix(Matrix&);
	~Matrix();
public:
	void Set(int);
	Matrix& operator= (const Matrix&);
	Matrix& operator= (Matrix&&);
	Matrix operator+(const Matrix&) const;
	Matrix operator- (const Matrix&) const;
	bool operator!=(const Matrix&) const;
	bool operator==(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	friend ostream& operator<<(ostream& _os, const Matrix& _matr) {
		for (int i = 0; i < _matr.m_dim; i++) {
			for (int j = 0; j < _matr.m_dim; j++) {
				_os << _matr.m_mas[i][j] << " ";
			}
			_os << "\n";
		}
		return _os;
	}

	Matrix operator++() const;
	Matrix operator()(int, int) const;
	String operator[] (int);
	Column operator()(int);
};