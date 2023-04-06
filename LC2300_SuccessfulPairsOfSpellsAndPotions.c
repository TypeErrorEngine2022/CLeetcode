#include <stdlib.h>

int compfunc(const void* a, const void* b) {
	return (*(int*)a > *(int*)b);
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize
		, long long success, int* returnSize){
	int* res = (int*)calloc(spellsSize, sizeof(int));
	*returnSize = spellsSize;
	qsort(potions, potionsSize, sizeof(int), compfunc);
	for (int i = 0; i < spellsSize; i++) {
		int l = 0;
		int r = potionsSize - 1;
		int mid;
		while (l <= r) {
			mid = l + (r - l) / 2;
			long long product = (long long)spells[i] * potions[mid];
			if (product >= success)
				r = mid - 1;
			else if (product < success)
				l = mid + 1;
		}
		res[i] = potionsSize - l;
	}
	return res;
}
