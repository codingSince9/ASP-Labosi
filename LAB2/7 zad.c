#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct at {
	char cvor[40 + 1];
	struct at *sljed;
}; typedef struct at cvor;

int upis(cvor **glava, char *niz) {
	cvor *novi = malloc(sizeof(cvor));
	if (novi == NULL)
		return 0;
	strcpy(novi->cvor, niz);
	novi->sljed = *glava;
	*glava = novi;
	return 1;
}

int main(void) {
	cvor *glava = NULL;
	char niz[40];
	int n, i;
	do {
		printf("upisite broj znakovnih nizova: ");
		scanf("%d", &n);
	} while (n > 10);
	for (i = 0; i < n; ++i) {
		printf("upisite niz: \n");
		scanf("%s", niz);
		upis(&glava, niz);
	}
	printf("\n");
	if (upis) {
		for (; glava; glava = glava->sljed) {
			printf("%s\n", glava->cvor);
		}
	}
	return 0;
}