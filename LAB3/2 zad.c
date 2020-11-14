#include <stdio.h>
#define MAX 10

struct Red {
	double polje[MAX];
	int ulaz;
	int izlaz;
};
typedef struct Red Red;

void init_red(Red *red) {
	red->ulaz = 0;
	red->izlaz = 0;
}

int dodajURed(double broj, Red *red) {
	if ((red->ulaz + 1) % MAX == red->izlaz)
		return 0;
	red->ulaz++;
	red->ulaz %= MAX;
	red->polje[red->ulaz] = broj;
	return 1;
}

int skiniIzReda(double *broj, Red *red) {
	if (red->ulaz == red->izlaz)
		return 0;
	red->izlaz++;
	red->izlaz %= MAX;
	*broj = red->polje[red->izlaz];
	return 1;
}

int main(void) {
	int n, i;
	double broj;
	Red red;
	init_red(&red);
	do {
		printf("upisite broj clanova: ");
		scanf("%d", &n);
	} while (n > 10);
	for (i = 0; i < n; ++i) {
		printf("upisite %d. clan: ", i + 1);
		scanf("%lf", &broj);
		dodajURed(broj, &red);
	}
	for (i = 0; i < n; ++i) {
		skiniIzReda(&broj, &red);
		printf("skinuti clan: %.2f\n", broj);
	}
	return 0;
}