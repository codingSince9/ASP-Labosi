#include <stdio.h>
#include <stdlib.h>

struct at {
	int broj;
	struct at *sljed;
}; typedef struct at cvor;

int upis(cvor **glava, int element) {
	cvor *novi = malloc(sizeof(cvor));
	if (novi == NULL)
		return 0;
	if (*glava == NULL) {
		novi->broj = element;
		novi->sljed = NULL;
		*glava = novi;
	}
	else if (element <= (*glava)->broj) {
		novi->broj = element;
		novi->sljed = *glava;
		*glava = novi;
	}
	else {
		while (element > (*glava)->broj) {
			glava = &((*glava)->sljed);
			if (*glava == NULL)
				break;
		}
		novi->broj = element;
		novi->sljed = *glava;
		*glava = novi;		
	}
	return 1;
}

int main(void) {
	cvor *glava = NULL;
	int broj;
	int n, i;
	do {
		printf("upisite broj brojeva: ");
		scanf("%d", &n);
	} while (n > 10);
	for (i = 0; i < n; ++i) {
		printf("upisite broj: \n");
		scanf("%d", &broj);
		upis(&glava, broj);
	}
	printf("\n");
	if (upis) {
		for (; glava; glava = glava->sljed) {
			printf("%d\n", glava->broj);
		}
	}
	return 0;
}