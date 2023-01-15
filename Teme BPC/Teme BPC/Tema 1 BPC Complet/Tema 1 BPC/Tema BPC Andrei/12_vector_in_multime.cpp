/* 12. Dandu-se un vector de maxim 100 de elemente, sa scrie algoritmul pentru transformarea vectorului in multime, prin eliminarea dublurilor 
(operatia de compactare) */

#include "stdafx.h"


int main()
{
	int x[100], n, i, k, j;

	printf("Introduceti nr. elementelor tabloului, n >= 2 : ");
	scanf_s("%d", &n);

	printf("\nIntroduceti elementele tabloului: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] == x[j]) {
					for (int k = j; k < n; k++) {
						x[k] = x[k+ 1];
					}
					n--;
					j--;
			}
		}
	}

	printf("\nTabloul rezultat: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
    return 0;
}

