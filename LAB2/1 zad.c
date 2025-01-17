#include <stdio.h>
#include <stdlib.h>

struct zap {
	int broj;
	char mjesto[40 + 1];
}; typedef struct zap zapis;

void insertionSort(zapis *A, int n, char smjer) {
	int i, j;
	zapis pom;
	if (smjer == '0') {
		for (i = 1; i < n; i++) {
			pom = A[i];
			for (j = i; j >= 1 && A[j - 1].broj >= pom.broj; j--)
				A[j] = A[j - 1];
			A[j] = pom;
		}
	}
	else {
		for (i = 1; i < n; ++i) {
			pom = A[i];
			for (j = i; j >= 1 && A[j - 1].broj <= pom.broj; j--)
				A[j] = A[j - 1];
			A[j] = pom;
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
		printf("upisite %d. postanski broj: ", i + 1);
		scanf("%d", &A[i].broj);
		printf("upisite %d. naziv mjesta: ", i + 1);
		scanf("%s", &A[i].mjesto);
	}
	printf("\n");
	printf("upisite smjer sortiranja (0=uzlazno, 1=silazno): ");
	getchar();
	scanf("%c", &smjer);
	insertionSort(&A[0], n, smjer);
	for (i = 0; i < n; ++i) {
		printf("%d ", A[i].broj);
		printf("%s \n", A[i].mjesto);
	}
	return 0;
}