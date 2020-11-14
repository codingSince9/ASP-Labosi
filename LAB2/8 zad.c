#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char **a, int n, int smjer) {
	int i, j, m;
	char *pom;
	if (smjer) {
		for (i = 0; i < n; ++i) {
			pom = a[i];
			for (j = i; j >= 1 && (*a[j - 1]) > *pom; --j)
				a[j] = a[j - 1];
			a[j] = pom;
		}
	}
	else {
		for (i = 0; i < n; ++i) {
			pom = a[i];
			for (j = i; j >= 1 && (*a[j - 1]) < *pom; --j)
				a[j] = a[j - 1];
			a[j] = pom;
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
	insertionSort(niz, n, smjer);
	for (i = 0; i < n; ++i)
		printf("%s \n", niz[i]);
	return 0;
}