#include "math.h"

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
	*returnSize = numsSize;
	int* res = (int*)malloc(numsSize * sizeof(int));
	int l = 0, r = numsSize - 1;
	int pt = numsSize - 1;
	while (l <= r) {
		int lp = abs(nums[l]);
		int rp = abs(nums[r]);
		if (lp <= rp) {
			res[pt--] = nums[r] * nums[r];
			r--;
		}
		else {
			res[pt--] = nums[l] * nums[l];
			l++;
		}
	}
	return res;
}
