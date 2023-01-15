/*Ex. 20: Scrieti programul care determina liniile unei matrici cu elemente in
ordine crescatoare.*/

#include <iostream>
using namespace std;

void citireMatrice(int mat[][20], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> mat[i][j];
		}
	}
}

void afisareMatrice(int mat[][20], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << "\n";
	}	
}

void afisareVector(int p[], int m) {
	for (int i = 0; i < m; i++) {
		cout << "p[" << i << "]= " << p[i] << "\n";
	}
}

int VerifSortLinie(int p[], int n) {
	int b = 1;
	for (int i = 0; i < n-1; i++) {

		if (p[i] >= p[i + 1]) {
			b = 0;
			break;
		}
	}
	return b;
}

void VerifLiniiMatriceStatic(int m1[][20], int m, int n, int r1[],int *dim_r1) {
	*dim_r1 = 0;
	for (int i = 0; i < m; i++) {
		if (VerifSortLinie(m1[i], n) == 1) {
			r1[*dim_r1] = i;
			(*dim_r1)++;
		}
	}
}

int main() {
	int m, n, mat[20][20], rez[20], dim_rez;

	cout << "Introduceti numarul de linii: ";
	cin >> m;

	cout << "Introduceti numarul de coloane: ";
	cin >> n;

	cout << "\nIntroduceti elementele matricei: \n";
	citireMatrice(mat, m, n);

	cout << "\nMatricea introdusa:\n";
	afisareMatrice(mat, m, n);

	VerifLiniiMatriceStatic(mat, m, n, rez,&dim_rez);
	cout << "\nLiniile care au elementele in ordine crescatoare: \n";
	afisareVector(rez, dim_rez);
}