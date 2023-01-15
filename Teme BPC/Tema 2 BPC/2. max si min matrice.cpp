/*#include <stdio.h>
#include <conio.h> */

#include <iostream>
using namespace std;

void main()
{
	int n, m, i, j, s, max, min, a[100][100];
	//printf("Nr de linii= "); scanf_s("%d", &m);
	cout << "Introduceti nr linii= "; cin >> m;
	//printf("Nr de coloane= "); scanf_s("%d", &n);
	cout << "Introduceti nr coloane= "; cin >> n;
	for (i=0; i<m;i++)
		for (j=0; j<n;j++)
		{
			//printf("a[%d][%d]= ", i, j); scanf_s("%d", &a[i][j]);
			cout << "a[" << i << "][" << j << "]= "; cin >> a[i][j];
		}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			//printf(" %d ", a[i][j]); printf("\n");
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
	//printf("\n Maximul este: %d ", max);
	cout << "\nMaximul este: " << max << "\n";
	//printf("\n Minimul este: %d ", min);
	cout << "Minimul este: " << min << "\n";
	//_getch();
}