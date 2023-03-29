#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int** data; //data[i] = pointer to {val, extra info1, extra info2...}
    int size; // since the element is 1-indexing, the last element is data[size - 1]
    int capacity;
    int isMinHeap;
    int elementSize;
}HeapForArray;

HeapForArray* createMinArrayHeap(int capacity, int elementSize) {
    HeapForArray* heap = (HeapForArray*)malloc(sizeof(HeapForArray));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> data = (int**)malloc((capacity) * sizeof(int*));
    memset(heap -> data, 0, capacity * sizeof(int*));
    heap -> isMinHeap = 1;
    heap -> elementSize = elementSize;
    return heap;
}

HeapForArray* createMaxArrayHeap(int capacity, int elementSize) {
    HeapForArray* heap = (HeapForArray*)malloc(sizeof(HeapForArray));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> data = (int**)malloc((capacity) * sizeof(int*));
    memset(heap -> data, 0, capacity * sizeof(int*));
    heap -> elementSize = elementSize;
    heap -> isMinHeap = 0;
    return heap;
}

// heap will be null after closeHeap
// FREE the arr by creator
void closeArrayHeap(HeapForArray* heap) {
    free(heap -> data);
    free(heap);
}

int getSizeForArrayHeap(HeapForArray* heap) {
    return heap -> size;
}

int isEmptyForArrayHeap(HeapForArray* heap) {
    return heap -> size == 0;
}

int* getRootForArrayHeap(HeapForArray* heap) {
    if (!isEmptyForArrayHeap(heap))
        return heap -> data[0];
    
    fprintf(stderr, "no root for empty heap\n");
    return NULL;
}

int** getDataForArrayHeap(HeapForArray* heap) {
    return heap -> data;
}

int isFullForArrayHeap(HeapForArray* heap) {
    return heap -> size == heap -> capacity;
}

int lessForArrayHeap(HeapForArray* heap, int i, int j) {
    //larger element has lower priority
    // so root will be the smallest element (highest priority)
    if (heap -> isMinHeap)
        return heap -> data[i][0] >= heap -> data[j][0];
    else 
        // smaller elements has lower priority
        // so root will be the largest element
        return heap -> data[i][0] <= heap -> data[j][0];
}

void swapForArrayHeap(HeapForArray* heap, int i, int j)
{
    int* tmp = heap -> data[j];
    heap -> data[j] = heap -> data[i];
    heap -> data[i] = tmp;
}

void sinkForArrayHeap(HeapForArray* heap, int index)
{
    while (2 * index + 1 < heap -> size)
    {
        int j = 2 * index + 1;

        //choose the larger children to compare with the parent
        if (j < heap -> size - 1 && lessForArrayHeap(heap, j, j + 1))
        {
            ++j;
        }
        //If it is larger than the largest children, do not sink 
        if (!lessForArrayHeap(heap, index, j))
        {
            break;
        }
        swapForArrayHeap(heap, index, j);
        index = j;
    }
}

void swimForArrayHeap(HeapForArray* heap, int index) {
    while (index > 0 && lessForArrayHeap(heap, (index - 1) / 2, index))
    {
        swapForArrayHeap(heap, (index - 1) / 2, index);
        index = (index - 1) / 2;
    }
}

// do not address situation when heap is full
void insertForArrayHeap(HeapForArray* heap, int* val) {
    if (!isFullForArrayHeap(heap)) {
        heap -> data[heap -> size] = val;
        heap -> size += 1;
        swimForArrayHeap(heap, heap -> size - 1);
    }
}

int* delMaxForArrayHeap(HeapForArray* heap) {
    int* max = heap -> data[0];
    //exchange with the last item, since last item has no children
    //less link to break
    // Also, the oldMax is put in the extra space in array
    // (heap) | (free space filled with max)
    // after all elements is deleted, the array is sorted in ascending order
    swapForArrayHeap(heap, 0, heap -> size - 1);
    heap -> size -= 1;
    sinkForArrayHeap(heap, 0);
    return max;
}

void printArrayHeap(HeapForArray* heap) {
    for (int i = 0; i < heap -> size; i++)
    {
        printf("(");
        for (int j = 0; j < heap -> elementSize; j++) {
            if (j != 0) printf(", ");
            printf("%d", heap -> data[i][j]);
        }
        printf(")");
    }
    printf("\n");
}


