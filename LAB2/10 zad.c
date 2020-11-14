#include <stdio.h>
#include <stdlib.h>

void zamijeni(char *prvi, char *drugi) {
	char pom;
	pom = *prvi;
	*prvi = *drugi;
	*drugi = pom;
}

void bubbleSortPoboljsani(char **a, int n, int smjer) {
	int i, j, min, bilazamjena=1;
	if (smjer) {
		for (i = 0; bilazamjena; ++i) {
			bilazamjena = 0;
			for (j = 0; j < n - 1 - i; ++j) {
				if ((*a[j]) > (*a[j + 1])) {
					zamijeni(&a[j], &a[j + 1]);
					bilazamjena = 1;
				}
			}
		}
	}
	else {
		for (i = 0; bilazamjena; ++i) {
			bilazamjena = 0;
			for (j = 0; j < n - 1 - i; ++j) {
				if ((*a[j]) < (*a[j + 1])) {
					zamijeni(&a[j], &a[j + 1]);
					bilazamjena = 1;
				}
			}
		}
	}
}


int main(void) {
	int n, i, smjer, duljina;
	char *niz[10];
	printf("upisite broj nizova: ");
	scanf("%d", &n);
	printf("upisite smjer sorta: ");
	scanf("%d", &smjer);
	for (i = 0; i < n; ++i) {
		niz[i] = malloc(sizeof(char) * 20);
		printf("upisite %d. niz: ", i + 1);
		scanf("%s", niz[i]);
	}
	bubbleSortPoboljsani(niz, n, smjer);
	for (i = 0; i < n; ++i) {
		printf("%s \n", niz[i]);
		free(niz[i]);
	}
	return 0;
}