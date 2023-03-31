#include "ArrayList.h"

typedef struct {
	ArrayList* s1;
	ArrayList* s2;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue -> s1 = createArrayList(100);
	queue -> s2 = createArrayList(100);
	return queue;
}

void myQueuePush(MyQueue* obj, int x) {
	push_backForArrayList(obj -> s1);
}

int myQueuePop(MyQueue* obj) {
	if (!isEmptyForArrayList(obj -> s2))
		return pop_backForArrayList(obj -> s2);

	while (!isEmptyForArrayList(obj -> s1))
		push_backForArrayList(obj -> s2, pop_backForArrayList(obj -> s1));

	return pop_backForArrayList(obj -> s2);
}

int myQueuePeek(MyQueue* obj) {
	int res = myQueuePop(obj);
	push_backForArrayList(obj -> s2);
	return res;
}

bool myQueueEmpty(MyQueue* obj) {
	return isEmptyForArrayList(obj -> s1) && isEmptyForArrayList(obj -> s2); 
}

void myQueueFree(MyQueue* obj) {
	closeArrayList(obj -> s1);
	closeArrayList(obj -> s2);
	free(obj);
}
