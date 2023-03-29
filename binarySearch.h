// return the index of target
// input array must be sorted
int binarySearch(int* arr, int l, int r, int target) {
	int mid = l + (r - 1) / 2;
	if (arr[mid] == target)
		return target;
	else if (arr[mid] > target) 
		return binarySearch(arr, l, r - 1, target);
	
	return binarySearch(arr, mid + 1, r, target);
}
