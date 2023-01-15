/*Ex. 20: Scrieti programul care calculeaza produsul vectorial intre doi vectori alocati dinamic. */

#include <iostream>
using namespace std;

int *alocareVector(int m) {
	int *p1 = new int[m];
	return p1;
}

void citireVector(int *p2, int m) {
	for (int i = 0; i < m; i++) {
		cout << "p[" << i << "]= ";
		cin >> p2[i];
	}
}

void afisareVector(int *p, int m) {
	for (int i = 0; i < m; i++) {
		cout << "p[" << i << "]=" << p[i] << "\n";
	}
}

void produsVectorial(int *p1, int *p2, int m, int *rezVectorial) {
	for (int i = 0; i < m; i++) {
		rezVectorial[i]= p1[i]*p2[i];
	}
}

int main() {
	int *p, *q, *rezVectorial_1, n;

	cout << "Introduceti dimensiunea vectorilor: ";
	cin >> n;

	p = alocareVector(n);
	q = alocareVector(n);

	cout << "Introduceti elementele pentru primul vector: \n";
	citireVector(p,n);

	cout << "\nIntroduceti elementele pentru cel de-al doilea vector: \n";
	citireVector(q,n);

	rezVectorial_1 = alocareVector(n);
	produsVectorial(p, q, n, rezVectorial_1);

	cout << "\nProdusul vectorial este: \n";
	afisareVector(rezVectorial_1, n);

	delete[] p;
	delete[] q;
	delete[] rezVectorial_1;
}