int findTheLongestBalancedSubstring(char * s){
	int max = 0;
	int cur = 0;
	int zero = 0;
	int inZero = 1;
	// make sure the first char is 0
	while (s[0] == '1') {
		s++;
	}
	for (int i = 0; s[i] != NULL; i++) {
        if (inZero) {
            if (s[i] == '0') { // state 1
                zero++;
			    cur++;
            }
            else {
                inZero = 0; // state 2
                zero--;
                cur++;
            }
        }
        else {
            if (s[i] == '1') { // state 3
                zero--;
			    cur++;
            }
            else { // state 4
                inZero = 1;
                if (zero < 0)
                    cur += zero; // remove excess 1
                else if (zero > 0)
                    cur -= zero; // remove excess 0
                max = (cur >= max)? cur: max;
                zero = 1;
                cur = 1;
            }
        }
	}
	// check for last substring
	if (zero < 0)
		cur += zero; // remove excess 1
	else if (zero > 0)
		cur -= zero; // remove excess 0
	max = (cur >= max)? cur: max;
	return max;
}
