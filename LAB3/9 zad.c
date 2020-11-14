#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#define M 256
#define A  2654435769

unsigned long int Adresa(unsigned long int broj) {
	return (((A*broj) >> 24) % M);
}

int upis(int hash[], int broj) {
	unsigned long int adresa;
	int i, index;
	adresa = Adresa(broj);
	for (i = 0; i < M; ++i) {
		index = (adresa + i * i) % M;
		if (hash[index] == -1) {
			hash[index] = broj;
			return 1;
		}
	}
	return 0;
}

int main(void) {
	int i, n = 257;
	int hash[M];
	for (i = 0; i < M; ++i) {
		hash[i] = -1;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < n; ++i) {
		upis(hash, rand());
	}
	for (i = 0; i < M; ++i) {
		printf("%d.   %d\n", i, hash[i]);
	}
	return 0;
}