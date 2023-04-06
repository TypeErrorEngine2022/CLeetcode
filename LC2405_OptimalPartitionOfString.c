#include <string.h> 

int partitionString(char * s){
	int pos[26]; // store the position of last occurrence
	// don't use 0 to initialize pos
	// otherwise all pos will >= init start = 0 -> trigger res++
	memset(pos, -1, 26 * sizeof(int));
	int res = 0;
	int start = 0; // start of current substring
	for (int i = 0; s[i] != NULL; i++) {
		char cur = s[i];
		if (pos[cur - 'a'] >= start) {
			res++;
			start = i;
			pos[cur - 'a'] = i;
		}
		pos[cur - 'a'] = i;
	}
	res++; // for last substring
	return res;
}

int getBit(int mask, int pos) {
	return (mask & (1 << pos)) > 0;
}

void setBit(int mask, int pos) {
	mask |= (1 << pos);
}

// O(1) Space
int partitionString(char * s) {
	int mask = 0;
	for (int i = 0; s[i] != NULL; i++) {
		char cur = s[i];
		if (getBit(cur - 'a')) {
			res++;
			mask = 0; // clear bitmask
		}
		setBit(mask, pos);
	}
	res++; // for last substring
	return res;
}
