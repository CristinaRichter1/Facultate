// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int **matrice, n, i, j, min1, min2;

void main()
{
	cout << "Introduceti dimensiunea:\t";
	cin >> n;
	matrice = new int*[n];
	for (i = 0;i < n;i++) matrice[i] = new int[n];

	cout << "Introduceti elementele:\n";
	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++)
			cin >> matrice[i][j];

	min1 = matrice[0][0];

	for (i = 0;i <n;i++) {
		for (j = i;j < n;j++) {

			if (matrice[i][j] < min1)

				min1 = matrice[i][j];

		}

	}

	cout << "minimul din triunghiul superior diagonalei principale\n" << " " << min1 << "\n";

	min2 = matrice[0][0];

	for (i = 0;i < n;i++) {
		for (j = 0;j < n - i;j++) {
			if (matrice[i][j] < min2)
				min2 = matrice[i][j];
		}
	}

	cout << "minimul din triunghiul superior diagonalei secundare\n" << " " << min2;


	for (i = 0;i < n;i++)
		delete[]matrice[i];
	delete[] matrice;




}


