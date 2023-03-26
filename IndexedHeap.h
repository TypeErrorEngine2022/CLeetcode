#pragma once

// Each element(item with priorities) has a key(name)
typedef struct {
    // items[1] = item for key 1
    int* items;
    // keys[1] = key for 1st node
    // it represents the heap
    // although priorities are sorted by items!!
    // key[0] = key with highest priorities
    int* keys;
    // pm[1] = node number for key 1 in the heap(keys)
    // position map
    int* pm;

    int size;
    int capacity;
    int isMinHeap;
}IndexedHeap;


IndexedHeap* createIndexedHeap(int capacity, int isMinHeap) {
    IndexedHeap* heap = (IndexedHeap*)malloc(sizeof(IndexedHeap));
    heap -> size = 0;
    heap -> capacity = capacity;
    heap -> items = (int*)malloc((capacity) * sizeof(int));
    heap -> keys = (int*)malloc((capacity) * sizeof(int));
    heap -> pm = (int*)malloc((capacity) * sizeof(int));
    heap -> isMinHeap = isMinHeap;
    return heap;
}

// heap will be null after closeIndexedHeap
// all resources of heap will be released
// DO NOT use closeheap when the heap is from heapify
void closeIndexedHeap(IndexedHeap* heap) {
    free(heap -> data);
    free(heap);
}

int getSize(IndexedHeap* heap) {
    return heap -> size;
}

int isEmpty(IndexedHeap* heap) {
    return heap -> size == 0;
}

int getRoot(IndexedHeap* heap) {
    if (!isEmpty(heap))
        return heap -> items[heap -> keys[0];
    
    fprintf(stderr, "no root for empty heap\n");
    return 1;
}

int isFullForIndexedHeap(IndexedHeap* heap) {
    return heap -> size == heap -> capacity;
}

int lessForIndexedHeap(IndexedHeap* heap, int i, int j) {
    //larger element has lower priority
    // so root will be the smallest element (highest priority)
    if (heap -> isMinHeap)
        return heap -> items[i] >= heap -> items[j];
    else 
        // smaller elements has lower priority
        // so root will be the largest element
        return heap -> items[i] <= heap -> items[j];
}

void helperSwap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = arr[i];
}

void swapForIndexedHeap(IndexedHeap* heap, int i, int j)
{
    int key1 = heap -> keys[i];
    int key2 = heap -> keys[j];

    helperSwap(heap -> keys, i, j);
    helperSwap(heap -> pm, key1, key2);
}

void sinkForIndexedHeap(IndexedHeap* heap, int index)
{
    while (2 * index + 1 < heap -> size)
    {
        int j = 2 * index + 1;

        //choose the larger children to compare with the parent
        if (j < heap -> size - 1 && lessForIndexedHeap(heap, j, j + 1))
        {
            ++j;
        }
        //If it is larger than the largest children, do not sink 
        if (!lessForIndexedHeap(heap, index, j))
        {
            break;
        }
        swapForIndexedHeap(heap, index, j);
        index = j;
    }
}

void swimForIndexedHeap(IndexedHeap* heap, int index) {
    while (index > 0 && less(heap, (index - 1) / 2, index))
    {
        swapForIndexedHeap(heap, (index - 1) / 2, index);
        index = (index - 1) / 2;
    }
}

// do not address situation when heap is full
void insertForIndexedHeap(IndexedHeap* heap, int item, int key) {
    if (!isFull(heap)) {
        heap -> items[key] = items;
        heap -> keys[heap -> size] = val;
        heap -> pm[key] = heap -> size;
        heap -> size += 1;
        swimForIndexedHeap(heap, heap -> size - 1);
    }
}

// return the value of item with highest priority key
int delMaxForIndexedHeap(IndexedHeap* heap) {
    int maxKey = heap -> keys[0];
    int max = heap -> items[maxKey];
    //exchange with the last item, since last item has no children
    //less link to break
    // Also, the oldMax is put in the extra space in array
    // (heap) | (free space filled with max)
    // after all elements is deleted, the array is sorted in ascending order
    swapForIndexedHeap(heap, 0, heap -> size - 1);
    heap -> size -= 1;
    sinkForIndexedHeap(heap, 0);
    // mark the key as invalid
    heap -> pm[heap -> keys[heap -> size + 1]] = -1;
    heap -> 
    return max;
}

// O(N)
IndexedHeap* heapify(int* arr, int size, int isMinIndexedHeap) {
    IndexedHeap* heap = (IndexedHeap*)malloc(sizeof(IndexedHeap));
    heap -> data = arr;
    heap -> capacity = size; 
    heap -> size = size;
    heap -> isMinIndexedHeap = isMinIndexedHeap;
    for (int i = (size - 1) / 2; i >= 0; i--)
        sink(heap, i);
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

void print(IndexedHeap* heap) {
    for (int i = 0; i <= heap -> size; i++)
    {
        printf("%d ", heap -> data[i]);
    }
    printf("\n");
}


