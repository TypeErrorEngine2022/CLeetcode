#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** data; // arr[i] = {info1, info2, ...}
    int head;
    int rear;
    int num; // number of elements in queue
    int size;// max size of list
	int elementSize;
}DequeForIntArr;


DequeForIntArr* createDequeForIntArr(int capacity, int elementSize) {
    int** data = (int**)malloc(capacity * sizeof(int*));
	memset(data, 0, capacity * sizeof(int*));
    DequeForIntArr* list = (DequeForIntArr*)malloc(sizeof(DequeForIntArr));
    if (list == NULL) return 0;
    list -> data = data;
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
    list -> size = capacity;
	list -> elementSize = elementSize;
    return list;
}

void clearDequeForIntArr(DequeForIntArr* list) {
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
} 

void reallocate(DequeForIntArr* list, int capacity) {
    int** newData = list -> data;
    if (list -> size < capacity) {
        // will free original data if not enough space to extend
        newData = (int**)realloc(list -> data, capacity * sizeof(int));
		memset(newData, 0, capacity * sizeof(int*));
        if (newData == NULL) printf("Not enough space\n");
    }
    
    list -> data = newData;
    list -> head = -1;
    list -> rear = 0;
    list -> num = 0;
    list -> size = capacity;
}

int getSizeForDequeForIntArr(DequeForIntArr* list) {
    return list -> num;
}

int isEmptyForDequeForIntArr(DequeForIntArr* list) {
    return list -> num == 0;
}

int isFullForDequeForIntArr(DequeForIntArr* list) {
    return list -> num == list -> size;
}

int* getFrontForDequeForIntArr(DequeForIntArr* list) {
    if (!isEmptyForDequeForIntArr(list)) {
        return list -> data[list -> head];
    }
    else return NULL;
}

int* getEndForDequeForIntArr(DequeForIntArr* list) {
    if (!isEmptyForDequeForIntArr(list)) {
        return list -> data[list -> rear];
    }
    else return NULL;
}

int* getKthForDequeForIntArr(DequeForIntArr* list, int k) {
    if (!isEmptyForDequeForIntArr(list)) {
        return list -> data[(k + list -> head) % (list -> size)];
    }
    return NULL;
}

int** getDateForDequeForIntArr(DequeForIntArr* list) {
	return list -> data;
}

void push_frontForDequeForIntArr(DequeForIntArr* list, int* val) {
    if (!isFullForDequeForIntArr(list)) {
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
    }
}

int* pop_frontForDequeForIntArr(DequeForIntArr* list) {
    if (!isEmptyForDequeForIntArr(list)) {
        int* val = getFrontForDequeForIntArr(list);
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
        (list -> num)--;
        return val;
    } 
    printf("cannot pop empty arraylist\n");
    return NULL;
}

void printDequeForIntArr(DequeForIntArr* list) {
    for (int i = 0; i < list -> size; i++) {
		printf("(");
        for (int j = 0; j < list -> elementSize; j++) {
            if (j != 0) printf(", ");
        	printf("%d ", list -> data[(i + list -> head) % (list -> size)][j]);
        }
        printf(")");
    }
}

void push_backForDequeForIntArr(DequeForIntArr* list, int* val) {
	if (isFullForDequeForIntArr(list)) return;

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
}

int* pop_backForDequeForIntArr(DequeForIntArr* list) {
    if (!isEmptyForDequeForIntArr(list)) {
        int* val = getEndForDequeForIntArr(list);
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

// free arr by creator!
void closeDequeForIntArr(DequeForIntArr* list) {
    free(list -> data);
    free(list);
}
