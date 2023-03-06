#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 
 * Linked List implementation for int data type with virtual header
 * List* createList()
 * -> create empty list
 * -> return the virtual header
 * 
 * void push_front(List* list, int val)
 * -> insert the node at the beginning of the list
 * -> Time O(1) Space O(1)
 *
 * void push_back(List* list, int val)
 * -> insert the node at the end of the list
 * -> Time O(1) Space O(1)
 * 
 ** int pop_front(List* list)
 * -> remove the first element 
 * -> Time O(1) Space O(1)
 *
 * void pop_back(List* list)
 * -> remove the last element
 * -> Time O(1) Space O(1)
 * 
 * void insertAtKth(List* list, int pos, int val)
 * -> insert the node at the kth pos of the list
 * -> Time O(n) Space O(1) 
 * 
 * void printList()
 * -> print the list from head to tail
 * -> Time O(n) Space O(1)
 * 
 * int getFront(List* list)
 * -> get the first element of the list
 * -> return the value of first element 
 * -> Time O(1) Space O(1)
 * 
 * int getEnd(List* list)
 * -> get the last element of the list
 * -> return the value of the last element
 * -> Time O(1) Space O(1)
 *  
 * int getKth(List* list, int pos)
 * -> get the element at the kth position
 * -> return the value of the kth element
 * -> Time O(n) Space O(1)
 * 
 * int pop_front(List* list)
 * -> remove the first element 
 * -> Time O(1) Space O(1)
 * 
 * void deleteKth(List* list, int pos)
 * -> delete kth element from the list
 * -> Time O(n) Space O(1)
 * 
 * int empty(List* list)
 * -> check whether the list is empty
 * -> return 1 if the list is empty, else return 0
 * -> Time O(1) Space O(1)
 *  
 * int sizeOfList(List* list)
 * -> find the size of the list 
 * -> return the size of list
 * -> Time O(n) Space O(1)
 * 
 * void clear(List* list)
 * -> clear the list to make it empty 
 * 
 * void closeList(List* list)
 * -> clear list and then free the virtual header
 * -> Time O(n) Space O(1)
 */

typedef struct node_s
{
   int data;
   struct node_s* next; 
   struct node_s* prev;
}node;

typedef struct List_s
{
    node* head;
    node* end;
}List;


List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list -> head = NULL;
    list -> end = NULL; 
    return list;
}

int empty(List* list) {
    if (list -> head == NULL) return 1;
    
    return 0;
}

void push_front(List* list, int val){
    node* head = list -> head;
    node* cur = (node*)malloc(sizeof(node));
    cur -> data = val;
    cur -> next = head; 
    cur -> prev = NULL;
    if (empty(list)) list -> end  = cur;
    list -> head = cur;
}

void push_back(List* list, int val) {
    node* cur = (node*)malloc(sizeof(node));
    cur -> data = val;
    cur -> next = NULL;
    cur -> prev = list -> end;
    if (empty(list)) 
        list -> head = cur;
    else 
        list -> end -> next = cur;
    list -> end = cur;
}

int pop_front(List* list) {
    if (empty(list)) {
        printf("Cannot pop empty list\n");
        return -1;
    }
    node* target = list -> head;
    list -> head = list -> head -> next;
    if (list -> head == NULL) list -> end = NULL;
    else list -> head -> prev = NULL;
    int targetVal = target -> data;
    free(target);
    return targetVal;
}

int pop_back(List* list) {
    if (empty(list)) {
        printf("Cannot pop empty list\n");
        return -1;
    }
    node* target = list -> end;
    list -> end = list -> end -> prev;
    if (list -> end == NULL) list -> head = NULL;
    else list -> end -> next = NULL;
    int targetVal = target -> data;
    free(target);
    return targetVal;
}

void printList(List* list) {
    if (empty(list) == 1) return;

    node* temp = list -> head;
    while (temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void insertAtKth(List* list, int data, int pos) {
    if (pos == 1) {
        push_front(list, data);
        return;
    }

    node* cur = (node*)malloc(sizeof(node));
    cur -> data = data;

    node* temp = list -> head;
    // traverse to the (k-1)th node
    for (int i = 0; i < pos - 2; i++) {
        temp = temp -> next;
    } 
    node* oriKth = temp -> next;
    temp -> next = cur;
    cur -> next = oriKth;
}

void deleteAtKth(List* list, int pos) {
    node* temp = list -> head;
    // traverse to the (k-1)th node
    for (int i = 0; i < pos - 2; i++) {
        temp = temp -> next;
    }
    node* target = temp -> next;
    temp -> next = target -> next;
    free(target);
}

int getFront(List* list) {
    return list -> head -> data;
}

int getEnd(List* list) {
    return list -> end -> data;
}

int getKth(List* list, int pos) {
    node* temp = list -> head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp -> next;
    }
    return temp -> data;
}

void clear(List* list) {
    node* temp = list -> head;
    while (temp != NULL) {
        node* tp2 = temp -> next;
        free(temp);
        temp = tp2;
    }
    list -> head = NULL;
    list -> end = NULL;
} 

int sizeOfList(List* list) {
    node* temp = list -> head;
    int sz = 0;
    while (temp != NULL) {
        sz++;
        temp = temp -> next;
    }
    return sz;
}

void closeList(List* list){
    clear(list);
}