#include "iostream"
#include "stdio.h"
using namespace std;
enum TipHardware
{
	MONITOR = 10,
	HARD_DRIVE = 20,
	RAM = 30,
	PCU = 40
};
struct ComponentaHdw
{
	char* denumire;
	TipHardware tipHardware;
	float valoarePiesa;
	int luniGarantie;
};
struct PiesaSistem
{
	ComponentaHdw* ch;
	PiesaSistem* next;
};
struct SistemCalcul
{
	PiesaSistem* head = nullptr;
	PiesaSistem* tail = nullptr;
};

void initCoada(SistemCalcul& coada)
{
	coada.head = coada.tail = nullptr;
}
bool isQueueEmpty(const SistemCalcul& coada)
{
	return coada.head == nullptr ? true : false;
}
ComponentaHdw* creareHdw(char* den, TipHardware hdwType, float hdwPrice, int hdwWarranty)
{
	ComponentaHdw* result =
		(ComponentaHdw*)malloc(sizeof(ComponentaHdw));
	result->denumire = (char*)malloc(strlen(den) + 1);
	strcpy(result->denumire, den);
	result->tipHardware = hdwType;
	result->valoarePiesa = hdwPrice;
	result->luniGarantie = hdwWarranty;
	return result;
}
PiesaSistem* creareNodCoada(ComponentaHdw* hdw)
{
	PiesaSistem* nod = (PiesaSistem*)malloc(sizeof(PiesaSistem));
	nod->ch = hdw;
	nod->next = NULL;
	return nod;
}
void Enqueue(SistemCalcul& coada, PiesaSistem* nod)
{
	if (isQueueEmpty(coada))
		coada.head = coada.tail = nod;
	else
	{
		coada.tail->next = nod;
		coada.tail = nod;
	}
}

ComponentaHdw* Dequeue(SistemCalcul& coada)
{
	ComponentaHdw* piesa = nullptr;
	if (!isQueueEmpty(coada))
	{
		PiesaSistem* tmpq = coada.head;
		coada.head = tmpq->next;
		free(tmpq);
	}
	return piesa;
}

void main()
{
	SistemCalcul coada;
	initCoada(coada);
	FILE* pFile = fopen("Sistem.txt", "r");
	if (pFile)
	{
		char buffer[50]; int hdwType, hdwWar; float hdwPrice;
		fscanf(pFile, "%s", buffer);
		while (!feof(pFile))
		{
			fscanf(pFile, "%d", &hdwType);
			fscanf(pFile, "%f", &hdwPrice);
			fscanf(pFile, "%d", &hdwWar);
			ComponentaHdw* chdw = creareHdw(buffer, (TipHardware)hdwType, hdwPrice, hdwWar);
			PiesaSistem* nod = creareNodCoada(chdw);
			Enqueue(coada, nod);
			fscanf(pFile, "%s", buffer);
		}
		fclose(pFile);
	}
	/*while (!isQueueEmpty(coada))
	{
		ComponentaHdw* hwd = Dequeue(coada);
		if (hwd)
			printf("Componenta: %s, tip: %d, price: %3.2f\n",
				hwd->denumire, hwd->tipHardware, hwd->valoarePiesa);
	}*/
}