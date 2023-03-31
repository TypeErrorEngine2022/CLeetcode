#include "ArrayList.h"

typedef struct {
	ArrayList* queue;    
} MyStack;


MyStack* myStackCreate() {
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	stack -> queue = createArrayList(101);
	return stack;
}

void myStackPush(MyStack* obj, int x) {
	push_backForArrayList(obj -> queue, x);
}

int myStackPop(MyStack* obj) {
	for (int i = 0; i < getSizeForArrayList(obj -> queue) -  1; i++) {
		push_backForArrayList(obj -> queue, pop_frontForArrayList(obj -> queue));
	}
	int res = pop_frontForArrayList(obj -> queue);
	return res;
}

int myStackTop(MyStack* obj) {
	int res = myStackPop(obj);
	myStackPush(obj, res);
	return res;
}

bool myStackEmpty(MyStack* obj) {
	return getSizeForArrayList(obj -> queue) == 0; 
}

void myStackFree(MyStack* obj) {
	closeArrayList(obj -> queue);
	free(obj);
}
