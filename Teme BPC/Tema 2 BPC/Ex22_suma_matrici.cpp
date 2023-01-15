/*Ex. 22: Scrieti programul care calculeaza suma dintre doua matrice alocate dinamic. Transferul datelor se va face prin 
parametrii.*/

#include <iostream>
using namespace std;

int **alocareMatrice(int m, int n) {
	int **mat;
	mat = new int*[n];
	for (int i = 0; i < n; i++) {
		mat[i]=new int[m];
	}
	return mat;
}

void dezalocareMatrice(int **mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

void citireMatrice(int **mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "mat[" << i << "]["<<j<<"]= ";
			cin >> mat[i][j];
		}
	}
}

void afisareMatrice(int **mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "mat[" << i << "][" << j << "]= " << mat[i][j] << "\n";
		}
	}
}

int **adunMatrice(int **mat1, int **mat2, int m, int n) {
	int **matRez;
	matRez = alocareMatrice(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matRez[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	return matRez;
}


int main(){
	int **mat1, **mat2,**matRezAdun, m,n;
	
	cout << "Introduceti numarul de linii: ";
	cin >> m;

	cout << "\nIntroduceti numarul de coloane: ";
	cin >> n;

	mat1 = alocareMatrice(m, n);
	mat2 = alocareMatrice(m, n);

	cout << "\nIntroduceti elementele primei matrici: \n";
	citireMatrice(mat1, m, n);

	cout << "\nIntroduceti elementele celei de-a doua matrici: \n";
	citireMatrice(mat2, m, n);

	matRezAdun = adunMatrice(mat1, mat2, m, n);
	
	cout << "\nSuma elementelor celor doua matrici: \n";
	afisareMatrice(matRezAdun, m, n);

	dezalocareMatrice(mat1, n);
	dezalocareMatrice(mat2, n);
	dezalocareMatrice(matRezAdun,n);

}