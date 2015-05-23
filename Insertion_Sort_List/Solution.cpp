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
    ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode newHead(-1);
		ListNode *newH = &newHead;

		newH->next = head;

		ListNode *tmp = head->next;
		head->next = NULL;

		while (tmp != NULL) {
			ListNode *tmpNext = tmp->next;
			int tmpVal = tmp->val;
			while (newH->next != NULL && newH->next->val < tmpVal) {
				newH = newH->next;
			}

			if (newH->next != NULL) {
				ListNode *t = newH->next;
				newH->next = tmp;
				tmp->next = t;
			} else {
				newH->next = tmp;
				tmp->next = NULL;
			}

			tmp = tmpNext;
			newH = &newHead;
		}

		return newHead.next;
    }
};

int main ()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(5);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution *sl = new Solution();
	ListNode *h = sl->insertionSortList(n1);

	ListNode *tmp = h;
	while (tmp != NULL) {
		std::cout << "The val is: " << tmp->val << std::endl;
		tmp = tmp->next;
	}

	return 0;
}
