/*Ex. 19: Scrieti programul care calculeaza suma elementelor de sub
diagonala secundara (exclusiv diagonala) dintr-o matrice. Se vor folosi subprograme
pentru citirea, afisare, calcul suma elemente.*/

#include <iostream>
using namespace std;

void citireMatrice(int mat[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> mat[i][j];
		}
	}
}

void afisareMatrice(int mat[][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << "\n";
	}
}

int sumDiagSecMatrice(int mat[][100], int m) {
	int sum = 0;
	for (int i = 1; i < m; i++) {
		for (int j = m - i; j < m; j++) {
			sum = sum + mat[i][j];
		}
	}
	return sum;
}

int main() {
	int m, sum, mat[100][100];

	cout << "Introduceti numarul de linii si de coloane: ";
	cin >> m;

	cout << "\nIntroduceti elementele matricei: \n";
	citireMatrice(mat, m, m);
	

	cout << "\nMatricea introdusa:\n";
	afisareMatrice(mat, m, m);

	sum = sumDiagSecMatrice(mat, m);
	cout << "\nSuma elementelor de sub diagonala secundara este: " << sum << ".\n";
		
}