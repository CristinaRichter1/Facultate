
// 19. Sa se determine cel mai mic multiplu comun dintr-un sir de numere naturale nenule, n>2.

#include "stdio.h"


void main()
{
	int n = 0, cmmmc, x[100];
	while (n < 2) {
		printf("Introduceti nr. elementelor tabloului, n >= 2 : ");
		scanf_s("%d", &n);
	}
	printf("\nIntroduceti elementele tabloului: \n");
	for (int i = 0; i < n; i++) {
		do {
			printf("x[%d] = ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < 1);
	}

	cmmmc = x[0];
	for (int i = 1; i < n; i++) {
		int y = x[i];
		int cmd = cmmmc;
		while (y != 0) {
			int r = cmd % y;
			cmd = y;
			y = r;
		}
		cmmmc = cmmmc*x[i] / cmd;
	}
	printf("Cel mai mic multiplu comun: %d \n", cmmmc);
}


