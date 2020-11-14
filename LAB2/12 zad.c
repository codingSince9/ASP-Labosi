#include <stdio.h>		
#include <stdlib.h>
#include <math.h>
void ShellSort_Hibbard(char **A, int N, int smjer);
int main(){
	int n, smjer, i;
	char *nizovi[10];
	do {
		printf("\nKoliko elemenata zelite: ");
		scanf("%d", &n);
	} while (!(n >= 1 && n <= 10));
	printf("\nKoji smjer zelite ?");
	scanf("%d", &smjer);
	for (i = 0; i < n; i++){
		printf("\nUpisite %d. niz:", i + 1);
		nizovi[i] = (char*)malloc(40 * sizeof(char));
		scanf("%s", nizovi[i]);
	}
	ShellSort_Hibbard(nizovi, n, smjer);
	printf("\nPoslije sortiranja :");
	for (i = 0; i < n; i++){
		printf("\n%s", nizovi[i]);
		free(nizovi[i]);
	}
	return 0;
}
void ShellSort_Hibbard(char **A, int N, int smjer) {
	char *pom;
	int i, j, korak, pot = 1, k;
	for (i = 2; true; i++){
		if ((pow(2, i) - 1) >= N)
			pot = i;
		else
			break;
	}
	if (smjer) {
		for (k = pot; k >= 1; k--){
			korak = pow(2, k) - 1;
			for (i = 1; i < N; i += korak){
				pom = A[i];
				for (j = i; j > korak - 1; j -= korak){
					if (*(A[j]) < *(A[j - korak]))
						A[j] = A[j - korak];
					else
						break;
				}
				A[j] = pom;
			}
		}
	}
	else{
		for (k = pot; k >= 1; k--){
			korak = pow(2, k) - 1;
			for (i = 1; i < N; i += korak){
				pom = A[i];
				for (j = i; j > korak - 1; j -= korak){
					if (*(A[j]) > *(A[j - korak]))
						A[j] = A[j - korak];
					else
						break;
				}
				A[j] = pom;
			}
		}
	}
}