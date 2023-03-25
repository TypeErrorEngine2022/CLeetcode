#include <stdio.h>

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

int main() {
    int arr[6] = {4, 2, 6, 1, 3, 5};
    printf("2-th largest is %d\n", arr[quickSelect(arr, 6, 2)]);
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

    