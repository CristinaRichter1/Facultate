

#include "stdafx.h"
#include <iostream>
using namespace std;


int **matrice1, **matrice2, i, n, j, m, k;

void main()
{

	cout << "Introducdeti dimensiunile:\t";
	cin >> n;
	cin >> m;

	matrice1 = new int*[n];

	for (i = 0;i < n;i++)
		matrice1[i] = new int[m];

	matrice2 = new int*[n];

	for (k = 0;k < n;k++)
		matrice2[k] = new int[m];

	cout << "Introduceti prima matrice:\t";
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			cin >> matrice1[i][j];


	cout << "Introduceti a doua matrice:\t";
	for (k = 0;k < n;k++)
		for (int s = 0;s < m;s++)
			cin >> matrice2[k][s];



	/*	for (i = 0;i < n;i++)
	for (j = 0;j < m;j++)
	cout << matrice[i][j]<<" ";



	*/

	cout << "Matricea rezultata este:";


	for (i = 0;i<n;i++) {

		for (j = 0;j < m;j++) {
			cout << matrice1[i][j] + matrice2[i][j] << " ";
		}
		cout << "\n";

	}


	for (i = 0;i < n;i++)
		delete[] matrice1[i];
	delete[] matrice1;

	for (i = 0;i < n;i++)
		delete[] matrice2[i];
	delete[] matrice2;
}



