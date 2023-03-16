#include "Heap.h"
#include <stdio.h>

void testInsert() {
    Heap* heap = createMaxHeap(5);
    for (int i = 5; i >= 1; i--) {
        insert(heap, i);
    }
    print(heap);
}

void testsort() {
    int arr[7] = {7,5,3,4,1,6,2};
    heapSort(arr, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    testsort();
}