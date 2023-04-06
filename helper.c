struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = NULL;
	while (cur != NULL) {
		next = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

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

void swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/**
 * @brief partition the array using the pivot value such that all values before pivot are less than or equal to the pivot
 * 
 * @param arr target array from [l, r]
 * @param l left bound of array
 * @param r right bound of array
 * @param pivot Index of pivot before partition
 * @return Index of pivot after partition
 */
int partition(int* arr, int l, int r, int pivot) {
    swap(arr, r, pivot);
    int p = l;
    for (int i = l; i < r; i++) {
        if (arr[i] <= arr[r]) {
            swap(arr, i, p);
            p++;
        }
    }
    swap(arr, p, r);
    return p;
}

/**
 * @brief find the k-th largest element in array
 * 
 * @param arr 
 * @param arrSize 
 * @param k 
 * @return the index of k-th largest element
 */
int quickSelect(int* arr, int arrSize, int k) {
    int l = 0;
    int r = arrSize - 1;
    // 1-th largest in size n array -> pivot = (n - 1)th element
    // target index = n - k
    k = arrSize - k;
    int pivot = 0;
    while (l <= r) {
        pivot = partition(arr, l, r, r);
        if (pivot == k) 
            break;
        else if (pivot < k) 
            l = pivot + 1;
        else            
            r = pivot - 1;
    }
    return pivot;
}            

// if len == even, return the second node in middle
// eg. 1 -> 2 -> 2 -> 4 will return the second 2
// if we need first 2
// change the while condition to
// while (fast -> next != NULL && fast -> next -> next != NULL) 
// so that fast will have one less step 
struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

// retrun the max value
int max(int a, int b) {
	return (a >= b)? a: b;
}

int compfunc(const void* a, const void* b) {
	return (*(int*)a >= *(int*)b);
}
