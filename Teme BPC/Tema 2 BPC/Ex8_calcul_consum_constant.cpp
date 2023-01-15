/*
Ex 8.  Fie o matrice de dimensiuni mxn, reprezentand consumurile 
de energie pentru fabricarea a m produse intr-o perioada de n zile. 
Sa se scrie programul care afiseaza produsele care au inregistrat 
consumuri constante pe intreaga perioada.*/

#include<iostream>

using namespace std;


int main()
{
	int n, m, aMat[10][10];

	cout << "Introduceti numarul de linii ale matricelor:\n";
	cin >> n;
	cout << "Introduceti numarul de coloane ale matricelor:\n";
	cin >> m;

	if (n > 10 || n < 1 || m > 10 || m < 1)
	{
		cout << "Introduceti matrici de alte dimensiuni";
		return 0;
	}


	//Inserare elementele primei matrici
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> aMat[i][j];
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n\nProdusele cu consumuri constante sunt:\n";

	//Algoritm pentru verificare consum energie constant (elementele de pe linie trebuie sa fie egale)
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		int standard = aMat[i][0];
		for (int j = 1; j < m; j++)
		{
			if (aMat[i][j] != standard)
				flag = 1;
		}
		if (flag == 0)
			cout << i + 1 << " ";
	}
	cout << "\n\n";


	return 0;
}