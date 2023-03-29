#include <stdlib.h>
#include <stdbool.h>

bool backspaceCompare(char * s, char * t){
int sp = strlen(s) - 1;
	int tp = strlen(t) - 1;
	bool same = true;
	int delete = 0;
	while (sp >= 0 || tp >= 0) {
		// loop until all delete is used till sp or sp is invalid
		// eg. ...ca#b#, can stop at c, it is the first valid char in text editor
		while (sp >= 0) {
			// in a#b#, # will accumulate after b is deleted, and meet # again
			if (s[sp] == '#') {
				delete++;
				sp--;
			}
			// non #, but need to delete
			// eg. aa##
			else if (delete > 0) {
				sp--;
				delete--;
			}
			// all delete is used, meet valid char
			else
				break;
		}

		delete = 0;
		
		while (tp >= 0) {
			if (t[tp] == '#') {
				delete++;
				tp--;
			}
			else if (delete > 0) {
				tp--;
				delete--;
			}
			else {
				break;
			}
		}

		if (sp < 0 && tp < 0) return true; // all empty
		if (sp < 0 && tp >= 0) return false;
		if (sp >= 0 && tp < 0) return false;
		if (s[sp] != t[tp]) return false;
		sp--;
		tp--;
	}
	return same;	
}
