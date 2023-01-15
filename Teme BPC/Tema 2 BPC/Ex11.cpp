// 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int *vector1, *vector2, n, i, j, *vector3;

void main()
{
	cout << "Introduceti dimensiunea vectorilor:";
	cin >> n;

	vector1 = new int[n];
	vector2 = new int[n];
	vector3 = new int[n];

	cout << "Introduceti primul vector\t";
	for (i = 0;i < n;i++)
		cin >> vector1[i];

	cout << "Introduceti al doilea vector\t";
	for (i = 0;i < n;i++)
		cin >> vector2[i];

	for (i = 0;i < n;i++)
		vector3[i] = vector1[i] * vector2[i];


	cout << "Produsul vectorial este:\n";
	for (i = 0;i < n;i++)
		cout << vector3[i] << " ";

	delete[]vector1;
	delete[]vector2;
	delete[]vector3;
}

