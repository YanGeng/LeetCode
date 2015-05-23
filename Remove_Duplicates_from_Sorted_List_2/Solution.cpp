#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode tmpH(-1);
		tmpH.next = head;

		ListNode *pre = &tmpH;
		ListNode *p1 = pre->next;
		ListNode *p2 = p1->next;

		bool p1_flag = false;

		while (p2 != NULL) {
			if (p1->val == p2->val) {
				p1_flag = true;
				ListNode *tmp = p2;
				p2 = tmp->next;
				delete tmp;
			} else if (p1->val != p2->val) {
				if (p1_flag) {
					ListNode *tmp = p1;
					p1 = p2;
					p2 = p1->next;
					pre->next = p1;
					delete tmp;
				} else {
					pre = p1;
					p1 = pre->next;
					p2 = p1->next;
				}
				p1_flag = false;
			}
		}

		if (p1_flag) {
			pre->next = NULL;
		}

		return tmpH.next;
    }
};


int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(5);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(3);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *h = sl->deleteDuplicates(n1);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
