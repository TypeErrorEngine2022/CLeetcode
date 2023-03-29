struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	// if n = 1, remove (size -1)th from start
	// if n = 2, remove (size -2)th from start
	/**if (head -> next == NULL) {
		free(head);
		return NULL;
	}
	
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	int targetDiff = n;
	int diff = 0;
	while (fast -> next != NULL) {
		fast = fast -> next;
		if (diff >= targetDiff)
			slow = slow -> next;
		diff++;
	}
	if (diff < targetDiff) {
		struct ListNode* newHead = head -> next;
		free(head);
		return newHead;
	}
	struct ListNode* target = slow -> next;
	slow -> next = target -> next;
	free(target);
	target = NULL;
	return head;*/

	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy -> next = head;
	struct ListNode* l = dummy;
	struct ListNode* r = head;
	for (int i = 0; i < n; i++) {
		r = r -> next;
	}
	while (r != NULL) {
		r = r -> next;
		l = l -> next;
	}
	struct ListNode* target = l -> next;
	l -> next = l -> next -> next;
	free(target);
	struct ListNode* res = dummy -> next;
	free(dummy);
	return res;
}
