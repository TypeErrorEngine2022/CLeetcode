#include "Heap.h"

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) return NULL;
    HeapForArray* heap = createMinArrayHeap(listsSize, 2);
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res -> next = NULL;
    struct ListNode* prev = res; 

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) continue;
        int* tmp = (int*)malloc(2 * sizeof(int));
        tmp[0] = lists[i] -> val;
        tmp[1] = i;
        lists[i] = lists[i] -> next;
        insertForArrayHeap(heap, tmp);
    }

    if (isEmptyForArrayHeap(heap)) return NULL;

    while (getSizeForArrayHeap(heap)) {
        int* root = delMaxForArrayHeap(heap);
        struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur -> val = root[0];
        cur -> next = NULL;
        prev -> next = cur;
        prev = cur;
        int index = root[1];
        free(root);

        if (lists[index] != NULL) {
            int* tmp = (int*)malloc(2 * sizeof(int));
            tmp[0] = lists[index] -> val;
            tmp[1] = index;
            lists[index] = lists[index] -> next;
            insertForArrayHeap(heap, tmp);
        }
    }
    struct ListNode* ans = res -> next;
    free(res);
    prev = NULL;
    closeArrayHeap(heap);
    return ans;
}