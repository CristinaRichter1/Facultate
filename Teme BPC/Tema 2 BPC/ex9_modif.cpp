#include <iostream>
#include <conio.h>
using namespace std;

	int main() 
	{
		int *p, n;

		cout << "Introduceti dimensiunea vectorului: ";
		cin >> n;

		p = new int[n];
		
		cout << "Introduceti elementele vectorului: \n";

		for (int i = 0; i < n; i++) {
			cout << "p[" << i << "]= ";
			cin >> p[i];
		}

		cout << "\nVectorul este: \n";

		for (int i = 0; i < n; i++) {
			cout << "p[" << i << "]=" << p[i] << "\n";
		}

		delete[] p;
		//getch();
	}