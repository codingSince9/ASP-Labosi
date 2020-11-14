#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

struct Stog {
	int vrh;
	int polje[MAX];
};
typedef struct Stog Stog;

void init_stog(Stog *stog) {
	stog->vrh = -1;
}

int dodaj(int broj, Stog *stog) {
	if (stog->vrh == MAX - 1)
		return 0;
	stog->vrh++;
	stog->polje[stog->vrh] = broj;
	return 1;
}

int main(void) {
	Stog stog;
	init_stog(&stog);
	int i, broj;
	srand((unsigned)time(NULL));
	for (i = 0; i <= MAX; ++i) {
		broj = rand() % 10 + 1;
		dodaj(broj, &stog);
	}
	for (i = 0; i < stog.vrh; ++i)
		printf("%d ", stog.polje[i]);
	return 0;
}