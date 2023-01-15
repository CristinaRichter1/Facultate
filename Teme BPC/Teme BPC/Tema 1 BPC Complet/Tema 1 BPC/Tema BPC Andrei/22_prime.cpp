// 22. Sa se determine toate numerele prime dintr-un sir de numere naturale.

#include "stdio.h"


void main()
{
	int n = 0, d, x[100];
	while (n < 1) {
		printf("Introduceti nr. elementelor tabloului, n >= 1 : ");
		scanf_s("%d", &n);
	}

	printf("\nIntroduceti elementele tabloului: \n");
	for (int i = 0; i < n; i++) {
		do {
			printf("x[%d] = ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < 0); //naturale
	}

	for (int i = 0; i < n; i++) {
		bool prim = true;
		if (x[i] == 0 || x[i] == 1) {
			prim = false;
		}
		else for (d = 2; d < x[i]; d++) {
			if (x[i] % d == 0) {
				prim = false;
			}
		}
		if (prim) {
			printf("%d este prim. \n", x[i]);
		}
	}
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     