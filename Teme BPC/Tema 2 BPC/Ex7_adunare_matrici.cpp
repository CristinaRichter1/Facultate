/*Ex.7.  Sa se scrie programul care realizeaza adunarea a doua matrice*/

#include<iostream>

using namespace std;


int main()
{
	int n, m, aMat[10][10], bMat[10][10], cMat[10][10];

	cout << "Introduceti numarul de linii ale matricelor:\n";
	cin >> n;
	cout << "Introduceti numarul de coloane ale matricelor:\n";
	cin >> m;

	if (n > 10 || n < 1 || m > 10 || m < 1)
	{
		cout << "Introduceti matrice de alte dimensiuni";
		return 0;
	}


	//Inserare elementele primei matrice
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
	cout << "\n\n";

	//Inserare elementele celei de-a doua matrice
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "b[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> bMat[i][j];
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "Matricea rezultata:\n";
	//algoritm pentru calculul sumei matricelor
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cMat[i][j] = aMat[i][j] + bMat[i][j];
			cout << cMat[i][j] << "\t";
		}
		cout << "\n";
	}


	return 0;

}