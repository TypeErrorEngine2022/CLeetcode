#include "LightDeque.h"

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
	*returnSize = numsSize - k + 1;
	int* res = (int*)malloc(*returnSize * sizeof(int));
	// store index
	LightDeque* deque = createLightDeque(numsSize);
	int l = 0, r = 0;
	for (r = 0; r < numsSize; r++) {
		while (!isEmptyForLightDeque(deque) &&
				nums[getEndForLightDeque(deque)] < nums[r])
			pop_backForLightDeque(deque);

		// nums[i] > elements in queue
		// monotonic decreasing queue
		push_backForLightDeque(deque, r);

		// remove oldest value which is out of bound
		if (getFrontForLightDeque(deque) < l)
			pop_frontForLightDeque(deque);
		
		// only for first window since first update is when l = 0, r = k - 1
		if (r >= k - 1) {
			// since monotonic decreasing
			// leftmost value is max
			int maxIx = getFrontForLightDeque(deque);
			res[l] = nums[maxIx];
			l++;
		}
	}
	closeLightDeque(deque);
	return res;
}
