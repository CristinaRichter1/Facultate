#include <stdio.h>
#include <conio.h>
void main()
{
	int n, m, i, j, s, a[100][100];
		printf("Introduceti nr linii= "); scanf("%d", &m);
	printf("Introduceti nr coloane= "); scanf("%d", &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			printf("a[%d][%d]= ", i, j); scanf("%d", &a[i][j]);
		}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf(" %d ", a[i][j]);
		printf("\n");
	}
	s = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) s += a[i][j];
	printf("\n Suma elementelor matricei este= %d ", s);
	getch();
}