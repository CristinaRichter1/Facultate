/*6.  Scrieti programul care sa calculeze produsul vectorial a doi vectori.*/
#include<iostream>

using namespace std;


int main()
{
	int n, *nVect, *mVect, *resVect, produs = 0;

	do
	{
		cout << "Introduceti dimensiunea vector:\n";
		cin >> n;
	} while (n < 1);


	//allocate memory for vectors
	nVect = new int[n];
	mVect = new int[n];
	resVect = new int[n];

	//read vector nVect from user
	for (int i = 0; i < n; i++)
	{
		cout << "X[" << i + 1 << "] = ";
		cin >> nVect[i];
		cout << "\n";
	}
	cout << "\n\n";
	//read vector mVect from user
	for (int i = 0; i < n; i++)
	{
		cout << "Y[" << i + 1 << "] = ";
		cin >> mVect[i];
		cout << "\n";
	}
	cout << "Vectorul rezultat este: \n";

	for (int i = 0; i < n; i++)
	{
		resVect[i] = nVect[i] * mVect[i];
		cout << "Z[" << i + 1 << "] = " << resVect[i] << "\n";
	}

	return 0;
}