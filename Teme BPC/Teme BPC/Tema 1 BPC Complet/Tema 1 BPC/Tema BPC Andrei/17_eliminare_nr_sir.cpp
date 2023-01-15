// 17. Elimina dintr-un sir de numere toate numerele egale cu o valoare data, fara a utiliza un alt sir

#include "stdio.h"


void main()
{
	int n = 0, de_sters, x[100];
	while (n < 1) {
		printf("Introduceti nr. elementelor tabloului, n >= 1 : ");
		scanf_s("%d", &n);
	}

	printf("\nIntroduceti elementele tabloului: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}

	printf("\nIntroduceti elementul de sters din sir: \n");
	scanf_s("%d", &de_sters);
	
	for (int i = 0; i < n; i++) {
		if (x[i] == de_sters) {
			if (i + 1 != n) {
				for (int j = i; j < n; j++) {
					x[j] = x[j + 1];
				}
				n = n - 1;
				i = -1;
			} else if (i + 1 == n) {
				n = n - 1;
			}
		}
	}

	printf("\nTabloul rezultat: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
}