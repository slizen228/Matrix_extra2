#pragma once
#include <stdio.h>
#include <iostream>
#include "Matrix.h"
using namespace std;
class Column {
public:
	int m_number;
	int** m_col;
	int m_dim;
public:
	Column();
	Column(int, Matrix&);
	Column(const Column&);
	Column(Column&);
	~Column();
public:
	int& operator[](int);
	Column& operator= (const Column&);
	Column& operator= (Column&&);
};
