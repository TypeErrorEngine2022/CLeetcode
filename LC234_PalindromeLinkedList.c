#include <stdbool.h>
#include "helper.h"

bool isPalindrome(struct ListNode* head){ struct ListNode* cur = head;
	if (head == NULL) return true;
	struct ListNode* mid = middleNode(head);
	struct ListNode* second = reverseList(mid);
	// for 1, 2, 2(mid), 1(second)
	// it becomes 1 -> 2 -> 2 <- 1(second)
	// 						|
	//						v 
	//						NULL
	// first half: 1, 2, 2(mid), null
	// second half: 1, 2(mid), null (the 2 is the second 2 above)
	// the 2(mid) is not checked in first half
	// because r has already becomes NULL

	// for 1, 2, 3, 2, 1
	// it becomes 1 -> 2 -> 3 <- 2 <- 1(second)
	// 						|
	//						v 
	//						NULL
	// first half: 1, 2, 3, null
	// second half: 1, 2, 3, null
	struct ListNode* l = head;
	struct ListNode* r = second
	bool res = true;
	while (r != NULL) {
		if (l -> val != r -> val) {
			res = false;
			break;
		}
		l = l -> next;
		r = r -> next;
	}
	// 1 -> 2 -> 3 back to 3 -> 2 -> 1
	reverseList(second); 
	return res;
}
