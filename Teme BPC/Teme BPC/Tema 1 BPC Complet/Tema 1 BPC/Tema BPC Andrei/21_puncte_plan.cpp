// 21. Se dau n puncte in plan si coordonatele lor(x,y). Sa se determine distanta maxima dintre toate punctele.

#include "stdio.h"
#include "math.h"

void main()
{
	int n = 0;
	double v[100][2];
	while (n < 2) {
		printf("Introduceti nr. punctelor in plan, n >= 1 : ");
		scanf_s("%d", &n);
	}

	printf("\nIntroduceti coordonatele punctelor in plan: \n");
	for (int i = 0; i < n; i++) {
		printf("Punctul %d: \n", i);
		printf("X%d = ", i);
		scanf_s("%lf", &v[i][0]);
		printf("Y%d = ", i);
		scanf_s("%lf", &v[i][1]);
	}

	double dist_max = 0;
	int poz_max_1;
	int poz_max_2;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt((v[i][0] - v[j][0])*(v[i][0] - v[j][0]) + (v[i][1] - v[j][1])*(v[i][1] - v[j][1]));
			if (dist > dist_max) {
				dist_max = dist;
				poz_max_1 = i;
				poz_max_2 = j;
			}
		}
	}
	
	printf("Distanta maxima dintre toate punctele: %f, apartinand punctelor %d si %d.\n", dist_max, poz_max_1, poz_max_2);
	
	/*printf("\nPunctele in plan: \n");
	for (int i = 0; i < n; i++) {
		printf("(X%d,Y%d) = (%f,%f)\n", i, i, v[i][0], v[i][1]);
	} */
	
}