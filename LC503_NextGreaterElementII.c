#include <limits.h>
#include "ArrayList.h"

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
	ArrayList* stack = createArrayList(numsSize);
	int* res = (int*)malloc(numsSize * sizeof(int));
	*returnSize = numsSize;
	for (int i = 0; i < numsSize; i++) 
        res[i] = -1;
	// twice from [0: sz -1] since it is circular
    // pos = i % numsSize for circular array
	for (int i = 0; i < 2 * numsSize; i++) {
		// if cur element is the next greater element for elements in stack
		// use stack because it can retrieve closest element to cur
		while (!isEmptyForArrayList(stack) 
				&& nums[i % numsSize] > nums[getEndForArrayList(stack)]) {
			res[getEndForArrayList(stack)] = nums[i % numsSize];
			pop_backForArrayList(stack);
		}
		// store the index so to find cur's next greater
		push_backForArrayList(stack, i % numsSize);
	}
    closeArrayList(stack);
	return res;
}
