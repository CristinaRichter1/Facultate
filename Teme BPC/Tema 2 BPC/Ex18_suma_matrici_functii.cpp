/*Ex. 18. - Scrieti programul care realizeaza adunarea a doua matrice alocate static folosind subprograme pentru citire, afisare, calcul suma matrice.*/



#include<iostream>

using namespace std;

void citire_matrice(int[30][30], int, int);
void calcul_suma_matrici(int aMat[][30], int bMat[][30], int cMat[][30], int linii, int coloane);
void afisare_matrice(int aMat[][30], int linii, int coloane);

int main()
{
	int n, m, matA[30][30], matB[30][30], matC[30][30];

	cout << "Introduceti numarul de linii ale matricelor:\n";
	cin >> n;
	cout << "Introduceti numarul de coloane ale matricelor:\n";
	cin >> m;


	cout << "Introduceti elementele primei matrici:\n";
	citire_matrice(matA, n, m);

	cout << "Introduceti elementele celei de-a doua matrici:\n";
	citire_matrice(matB, n, m);

	calcul_suma_matrici(matA, matB, matC, n, m);

	cout << "Matricea rezultata in urma adunarii:\n\n";
	afisare_matrice(matC, n, m);

	return 0;
}


void citire_matrice(int matrice[][30], int linii, int coloane)
{
	for (int i = 0; i < linii; i++)
	{
		for (int j = 0; j < coloane; j++)
		{
			cout << "X[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> matrice[i][j];
			cout << "\n";
		}
	}
	cout << "\n\n";
}


void afisare_matrice(int aMat[][30], int linii, int coloane)
{


	for (int i = 0; i < linii; i++)
	{
		for (int j = 0; j < coloane; j++)
			cout << aMat[i][j] << "\t";
		cout << "\n\n";
	}
}

void calcul_suma_matrici(int aMat[][30], int bMat[][30], int cMat[][30], int linii, int coloane)
{
	for (int i = 0; i < linii; i++)
	for (int j = 0; j < coloane; j++)
		cMat[i][j] = aMat[i][j] + bMat[i][j];
}