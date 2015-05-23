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
    ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode newHead(-1);
		newHead.next = head;

		ListNode *tail1 = &newHead;
		ListNode *tmp = &newHead;
		ListNode *head2 = NULL;

		while (tmp->next != NULL && tmp->next->val < x) {
			tmp = tmp->next;
		}

		if (tmp->next != NULL) {
			tail1 = tmp;
			head2 = tmp->next;

			ListNode *tmpH2 = head2;
			ListNode *pre = tmpH2;
			ListNode *p1 = pre->next;

			while (p1 != nullptr) {
				if (p1->val < x) {
					pre->next = p1->next;
					tail1->next = p1;
					tail1 = tail1->next;
					p1 = pre->next;
				} else {
					pre = pre->next;
					p1 = pre->next;
				}
			}

			tail1->next = head2;
		}

		return newHead.next;
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(4);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(5);
	ListNode *n6 = new ListNode(2);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	Solution *sl = new Solution();
	ListNode *h = sl->partition(n1, 3);

	ListNode *tmp = h;
	while (tmp != nullptr) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
