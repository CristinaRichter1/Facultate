#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	int n, m, i, j, s, max, min, a[100][100];
	cout << "Introduceti nr linii= "; cin >> m;
	cout << "Introduceti nr coloane= "; cin >> n;
	for (i=0; i<m;i++)
		for (j=0; j<n;j++)
		{
			cout << "a[" << i << "][" << j << "]= "; cin >> a[i][j];
		}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
	max = a[0][0]; min = a[0][0];
	for (i=0; i<m;i++)
		for (j=0; j<n; j++)
		{
			if (max < a[i][j]) max = a[i][j];
			if (min > a[i][j]) min = a[i][j];
		}
	cout << "\nMaximul este: " << max << "\n";
	cout << "Minimul este: " << min << "\n";
	_getch();
}