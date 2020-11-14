#include <stdio.h>
#include <stdlib.h>

void selection2Sort(int *A, int n, char smjer) {
	int i, j, max[2];
	if (!smjer) {
		for (i = n - 1; i > 0; i--) {
			max[0] = 0;
			max[1] = A[0];
			for (j = 1; j <= i; j++) {
				if (A[j] > max[1]) {
					max[1] = A[j];
					max[0] = j;
				}
			}
			A[max[0]] = A[i];
			A[i] = max[1];
		}
	}
	else {
		for (i = n - 1; i > 0; i--) {
			max[0] = 0;
			max[1] = A[0];
			for (j = 1; j <= i; j++) {
				if (A[j] < max[1]) {
					max[1] = A[j];
					max[0] = j;
				}
			}
			A[max[0]] = A[i];
			A[i] = max[1];
		}
	}
}

int main(void) {
	int i, n, *polje, smjer;
	do {
		printf("upisite broj clanova polja: ");
		scanf("%d", &n);
	} while (n > 10 || n < 0);
	polje = malloc(sizeof(int)*n);
	for (i = 0; i < n; ++i) {
		printf("upisite %d. clan polja: ", i + 1);
		scanf("%d", &polje[i]);
	}
	printf("upisite smjer sorta(0=uzlazno, 1=silazno): ");
	scanf("%d", &smjer);
	selection2Sort(&polje[0], n, smjer);
	printf("\n sortirano polje: \n");
	for (i = 0; i < n; ++i)
		printf("%d", polje[i]);
	return 0;
}