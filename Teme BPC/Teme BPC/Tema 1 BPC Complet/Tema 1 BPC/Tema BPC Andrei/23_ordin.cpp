/* 23. Dandu-se un vector neordonat avand n componente, sa se determine elementul cu numarul de ordine i
din masivul ordonat crescator/descrescator fara a ordona vectorul. */

#include "stdio.h"


void main()
{
	int n = 0, ordin = 0, crescator = -1, x[100];

	while (n < 1) {
		printf("Introduceti nr. elementelor tabloului, n >= 1 : ");
		scanf_s("%d", &n);
	}

	printf("\nIntroduceti elementele tabloului: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}

	while (ordin < 1 || ordin > n) {
		printf("\nIntroduceti ordinul i: ");
		scanf_s("%d", &ordin);
	}

	while (crescator != 0 && crescator != 1) {
		printf("\nIntroduceti modul in care este ordonat sirul crescator (1) sau descrescator (0): ");
		scanf_s("%d", &crescator);
	}

	int count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x[i] > x[j]) {
				count++;
			}
		}
		if (crescator == 1) {
			if (count == ordin) {
				printf("\nElementul de ordin %d din masivul ordonat crescator este %d. \n", ordin, x[i]);
				break;
			}
			else count = 1;
		}
		else if (crescator == 0) {
			count = n - count + 1;
			if (count == ordin) {
				printf("\nElementul de ordin %d din masivul ordonat descrescator este %d. \n", ordin, x[i]);
				break;
			}
			else count = 1;
		}
	}
}


