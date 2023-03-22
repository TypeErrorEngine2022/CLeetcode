#include "Heap.h"

typedef struct {
    Heap* heap;
    int k;
} KthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj -> heap = createMinHeap(k+1);
    obj -> k = k;
    for (int i = 0; i < numsSize; i++) {
        insert(obj -> heap, nums[i]);
        if (getSize(obj -> heap) > k)
            delMax(obj -> heap);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    // only when size == k - 1
    // assumed to have k data after add()
    if (getSize(obj -> heap) < obj -> k) {
        insert(obj -> heap, val);
    }
    else {
        // if smaller than cur k-th largest
        // impossible to be the new k-th largest
        if (val > getRoot(obj -> heap)) {
            insert(obj -> heap, val);
            delMax(obj -> heap);
        }
    }
    return getRoot(obj -> heap);
}

void kthLargestFree(KthLargest* obj) {
    closeHeap(obj -> heap);
    free(obj);
}

int main() {
    int arr[4] = {4,5,8,2};
    KthLargest* obj = kthLargestCreate(3, arr, 4);
    printf("%d", kthLargestAdd(obj, 3));
    return 0;
}