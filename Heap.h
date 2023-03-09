#pragma once

#include <stdio.h>
#include <stdlib.h>

// MinPQ
typedef struct BinaryHeap {
    int* data;
    int size;
    int capacity;
    int isMinHeap;
}Heap;

Heap* createMinHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> data = (int*)malloc((capacity + 1) * sizeof(int));
    heap -> isMinHeap = 1;
    return heap;
}

Heap* createMaxHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> data = (int*)malloc((capacity + 1) * sizeof(int));
    heap -> isMinHeap = 0;
    return heap;
}

int getSize(Heap* heap) {
    return heap -> size;
}

int isEmpty(Heap* heap) {
    return heap -> size == 0;
}

int less(Heap* heap, int i, int j) {
    //larger element has lower priority
    // so root will be the smallest element (highest priority)
    if (heap -> isMinHeap)
        return heap -> data[i] >= heap -> data[j];
    else 
        // smaller elements has lower priority
        // so root will be the largest element
        return heap -> data[i] <= heap -> data[j];
}

void swap(Heap* heap, int i, int j)
{
    int tmp = heap -> data[j];
    heap -> data[j] = heap -> data[i];
    heap -> data[i] = tmp;
}

void sink(Heap* heap, int index)
{
    while (2 * index <= heap -> size)
    {
        int j = 2 * index;

        //choose the larger children to compare with the parent
        if (j < heap -> size && less(heap, j, j + 1))
        {
            ++j;
        }
        //If it is larger than the largest children, do not sink 
        if (!less(heap, index, j))
        {
            break;
        }
        swap(heap, index, j);
        index = j;
    }
}

void swim(Heap* heap, int index) {
    while (index > 1 && less(heap, index / 2, index))
    {
        swap(heap, index / 2, index);
        index = index / 2;
    }
}

void insert(Heap* heap, int val) {
    heap -> data[++(heap -> size)] = val;
    swim(heap, heap -> size);
}

int delMax(Heap* heap) {
    int max = heap -> data[1];
    //exchange with the last item, since last item has no children
    //less linindex to breaindex
    swap(heap, 1, heap -> size--);
    sink(heap, 1);

    return max;
}

int* sort(Heap* heap)
{
    int size = heap -> size;
    //build max-heap : O(n)
    for (int i = heap -> size / 2; i >= 1; i--)
    {
        sink(heap, i);
    }

    while (size > 1)
    {
        swap(heap, 1, size--);
        sink(heap, 1);
    }

    return heap -> data;
}

void print(Heap* heap) {
    for (int i = 1; i <= heap -> size; i++)
    {
        printf("%d ", heap -> data[i]);
    }
    printf("\n");
}


