#include <stdio.h>
#include <stdlib.h>

void zamijeni(char *prvi, char *drugi) {
	char pom;
	pom = *prvi;
	*prvi = *drugi;
	*drugi = pom;
}

void shellSort(char **a, int n, int smjer) {
	int i, j, pom, korak;
	if (smjer) {
		for (korak = n / 2; korak >= 1; korak /= 2) {
			for (i = 1; i < n; i += korak) {
				pom = a[i];
				for (j = i; j > korak - 1; j -= korak){
					if (*(a[j]) < *(a[j - korak]))
						a[j] = a[j - korak];
					else
						break;
				}
				a[j] = pom;
			}
		}
	}
	else {
		for (korak = n / 2; korak >= 1; korak /= 2) {
			for (i = 1; i < n; i += korak) {
				pom = a[i];
				for (j = i; j > korak - 1; j -= korak) {
					if (*(a[j]) > *(a[j - korak]))
						a[j] = a[j - korak];
					else
						break;
				}
				a[j] = pom;
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
		niz[i] = malloc(sizeof(char) * 40);
		printf("upisite %d. niz: ", i + 1);
		scanf("%s", niz[i]);
	}
	shellSort(niz, n, smjer);
	for (i = 0; i < n; ++i) {
		printf("%s \n", niz[i]);
		free(niz[i]);
	}
	return 0;
}