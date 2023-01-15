
// 18. Sa se determine cel mai mare divizor comun dintr-un sir de numere naturale nenule.

#include "stdio.h"


void main()
{
	int n = 0, cmmd ,r, x[100];
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

	cmmd = x[0];
	for (int i = 1; i < n; i++) {
		    int y = x[i];
			while (y != 0) {
				r = cmmd % y;
				cmmd = y;
				y = r;
			}
	}
	printf("Cel mai mare divizor comun: %d \n", cmmd);
}

