#include "HeapForArray.h"
#include <limits.h>

// O(nlogk)
/**int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){
    if (k == numsSize) {
        int* res = (int*)malloc(k * sizeof(int));
        memcpy(res, nums, numsSize * sizeof(int));
        *returnSize = k;
        return res;
    }
    *returnSize = 0;
    HeapForArray* heap = createMinArrayHeap(k, 2);
    for (int i = 0; i < numsSize; i++) {
        if (getSizeForArrayHeap(heap) == k) {
            if (nums[i] >= getRootForArrayHeap(heap)[0]) {
                int* max = delMaxForArrayHeap(heap);
                nums[max[1]] = INT_MIN;
                // if not free, it will be covered by new data
                // dangling pointer
                free(max); 
            }
            else 
                nums[i] = INT_MIN;
        }
        int* arr = (int*)malloc(2 * sizeof(int));
        arr[0] = nums[i];
        arr[1] = i;
        insertForArrayHeap(heap, arr);
    }
    int* res = (int*)malloc(k * sizeof(int));
    int pt = 0;
    for (int i = 0; i < numsSize && pt < k; i++)
        if (nums[i] != INT_MIN)
            res[pt++] = nums[i];
    *returnSize = k;
    closeHeapForArray(heap);
    return res;
}**/

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){
    if (k == numsSize) {
        int* res = (int*)malloc(k * sizeof(int));
        memcpy(res, nums, numsSize * sizeof(int));
        *returnSize = k;
        return res;
    }

    // copy of nums for quickselect to modify
    int* arr = (int*)malloc(numsSize * sizeof(int));
    memcpy(arr, nums, numsSize * sizeof(int));
    int pivotIx = quickSelect(arr, numsSize, k);
    int freqOfKth = 1;
    for (int i = 0; i < pivotIx; i++) {
        if (arr[i] == arr[pivotIx])
            freqOfKth++;
    }
    int* res = (int*)malloc(k * sizeof(int));
    int pt = 0;
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] == arr[pivotIx] && freqOfKth == 1) ||
            nums[i] > arr[pivotIx]) {
            res[pt++] = nums[i];
        }
        else if (nums[i] == arr[pivotIx])
            freqOfKth--;
    }
    free(arr);
    *returnSize = k;
    return res;
}
        


int main() {
    int arr[4] = {-1, -2, 3, 4};
    int size = 0;
    int* maxsub = maxSubsequence(arr, 4, 3, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", maxsub[i]);
    }
    printf("\n");
    return 0;
}