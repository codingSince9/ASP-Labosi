#include <stdio.h>
#include <stdlib.h>

struct cv {
	float element;
	struct cv *sljed;
};
typedef struct cv cvor;

int upis(cvor **glava, cvor **rep, float broj) {
	cvor *novi;
	if ((novi = malloc(sizeof(cvor))) == NULL)
		return 0;
	novi->element = broj;
	novi->sljed = NULL;
	if (*glava == NULL) {
		*glava = novi;
		*rep = novi;
	}
	else {
		(*rep)->sljed = novi;
		*rep = novi;
	}
	return 1;
}
int main(void) {
	int n, i;
	float broj;
	cvor *glava = NULL;
	cvor *rep = NULL;
	cvor *ispis;
	cvor *brisi;
	do {
		printf("upisite broj brojeva: ");
		scanf("%d", &n);
	} while (n > 10);
	for (i = 0; i < n; ++i) {
		printf("upisite %d. broj: ", i + 1);
		scanf("%f", &broj);
		if (!upis(&glava, &rep, broj))
			printf("upisivanje nije uspjelo\n");
	}
	ispis = glava;
	while(ispis) {
		printf("%.2f ", ispis->element);
		brisi = ispis;
		ispis = ispis->sljed;
		free(brisi);
	}
	printf("\n");
	return 0;
}