#include <stdio.h>
#include <conio.h>
void main()
{
	int n, m, i, j, s, max, min, a[100][100];
	printf("Nr de linii= "); scanf_s("%d", &m);
	printf("Nr de coloane= "); scanf_s("%d", &n);
	for (i=0; i<m;i++)
	for (j=0; j<n;j++)
	{
		printf("a[%d][%d]= ", i, j); scanf_s("%d", &a[i][j]);
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf(" %d ", a[i][j]); printf("\n");
	}
	max = a[0][0]; min = a[0][0];
	for (i=0; i<m;i++)
		for (j=0; j<n; j++)
		{
			if (max < a[i][j]) max = a[i][j];
			if (min > a[i][j]) min = a[i][j];
		}
	printf("\n Maximul este: %d ", max);
	printf("\n Minimul este: %d ", min);
	_getch();
}