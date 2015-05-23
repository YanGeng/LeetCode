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
	ListNode *reverse(ListNode *head, ListNode **newHead) {
		if (head == NULL || head->next == NULL) {
			*newHead = head;
			return head;
		}

		ListNode *res = reverse(head->next, newHead);

		res->next = head;
		head->next = NULL;

		return head;
	}

	ListNode *merge(ListNode *l1, ListNode *l2, int &flag) {
		if (l1 == NULL)
			return l2;

		if (l2 == NULL)
			return l1;

		if (flag % 2 == 0) {
			flag ++;
			l1->next = merge(l1->next, l2, flag);
			return l1;
		} else {
			flag ++;
			l2->next = merge(l1, l2->next, flag);
			return l2;
		}
	}

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
			return;

		ListNode *p1 = head;
		ListNode *p2 = head;
		ListNode *pre = head;

		while (p2 != NULL && p2->next != NULL) {
			pre = p1;
			p1 = p1->next;
			p2 = p2->next->next;
		}

		pre->next = NULL;

		ListNode *newHead = NULL;
		reverse(p1, &newHead);

 		int flag = 0;
		ListNode *resHead = merge(head, newHead, flag);
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
//	ListNode *n3 = new ListNode(3);
//	ListNode *n4 = new ListNode(4);
//	ListNode *n5 = new ListNode(5);

	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;

	Solution *sl = new Solution();
	sl->reorderList(n1);

	ListNode *tmp = n1;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
