#include "DequeForIntArr.h"

int largestRectangleArea(int* heights, int heightsSize){
	DequeForIntArr* stack = createDequeForIntArr(heightsSize, 2);
	int maxArea = -1;
	for (int i = 0; i < heightsSize; i++) {
		int* arr = (int*)malloc(2 * sizeof(int));
		arr[0] = i; // left extension bounder
		arr[1] = heights[i]; 
		if (isEmptyForDequeForIntArr(stack) 
			|| heights[i] > getEndForDequeForIntArr(stack)[1]) {
			push_backForDequeForIntArr(stack, arr);
        }
        else {
            while (!isEmptyForDequeForIntArr(stack) && 
                    getEndForDequeForIntArr(stack)[1] >  heights[i]) {
                int* top = pop_backForDequeForIntArr(stack);
                int area = top[1] * (i - top[0]);
                maxArea = (area > maxArea)? area: maxArea;
                arr[0] = top[0];
                free(top);
            }
            push_backForDequeForIntArr(stack, arr);
        }
	}
	while (!isEmptyForDequeForIntArr(stack)) {
		int* top = pop_backForDequeForIntArr(stack);
		int area = top[1] * (heightsSize - top[0]);
		maxArea = (area > maxArea)? area: maxArea;
		free(top);
	}
	closeDequeForIntArr(stack);
	return maxArea;
}
