#include <stdio.h>
#include "Heap.h"

int solve(int* stones, int stonesSize, int curSize) {
    if (curSize == 1) {
        for (int i = 0; i < stonesSize; i++)
            if (stones[i] != 0) return stones[i];
    }

    printf("size: %d\n", curSize);
    for (int i = 0; i < stonesSize; i++) {
        printf("%d ", stones[i]);
    }
    printf("\n");
    int size = stonesSize;
    int firstmax = -1, secondmax = -1;
    int ix1 = 0, ix2 = 0;
    int i = 0;
    while (size > 0 && i < stonesSize) {
        printf("i: %d\n", i);
        if (stones[i] == 0) {
            i++;
            continue;
        }

        if (stones[i] > firstmax) {
            secondmax = firstmax;
            firstmax = stones[i];
            ix2 = ix1;
            ix1 = i;
        }
        else if (stones[i] > secondmax) {
            secondmax = stones[i];
            ix2 = i;
        }
        size--;
        i++;
    }
    printf("max1: %d, max2: %d\n", firstmax, secondmax);
    if (firstmax == secondmax) {
        stones[ix1] = stones[ix2] = 0;
        curSize -= 2;
    }
    else {
        stones[ix1] = firstmax - secondmax;
        stones[ix2] = 0;
        curSize--;
    }
    if (curSize == 0) return 0;
    return solve(stones, stonesSize, curSize);
}


/*int lastStoneWeight(int* stones, int stonesSize){
    return solve(stones, stonesSize, stonesSize);
}*/

int lastStoneWeight(int* stones, int stonesSize){
    if (stonesSize == 1) return stones[0];
    Heap* heap = heapify(stones, stonesSize);
    while (getSize(heap) > 1) {
        int max1 = delMax(heap);
        int max2 = delMax(heap);
        if (max1 > max2)
            insert(heap, max1 - max2);
    }
    int res = 0;
    if (getSize(heap) == 1)
        res = getRoot(heap);
    closeHeap(heap);
    return res;
}

int main() {
    int arr[6] = {2,7,4,1,8,1};
    printf("%d\n", lastStoneWeight(arr, 6));
    return 0;
}