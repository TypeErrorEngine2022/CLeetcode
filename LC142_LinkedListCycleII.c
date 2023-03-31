struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	int hasCycle = 0;
	while (fast != NULL && fast -> next != NULL) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if (fast -> val == slow -> val) {
			hasCycle = 1;
			break;
		}
	}

	if (!hasCycle) return NULL;

	slow = head;
	while (slow -> val != fast -> val) {
		slow = slow -> next;
		fast = fast -> next;
	}
	return slow;
}
