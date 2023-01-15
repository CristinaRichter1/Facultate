
// 20. Sa se determine amplitudinea unui sir de numere.

#include "stdio.h"
#include "stdlib.h"


void main()
{
	int n = 0;
	double xmin, xmax, x[100];
	while (n < 1) {
		printf("Introduceti nr. elementelor tabloului, n >= 1 : ");
		scanf_s("%d", &n);
	}
	printf("\nIntroduceti elementele tabloului: \n");
	for (int i = 0; i < n; i++) {
		printf("x[%d] = ", i);
		scanf_s("%lf", &x[i]); // %lf pentru double la scanf_s
	}

	xmin = x[0];
	xmax = x[0];

	for (int i = 1; i < n; i++) {
		if (x[i] < xmin)
		{
			xmin = x[i];
		} else if (x[i] > xmax) {
			xmax = x[i];
		}
	}
	double amplit = xmax - xmin;
	printf("Xmin: %f, Xmax: %f, Amplitudine: %f. \n", xmin,xmax,amplit); // %f pentru double la printf
}



