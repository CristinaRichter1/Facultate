// 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


void Citeste(int a[100],int n) {
	

	for (int i = 0;i < n;i++)
		cin >> a[i];
}

void Afisare(int a[100],int n) {
	
	cout << "Vectorul este:\t";
	for (int i = 0;i < n;i++)
		cout << a[i]<<" ";
}


void Produs(int a[100], int b[100], int n,int c[100]) {
	
	for (int i = 0;i < n;i++)
		c[i] = a[i] * b[i];
}

void main()
{
	int n, a[100], b[100], i, j, c[100];

	cout << "Introduceti dimensiunea vectorilor\n";
	cin >> n;
	
	cout << "Introduceti primul vector\t";
	Citeste(a, n);
	
	cout << "Introduceti al doilea vector\t";
	Citeste(b, n);
	
	Produs(a, b, n,c);

	Afisare(c, n);
   
}

