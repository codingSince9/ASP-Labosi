#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define M 128
#define A 2654435769

struct zapis {
	int broj;
	struct zapis *sljed;
};
typedef struct zapis zapis;

void init_hash(zapis *hash[]) {
	int i;
	for (i = 0; i < M; ++i)
		hash[i] = NULL;
}

unsigned long int Adresa(unsigned long int broj) {
	return (((A*broj) >> 25) % M);
}

void upis(zapis *hash[], zapis *p) {
	unsigned long int i = Adresa(p->broj);
	p->sljed = hash[i];
	hash[i] = p;
}

int main(void) {
	int i, n = 129;
	zapis *p;
	zapis *hash[M];
	init_hash(hash);
	srand((unsigned)time(NULL));
	for (i = 0; i < n; ++i) {
		p = malloc(sizeof(zapis));
		p->broj = rand();
		upis(hash, p);
	}
	for (i = 0; i < M; ++i) {
		printf("%d.  ", i);
		p = hash[i];
		while (p) {
			printf("%d  ", p->broj);
			p = p->sljed;
		}
		printf("\n");
	}
	return 0;
}