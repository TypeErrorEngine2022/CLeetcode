struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	/**if (headA == headB) return headA;
	if (headA -> next == NULL) {
		while (headB != NULL) {
			if (headB == headA) {
				return headB;
			}
			headB = headB -> next;
		}
		return 0;
	}	
	if (headB -> next == NULL) {
		while (headA != NULL) {
			if (headA == headB) {
				return headB;
			}
			headA = headA -> next;
		}
		return 0;
	}
	struct ListNode* b = headB;
	struct ListNode* a = headA;
	int alen = 0, blen = 0;
	while (b -> next != NULL) {
		blen++;
		b = b -> next;
	}
	while (a -> next != NULL) {
		alen++;
		a = a -> next;
	}
	if (alen > blen) {
		struct ListNode* tmp = headA;
		headA = headB;
		headB = tmp;
	}
	struct ListNode* fast = NULL;
	struct ListNode* slow = NULL;
	int hasCycle = 0;
	struct ListNode* bend = b;
	// there will be cycle if the lists have intersection
	bend -> next = headA;
	b = NULL;
	fast = headB;
	slow = headB;
	
	hasCycle = 0;
	while (fast != NULL && fast -> next != NULL) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if (slow == fast) {
			hasCycle = 1;
			break;
		}
	}
	// find entry point of cycle
	if (hasCycle) {
		slow = headB;
		while (fast != NULL) {
			fast = fast -> next;
			slow = slow -> next;
			if (slow == fast) {
				break;
			}
		}
	}
	bend -> next = NULL;
	return hasCycle? slow: NULL;**/
	
	// O(2(m + n)) solution
	// let a be non-intersected part in list A
	// let b be non-intersected part in list B
	// let c be intersected part between list A and list B
	// concatenate list A and list B, so after list A is list B and after list B is list A 
	// let * be start of intersection
	// path of l1 = a + * + c + NULL + b + *
	// path of l2 = b + * + c + NULL + a + *
	// before the last *, len(path of l1) == len(path of l2)
	// so when l1 and l2 meet, there must be intersection
	// otherwise, they will be both NULL
	struct ListNode* l1 = headA;
	struct ListNode* l2 = headB;
	while (l1 != l2) {
		l1 = (l1 == NULL)? headB: l1 -> next;
		l2 = (l2 == NULL)? headA: l2 -> next;
	}
	return l1
}

