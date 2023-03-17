#include "Heap.h"
#include <stdio.h>

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    // reserve 1 place for the new element
    Heap* heap = createMaxHeap(k + 1);

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            // so the root is the k-th smallest element
            // k-th smallest = k-th element in ascending order
            // let the new element swim first
            // since the new element may be the right one
            insert(heap, matrix[i][j]);
            // the (k+1)th smallest element(new root) will always be removed
            // the heap size is kept <= k
            if (getSize(heap) > k)
                delMax(heap);
        }
    }

    int res = getRoot(heap);
    closeHeap(heap);
    return res;
}

int main() {
    return 0;
}