void deleteNode(struct ListNode* node) {
	/*struct ListNode* next = node -> next;
	if (next == NULL) return;
	node -> val = next -> val;
	if (node -> next -> next == NULL)
		node -> next = NULL;
	deleteNode(next);*/

	node -> val = node -> next -> val;
	node -> next = node -> next -> next;
}
