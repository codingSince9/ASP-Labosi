#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

struct cvor {
	int element;
	struct cvor *sljed;
};
typedef struct cvor cvor;

struct Stog {
	cvor *vrh;
};
typedef struct Stog Stog;

void init_Stog(Stog *stog) {
	stog->vrh = NULL;
}

int dodaj(int broj, Stog *stog) {
	cvor *novi;
	if ((novi = malloc(sizeof(cvor))) == NULL)
		return 0;
	novi->element = broj;
	novi->sljed = stog->vrh;
	stog->vrh = novi;
	printf("dodani broj: %d  ", (stog->vrh)->element);
	return 1;
}

int main(void) {
	int i, broj;
	Stog *stog;
	init_Stog(&stog);
	srand((unsigned)time(NULL));
	for (i = 0; i <= MAX; ++i) {
		broj = rand() % 10 + 1;
		if (dodaj(broj, &stog))
			printf("broj je uspjesno dodan\n");
		else {
			printf("neuspjeh");
			break;
		}
	}
	return 0;
}