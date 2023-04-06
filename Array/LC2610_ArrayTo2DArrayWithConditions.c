/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int hash[201];
    memset(hash, 0, 201 * sizeof(int));
    
	int max = 0;
	int minVal = 201, maxVal = -1;
	for (int i = 0; i < numsSize; i++) {
		hash[nums[i]]++;
		max = (hash[nums[i]] >= max)? hash[nums[i]]: max;
		minVal = (nums[i] < minVal)? nums[i]: minVal;
		maxVal = (nums[i] > maxVal)? nums[i]: maxVal;
	}
    
    *returnSize = max;
	int** res = (int**)calloc(*returnSize, sizeof(int*));
    // returnColumnSizes is address of 1D array
    (*returnColumnSizes) = (int*)calloc(*returnSize, sizeof(int)); // store the size of i-th row
	
	for (int resPt = 0; resPt < *returnSize; resPt++) {
        // at most (maxVal - minVal + 1) distinct integers
		int* sub = (int*)calloc(maxVal - minVal + 1, sizeof(int));
		int pt = 0;
		for (int i = minVal; i <= maxVal; i++) {
			if (hash[i] > 0) {
				hash[i]--;
				sub[pt++] = i;
			}
		}
		sub = (int*)realloc(sub, pt * sizeof(int));
		res[resPt] = sub;
		((*(returnColumnSizes))[resPt]) = pt;
	}

	return res;
}
