#include "gauss.h"
#include <math.h>
// #include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *A, Matrix *B) {

	int n = A->r;

	for (int k = 0; k < n - 1; k++) {
		// Sprawdzenie czy element na diagonali nie jest zerem
		if (fabs(A->data[k][k]) < 1e-12) {
			return 1; // Macierz osobliwa
		}

		for (int i = k + 1; i < n; i++) {
			double factor = A->data[i][k] / A->data[k][k];

			for (int j = k; j < n; j++) {
				A->data[i][j] -= factor * A->data[k][j];
			}
			B->data[i][0] -= factor * B->data[k][0];
		}
	}

	// TESTY: Wyswietlanie macierzy
	// for (int i = 0; i < A->r; i++) {
	// 	for (int j = 0; j < A->c; j++)
	// 		printf("%f ", A->data[i][j]);
	// 	printf("| %f\n", B->data[i][0]);
    // }

    return 0;
}

