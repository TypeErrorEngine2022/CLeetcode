#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList_s
{
    int* data;
    int head;
    int rear;
    int num; // number of elements in queue
    int size;// max size of list
}ArrayList;


ArrayList* createArrayList(int capacity) {
    int* data = (int*)malloc(capacity * sizeof(int));
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    if (list == NULL) return 0;
    list -> data = data;
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
    list -> size = capacity;
    return list;
}

void clearArrayList(ArrayList* list) {
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
} 

void reallocate(ArrayList* list, int capacity) {
    if (list -> size < capacity) {
        // will free original data if not enough space to extend
        int* newData = (int*)realloc(list -> data, capacity * sizeof(int));
        if (newData == NULL) printf("Not enough space\n");
    }

    //printf("reallocating...\n");
    
    list -> data = newData;
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
    list -> size = capacity;
}

int getSize(ArrayList* list) {
    return list -> num;
}

int empty(ArrayList* list) {
    return list -> num == 0;
}

int isFull(ArrayList* list) {
    return list -> num == list -> size;
}

int getFront(ArrayList* list) {
    if (!empty(list)) {
        return list -> data[list -> head];
    }
    else return 0;
}

int getEnd(ArrayList* list) {
    if (!empty(list)) {
        return list -> data[list -> rear];
    }
    else return 0;
}

int push_front(ArrayList* list, int val) {
    if (!isFull(list)) {
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
        (list -> num)++;
        return 1;
    }
    else return 0; 
}

int pop_front(ArrayList* list) {
    if (!empty(list)) {
        int val = getFront(list);
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
    return 0;
}

void printArrayList(ArrayList* list) {
    for (int i = 0; i < list -> size; i++) {
        printf("%d ", list -> data[(i + list -> head) % (list -> size)]);
    }
}

int push_back(ArrayList* list, int val) {
    if (!isFull(list)) {
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

int pop_back(ArrayList* list) {
    if (!empty(list)) {
        int val = getEnd(list);
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
    return 0;
}

void closeArrayList(ArrayList* list) {
    free(list -> data);
    free(list);
}

#endif