/*5.  Scrieti programul care numara cate elemente negative sunt intr-un vector.*/
#include <iostream>

using namespace std;


int main()
{
	int n, count = 0, *vArray;
	do
	{
		cout << "Introduceti numarul de elemente ale vectorului:\n";
		cin >> n;
	} while (n < 1);

	vArray = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "X[" << i + 1 << "] = ";
		cin >> vArray[i];
		cout << "\n" << endl;
		if (vArray[i] < 0)
			count++;
	}


	cout << "Vectorul are " << count << " elemente negative.\n";


	delete[] vArray;
	//vArray = NULL;

	return 0;

}