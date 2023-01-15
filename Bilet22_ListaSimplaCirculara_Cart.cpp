#include <iostream>

struct Cart {
	int id;
	char *producator;
	int an_fabricatie;
	int capacitate_motor;
};

Cart creeazaCart(int ID, char *prod, int anFab, int capMotor) {
	Cart c;
	c.id = ID;
	c.an_fabricatie = anFab;
	c.capacitate_motor = capMotor;
	c.producator = (char*)malloc(sizeof(char) * strlen(prod) + 1);
	strcpy(c.producator, prod);

	return c;
}

Cart copiazaCart(Cart cart) {
	Cart c;
	c.id = cart.id;
	c.an_fabricatie = cart.an_fabricatie;
	c.capacitate_motor = cart.capacitate_motor;
	c.producator = (char*)malloc(sizeof(char) * strlen(cart.producator) + 1);
	strcpy(c.producator, cart.producator);

	return c;
}

void afiseazaCart(Cart c) {
	printf("ID: %d - Producator: %s - An: %d - %d cm cubi.\n", c.id, c.producator, c.an_fabricatie, c.capacitate_motor);
}

struct Nod {
	Cart info;
	Nod *next;
};

Nod *insereazaInLista(Nod *head, Cart c) {
	if (head) {
		Nod *last = head;
		while (last->next != head) {
			last = last->next;
		}
		Nod *nou = (Nod*)malloc(sizeof(Nod));;
		nou->info = copiazaCart(c);
		last->next = nou;
		nou->next = head;

		return head;
	}
	else {
		Nod *nou = (Nod*)malloc(sizeof(Nod));
		nou->info = copiazaCart(c);
		nou->next = nou;

		return nou;
	}
}

void afisezaLista(Nod *head) {
	printf("Lista carturi: \n");
	if (head) {
		Nod *last = head;
		afiseazaCart(head->info);
		printf(" --> ");
		while (last->next != head) {
			last = last->next;
			afiseazaCart(last->info);
			printf(" --> ");
		}
	}
	printf("\n");
}

int calculeazaNrCarturi(Nod *head) {
	int count = 0;
	if (head) {
		Nod *last = head;
		count++;
		while (last->next != head) {
			last = last->next;
			count++;
		}
	}
	return count;
}

void afiseazaNrCarturi(Nod *head) {
	printf("Lista contine %d carturi.\n", calculeazaNrCarturi(head));
}

int *aniFabCarturi(Nod *head) {
	int nrCart = calculeazaNrCarturi(head);
	int *aniFab = (int*)malloc(sizeof(int) * nrCart);
	int iterator = 0;

	if (head) {
		Nod *last = head;
		aniFab[iterator++] = last->info.an_fabricatie;
		while (last->next != head) {
			last = last->next;
			aniFab[iterator++] = last->info.an_fabricatie;
		}
	}
	return aniFab;
}

void afiseazaAniFabCarturi(Nod *head) {
	int count = calculeazaNrCarturi(head);
	int *ani = aniFabCarturi(head);
	printf("Ani de fabricatie carturi: \n");
	for (int i = 0; i < count; i++) {
		printf("%i\t", ani[i]);
	}
	printf("\n");
}



Nod *elibereazaMemCart(Nod *nod) {
	if (nod && &nod->info != NULL) {
		free(nod->info.producator);
	}
	else {
		return NULL;
	}
	return nod;
}

Nod *stergeCart(Nod *head, int id) {
	//exista cel putin un nod
	if (head) {
		Nod *last = head;
		// primul nod este cel care trebuie sters
		if (last->info.id == id) {
			// un singur nod
			if (last->next == last) {
				last = elibereazaMemCart(last);
				free(last);
				return NULL;
			}
			// mai multe noduri
			else {
				Nod *temp = last;
				Nod * second = last->next;

				while (last->next != temp) {
					last = last->next;
				}
				last->next = second;
				printf("Size of last: %ld\n", sizeof(temp));
				temp = elibereazaMemCart(temp);
				printf("Size of last: %ld\n", sizeof(temp));
				free(temp);


				return second;
			}
		}
		else {
			// un alt nod decat primul
			// gaseste nod
			while (last->next != head) {

				//nod gasit
				if (last->next->info.id == id) {
					Nod *temp = last->next;
					last->next = temp->next;
					temp = elibereazaMemCart(temp);
					free(temp);

					return head;
				}

				last = last->next;
			}
		}
	}
	else {
		return NULL;
	}
}

Nod *maresteCapacitate(Nod *head, char *prod) {
	Nod *temp = head;
	while (temp->next != head) {
		if (strcmp(temp->info.producator, prod) == 0) {
			temp->info.capacitate_motor += 10;
			return head;
		}
		temp = temp->next;
	}
	return head;
}

Nod *filtreazaDupaCapacitate(Nod *head, int capMax) {
	if (head) {
		Nod *list = NULL;
		Nod *temp = head;
		while (temp->next != head) {
			if (temp->info.capacitate_motor <= capMax) {
				list = insereazaInLista(list, temp->info);
			}
			temp = temp->next;
		}
		return list;

	}
	return NULL;
}




void main() {
	Cart tony = creeazaCart(11, "Tony", 2014, 128);
	Cart suzuki = creeazaCart(32, "Suzuki", 2016, 990);
	Cart suzuki2 = copiazaCart(suzuki);
	Cart yamaha = creeazaCart(141, "Yamaha", 2018, 256);
	Cart vw = creeazaCart(112, "Volskwagen", 2017, 256);
	Cart ford = creeazaCart(192, "Ford", 2019, 512);



	Nod *cap = NULL;
	cap = insereazaInLista(cap, tony);
	cap = insereazaInLista(cap, suzuki);
	cap = insereazaInLista(cap, suzuki2);
	cap = insereazaInLista(cap, yamaha);
	afiseazaNrCarturi(cap);
	cap = insereazaInLista(cap, vw);
	cap = insereazaInLista(cap, ford);
	afisezaLista(cap);

	afiseazaNrCarturi(cap);
	afiseazaAniFabCarturi(cap);
	cap = stergeCart(cap, 32);
	cap = stergeCart(cap, 11);
	afisezaLista(cap);
	cap = stergeCart(cap, 112);
	afisezaLista(cap);
	cap = insereazaInLista(cap, suzuki);
	Nod *listaFiltrata = NULL;

	cap = maresteCapacitate(cap, "Suzuki");
	afisezaLista(cap);

	printf("\n--------------------------------------------------------------\n");

	listaFiltrata = filtreazaDupaCapacitate(cap, 512);
	afisezaLista(listaFiltrata);
}