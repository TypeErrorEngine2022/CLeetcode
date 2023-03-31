// only support
// push_back
// pop_front, pop_back
#pragma once
#include <stdlib.h>

typedef struct {
	int* data;
	int front;
	int rear;
} LightDeque;

LightDeque* createLightDeque(int capacity) {
	LightDeque* deque = (LightDeque*)malloc(sizeof(LightDeque));
	deque -> data = (int*)malloc(capacity * sizeof(int));
	deque -> front = 0;
	deque -> rear = -1;
	return deque;
}

void push_backForLightDeque(LightDeque* deque, int val) {
	deque -> rear += 1;
	deque -> data[deque -> rear] = val;
}

int pop_frontForLightDeque(LightDeque* deque) {
	int data = deque -> data[deque -> front];
	deque -> front += 1;
	return data;
}

int pop_backForLightDeque(LightDeque* deque) {
	int data = deque -> data[deque -> rear];
	deque -> rear -= 1;
	return data;
}

int getFrontForLightDeque(LightDeque* deque) {
	return deque -> data[deque -> front];
}

int getEndForLightDeque(LightDeque* deque) {
	return deque -> data[deque -> rear];
}

int isEmptyForLightDeque(LightDeque* deque) {
	return deque -> rear < deque -> front;
}

void closeLightDeque(LightDeque* deque) {
	free(deque -> data);
	free(deque);
}
