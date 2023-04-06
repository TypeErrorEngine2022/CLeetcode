#include <stdlib.h>

int compfunc(const void* a, const void* b) {
	return (*(int*)a >= *(int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit){
	qsort(people, peopleSize, sizeof(int), compfunc);

	int l = 0;
	int r = peopleSize - 1;
	int res = 0;
	while (l <= r) {
		int remain = limit - people[r];
		r--; // put the heaviest on boat first
		
		// the l <= r ensures that we will not put same person on boat twice
		// when l == r, r-- on above will cause l <= r false
		if (l <= r && remain >= people[l])
			l++; // put the lightest on boat
		res++;
	}
	return res;
}
