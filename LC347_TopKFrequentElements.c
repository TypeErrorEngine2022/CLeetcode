#include <stdio.h>
#include "HashTableForInt.h"
#include "LinkedList.h"

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = k;
    int* res = (int*)malloc(k * sizeof(int));
    memset(res, 0, k * sizeof(int));
    HashTableForInt* table = createHashTableForInt(numsSize * 1.7);

    for (int i = 0; i < numsSize; i++) {
        insertForIntHashTable(table, nums[i], getForIntHashTable(table, nums[i]) + 1);
    }
    printHashTableForInt(table);

    List** bucket = (List**)malloc((numsSize + 1) * sizeof(List*)); // max freq = size -> arr size = max freq + 1;
    memset(bucket, 0, (numsSize + 1) * sizeof(List*));
    HashTableIterator* iter = createHashTableIterator();

    while(iter -> count < table -> size) {
        ht_item* item = nextElement(table, iter);
        int freq = item -> val;
        if (bucket[freq] == NULL) 
            bucket[freq] = createList();
        push_front(bucket[freq], item -> key);
    }

    int sz = 0;
    for (int i = numsSize; i >= 0; i--) {
        if (bucket[i] == NULL) continue;
        if (sz == k) break;

        while (!empty(bucket[i]) && sz < k) {
            res[sz++] = pop_front(bucket[i]);
        }
    }
            
    return res; 
}

int main() {
    int arr[6] = {-1, -1};
    int returnSize;
    int* res = topKFrequent(arr, 2, 1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}