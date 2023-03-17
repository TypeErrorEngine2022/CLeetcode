#include "Heap.h"
#include "HeapForArray.h"
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

// leverage the fact that each row in matrix is sorted
int kthSmallestSecondVersion(int** matrix, int matrixSize, int* matrixColSize, int k){
    HeapForArray* heap = createMinArrayHeap(k);
    for (int i = 0; i < matrixSize; i++) {
        int* arr = (int*)malloc(3 * sizeof(int));
        arr[0] = matrix[i][0];
        arr[1] = i;
        arr[2] = 0;
        insertForArrayHeap(heap, arr);
    }

    int* min = NULL;
    while (k--) {
        min = delMaxForArrayHeap(heap); // each time pop the i-th smallest element, i in [1,k]
        int minrow = min[1];
        int mincol = min[2];
        if (mincol + 1 < matrixSize) {
            int* arr = (int*)malloc(3 * sizeof(int));
            arr[0] = matrix[minrow][mincol + 1];
            arr[1] = minrow;
            arr[2] = mincol + 1;
            insertForArrayHeap(heap, arr);
        }
    }
    closeHeapForArray(heap);
    return min[0];
}
         

int main() {
    return 0;
}