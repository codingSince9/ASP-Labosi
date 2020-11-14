#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

struct Stog {
	int vrh, polje[MAX];
};
typedef struct Stog Stog;

void init_Stog(Stog *stog) {
	stog->vrh = -1;
}

int dodaj(int broj, Stog *stog) {
	if (stog->vrh >= MAX - 1)
		return 0;
	stog->vrh++;
	stog->polje[stog->vrh] = broj;
	return 1;
}

int skini(int *broj, Stog *stog) {
	if (stog->vrh < 0)
		return 0;
	*broj = stog->polje[stog->vrh];
	stog->vrh--;
	return 1;
}

int ispis(Stog stog) {
	int i;
	printf("stog: ");
	for (i = 0; i < stog.vrh; ++i)
		printf("%d ", stog.polje[i]);
}

int main(void) {
	Stog stog1, stog2;
	init_Stog(&stog1);
	init_Stog(&stog2);
	int i, broj;
	srand((unsigned)time(NULL));
	for (i = 0; i < MAX; ++i)
		dodaj(rand() % 10 + 1, &stog1);
	ispis(stog1);
	for (i = 0; i < MAX; ++i) {
		skini(&broj, &stog1);
		dodaj(broj, &stog2);
	}
	printf("\nispis: ");
	for (i = 0; i < MAX - 1; ++i) {
		skini(&broj, &stog2);
		printf("%d ", broj);
	}
	return 0;
}