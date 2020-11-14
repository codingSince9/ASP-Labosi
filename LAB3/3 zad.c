#include <stdio.h>
#include <stdlib.h>

struct cvor {
	float broj;
	struct cvor *sljed;
};
typedef struct cvor cvor;

struct Red {
	cvor *ulaz;
	cvor *izlaz;
};
typedef struct Red Red;

void init_red(Red *red) {
	red->ulaz = NULL;
	red->izlaz = NULL;
}

int dodajURed(double broj, Red *red) {
	cvor *novi;
	novi = malloc(sizeof(cvor));
	if (novi == NULL)
		return 0;
	novi->broj = broj;
	novi->sljed = NULL;
	if (red->izlaz == NULL)
		red->izlaz = novi;
	else
		(red->ulaz)->sljed = novi;
	red->ulaz = novi;
	return 1;
}

int main(void) {
	int i, n;
	float broj;
	Red red;
	init_red(&red);
	printf("upisi broj clanova: ");
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		printf("upisi %d. clan: ", i + 1);
		scanf("%f", &broj);
		if (!dodajURed(broj, &red))
			return 1;
		printf("%.2f\n", red.ulaz->broj);
	}
	return 0;
}