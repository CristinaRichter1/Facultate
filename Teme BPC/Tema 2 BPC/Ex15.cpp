// 15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int **matrice, i, n, m, j,a;

void main()
{
	cout << "Introduceti dimensiunile:\t";

	cin >> n >> m;
	matrice = new int*[n];
	 
	for (i = 0;i < n;i++)
		matrice[i] = new int[m];

	cout << "Introduceti elementele:\n";
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			cin >> matrice[i][j];

	cout << "Introduceti valoarea de verificat:\t";
	cin >> a;
	
	
	int nr = 0;

	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			if (matrice[i][j] == a) nr++;

	cout << "Valoarea introdusa apare de" << " ";
	cout << nr << " " << "ori";

	for (i = 0;i <n;i++) 
		delete[] matrice[i];


	delete[]matrice;

			
			

			}
    


