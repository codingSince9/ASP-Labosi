#include <stdio.h>
#include <stdlib.h>

void spojiPolja(int *a, int *b, int *rez, int n1, int n2) {
	int i = 0, j = 0;
	while (n1 != 0 && n2 != 0) {
		if (a[i] > b[j]) {
			rez[i + j] = a[i];
			i++;
			n1--;
		}
		else {
			rez[i + j] = b[j];
			j++;
			n2--;
		}
	}
}

int main(void) {
	int i, *rez;
	int a[] = { 9,7,5,3,1 };
	int b[] = { 8,6,4,2,0 };
	rez = malloc(sizeof(int) * 11);
	spojiPolja(&a[0], &b[0], &rez[0], 5, 5);
	for (i = 0; i < 10; ++i) {
		printf("%d", rez[i]);
	}
	return 0;
}