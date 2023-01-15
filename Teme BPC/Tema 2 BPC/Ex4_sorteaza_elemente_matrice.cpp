/*Ex. 4: Sa se scrie programul care sorteaza elementele unei matrici A(mxn)
in ordine crescatoare.*/

#include <iostream>
using namespace std;

int main() {
	int m, n, a[10][10], c[10][10], v[100], aux;

	cout << "Introduceti numarul de linii: ";
	cin >> m;
	cout << "Introduceti numarul de coloane: ";
	cin >> n;

	cout << "\nIntroduceti elementele matricei: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}

	cout << "\nMatricea initiala:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}

	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			v[k] = a[i][j];
			k += 1;
		}
	}

	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}

	/*for (int i = 0; i < k; i++) {
		cout << v[i]; //Afiseaza vectorul cu elementele sortate.
	}*/

	int l = 0;
	while (l < m*n) {
		int i = 0;
		while (i < m) {
			int j = 0;
			while (j < n) {
				c[i][j] = v[l];
				j += 1;
				l += 1;
			}
			i += 1;
		}
	}

	cout << "\nMatricea cu elementele sortate in ordine crescatoare:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c[i][j] << "\t";
		}
		cout << "\n";
	}
}