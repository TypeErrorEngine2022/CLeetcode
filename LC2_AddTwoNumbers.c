struct ListNode* solve(struct ListNode* l1, struct ListNode* l2, int carryIn) {
	if (l1 == NULL && l2 == NULL && carryIn == 0) return NULL;
	struct ListNode* cur = (struct ListNode*)malloc(sizeof(struct ListNode));
	int lval = (l1 == NULL)? 0: l1 -> val;
	int rval = (l2 == NULL)? 0: l2 -> val;
	cur -> val = lval + rval + carryIn;
	if (cur -> val >= 10) {
		cur -> val -= 10;
		carryIn = 1;
	}
	cur -> next = NULL;
	struct ListNode* op1 = (l1 == NULL)? NULL: l1 -> next;
	struct ListNode* op2 = (l2 == NULL)? NULL: l2 -> next;
	cur -> next = solve(op1, op2, carryIn);
	return cur;
}
	

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	return solve(l1, l2, 0);		    
}
