#include <stdio.h>
#include <stdlib.h>

struct zap {
	int sifra;
	char naziv[40 + 1];
}; typedef struct zap zapis;

void Zamijeni(zapis *a, zapis *b) {
	zapis pom;
	pom = *a;
	*a = *b;
	*b = pom;
	return;
}

void obicanBubbleSort(zapis *A, int n, char smjer) {
	int i, j;
	if (smjer == '0') {
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < (n - i - 1); j++) {
				if (A[j + 1].sifra < A[j].sifra)
					Zamijeni(A + j, A + j + 1);
			}
		}
	}
	else {
		for (i = 0; i < n - 1; i++) {
			for (j = 0; j < (n - i - 1); j++) {
				if (A[j + 1].sifra > A[j].sifra)
					Zamijeni(A + j, A + j + 1);
			}
		}
	}
}

int main(void) {
	char smjer;
	int n, i;
	zapis *A;
	do {
		printf("upisite zeljeni broj zapisa: ");
		scanf("%d", &n);
	} while (n >= 10 || n < 0);
	A = (zapis*)malloc(sizeof(zapis)*n);
	for (i = 0; i < n; ++i) {
		printf("upisite %d. sifru jela: ", i + 1);
		scanf("%d", &A[i].sifra);
		printf("upisite %d. naziv jela: ", i + 1);
		scanf("%s", A[i].naziv);
	}
	printf("upisite smjer sortiranja (0=uzlazno, 1=silazno): ");
	getchar();
	scanf("%c", &smjer);
	obicanBubbleSort(&A[0], n, smjer);
	for (i = 0; i < n; ++i) {
		printf("%d ", A[i].sifra);
		printf("%s \n", A[i].naziv);
	}
	return 0;
}