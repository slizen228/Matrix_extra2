// Matrix_extra.cpp: определяет точку входа для приложения.
//



// 
// Created by Stanislav Chayka
//

#include <stdio.h>
#include "Matrix.h"
#include <iostream>
#include "Column.h"
#include "String.h"
using namespace std;
int main()
{
	int n, k;
	int* mas;
	cin >> n;
	Matrix a, b, c, d, result;
	cin >> k;
	mas = new int[n];
	for (int i = 0; i < n; i++) {
		mas[i] = k;
	}
	Matrix K(n, mas);
	a.Set(n);
	b.Set(n);
	c.Set(n);
	d.Set(n);
	result = (a + (b * (++c)) + K) * (++d);
	cout << result << endl;
	cout << a << endl;
	a(1)[0] = 12;
	cout << a << endl;
	a[1][1];
	a[1][1] = 12;
	cout << a << endl;
	delete[] mas;
	return 0;
}
