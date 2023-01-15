// 13. Sa se scrie algoritmul care realizeaza operatia de reuniune a doua multimi.

#include "stdafx.h"


int main()
{
	int a[100], b[100], r[100], n, m, gasit, k;

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

	for (int i = 0; i < n; i++) {
		r[i] = a[i];
	}

	k = n;
	for (int j = 0; j < m; j++) {
		gasit = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[j]) {
				gasit = 1;
			}
		}
		if (gasit != 1) {
			r[k] = b[j];
			k++;
		}
	}

	printf("\nReuniunea celor doua multimi: \n");
	for (int i = 0; i < k; i++) {         //k - artificiu nu stim lungimea tabloului c
		printf("C[%d] = %d\n", i, r[i]);
	}

	return 0;
}

