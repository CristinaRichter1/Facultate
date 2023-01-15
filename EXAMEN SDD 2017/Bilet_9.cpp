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

struct NodArb {
	Task tsk;
	NodArb *st, *dr;
};

NodArb *inserare(NodArb *r, Task t, int &er)
{
	if(r==NULL){	
		NodArb *nou = new NodArb;
		nou->dr = NULL;
		nou->st = NULL;
		nou->tsk = t;
		r = nou;
	}
	else if(r->tsk.idTask == t.idTask) er=1;
	else if(r->tsk.idTask > t.idTask)
		r->st = inserare(r->st, t, er);
	else 
		r->dr = inserare(r->dr,t,er);
	return r;
}	

int nrTaskuri(NodArb *r, char * inginer)
{
	if(r){		
		
		if(!strcmp(r->tsk.numeInginerAsignat, inginer))
			return 1 + nrTaskuri(r, inginer) + nrTaskuri(r, inginer);

		return 1 + nrTaskuri(r->st, inginer) + nrTaskuri(r->dr, inginer);
	}

	return 0;
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

void main() {

	Task t;
	NodArb *root = NULL;

	FILE * f;
	f = fopen("Tasks.txt", "r");

	char *token, file_buf[LINESIZE], sep_list[] = ",;";

	while(fgets(file_buf, sizeof(file_buf), f)) {
		token = strtok (file_buf, sep_list);
		t.idTask = atoi(token);

		token = strtok (NULL, sep_list);
		t.dataAsignare = (char*)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(t.dataAsignare, token);

		token = strtok (NULL, sep_list);
		t.numeInginerAsignat = (char*)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(t.numeInginerAsignat, token);

		token = strtok (NULL, sep_list);
		t.nivelComplexitate = atoi(token);

		token = strtok (NULL, sep_list);
		t.stareTask = (char*)malloc((strlen(token) + 1) * sizeof(char));
		strcpy(t.stareTask, token);
		
		int err = 0;		
		root = inserare(root, t, err);
		if(err) {
			printf("\nTask-ul cu id %d exista in arbore.\n", t.idTask);
			free(t.dataAsignare);
			free(t.numeInginerAsignat);
			free(t.stareTask);
		}
		else
			printf("\nTask-ul cu id %d a fost inserat\n", t.idTask);
	}
	afisarePre(root);
	fclose(f);
}