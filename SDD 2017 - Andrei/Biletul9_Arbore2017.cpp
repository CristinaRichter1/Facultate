#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 256

struct Task {
	int idTask;
	char *dataAsignare;
	char *numeInginerAsignat;
	int nivelComplexitate;
	char *stareTask; // "nou", "deschis", "in lucru", "rezolvat", "inchis"
};

Task creareTask(int id, char *dataAsignare, char *numeInginerAsignat, int nivelComplexitate, char *stareTask) {
	Task tsk;
	tsk.idTask = id;
	tsk.dataAsignare = (char*)malloc(sizeof(char)*(strlen(dataAsignare) + 1));
	strcpy(tsk.dataAsignare, dataAsignare);
	tsk.numeInginerAsignat = (char*)malloc(sizeof(char)*(strlen(numeInginerAsignat) + 1));
	strcpy(tsk.numeInginerAsignat, numeInginerAsignat);
	tsk.nivelComplexitate = nivelComplexitate;
	tsk.stareTask = (char*)malloc(sizeof(char)*(strlen(stareTask) + 1));
	strcpy(tsk.stareTask, stareTask);
	return tsk;
}

void afisareTask(Task task) {
	printf("Task-ul %d a fost asignat pe data %s lui %s si are nivelul de complexitate %d si starea %s \n", task.idTask, task.dataAsignare, task.numeInginerAsignat, task.nivelComplexitate, task.stareTask);
}

struct NodArb {
	Task tsk;
	NodArb *st, *dr;
};


NodArb *inserare(NodArb *r, Task t, int &er)
{
	if (r == NULL) {
		NodArb *nou = new NodArb;
		nou->dr = NULL;
		nou->st = NULL;
		nou->tsk = t;
		r = nou;
	}
	else if (r->tsk.idTask == t.idTask) er = 1;
	else if (r->tsk.idTask > t.idTask)
		r->st = inserare(r->st, t, er);
	else
		r->dr = inserare(r->dr, t, er);
	return r;
}

struct nodLista {
	nodLista* next;
	Task info;
};

nodLista* creareNodLista(Task info, nodLista* next) {
	nodLista* nou = (nodLista*)malloc(sizeof(nodLista));
	nou->info = creareTask(info.idTask,info.dataAsignare,info.numeInginerAsignat,info.nivelComplexitate,info.stareTask);
	nou->next = next;
	return nou;
}

nodLista* nodInserareSfarsit(nodLista* cap, Task info) {
	nodLista* nou = creareNodLista(info, NULL);
	if (cap) {
		nodLista* p = cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
		return cap;
	}
	else {
		return nou;
	}
}

void afisareLista(nodLista* cap) {
	if (cap) {
		nodLista* p = cap;
		while (p) {
			afisareTask(p->info);
			p = p->next;
		}
	}
	else {
		printf("Nu a fost gasit niciun rezultat.");
	}
}

void stergeLista(nodLista* cap) {
	while (cap) {
		free(cap->info.dataAsignare);
		free(cap->info.numeInginerAsignat);
		free(cap->info.stareTask);
		nodLista* p = cap;
		cap = cap->next;
		free(p);
	}
	cap = NULL;
}

int nrTaskuri(NodArb *r, char * inginer)
{
	int count = 0;
	if (r) {
		if (strcmp((r->tsk.numeInginerAsignat), (inginer)) == 0)
			++count;

		count += nrTaskuri(r->st, inginer);
		count += nrTaskuri(r->dr, inginer);

	}
	return count;
}

void afisarePre(NodArb* radacina)
{
	if (radacina)
	{
		printf("%d %s\n", radacina->tsk.idTask, radacina->tsk.dataAsignare);
		afisarePre(radacina
			->st);
		afisarePre(radacina->dr);
	}
}

void scrieTaskInFisier(Task tsk, FILE* f) {
	fprintf(f, "%d,%s,%s,%d,%s, \n", tsk.idTask, tsk.dataAsignare, tsk.numeInginerAsignat, tsk.nivelComplexitate, tsk.stareTask);
}


void salvareArboreInFisier(NodArb* r, FILE* file) {
	if (r) {
		salvareArboreInFisier(r->dr, file);
		scrieTaskInFisier(r->tsk,file);
		salvareArboreInFisier(r->st, file);
	}
}

void afisareArbore(NodArb* rad) {
	if (rad) {
		afisareArbore(rad->st);
		afisareTask(rad->tsk);
		afisareArbore(rad->dr);
	}
}

void schimbaStareTask(NodArb* r) {
	if (r) {
		if (strcmp((r->tsk.stareTask),("nou")) == 0) {
			free(r->tsk.stareTask);
			r->tsk.stareTask = (char*)malloc(sizeof(char)*(strlen("deschis") + 1));
			strcpy(r->tsk.stareTask, "deschis");
		}
		schimbaStareTask(r->st);
		schimbaStareTask(r->dr);
	}
}

void cautaTaskuriComplexitate(NodArb* rad, int complexitateCautata, nodLista** rezultat) {
	if (rad) {
		if (rad->tsk.nivelComplexitate > complexitateCautata) {
			*rezultat = nodInserareSfarsit(*rezultat, rad->tsk);
		}
		cautaTaskuriComplexitate(rad->st, complexitateCautata, rezultat);
		cautaTaskuriComplexitate(rad->dr, complexitateCautata, rezultat);
	}
}

void stergereArbore(NodArb** rad) {
	if (*rad) {
		stergereArbore(&(*rad)->st);
		stergereArbore(&(*rad)->dr);
		free((*rad)->tsk.dataAsignare);
		free((*rad)->tsk.numeInginerAsignat);
		free((*rad)->tsk.stareTask);
		free(*rad);
		*rad = NULL;
	}
}

void main() {

	Task t;
	NodArb *root = NULL;

	FILE * f;
	f = fopen("Tasks.txt", "r");

	char *token, file_buf[LINESIZE], sep_list[] = ",;";

	while (fgets(file_buf, sizeof(file_buf), f)) {
		token = strtok(file_buf, sep_list);
		t.idTask = atoi(token);

		token = strtok(NULL, sep_list);
		t.dataAsignare = (char*)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(t.dataAsignare, token);

		token = strtok(NULL, sep_list);
		t.numeInginerAsignat = (char*)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(t.numeInginerAsignat, token);

		token = strtok(NULL, sep_list);
		t.nivelComplexitate = atoi(token);

		token = strtok(NULL, sep_list);
		t.stareTask = (char*)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(t.stareTask, token);

		int err = 0;
		root = inserare(root, t, err);
		if (err) {
			printf("\nTask-ul cu id %d exista in arbore.\n", t.idTask);
			free(t.dataAsignare);
			free(t.numeInginerAsignat);
			free(t.stareTask);
		}
		else
			printf("\nTask-ul cu id %d a fost inserat\n", t.idTask);
	}
	//afisarePre(root);
	printf("Parcurgere arbore: \n");
	afisareArbore(root);
	printf("Nr. de task-uri realizate de Popescu: %d\n", nrTaskuri(root, "Popescu"));
	printf("Schimbare stare din nou in deschis: \n");
	schimbaStareTask(root);
	afisareArbore(root);
	printf("Cautare sarcini cu complexitate mai mare de 2: \n");
	nodLista* rezultatCautare = NULL;
	cautaTaskuriComplexitate(root, 2, &rezultatCautare);
	afisareLista(rezultatCautare);
	stergeLista(rezultatCautare);
	stergereArbore(&root);
	if (root == NULL) {
		printf("Arborele este gol.");
	}
	fclose(f);
	
}