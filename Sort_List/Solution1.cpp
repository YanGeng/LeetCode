#include <iostream>

using namespace std;

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
	ListNode* merge(ListNode *h1, ListNode *h2) {
		if (h1 == NULL) 
			return h2;

		if (h2 == NULL)
			return h1;

		if (h1->val > h2->val) {
			h2->next = merge(h1, h2->next);
			return h2;
		} else {
			h1->next = merge(h1->next, h2);
			return h1;
		}
	}

    ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) 
			return head;

		ListNode *p1 = head;
		ListNode *p2 = head;
		ListNode *pre_p1 = head;

		while (p2 != NULL && p2->next != NULL ) {
			pre_p1 = p1;
			p1 = p1->next;
			p2 = p2->next->next;
		}

		pre_p1->next = NULL;
		ListNode *h1 = sortList(head);
		ListNode *h2 = sortList(p1);

		ListNode *res = merge(h1, h2);
		return res;
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(4);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *h = sl->sortList(n1);
//	ListNode *hh = sl->merge(n1, n3);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
