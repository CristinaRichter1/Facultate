/*Ex. 3: Sa se scrie programul care realizeaza determinarea pozitiei primei aparitii
a unei valori date dintr-o matrice dreptunghiulara A(mxn).*/

#include <iostream>
using namespace std;

int main() {
	int m, n, val, pozl, pozc, a[100][100];

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

	cout << "\nIntroduceti valoarea cautata: ";
	cin >> val;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}

	int gasit = 0;
	int i = 0;
	while (i < m && !gasit) {
		int j = 0;
		while (j < n && !gasit) {
			if (a[i][j] == val) {
				gasit = 1;
				pozl = i;
				pozc = j;
			}
			j += 1;
		}
		i += 1;
	}

	if (gasit) {
		cout << "\nValoarea cautata se afla pe linia " << pozl << " si coloana " << pozc <<".\n";
	}
	else {
		cout << "\nValoarea cautata nu a fost gasita in matrice.\n";
	}
}