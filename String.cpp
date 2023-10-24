#include <stdio.h>
#include "String.h"
#include "Matrix.h"
#include <iostream>
using namespace std;
String::String() {
	m_str = nullptr;
	m_number = 0;
	m_dim = 0;
}

String::String(int _number, Matrix& _matrix) {
	m_number = _number;
	m_dim = _matrix.m_dim;
	m_str = new int* [m_dim];
	for (int i = 0;i < _matrix.m_dim;i++) {
		m_str[i] = &(_matrix.m_mas[m_number][i]);
	}
}

String::String(const String& _str) {
	m_number = _str.m_number;
	m_dim = _str.m_dim;
	m_str = new int* [m_dim];
	for (int i = 0; i < m_dim; i++) {
		m_str[i] = _str.m_str[i];
	}
}

String::String(String& _str) {
	m_number = _str.m_number;
	m_dim = _str.m_dim;
	m_str = _str.m_str;
	_str.m_str = nullptr;
}

String::~String() {
	if (m_str != nullptr) {
		delete[] m_str;
	}
}

String& String::operator= (const String& _str) {
	if (m_dim != _str.m_dim) {
		cout << "dimensioins aren't equal 11";
		exit(0);
	}
	if (m_str != nullptr) {
		for (int i = 0; i < m_dim; i++) {
			delete[] m_str[i];
		}
		delete[] m_str;
	}
	m_str = new int* [m_dim];
	for (int i = 0; i < m_dim; i++) {
		m_str[i] = _str.m_str[i];
	}
	return *this;
}

String& String::operator= (String&& _str) {
	if (m_dim != _str.m_dim) {
		cout << "dimensioins aren't equal 11";
		exit(0);
	}
	if (m_str != nullptr) {
		for (int i = 0; i < m_dim; i++) {
			delete[] m_str[i];
		}
		delete[] m_str;
	}
	m_str = _str.m_str;
	_str.m_str = nullptr;
	return *this;
}

int& String::operator[](int _n) {
	return *m_str[_n];
}