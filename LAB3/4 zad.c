#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

struct cvor {
	int broj;
	struct cvor *sljed;
};
typedef struct cvor cvor;

struct Red {
	cvor *ulaz;
	cvor *izlaz;
};
typedef struct Red Red;

void init_red(Red *red) {
	red->ulaz = NULL;
	red->izlaz = NULL;
}

int dodajURed(double broj, Red *red) {
	cvor *novi;
	novi = malloc(sizeof(cvor));
	if (novi == NULL)
		return 0;
	novi->broj = broj;
	novi->sljed = NULL;
	if (red->izlaz == NULL)
		red->izlaz = novi;
	else
		(red->ulaz)->sljed = novi;
	red->ulaz = novi;
	return 1;
}

int poljeURed(int polje[], int n, Red *red) {
	int provjera;
	if (n == 0)
		return 1;
	provjera = poljeURed(polje + 1, n - 1, red);
	if (provjera == 0)
		return 0;
	return dodajURed(*polje, red);
}

void ispis(Red red) {
	while (red.izlaz) {
		printf("%d ", red.izlaz->broj);
		red.izlaz = red.izlaz->sljed;
	}
}

int main(void) {
	int i, polje[MAX];
	Red red;
	init_red(&red);
	srand((unsigned)time(NULL));
	for (i = 0; i < MAX; ++i)
		polje[i] = rand() % 10 + 1;
	printf("clanovi polja: ");
	for (i = 0; i < MAX; ++i)
		printf("%d ", polje[i]);
	poljeURed(polje, MAX, &red);
	printf("\n");
	printf("clanovi reda: ");
	ispis(red);
	return 0;
}