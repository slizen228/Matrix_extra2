#include <stdio.h>
#include "Column.h"
#include "Matrix.h"
#include <iostream>
using namespace std;
Column::Column() {
	m_col = nullptr;
	m_number = 0;
	m_dim = 0;
}

Column::Column(int _number, Matrix& _matrix) {
	m_number = _number;
	m_dim = _matrix.m_dim;
	m_col = new int*[m_dim];
	for (int i = 0;i < _matrix.m_dim;i++) {
		m_col[i] = &(_matrix.m_mas[i][m_number]);
	}
}

Column::Column(const Column& _col) {
	if (m_dim != _col.m_dim) {
		cout << "dimensioins aren't equal 22";
		exit(0);
	}
	m_number = _col.m_number;
	m_col = new int* [m_dim];
	for (int i = 0; i < m_dim; i++) {	
		m_col[i] = _col.m_col[i];
	}
}

Column::Column(Column& _col) {
	m_number = _col.m_number;
	m_dim = _col.m_dim;
	m_col = _col.m_col;
	_col.m_col = nullptr;
}

Column::~Column() {
	if (m_col != nullptr) {
		delete[] m_col;
	}
}

Column& Column::operator= (const Column& _col) {
	if (m_dim != _col.m_dim) {
		cout << "dimensioins aren't equal 11";
		exit(0);
	}
	if (m_col != nullptr) {
		for (int i = 0; i < m_dim; i++) {
			delete[] m_col[i];
		}
		delete[] m_col;
	}
	m_col = new int* [m_dim];
	for (int i = 0; i < m_dim; i++) {
		m_col[i] = _col.m_col[i];
	}
	return *this;
}

Column& Column::operator= (Column&& _col) {
	if (m_dim != _col.m_dim) {
		cout << "dimensioins aren't equal 11";
		exit(0);
	}
	if (m_col != nullptr) {
		for (int i = 0; i < m_dim; i++) {
			delete[] m_col[i];
		}
		delete[] m_col;
	}
	m_col = _col.m_col;
	_col.m_col = nullptr;
	return *this;
}

int& Column::operator[](int _n){
	return *(m_col[_n]);
}

