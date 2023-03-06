#ifndef TREENODEARRAYLIST_H
#define TREENODEARRAYLIST_H
#include "TreeNode.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNodeArrayList_s
{
    struct TreeNode** data;
    int head;
    int rear;
    int num; // number of elements in queue
    int size;// max size of list
}TreeNodeArrayList;


TreeNodeArrayList* createTreeNodeArrayList(int capacity) {
    struct TreeNode** data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    TreeNodeArrayList* list = (TreeNodeArrayList*)malloc(sizeof(TreeNodeArrayList));
    if (list == NULL) return 0;
    list -> data = data;
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
    list -> size = capacity;
    return list;
}

void reallocate(TreeNodeArrayList* list, int capacity) {
    if (list -> size < capacity) {
        //printf("list size is %d\n", list -> size);
        //printf("no need reallocate, capacity is %d\n", capacity);
        struct TreeNode** newData = (struct TreeNode**)realloc(list -> data, capacity * sizeof(struct TreeNode*));
        if (newData == NULL) printf("Not enough space\n");
        list -> data = newData;
        return;
    }

    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
    list -> size = capacity;
}

int getSize(TreeNodeArrayList* list) {
    return list -> num;
}

int empty(TreeNodeArrayList* list) {
    return list -> num == 0;
}

int isFull(TreeNodeArrayList* list) {
    return list -> num == list -> size;
}

struct TreeNode* getFront(TreeNodeArrayList* list) {
    if (!empty(list)) {
        return list -> data[list -> head];
    }
    else return NULL;
}

struct TreeNode* getEnd(TreeNodeArrayList* list) {
    if (!empty(list)) {
        return list -> data[list -> rear];
    }
    else return NULL;
}

int push_front(TreeNodeArrayList* list, struct TreeNode* val) {
    if (!isFull(list)) {
        // empty list
        if (list -> head == -1) {
            list -> head = 0;
            list -> rear = 0;
        } 
        // one element
        else if (list -> head == 0) {
            list -> head = list -> size - 1;
        }
        else {
            (list -> head)--;
        }

        list -> data[list -> head] = val;
        //printf("list -> head is %d to ", list -> head);
        /*list -> head = (list -> head - 1) % (list -> size); // mod
        if (list -> head < 0) list -> head *= -1;
        //printf("%d\n", list -> head);
        list -> data[list -> head] = val;*/
        (list -> num)++;
        return 1;
    }
    else return 0; 
}

struct TreeNode* pop_front(TreeNodeArrayList* list) {
    if (!empty(list)) {
        struct TreeNode* val = getFront(list);
        // only one element
        // cannot increment pointer, list -> data[1] and onwards are garbage values
        if (list -> head == list -> rear) {
            list -> head = -1;
            list -> rear = -1;
        }
        // eg. [rear, NULL, NULL, head]
        else if (list -> head == list -> size - 1) {
            list -> head = 0;
        }
        else {
            (list -> head)++;
        }
        //printf("list -> head is %d\n", list -> head);
        /*list -> head = (list -> head + 1) % (list -> size); // mod
        if (list -> head < 0) list -> head *= -1;*/
        (list -> num)--;
        return val;
    } 
    printf("cannot pop empty arraylist\n");
    return NULL;
}

void printTreeNodeArrayList(TreeNodeArrayList* list) {
    for (int i = 0; i < list -> size; i++) {
        printf("%d ", list -> data[(i + list -> head) % (list -> size)] -> val);
    }
}

int push_back(TreeNodeArrayList* list, struct TreeNode* val) {
    if (!isFull(list)) {
        // empty list
        if (list -> head == -1) {
            list -> head = 0;
            list -> rear = 0;
        }
        // rear == size - 1 does not imply full
        // eg. original: [NULL, NULL, head, val, val, rear]
        // after: [rear, NULL, head, val, val, val]
        else if (list -> rear == list -> size - 1) {
            list -> rear = 0;
        }
        else {
            (list -> rear)++;
        }
        /**list -> rear = (list -> rear + 1) % (list -> size); // mod
        if (list -> rear < 0) list -> rear *= -1;*/
        list -> data[list -> rear] = val;
        (list -> num)++;
        return 1;
    }
    else return 0; 
}

struct TreeNode* pop_back(TreeNodeArrayList* list) {
    if (!empty(list)) {
        struct TreeNode* val = getEnd(list);
        // one element
        if (list -> head == list -> rear) {
            list -> head = -1;
            list -> rear = -1;
        }
        // eg. [rear, NULL, NULL, head, val] after 3 push_front
        else if (list -> rear == 0) {
            list -> rear = list -> size - 1;
        }
        else {
            (list -> rear)--;
        }
        /*list -> rear = (list -> rear - 1) % (list -> size); // mod
        if (list -> rear < 0) list -> head *= -1;*/
        (list -> num)--;
        return val;
    } 
    printf("cannot pop empty arraylist\n");
    return NULL;
}

void closeTreeNodeArrayList(TreeNodeArrayList* list) {
    free(list -> data);
    free(list);
}

#endif
