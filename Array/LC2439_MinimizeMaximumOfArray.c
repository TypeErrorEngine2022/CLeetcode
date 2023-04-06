int minimizeArrayValue(int* nums, int numsSize){
	int* mean = (int*)calloc(numsSize, sizeof(int));
	mean[0] = nums[0];
	int max = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] >= mean[i - 1]) {
			long sum = (long)mean[i - 1] + nums[i];
			printf("sum: %ld\n", sum);
			mean[i] = ceill((long double)sum / 2.0);
		}
		else {
			mean[i] = nums[i];
		}
		max = (mean[i] > max)? mean[i]: max;
	}
	for (int i = 0; i < numsSize; i++)
		printf("mean[%d] = %d\n", i, mean[i]);
	free(mean);
	return max;	
}
