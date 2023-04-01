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
