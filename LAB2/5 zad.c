#include <stdio.h>
#include <stdlib.h>

void spojiNizove(char *a, char *b, char *rez) {
	int i, j = 0;
	for (i = 0; i < 10; ++i, ++j) {
		if (a[j] > b[j]) {
			rez[i] = a[j];
			++i;
			rez[i] = b[j];
		}
		else {
			rez[i] = b[j];
			++i;
			rez[i] = a[j];
		}
	}
}

int main(void) {
	char a[] = "ecaDB";
	char b[] = "dbECA";
	char *rez;
	rez = malloc(sizeof(char) * 11);
	spojiNizove(a, b, rez);
	printf("%s\n", rez);
	return 0;
}