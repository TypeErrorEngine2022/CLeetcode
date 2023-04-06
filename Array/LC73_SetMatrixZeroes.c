#include <stdlib.h>

// Time O(n), Space O(m + n)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	int* row = (int*)calloc(matrixSize, sizeof(int));
	int* col = (int*)calloc(*matrixColSize, sizeof(int));

	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < *matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				row[i] = col[j] = 1;
			}
		}
	}

	for (int r = 0; r < matrixSize; r++) {
		if (row[r])
			memset(matrix[r], 0, *matrixColSize * sizeof(int));
	}

	for (int c = 0; c < *matrixColSize; c++) {
		if (col[c]) {
			for (int r = 0; r < matrixSize; r++)
				matrix[r][c] = 0;
		}
	}

	free(row);
	free(col);
}

// Time: O(m * n), Space O(m + n)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
	int fCol = 0; // whether first col is marked
	int fRow = 0; // whether first row is marked

	for (int i = 0; i < matrixSize; i++) {
			if (matrix[i][0] == 0) {// loop through rows
					fCol = 1;
					break; // save time
			}
	}

	for (int i = 0; i < *matrixColSize; i++) {
		if (matrix[0][i] == 0) {// loop through cols
				fRow = 1;
				break;
		}
	}

	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < *matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0; // marker
				matrix[0][j] = 0; 
			}
		}
	}

	for (int i = 1; i < matrixSize; i++) {
		for (int j = 1; j < *matrixColSize; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}

	if (fCol) {
		for (int r = 0; r < matrixSize; r++)
			matrix[r][0] = 0;
	}

	if (fRow) {
		for (int c = 0; c < *matrixColSize; c++)
			matrix[0][c] = 0;
	}
}
