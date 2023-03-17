#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MinPQ
typedef struct {
    int* data;
    int size; // since the element is 1-indexing, the last element is data[size], not data[size -1]
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

// heap will be null after closeHeap
// all resources of heap will be released
void closeHeap(Heap* heap) {
    free(heap -> data);
    free(heap);
}

int getSize(Heap* heap) {
    return heap -> size;
}

int isEmpty(Heap* heap) {
    return heap -> size == 0;
}

int getRoot(Heap* heap) {
    if (!isEmpty(heap))
        return heap -> data[1];
    
    fprintf(stderr, "no root for empty heap\n");
    return 1;
}

int isFull(Heap* heap) {
    return heap -> size == heap -> capacity;
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

// do not address situation when heap is full
void insert(Heap* heap, int val) {
    if (!isFull(heap))
        heap -> data[++(heap -> size)] = val;

    swim(heap, heap -> size);
}

int delMax(Heap* heap) {
    int max = heap -> data[1];
    //exchange with the last item, since last item has no children
    //less link to break
    // Also, the oldMax is put in the extra space in array
    // (heap) | (free space filled with max)
    // after all elements is deleted, the array is sorted in ascending order
    swap(heap, 1, (heap -> size)--);
    sink(heap, 1);

    return max;
}

// O(N)
Heap* heapify(int* arr, int size) {
    Heap* heap = createMaxHeap(size);
    int* data = (int*)malloc((size + 1) * sizeof(int));
    // change 0-indexing to 1-indexing
    memcpy(data + 1, arr, size * sizeof(int));
    heap -> data = data;
    for (int i = size / 2; i >= 1; i++) {
        sink(heap, i);
    }
    return heap;
}

// external arr is 0-indexing
// so parent = k, children = 2k + 1, 2k + 2
// find parent = (index - 1) / 2 
// to avoid (2k + 2) / 2 = k + 1 WRONG
void _sink(int* arr, int size, int index) {
    while (2 * index + 1 <= size - 1)
    {
        int j = 2 * index + 1;

        //choose the larger children to compare with the parent
        if (j < size - 1 && arr[j] < arr[j + 1])
        {
            ++j;
        }
        //If it is larger than the largest children, do not sink 
        if (arr[index] > arr[j])
        {
            break;
        }
        int tmp = arr[j];
        arr[j] = arr[index];
        arr[index] = tmp; 
        index = j;
    } 
}

// for 0-indexing arr
int _delMax(int* arr, int size) {
    int tmp = arr[size - 1];
    arr[size - 1] = arr[0]; 
    arr[0] = tmp;
    size--;
    _sink(arr, size, 0);
    return size;
}

// in-place
void heapSort(int* arr, int size) {
    // heapify: O(n)
    // second half of data is leaf node(must be heap)
    // start from data[size / 2], it is root of heap with size 3
    for (int index = (size - 1) / 2; index >= 0; index--)
        _sink(arr, size, index);

    while (size > 0)
    {
        size = _delMax(arr, size);
    }
}

void print(Heap* heap) {
    for (int i = 1; i <= heap -> size; i++)
    {
        printf("%d ", heap -> data[i]);
    }
    printf("\n");
}


