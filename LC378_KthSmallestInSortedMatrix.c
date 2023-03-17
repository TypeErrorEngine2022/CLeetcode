#include "Heap.h"
#include <stdio.h>

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    Heap* heap = createMinHeap(k);

    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
        insert(heap, matrix[i][j]);

    int res = -1;
    for (int i = 0; i < k; i++) {
        res = delMax(heap);
    }
    return res;
}

int main() {
    return 0;
}