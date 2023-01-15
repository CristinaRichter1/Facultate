#include "stdlib.h"
#include "stdio.h"
#include "memory.h"
#include "iostream"
using namespace std;
struct Movie
{
	int cod;
	char* titlu;
	float buget;
	char* gen;
	int rating;
};
struct Heap
{
	Movie** elements;
	int heapSize;
	int index;
};

void InitHeap(Heap&, int);
Movie* CreateItem(int, int, char*, char*, int);
void Enqueue(Heap&, int, int, char*, char*, int);
Movie* Dequeue(Heap&);
void ReheapUp(Heap, int, int);
void ReheapDown(Heap, int, int);
void PrintHeap(Heap);

void InitHeap(Heap& heap, int size)
{
	heap.elements = (Movie**)malloc(sizeof(Movie*)*size);
	heap.heapSize = size;
	heap.index = 0;
	memset(heap.elements, NULL, sizeof(Movie*)*size);
}

Movie* CreateItem(int codFilm, int bugetFilm, char* titluFilm, char* genFilm, int ratingFilm)
{
	Movie* item = (Movie*)malloc(sizeof(Movie));
	item->cod = codFilm;
	item->buget = bugetFilm;
	item->rating = ratingFilm;
	item->titlu = (char*)malloc(strlen(titluFilm) + 1);
	strcpy(item->titlu, titluFilm);
	item->gen = (char*)malloc(strlen(genFilm) + 1);
	strcpy(item->gen, genFilm);
	return item;
}

void Enqueue(Heap& heap, int cod, int buget, char* titlu, char* gen, int rating)
{
	if (heap.index < heap.heapSize)
	{
		Movie* item = CreateItem(cod, buget, titlu, gen, rating);
		heap.elements[heap.index] = item;
		ReheapUp(heap, 0, heap.index);
		heap.index++;
		return;
	}
	printf("Heap structure is full!\n");
}

void ReheapUp(Heap heap, int first, int last)
{
	int parinte;
	Movie* temp = NULL;
	if (first < last)
	{
		parinte = (last - 1) / 2;
		if (heap.elements[parinte]->cod <
			heap.elements[last]->cod)
		{
			temp = heap.elements[parinte];
			heap.elements[parinte] = heap.elements[last];
			heap.elements[last] = temp;
			ReheapUp(heap, first, parinte);
		}
	}
}

void ReheapDown(Heap heap, int current, int last)
{
	int leftChild, rightChild, maxChild;
	Movie* temp = NULL;
	leftChild = 2 * current + 1;
	rightChild = 2 * current + 2;
	if (leftChild <= last)
	{
		if (leftChild == last)
			maxChild = leftChild;
		if (heap.elements[leftChild]->cod <
			heap.elements[rightChild]->cod)
			maxChild = leftChild;
		else
			maxChild = rightChild;

		if (heap.elements[current]->cod >
			heap.elements[maxChild]->cod)
		{
			temp = heap.elements[current];
			heap.elements[current] = heap.elements[maxChild];
			heap.elements[maxChild] = temp;
		}
		ReheapDown(heap, maxChild, last);
	}
}

Movie* Dequeue(Heap& heap)
{
	Movie* result = NULL;
	if (heap.index > 0)
	{
		result = heap.elements[0];
		heap.elements[0] = heap.elements[--heap.index];
		ReheapDown(heap, 0, heap.index - 1);
	}
	return result;
}

void main()
{
	Heap heap;
	InitHeap(heap, 8);
	FILE* pFile = fopen("Filme.txt", "r");
	if (pFile)
	{
		int cod, rating; float buget; char titlu[50], gen[50];
		fscanf(pFile, "%d", &cod);
		while (!feof(pFile))
		{
			fscanf(pFile, "%f", &buget);
			fscanf(pFile, "%s", titlu);
			fscanf(pFile, "%s", gen);
			fscanf(pFile, "%d", &rating);
			Enqueue(heap, cod, buget, titlu, gen, rating);
			fscanf(pFile, "%d", &cod);
		}
	}
	/*Movie* item = NULL;
	while ((item = Dequeue(heap)) != NULL)
		printf("Heap cod:%d, buget:%f\n",
		item->cod, item->buget);*/
}