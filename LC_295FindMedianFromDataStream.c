#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Heap* minHeap;
    Heap* maxHeap;
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder* mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf -> minHeap = createMinHeap(25010);
    mf -> maxHeap = createMaxHeap(25010);
    return mf;
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (getSize(obj -> minHeap) == getSize(obj -> maxHeap)) {
        int root1 = getRoot(obj -> minHeap);
        int root2 = getRoot(obj -> maxHeap);
        return (root1 + root2) / 2.0;
    }

    int diff = getSize(obj -> maxHeap) - getSize(obj -> minHeap);
    switch(diff) {
        case 1:
            return getRoot(obj -> maxHeap);
        case -1:
            return getRoot(obj -> minHeap);
    }

    return 0;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    double median;
    // insert to maxHeap first
    if (getSize(obj -> minHeap) == getSize(obj -> maxHeap) 
            && getSize(obj -> minHeap) == 0) 
        median = INT_MAX;
    else 
        median = medianFinderFindMedian(obj);

    if ((double)num > median)
        insert(obj -> minHeap, num);
    else   
        insert(obj -> maxHeap, num);

    // check unbalance
    // height of two heaps can only differ by 1
    int diff = getSize(obj -> maxHeap) - getSize(obj -> minHeap);
    switch (diff) {
        case 2:
            insert(obj -> minHeap, delMax(obj -> maxHeap));
            break;
        case -2:
            insert(obj -> maxHeap, delMax(obj -> minHeap));
            break;
    }
}


void medianFinderFree(MedianFinder* obj) {
    closeHeap(obj -> minHeap);
    closeHeap(obj -> maxHeap);
    free(obj);
}