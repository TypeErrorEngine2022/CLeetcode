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

struct ListNode* solve(struct ListNode* prev, struct ListNode* newHead) {
	struct ListNode* next = newHead -> next;
	newHead -> next = prev;
	if (next == NULL) 	
		return newHead;
	else
		return solve(newHead, next);
}

struct ListNode* reverseListRecursively(struct ListNode* head){
	if (head == NULL)
		return NULL;
	return solve(NULL, head);
}
