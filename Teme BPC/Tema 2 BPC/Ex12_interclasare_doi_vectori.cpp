#include<stdio.h>
#include<malloc.h>
void main()
{
	int m, n, p, i, j, k; float *x, *y, *z;
	printf("Dimensiunea primului vector, m=");
	scanf("%d", &m);
	x = (float*)malloc(m * sizeof(float));
	for (i=0;i<m;i++)
	{
		printf("x[%d]=", i); scanf("%f", x + 1);
	}
	printf("Dimensiunea vectorului doi, n=");
	scanf("%d", &n);
	y = (float*)malloc(n * sizeof(float));
	for (i = 0; i < n; i++) {
		printf("y[%d]=", i); scanf("%f", y + 1);
	}
	z= (float*)malloc((m+n) * sizeof(float));
	i = 0; j = 0; p = 0;
	while ((i < m) && (j < n))
		if (x[i] < y[j])
			z[p++] = x[i++];
		else z[p++] = y[j++];
	while (i < m) z[p++] = x[i++];
	while (j < n) z[p++] = y[j++];
	printf("Vectorul rezultat este: \n");
	for (i = 0; i < p; i++) printf("%4.2f ", z[i]);
	free(x); free(y); free(z);
}