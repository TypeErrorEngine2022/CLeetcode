struct ListNode* solveKGroup(struct ListNode* prev,
								struct ListNode* head, int k) {
	struct ListNode* cur = head;
	int i;
	for (i = 0; i < k - 1; i++) {
		if (cur == NULL) break;
		cur = cur -> next;
	}
	if (cur == NULL) return head;

	struct ListNode* oriNext = cur -> next;
	cur -> next = NULL;
	// in LC206_ReverseLinkedList.c
	struct ListNode* newHead = reverseList(head); 
	prev -> next = newHead;
	// head will becomes last node in list pointed by newHead
	head -> next = solveKGroup(head, oriNext, k);
	return newHead;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	solveKGroup(dummy, head, k);
	struct ListNode* res = dummy -> next;
	free(dummy);
	return res;

}
