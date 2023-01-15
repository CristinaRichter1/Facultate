/*Ex 16. - Realizati programul care sorteaza un vector prin metoda interschimbarii folosind subprograme pentru: citirea vectorului, afisarea vectorului, sortarea vector. */
#include<iostream>

using namespace std;

void afisare_vector(int vector[], int size);
void citeste_vector(int vector[], int size);
void sortare(int vector[], int size);


int main()
{
	int n, *vector;

	cout << "Scrieti numarul de elemente ale vectorului:\n"; cin >> n;
	vector = new int[n];

	cout << "Scrieti elementele vectorului:\n";
	citeste_vector(vector, n);

	afisare_vector(vector, n);

	sortare(vector, n);

	afisare_vector(vector, n);
	
	return 0;
}


void afisare_vector(int vector[], int size)
{
	cout << "[";
	for (int i = 0; i < size - 1; i++)
		cout << vector[i] << ", ";
	cout << vector[size - 1] << "]\n";
}



void citeste_vector(int vector[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << "x[" << i + 1 << "] = ";
		cin >> vector[i];
		cout << "\n";
	}
}



void sortare(int vector[], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i - 1; j < size - 1; j++)
		{
			if (vector[i] < vector[j])
			{
				int temp = vector[j];
				vector[j] = vector[i];
				vector[i] = temp;
			}
		}
	}
}