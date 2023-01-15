#include<stdio.h>

void main()
{
	int n; float x[100], a;
	printf("Dimensiunea vectorului:";
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("x[%d]=",i);
		scanf("%f", &x[i]);
	}
	
	printf ("Introduceti valoarea:";
	scanf ("%f", &a);
	i=0;
	while ((i<n) && (x[i]))i++;
	
	for (int j=n;j>i;j--) x[j] = j[j-1];
		x[j] = a;n++;
	printf("Vectorul rezultat este:\n");
	
	for (i=0;i<n;i++)printf("4.2f ",x[i])
}