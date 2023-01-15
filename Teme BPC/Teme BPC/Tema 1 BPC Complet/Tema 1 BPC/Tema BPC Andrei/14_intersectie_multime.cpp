// 14. Sa se scrie algoritmul care realizeaza operatia de intersectie a doua multimi.

#include "stdafx.h"


int main()
{
	int a[100], b[100], c[100], n, m, gasit, k;

	printf("Introduceti nr. elementelor multimii A: ");
	scanf_s("%d", &n);

	printf("\nIntroduceti elementele multimii A: \n");
	for (int i = 0; i < n; i++) {
		printf("A[%d] = ", i);
		scanf_s("%d", &a[i]);
	}

	printf("Introduceti nr. elementelor multimii B: ");
	scanf_s("%d", &m);

	printf("\nIntroduceti elementele multimii B: \n");
	for (int i = 0; i < m; i++) {
		printf("B[%d] = ", i);
		scanf_s("%d", &b[i]);
	}

	k = 0;
	for (int i = 0; i < n; i++) {
		gasit = 0;
		for (int j = 0; j < m; j++) {
			if (a[i] == b[j]) {
				gasit = 1;
			}
		}
		if (gasit == 1) {
			c[k] = a[i];
			k++;
		}
	}

	printf("\nIntersectia celor doua multimi: \n");
	for (int i = 0; i < k; i++) {         //k - artificiu ca sa nu aflam lungimea tabloului c
		printf("C[%d] = %d\n", i, c[i]);
	}

    return 0;
}

