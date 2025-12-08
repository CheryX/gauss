#include "backsubst.h"
#include <math.h>

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	if (b->c != 1 || x->c != 1) {
		return 2; // Sprawdzanie czy macierz wyniku i wartości mają 1 kolumne.
	}

	if (mat->r != mat->c || mat->r != b->r || mat->r != x->r) {
		return 2; // Sprawdzanie poprawności wymiarów macierzy względem siebie
	}

	int n = mat->r;

	for (int i = n - 1; i >= 0; i--) {
		// Sprawdzenie czy element na diagonali nie jest zerem
		if (fabs(mat->data[i][i]) < 1e-12) {
			return 1; // Macierz osobliwa
		}

		double s = 0;
		for (int j = i + 1; j < n; j++) {
			s += mat->data[i][j] * x->data[j][0];
		}

		x->data[i][0] = (b->data[i][0] - s) / mat->data[i][i];
	}

	return 0;
}


