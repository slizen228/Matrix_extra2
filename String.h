#pragma once
#include <stdio.h>
#include <iostream>
#include "Matrix.h"
using namespace std;
class String {
public:
	int m_number;
	int** m_str;
	int m_dim;
public:
	String();
	String(int, Matrix&);
	String(const String&);
	String(String&);
	~String();
public:
	int& operator[](int);
	String& operator= (const String&);
	String& operator= (String&&);
};