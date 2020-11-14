#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zamijeni(char *prvi, char *drugi) {
	char pom;
	pom = *prvi;
	*prvi = *drugi;
	*drugi = pom;
}

void selectionSort(char **a, int n, int smjer) {
	int i, j, min, max;
	for (i = 0; i < n; ++i) {
		min = i;
		max = i;
		for (j = i + 1; j < n; ++j) {
			if (strcmp(a[j], a[min])<0)
				min = j;
			else if (strcmp(a[j], a[max]) > 0) max = j;
		}
		if (smjer)
			zamijeni(&a[i], &a[min]);
		else
			zamijeni(&a[i], &a[max]);
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
	selectionSort(niz, n, smjer);
	for (i = 0; i < n; ++i)
		printf("%s \n", niz[i]);
	return 0;
}